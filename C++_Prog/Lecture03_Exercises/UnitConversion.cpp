// Converting Inches to Centimeters or Centimeters to Inches

#include <iostream>
using namespace std;

//Function to take in location of 
void conversion(double &cm_per_inch) //Reference location of cm_per_inch
{ 
double val;
char unit;
cout << "Please input a number value followed by 'i' for cm to inch conversion or 'c' for inch to cm conversion:\n";
while (cin >> val >> unit)  {  
if (unit == 'i' || unit == 'I') {cout << val << " in == " << val * cm_per_inch << " cm\n";} 
else if (unit == 'c' || unit == 'C') {cout << val << " cm == " << val / cm_per_inch << " in\n";} 
else {cout << "Invalid unit. Please use 'i' for inches or 'c' for centimeters.\n";}
                            }
}

int main() {
double cm_per_inch = 2.54;

conversion(cm_per_inch);

cm_per_inch *= 2.0; //Multiply cm_per_inch by 2.0 and store result in cm_per_inch

conversion(cm_per_inch); 
return 0;}
