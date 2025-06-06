//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
using namespace std;

double ctok(double c) // Converts Celsius to Kelvin
{
double k = c + 273.15; //K is an int, so there is no point in 273.15 as it is a float/double
return k;//Does not specify what int to return and no ';' also k is now declared as a double 
}
int main()
{
cout << "Please enter a Celsius Degree value\nWhich will be converted into Kelvin";
double c = 0; //Makes this depend on the cin function to be next in order for the program to work correctly
cin >> c; //d was not declared, replaced now by c.

double k = ctok( c ); //k is used in the function ctok and was declared as an int
//The function ctok expets a double but gets character "c".
cout << k << endl; //Not Cout but cout. Functions are caps sensitive!
return 0;
//no return 0 in main loop
}