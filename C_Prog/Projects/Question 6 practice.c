/* Question 6
 Programme that accepts command line arguments and prints out the product
 */

 #include <stdio.h> //import the input output library
 #include <stdlib.h> //library for the atoi function

int main (int argA , char* argB[] ){        // Passing the main loop through the parameters
int numarg;                                             // Holds the number of arguments received
numarg = argA -1 ;                                 // subtract 1 because the the program name counts as a variable
if(numarg>2){                                    // check if the numbe rof arguments is less than 2
    printf("Only 2 numbers are allowed\n");  // print statement if condition is true
}                                                  // if condition is not met ecit function and execute next command.
else if(numarg<2){                                // check for the gigev condition
    printf("Less than 2 numbers were enered\n");   
}
else {
printf("The name of the programme is %s\n", argB[0]);
for (int i = 1; i<= numarg; i++){
   
    printf("(%d) %s \n", i, argB[i]);

}
 float product =0;
    int valA, valB ;
    valA = atoi(argB[1]);
    valB = atoi(argB[2]);
    product = valA * valB;
    printf("The product of the Arguments is %.2f\n", product);
}

return 0;
 }  