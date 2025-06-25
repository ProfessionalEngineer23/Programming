//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//Function to find smallest, largest, sum, difference, ratio
void manipulations(double val1, double val2)
{cout<<"\nThe highest is: " << max(val1,val2) << "\nThe lowest is: " << min(val1,val2)
<< "\nThe sum is: " << val1+val2 
<< "\nThe difference is: " << abs(val1-val2) 
<< "\nThe product is: " << val1*val2
<< "\nThe ratio is: " << val1/val2;}

int main()
{
double val1 ,val2;
cout << "\nPlease enter values for Val1 and Val2:\n\nVal1: ";
cin >> val1;
cout << "Val2: ";
cin >> val2; 

if (val1 == 0 && val2 == 0){cout<<"Both are the same!\nSum: 0\nDifference: 0\nProduct: 0\nRatio: NULL ";}

else if (val1==val2){cout<<"Both are the same!"<<"\nThe sum is: " << val1+val2 
<< "\nThe difference is: " << abs(val1-val2)
<< "\nThe product is: " << val1*val2
<< "\nThe ratio is: 1:1";}

else{

manipulations(val1, val2);
}
return 0;
}
//Compare results to Question 4
//We got double value outputs