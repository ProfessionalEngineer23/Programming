
/* Mark Deegan Sun 27 Oct 2024 11:44:48 GMT
Simple programme to illustrate the limits of data types in C
MD20241027-01
*/

/* this is a pre-processor directive and it tells the compiler to 
include the definitions contained in stdio.h when compiling this code a
That file defines, among other things, the printf() function that we 
use below */
#include <stdio.h>
#include <limits.h>

/* start defining the main() method 
Every C programme requires one and only one main method which is where the
programme will commence execution */

int main()
{ /* start of main method */

   printf("The value of CHAR_BIT: %d\n", CHAR_BIT);
   printf("The value of SCHAR_MIN: %d\n", SCHAR_MIN);
   printf("The value of SCHAR_MAX: %d\n", SCHAR_MAX);
   printf("The value of UCHAR_MAX: %u\n", UCHAR_MAX);
   printf("The value of CHAR_MIN: %d\n", CHAR_MIN);
   printf("The value of CHAR_MAX: %d\n", CHAR_MAX);
   printf("The value of MB_LEN_MAX: %d\n", MB_LEN_MAX);
   printf("The value of SHRT_MIN: %d\n", SHRT_MIN);
   printf("The value of SHRT_MAX: %d\n", SHRT_MAX);
   printf("The value of USHRT_MAX: %u\n", USHRT_MAX);
   printf("The value of INT_MIN: %d\n", INT_MIN);
   printf("The value of INT_MAX: %d\n", INT_MAX);
   printf("The value of UINT_MAX: %u\n", UINT_MAX);
   printf("The value of LONG_MIN: %ld\n", LONG_MIN);
   printf("The value of LONG_MAX: %ld\n", LONG_MAX);
   printf("The value of ULONG_MAX: %lu\n", ULONG_MAX);
   return 0;
} /* end of main method */
