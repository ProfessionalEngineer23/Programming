//Name: Niki Mardari
//Student ID: B00159642
/*
The program takes a character for the operation, takes three user input values. 
Then it asks if the values are correct? If not the user inputs the numbers again.
The calculation is performed that was selected. Then the user is asked if they want to perform another calculation.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
double number1, number2, result;
char operation, correct; 
//Correct is a caharacter variable for determining if the numbers are correct and if the user wants to try again?
//Do while loop to ask for inputs while the user still wants to execute the program.
do{ 
cout << "Select operation (+, -, *, /): ";
cin >> operation;
cout << "Enter first number: ";
cin >> number1;
cout << "Enter second number: ";
cin >> number2;
cout << "The numbers entered are: " << "\nNumber1 = " << number1 << "\nNumber2 = " << number2 << "\nAre these correct? (y/n):\n";
cin >> correct;

//If user gets a value wrong and they admit it, the program lets them re-enter the values.
if (correct != 'y' && correct != 'Y')
{
cout << "Enter first number: ";
cin >> number1;
cout << "Enter second number: ";
cin >> number2;
}

switch(operation)
{
    case '+':
    result = number1 + number2;
    cout << number1 << " + " << number2 << " = " << result;
    break;

    case '-':
    result = number1 - number2;
    cout << number1 << " - " << number2 << " = " << result;
    break;

    case '*':
    result = number1 * number2;
    cout << number1 << " * " << number2 << " = " << result;
    break;

    case '/':
    if (number2!=0){
    result = number1 / number2;
    cout << number1 << " / " << number2 << " = " << result;}
    else {cout << "<\nError dividing by zero!\n";} 
    break;
//By default if none of the other operations were selected the operation is then invalid.
    default: 
    cout << "Invalid operation selected!\n";
    break;   
}

cout << "\nDo you want to perform another calculation? (y/n): ";
cin >> correct; 
}
while (correct == 'y' || correct == 'Y');
return 0;
}
/*==Sources== 
Programming1 Lecture 10
*/