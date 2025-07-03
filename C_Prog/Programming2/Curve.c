#include <stdio.h>                  //Standard I/O library 

int main()                          //Main function
{
int x, y, z;                        //Defines x,y,z as integers
for (z = 26; z>0; z--) {            //For loop to cycle through possible y values
for (x = -10; x <= 10; x++)         //For loop to cycle through possible x values
{
if ((x*x) == z) {                   //If x*x is equal to z(The possible y value) then a star is printed
printf("*");}                       //Prints star
else {                              //If x*x does not equal to a possible y value then a spaces are printed 
printf("\t\t");}                    //Prints two tab spaces
}
printf("\n");                       //Brings carriage to a new line
}
return 0;                           //End of program
}