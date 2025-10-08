// This generates a plain PGM file (P2) that is 256x256 pixels, all white (255).

#include <stdio.h>

int main(void) {
    int w = 256, h = 256, maxv = 255;
    FILE *f = fopen("white256.pgm", "w");
    if (!f) { perror("fopen"); return 1; }

    // Header
    fprintf(f, "P2\n%d %d\n%d\n", w, h, maxv);

    // Pixels: all 255
    for (int i = 0; i < w*h; ++i) {
        fprintf(f, "255 ");
        if ((i+1) % w == 0) fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}
