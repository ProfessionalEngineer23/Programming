/* Mark Deegan Sun 27 Oct 2024 13:16:35 GMT
Simple programme to print the ASCII characters
MD20241027-05
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

	printf("Hexadecimal(16), Scientifici(e), Decimal(10), Octal,   ASCII\n"); // print a header line
	for(int i = 33; i<= 'z'; i++) 
	{ // start for loop
		// print the HEX, DEC, OCT and ASCII(Character) versions of the same value
		printf("%x, %25e, %4d %12o, %6c\n", i, (double)i, i, i, i);
	} // end for loop
} // end declaration of main method
