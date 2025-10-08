#include <stdio.h>
#include <stdlib.h>

int main() 
{   
    // Open file for reading
    FILE *fptr = fopen("white.tud", "r");
    if (!fptr) return 1;

    // Read TUD header
    char magic[4]; 
    int width, height, depth;
    fscanf(fptr, "%s", magic);
    fscanf(fptr, "%d %d %d", &width, &height, &depth);

    char command;
    int value, count;

    FILE *out = fopen("decoded.pgm", "w");
    fprintf(out, "P2\n%d %d\n255\n", width, height);

    fscanf(fptr, " %c %d %d", &command, &value, &count);
    if (command == 'R') {
        for (int i = 0; i < count; i++) {
            fprintf(out, "%d ", value);
            if ((i+1) % width == 0) fprintf(out, "\n");
        }
    }

    fclose(fptr);
    fclose(out);
    return 0;
}
