/* Question 6
 Programme that accepts command line arguments and prints out the product
 */

#include <stdio.h> //Include the I/O library
#include <stdlib.h> //Include the standard library for atoi

int main (int argA , char* argB[] )       // Passing the arguments to the main function 
int numarg;                                             // Defines numarg as an integer
numarg = argA -1;                                 // subtract 1 because the the program name counts as a variable
if(numarg>2){                                    // Only 2 arguments allowed
printf("Please enter only 2 arguments!\n");  // print warning
}                                                  // if condition is not met ecit function and execute next command.
else if(numarg<2){                                // Else if statement with condition asking if the numarg is less than 2
printf("Please enter at least 2 arguments!\n");   //Warns user to input at least 2 arguments
}
else { //Else statement if previous condtions were not true
printf("The name of the programme is %s\n", argB[0]); //Prints string value of column 0 of array argB
for (int i = 1; i<= numarg; i++){ //For loop to increment i if i is less than numarg value of 2
   
printf("(%d) %s \n", i, argB[i]); //Prints i value and i value column from argB
}
float product=0; //Defines product as a float of 0
int valA, valB ; //Defines integers ValA and ValB
valA = atoi(argB[1]); //Converts valA character string to the number value stored in array argB column 1
valB = atoi(argB[2]); //Converts valB character string to the number value stored in array argB column 2
product = valA * valB; //Calculate product value
printf("The product of the Arguments is %.2f\n", product); //Prints product value to as a float to 2 decimal places
return 0; //End of main function
}  