#include<stdio.h> //Include standart I/O library 
#include<stdlib.h> //Include standart library

int main() //Start of main function
{
    int rows,columns; //Declare rows and columns as integers
    int matrix1[20][20]; //Define Matrix1
    int matrix2[20][20]; //Define Matrix2
    int matrix3[20][20]; //Define Matrix3

    FILE *fp = fopen("matrix1.txt","w"); //Create a file fp called matrix1 and open it  
    FILE *fp1 = fopen("matrix2.txt","w"); //Create a file fp1 called matrix2 and open it
    FILE *fp2 = fopen("matrix3.txt","w"); //Create a file fp2 called matrix3 and open it
    if (fp == NULL||fp1 == NULL||fp2 == NULL) //If statement to check if there is anything stored in the files
      { 
        printf("Could not open one of the files"); //If nothing is stored in either one of the files the program will end 
        return 0; //End program
      } 
    else { //Else statement to execute code if all files had something stored
    for(rows=0;rows<20;rows++) //For loop to cycle through rows of arrays
    {   
        for(columns=0;columns<20;columns++) //For loop to cycle through columns of arrays
           {   
            matrix1[rows][columns]=columns*21; //Sets values for each location of matrix1
            matrix2[rows][columns]=columns*22; //Sets values for each location of matrix2
            matrix3[rows][columns]=((columns*21)*(columns*22)); //Sets the value of each location in matrix 3 as the product of the current value of matrix1 and matrix2
                fprintf(fp,"%d\n",matrix1[rows][columns]);//Prints row, column values
                fprintf(fp1,"%d\n",matrix2[rows][columns]);//Prints row, column 
                fprintf(fp2,"%d\n",matrix3[rows][columns]);//Prints resultant matrix values
            }
    }
        }

  fclose(fp); //Close the first text file
  fclose(fp1); //Close the second text file
  fclose(fp2); //Close the third text file
    
    return 0; //End of program
}