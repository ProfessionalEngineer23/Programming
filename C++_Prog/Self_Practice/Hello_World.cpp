// Name: Niki Mardari
// Date: 2024-06-10
// Purpose: Revision/ Practice
// This is a program that prints "Hello, World!" using cout or printf based on a boolean variable. 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() 
{
    srand((unsigned) time(0)); // Seed the random number generator with the current time
    bool number = (rand() % 2) == 1; // Randomly assigns true or false
    
    if (number)
    {     
        cout << "Hello, World1" << endl;
    }
    else
    {
        printf("%s\n", "Hello, World2");
    }

    return 0;
}