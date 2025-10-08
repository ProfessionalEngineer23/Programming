// This converts a TUD file (with RLE) to a plain PGM file (P2).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input.tud output.pgm\n", argv[0]);
        return 1;
    }
    const char *inpath = argv[1];
    const char *outpath = argv[2];

    FILE *in = fopen(inpath, "r");
    if (!in) { perror("fopen input"); return 1; }

    char magic[16];
    if (fscanf(in, "%15s", magic) != 1 || strcmp(magic, "TUD1") != 0) {
        fprintf(stderr, "Error: Not a TUD1 file.\n");
        fclose(in);
        return 1;
    }

    int width=0, height=0, maxval=0;
    if (fscanf(in, "%d %d %d", &width, &height, &maxval) != 3) {
        fprintf(stderr, "Error: Bad TUD header dims/maxval.\n");
        fclose(in);
        return 1;
    }

    char mode[8];
    if (fscanf(in, "%7s", mode) != 1 || strcmp(mode, "RLE") != 0) {
        fprintf(stderr, "Error: Expected RLE section.\n");
        fclose(in);
        return 1;
    }

    FILE *out = fopen(outpath, "w");
    if (!out) { perror("fopen output"); fclose(in); return 1; }

    // Write PGM (P2) header
    fprintf(out, "P2\n%d %d\n%d\n", width, height, maxval);

    long total = (long)width * (long)height;
    long written = 0;

    while (written < total) {
        int value; long count;
        if (fscanf(in, "%d %ld", &value, &count) != 2) {
            fprintf(stderr, "Error: Unexpected end in RLE stream.\n");
            fclose(in); fclose(out);
            return 1;
        }
        if (value < 0 || value > maxval || count <= 0) {
            fprintf(stderr, "Error: Bad run: value=%d count=%ld\n", value, count);
            fclose(in); fclose(out);
            return 1;
        }

        for (long i = 0; i < count; ++i) {
            fprintf(out, "%d ", value);
            written++;
            if (written % width == 0) fprintf(out, "\n");
            if (written >= total) break;
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
