//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <cmath>
using namespace std;

void quad(double a, double b, double c)
{
double term = ((b*b)+(-4*a*c));
if (term < 0){cout << "Error the discriminant is less than 0"; }
else{
double x1 = (-(b)+(sqrt(term)))/(2*a);
double x2 = (-(b)-(sqrt(term)))/(2*a);
cout << "\nThe ((b*b)+(-4*a*c)) value is: " << term << "\nThe first solution is: " << x1 << "\nThe second solution is: " << x2;}
}

int main()
{
double a, b, c;
cout << "\nPlease enter values for 'a' , 'b' , 'c': ";
cin >> a >> b >> c;
quad(a,b,c);
return 0;
}