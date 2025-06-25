#include <stdio.h>                              //Include Standard I/O library

int main()                                      //Main Function
{
int m=4, x=10, y, z, rows=21;                   //Defines Variables
for(rows; rows>0; rows--)                       //First for loop to create 20 rows
{
y=m*x;                                          //Equation for y values
printf("%d\t\n\n", y);                          //Print Y axis
for(z=1; z<=rows; z++)                          //For loop to increase amount of spaces
{printf("\t\t");}                               //Print a space
printf("*(%d,%d)\n\n\n",x,y); 
x--;                                            //Decrement value of x
} 
for(int j=-10; j<=10; j++)                      //For loop for counting up for values of x
{
printf("\t\t%d,",j);                            //Print y axis value
}
return 0;                                       //End of main function
}