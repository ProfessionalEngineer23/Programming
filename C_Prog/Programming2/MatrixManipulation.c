#include <stdio.h> //Standard I/O library
int array1[3][2]={{1,2},{3,4},{5,6}}; //Array1 3 by 2 
int array2[2][3]={{7,8,9},{10,11,12}}; //Array2 2 by 3
int answer1; //Integer for reuslt from adding matrices
int answer2; //Integer for result from multipling matrices
int main() //Main function
{
    for(int i=0;i<3;i++) //For loop to go up in row values
    {
    for(int j=0;j<6 ;j++) //For loop to go up in column values
    {
    printf("%d  +  ",array1[i][j]); //Print a '+' sign
    answer1 = array1[i][j]+array2[i][j]; //Set output answer as the sum of the first values of array1 and 2 added together
    printf("%d = %d\n",array2[i][j],answer1); //Print value of array1 and answer1
    }

//Multiplication of the two arrays
answer2 = (array1[0][0]*array2[0][0])+(array1[0][1]*array2[1][0]);
printf("%d\t",answer2);
answer2 = (array1[0][0]*array2[0][1])+(array1[0][1]*array2[1][1]);
printf("%d\t",answer2);
answer2 = (array1[0][0]*array2[0][2])+(array1[0 ][1]*array2[1][2]);
printf("%d\n",answer2);

answer2 = (array1[1][0]*array2[0][0])+(array1[1][1]*array2[1][0]);
printf("%d\t",answer2);
answer2 = (array1[1][0]*array2[0][1])+(array1[1][1]*array2[1][1]);
printf("%d\t",answer2);
answer2 = (array1[1][0]*array2[0][2])+(array1[1][1]*array2[1][2]);
printf("%d\n",answer2);

answer2 = (array1[2][0]*array2[0][0])+(array1[2][1]*array2[1][0]);
printf("%d\t",answer2);
answer2 = (array1[2][0]*array2[0][1])+(array1[2][1]*array2[1][1]);
printf("%d\t",answer2);
answer2 = (array1[2][0]*array2[0][2])+(array1[2][1]*array2[1][2]);
printf("%d \n",answer2);
/*
00*00+01*10 
00*01+01*11 +1
00*02+01*12 +1

+10  +10

10*00+11*10
10*01+11*11 +1
10*02+11*12 +1

+10  +10

20*00+21*10
20*01+21*11 +1
20*02+21*12 +1

Only 3 numbers change; the first one and the third one aka the array 1 row values 
*/
//}

    return 0; //End of program
}
}