#include <stdio.h>                          //Standard I/O library 
#include <math.h>                           //Math library for sqrt function

int main()                                  //Main function
{
int x, y, z=10;                             //Defines x,y,z as integers
float origin;                               //Defines origin as float
{
for (x=0; x<=z*2; x++)                      //For loop to increase the distance from the left as x gets bigger
{
for (y=0; y<=z*2; y++)                      //For loop to increase the disance from the top as y gets bigger
{
origin=sqrt((x-z)*(x-z)+(y-z)*(y-z));       //origin as Distance from the centre using formula
printf(" ");                                //Print a space 
if (origin==z)                              //If the origin is the same as the vertical distance then a star prints out 
{printf("*");}                              //Prints star
else                                        //If the origin does not equal to the vertical distance then a space is printed 
{printf(" ");}                              //Prints space
}
printf("\n");                               //Prints a new line
}
}
return 0;                                   //End of program
}
                                            //Must use -lm at the end of gcc line so that gcc can link the math library 