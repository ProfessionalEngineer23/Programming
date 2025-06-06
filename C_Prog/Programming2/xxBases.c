/* Mark Deegan Sun 27 Oct 2024 14:58:22 GMT
Simple programme to print the Decimal, hex and octal numbers from 1 to 255

MD20241027-06
*/

/* this is a pre-processor directive and it tells the compiler to 
include the definitions contained in stdio.h when compiling this code a
That file defines, among other things, the printf() function that we 
use below */
#include <stdio.h>

/* start defining the main() method 
Every C programme requires one and only one main method which is where the
programme will commence execution */

int main()
{ // start declaration of main method
	int value; // will contain the value to be printed

	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex "); // print a header line
	printf(" Dec  Oct  Hex \n"); // print a header line
	for (int j=0; j<120; j++) printf("_");
	printf("\n");
	for(int row = 0; row < 32; row++) 
	{ // start for loop printing rows
		for(int column = 0; column < 8; column++)
		{ // start for loop printing columns
			value = ((row * 8) + column) ;
			// print the HEX, DEC, OCT and ASCII(Character) versions of the same value
			printf("%4d %4o %4x|", value, value, value);
		} // end for loop for columns
		printf("\n");
	} // end for loop
} // end declaration of main method
