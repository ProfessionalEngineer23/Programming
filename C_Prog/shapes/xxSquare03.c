/* Mark Deegan Mon 28 Oct 2024 13:16:29 GMT
xxSquare03.c
C programme to accept command-line arguments and to print a hollow square on the console using character specified
*/

#include <stdio.h>	// required for the printf function
#include <stdlib.h>	// required for the atoi function
#define SQUARE_SIZE 10

int main(int argc, char** argv)
{	// start declaration of main method
	int numArgs = argc;	// copy the numnber of Command-Line Arguments
	char use = argv[2][0];
	int side_len = SQUARE_SIZE;
	side_len = atoi(argv[1]);
	

	for (int i=0; i < side_len; i++)
	{	// begin printing rows
		for (int j = 0; j < side_len; j++)
		{ // start printing columns
			if( (j>0) && (j<(side_len-1) )&& (i>0) && (i<(side_len-1)) ) printf(" ");	
			else printf("%c",use);
		} // end printing columns
		printf("\n");
	}	// end printing rows
	
}	// end declaration of main method
