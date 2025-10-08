// Converts a plain PGM (P2) file to a simple run-length encoded TUD format.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static void skip_ws_and_comments(FILE *f) {
    int c;
    // Skip whitespace and # comments (PGM allows comments after '#')
    for (;;) {
        c = fgetc(f);
        if (c == '#') { // skip rest of line
            while ((c = fgetc(f)) != EOF && c != '\n');
        } else if (isspace(c)) {
            continue;
        } else {
            if (c != EOF) ungetc(c, f);
            break;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input.pgm output.tud\n", argv[0]);
        return 1;
    }
    const char *inpath = argv[1];
    const char *outpath = argv[2];

    FILE *in = fopen(inpath, "r");
    if (!in) { perror("fopen input"); return 1; }

    // --- Read PGM (P2) header ---
    char magic[3] = {0};
    if (fscanf(in, "%2s", magic) != 1 || strcmp(magic, "P2") != 0) {
        fprintf(stderr, "Error: Only ASCII PGM (P2) supported.\n");
        fclose(in);
        return 1;
    }

    skip_ws_and_comments(in);
    int width = 0, height = 0, maxval = 0;
    if (fscanf(in, "%d", &width) != 1) { fprintf(stderr, "Bad width\n"); return 1; }
    skip_ws_and_comments(in);
    if (fscanf(in, "%d", &height) != 1) { fprintf(stderr, "Bad height\n"); return 1; }
    skip_ws_and_comments(in);
    if (fscanf(in, "%d", &maxval) != 1) { fprintf(stderr, "Bad maxval\n"); return 1; }
    if (maxval <= 0 || maxval > 255) {
        fprintf(stderr, "Error: Only maxval 1..255 supported.\n");
        return 1;
    }

    // --- RLE encode as we read pixels ---
    FILE *out = fopen(outpath, "w");
    if (!out) { perror("fopen output"); fclose(in); return 1; }

    // Write TUD header
    fprintf(out, "TUD1\n%d %d %d\nRLE\n", width, height, maxval);

    int total = width * height;
    int first = 1;
    int current = 0;
    long count = 0;

    // Read pixels one by one (ASCII ints)
    for (int i = 0; i < total; ++i) {
        int px;
        if (fscanf(in, "%d", &px) != 1) {
            fprintf(stderr, "Error: Not enough pixel data in P2 file.\n");
            fclose(in); fclose(out);
            return 1;
        }
        if (px < 0 || px > maxval) {
            fprintf(stderr, "Error: Pixel out of range: %d\n", px);
            fclose(in); fclose(out);
            return 1;
        }

        if (first) {
            current = px;
            count = 1;
            first = 0;
        } else if (px == current) {
            count++;
        } else {
            // flush run
            fprintf(out, "%d %ld\n", current, count);
            current = px;
            count = 1;
        }
    }
    // flush last run
    if (!first) {
        fprintf(out, "%d %ld\n", current, count);
    }

    fclose(in);
    fclose(out);
    return 0;
}
