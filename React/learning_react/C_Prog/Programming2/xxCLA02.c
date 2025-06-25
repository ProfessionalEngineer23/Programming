/* Mark Deegan Fri 25 Oct 2024 14:29 IST
Simple programme to handle command-line arguments
This is used for demonstrating the basics of parameter handling for programme execution in C
MD20241025-05
*/

/* this is a pre-processor directive and it tells the compiler to 
include the definitions contained in stdio.h when compiling this code a
That file defines, among other things, the printf() function that we 
use below */
#include <stdio.h>

// every main function in a C programme is given two parameters, 
// these are, argc, the number of arguments, and
// argv, the array containing these argumnets as strings
int main(int argc, char* argv[]) 
{ // Start the declaration of the main method
	int numArgs; 			// declare a variable to hold the number of argumnets received
	numArgs = argc -1; 		// the nubmber of arguments as provided in argc above
	printf("The name of the progrgamme was %s\n", argv[0]);
	printf("You received %d command-line arguments\n", numArgs);	// print the number of arguments received
} // end the declaration of the main method
