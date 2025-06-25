/*
Mark Deegan Mon 21 Oct 2024 16:33:33 IST
Programme to print a countdown on screen
This is used for demonstrating the basics of C programming
and how to compile and run such programmes
MD20241021-02
*/

/* this is a pre-processor directive and it tells the compiler to 
include the definitions contained in stdio.h when compiling this code a
That file defines, among other things, the printf() function that we 
use below 
*/
#include <stdio.h>


/* start defining the main() method 
Every C programme requires one and only one main method which is where the
programme will commence execution 
*/

int main()
{					/* start of main method */
	int i;				/* declare a variable i that we will use to count down */
	i = 10; 			/* set an initial value for i */
	while(i>0)			/* continue executing as long as i > 0 */
	{ 				/* start the while loop */
		printf("%d\n",i);	/* print the value of i */
		i = i-1;		/* decrement (reduce) the value of i by one */
	} 				/* end the while loop */
}					/* end of main method */
