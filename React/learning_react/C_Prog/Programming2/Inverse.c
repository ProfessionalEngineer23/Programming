#include <stdio.h> //Include standard I/O library 

int main() { //Main function
    int array1[2][2] = {{5, 6}, {4, 5}}; // 2 by 2 Array 1 
    int array2[2][2] = {{6, 4}, {3, 3}}; // 2 by 2 Array 2 
    int array1Inverse[2][2] = {{5, -4}, {-6, 5}}; //Inverse of Array 1 
    int array2Inverse[2][2] = {{3,-4},{-3,6}}; //Inverse of Array 2
    int arrayResultant[2][2]; //Float value to store results for Array 1
    int arrayResultant1[2][2]; //Float value to store rsults for Array 2
    int detA = (array1[0][0] * array1[1][1]) - (array1[0][1] * array1[1][0]); //Calculating detA, determinant of array1 
    int detB = (array2[0][0] * array2[1][1]) - (array2[0][1] * array2[1][0]); //Calculating detB, determinant of array2

    //Multiplying detA by each value in array1 inverse and storing in arrayResultant
    arrayResultant[0][0] = (detA * array1Inverse[0][0]); 
    arrayResultant[0][1] = (detA * array1Inverse[0][1]);
    arrayResultant[1][0] = (detA * array1Inverse[1][0]);
    arrayResultant[1][1] = (detA * array1Inverse[1][1]);

    //Multiplying detB by each value in array2 inverse and storing in arrayResultant1
    arrayResultant1[0][0] = (detB * array2Inverse[0][0]);
    arrayResultant1[0][1] = (detB * array2Inverse[0][1]);
    arrayResultant1[1][0] = (detB * array2Inverse[1][0]);
    arrayResultant1[1][1] = (detB * array2Inverse[1][1]);

    for (int i = 0; i < 2; i++) { //For loop to cycle through each row of arrayResultant
        for (int j = 0; j < 2; j++) { //For loop to cycle through each column of arrayResultant 
            printf("%d", arrayResultant[i][j]); //Print value of arrayResultant at that current location
        }
        printf("\n"); //Print a new line
    }

    for (int x = 0; x < 2; x++) { //For loop to cycle through each row of arrayResultant1
        for (int y = 0; y < 2; y++) { //For loop to cycle through each column of arrayResultant1
            printf("%d", arrayResultant1[x][y]); //Print value of arrayResultant1 at that current location
        }
        printf("\n"); //Print a new line
    }

    return 0; //End of main function
}
