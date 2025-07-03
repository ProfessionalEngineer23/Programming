//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <cmath>
using namespace std;

class Bad_output {}; //Special class for exceptions.

double ctok(double c) // ctok is a function that converts Celsius to Kelvin
{
if( c <= -273.15 ){throw Bad_output();} //If Celsius value is <= -273.15, then a Bad_output exception is thrown.
double k = c + 273.15; 
return k;
}

double ktoc(double k) //ktoc is a function that converts Kelvin to Celsius 
{
if( k <= 0 ){throw Bad_output();}
return k - 273.15;
}

double convkc (double c, char unit)
{
    switch(tolower(unit))
    {
        case 'k': return ktoc(c);
        case 'c': return ctok(c);
        default: cerr << "Can't convert to this unit: " << unit << endl; 
        return NAN; //Returns Not A Number because other functions return the values we want
    }
}

int main(){
try{
double c;
char unit; 
cout << "Please enter a value and then it's unit. 'c' for degrees Celsius or 'k' for Kelvin\nIf 'c' is selected, the value is converted from degrees celsius into Kelvin\nIf 'k' is selected then the value is converted from Kelvin to degrees Celsius\nEnter value then unit:"; //Tells user what the program does.
cin >> c >> unit; 
cout << convkc(c,unit) << endl;
}
catch(Bad_output){cerr << "\n<<The lowest Kelvin temperature is 0 Kelvin or -273.15 degrees Celsius or -460 degrees Fahrenheit!\nAbsolute zero Kelvin means that there is no motion and no heat!\nThis is theoretically not possible!>>";}

return 0;}


/*
#include <iostream>
#include <cmath>
using namespace std;

// Convert celsius to fahrenheit
float c2k ( float c ) ;

// Convert fahrenheit to celsius
float k2c ( float f ) ;

// unit == 'c' ? convert K to C
// unit == 'k' ? convert C to K
float convkc ( float temperature, char unit ) ;

int main() {
char unit;
float t;
cin >> t >> unit ;
cout << convkc (t, unit) << "\n" ;
return 0;

}
float c2k ( float c ) {
float k = c + 273.0 ;
if (k<0.0)
cerr << "Warning - negative kelvins\n" ;
return k ;
}

float k2c ( float k ) {
if (k<0.0)
cerr << "Warning - negative kelvins\n" ;
return k - 273.0 ;
}

float convkc ( float t,char unit ) {
switch (tolower(unit)) {
case 'k': return c2k(t);
case 'c': return k2c(t);
default:
cerr << "Can't convert to " << unit << endl ;
}


return NAN;
}


*/