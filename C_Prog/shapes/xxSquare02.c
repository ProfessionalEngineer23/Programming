/* Mark Deegan Mon 28 Oct 2024 13:16:29 GMT
xxSquare02.c
C programme to print a hollow square on the console using character *
*/

#include <stdio.h> // required for the printf function
#define SQUARE_SIZE 10

int main(int argc, char** argv)
{	// start declaration of main method
	for (int i=0; i < SQUARE_SIZE; i++)
	{	// begin printing rows
		for (int j = 0; j < SQUARE_SIZE; j++)
		{ // start printing columns
			if( (j>0) && (j<(SQUARE_SIZE-1) )&& (i>0) && (i<(SQUARE_SIZE-1)) ) printf(" ");	
			else printf("*");
		} // end printing columns
		printf("\n");
	}	// end printing rows
	
}	// end declaration of main method
