#include <stdio.h> //Preprocessor directive to include standard input-output header file
#include <time.h>  //Preprocessor directive to include time header file

// Simple printing program in C
/*
Do your homework!
*/

int main(void) //Main function - execution starts here
{
    time_t currentTime; //Variable to store current time
    time(&currentTime); //Get current time
    const char *array[] = {"Hello World!", "Hello Mom!", "Hello Dad!", "Hello Bro!", "Hello Sis!"}; //Array of strings to be printed
    
    for(int i = 0; i<5; i++)
    {
        printf("%s\n It is %s\n", array[i], ctime(&currentTime)); //Prints "Hello, World!" to the console
    }
    
    return 0; //Returns 0 to indicate successful execution
}