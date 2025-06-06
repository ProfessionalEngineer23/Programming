#include <stdio.h> //Include standard I/O library

int price(int a, int b, int c, int d,  int e) //Function called price which takes in parameters a,b,c,d,e
{
  return ((a + b + c + d + e)/5); //The function will return the average of a,b,c,d,e
}
int main() //Main function
{
int add = price(10, 20, 30, 40, 50); //Integer 'add' is the resultant of function price with arguments  
  
  for(int i=1;i<5;i++) //For loop to print 5 hyphens(-) down
  { 
    for(int j=1;j<5;j++) //Nested for loop to print 5 hyphens(-) to the right
    {
        printf("-----\t"); //Print the hyphens vertical hyphen
    }
    printf("-----\n"); //Print the horizontal hyphens
  }

  printf("Average price is: %d\n", add); //Print the average price of the argument in function price
  return 0; //End of main function
}
