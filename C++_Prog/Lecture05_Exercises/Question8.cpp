//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <cmath>
using namespace std;

class Bad_number { }; //Special class to error handle 
void quad(double a, double b, double c) //quad is a function to perform a quadratic formula calculation
{
double term = ((b*b)+(-4*a*c));
if (term <= 0){throw Bad_number();}
double x1 = (-(b)+(sqrt(term)))/(2*a);
double x2 = (-(b)-(sqrt(term)))/(2*a);
cout << "\nThe ((b*b)+(-4*a*c)) value is: " << term << "\nThe first solution is: " << x1 << "\nThe second solution is: " << x2 << endl;
}

int main()
{
try
{
double a, b, c;
cout << "\nPlease enter values for 'a' , 'b' , 'c': ";
cin >> a >> b >> c;
if (a==0){cout << "\nError 'a' is 0. Can't divide by 0!";} //Error handling division b zero 
else{quad(a,b,c);} 
}

catch(Bad_number)
{cerr << "Error the discriminant is less than 0";}
return 0;
}

//Error Check if values are garbage