/* Mark Deegan Mon 28 Oct 2024 13:06:05 GMT
xxSquare01.c
C programme to print a solid square on the console
*/

#include <stdio.h> // required for the printf function
#define SQUARE_SIZE 10

int main(int argc, char** argv)
{	// start declaration of main method
	for (int i=0; i < SQUARE_SIZE; i++)
	{	// begin printing rows
		for (int j = 0; j < SQUARE_SIZE; j++)
		{ // start printing columns
			printf("*");
		} // end printing columns
		printf("\n");
	}	// end printing rows
	
}	// end declaration of main method
