#include <stdio.h>
#include <stdlib.h>

int main() 
{   
    // Open file for writing
    FILE *fptr = fopen("white.tud", "w");

    // Check if file opened successfully
    if (!fptr) {
        fprintf(stderr, "Failed to open file white.tud\n");
        return 1;
    }

    // Write TUD header
    int width = 256, height = 256;
    fprintf(fptr, "TUD\n");
    fprintf(fptr, "%d %d 8\n", width, height);

    // Run-length encoded: pixel 255 repeated width*height times
    fprintf(fptr, "R %d %d\n", 255, width * height);
    // Mnemonic R could mean “Repeat 255 for 256×256 pixels”.

    fclose(fptr);
    return 0;
}
