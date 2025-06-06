//Name: Niki Mardari
//Student ID: B00159642
// inch to cm and cm to inch conversion:
// keep reading as long as the user inputs an int and a char ok
// 'i' for inch
// 'c' for cm
// terminate on a “bad unit”, e.g. 'q'
//Introduced a bug on line 12 in Cout 'cm_per_inch *= 2.0;'
 
/*
The reason an error occurs is because cm_per_inch was declared as a constant double meaning that it can only be read and not modified
*/

#include <iostream>
using namespace std;
int main()
{
const double cm_per_inch = 2.54; 
cm_per_inch *= 2.0;
int val;
char unit;
while (cin >> val >> unit) {
if (unit == 'i') {cout << val << "in == " << val*cm_per_inch << "cm\n";}
else if (unit == 'c') {cout << val << "cm == "<<val/cm_per_inch<< "in\n";} 
else {return 0;}
}
return 0;
}
/*
UnitConversion.cpp: In function 'int main()':
UnitConversion.cpp:21:13: error: assignment of read-only variable 'cm_per_inch'
   12 | cm_per_inch *= 2.0;
      | ~~~~~~~~~~~~^~~~~~
*/