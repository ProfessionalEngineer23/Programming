#include<stdio.h> //Include standard I/O library

int main() //Main function
{
    int arrayC[2][3]={{1,2,3},{2,3,4}}; //2 by 3 array called arrayC
    int arrayD[3][2]={{4,4},{2,2},{2,2}}; //3 by 2 array called arrayD
    int arrayE[2][2]={{14,14},{22,22}}; //2 by 2 array called arrayE
    int i, j, answer2; //Integers i,j for cycling through arrays and answer2 for result value

    for(i=0;i<2;i++) //For loop to cycle through rows of arrayE
    {
        for(j=0;j<2;j++){ //For loop to cycle through columns of arrayE
    printf("%d ",arrayE[i][j]); //Print current cycle value in arrayE
    }
    printf("\n"); //Print a new line
    }

answer2 = (arrayC[0][0]*arrayD[0][0])+(arrayC[0][1]*arrayD[1][0])+(arrayC[0][2]*arrayD[2][0]); //Multiplying first row of arrayC by first column of arrayD and summing each term
printf("%d\t",answer2); //Print result of first resultant array value
answer2 = (arrayC[1][0]*arrayD[0][0])+(arrayC[1][1]*arrayD[1][0])+(arrayC[1][2]*arrayD[2][0]); //Multiplying first row of arrayC by second column of arrayD and summing each term
printf("%d\t",answer2); //Print result of second resultant array value
answer2 = (arrayC[1][0]*arrayD[0][0])+(arrayC[1][1]*arrayD[1][0])+(arrayC[1][2]*arrayD[2][0]); //Multiplying second row of arrayC by first column of arrayD and summing each term
printf("%d\t",answer2); //Print result of third resultant array value
answer2 = (arrayC[1][0]*arrayD[0][1])+(arrayC[1][1]*arrayD[1][1])+(arrayC[1][2]*arrayD[2][1]); //Multiplying second row of arrayC by second column of arrayD and summing each term
printf("%d\t",answer2); //Print result of fourth resultant array value

return 0; //End of main function
}