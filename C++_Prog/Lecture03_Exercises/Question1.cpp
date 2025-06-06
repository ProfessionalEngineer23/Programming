//Name: Niki Mardari
//Student ID: B00159642
/*
Variable a and b are declared as integer meaning it can have numbers from -2147483648 to 2147483647.
Variable b is declared as a character meaning it can store an 8 bit single character or more precisely an ASCII value which ranges from 0 to 127.
This code is an example of Implicit Narrowing. This occurs when a programmer tries to put a large value into a smaller variable.

In this code char c is equal to int a. Since char c is a character literal, it reads the value of variable a as an ASCII value. 
20,000 is a 16 bit number but a char can only store 8 bits. 20,000 --> (0b 01001110 00100000) so char only reads in 0010 0000 , 32 in decimal which is ASCII for a space.
Int b stores char c which turns out to be ASCII 32, therefore decimal 32 is stored in b and the output is 20,000 32 and a 'space'
*/

#include<iostream>
using namespace std;

int main(){
    
int a = 20000;
char c = a;
int b = c;
//Output values of a,b,c
cout << endl << a << endl <<b << endl << c << endl;
if (a != b){cout << "oops!: " << a << "!=" << b << "\n";} 
else {cout << "Wow! We have large characters\n";}
return 0;
}