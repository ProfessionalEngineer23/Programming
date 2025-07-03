//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
using namespace std;

class Bad_celius {}; //Special class for exception.
double ctok(double c) // Ctok is a function that converts Celsius to Kelvin
{
if( c <= -273.15 ){throw Bad_celius();} //If Celsius value is <= -273.15, then a Bad_celsius exception is thrown.
double k = c + 273.15; //K was an int, so there was no point in 273.15 as it is a float/double. Now k is a double.
return k;//Does not specify what int to return and no ';' also k is now declared as a double 
}
int main()
{
cout << "Please enter a Degree Celsius value\nThis value will be converted into Kelvin:"; //Tells user what the program does.
double c = 0; //Makes this depend on the cin function to be next in order for the program to work correctly
cin >> c; //d was not declared, replaced now by c.

try 
{
//k replaced by answer on next line
int answer = ctok( c ); 
//k was already used in the function ctok and was declared as an int. Reusing it can make debugging confusing.
//The function ctok expets a double but gets character "c".
cout << c << " degrees Celsius is " << answer << " in Kelvin\n"; //Not Cout but cout. Functions are caps sensitive!
}
catch(Bad_celius){cerr << "\n<<The lowest Kelvin temperature is 0 Kelvin or -273.15 degrees Celsius or -460 degrees Fahrenheit!\nAbsolute zero Kelvin means that there is no motion and no heat!\nThis is theoretically not possible!>>";}

return 0;
//no return 0 in main loop
}