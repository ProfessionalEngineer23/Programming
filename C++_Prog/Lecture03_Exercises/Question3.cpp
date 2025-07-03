//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//Function to find smallest, largest, sum, difference, ratio in Quotient form (a/b)
void manipulations(int val1, int val2, float ratio)
{cout<<"\nThe highest is: " << max(val1,val2) << "\nThe lowest is: " << min(val1,val2)
<< "\nThe sum is: " << val1+val2 
<< "\nThe difference is: " << abs(val1-val2) 
<< "\nThe product is: " << val1*val2
<< "\nThe ratio is: " << ratio;}

int main()
{
int val1 ,val2;
cout << "Please enter values for Val1 and Val2:\n\nVal1: ";
cin >> val1;
cout << "Val2: ";
cin >> val2; 
if (val1 == 0 && val2 == 0){cout<<"Both are the same!\nSum: 0\nDifference: 0\nProduct: 0\nRatio: NULL ";}
else if (val1==val2){cout<<"Both are the same!"<<"\nThe sum is: " << val1+val2 
<< "\nThe difference is: " << abs(val1-val2)
<< "\nThe product is: " << val1*val2
<< "\nThe ratio is: 1:1";}
else{
float ratio = (val1*1.0/val2); //Need a way to convert to float! Solution: simple multiplication or division
manipulations(val1, val2, ratio);
}
return 0;
}
/*==Sources:==
https://www.geeksforgeeks.org/stdmin-in-cpp/ - Helped me learn about the min(a,b) function in C++
https://www.geeksforgeeks.org/stdmax-in-cpp/?ref=ml_lbp - Helped me learn about the max(a,b) function in C++
*/