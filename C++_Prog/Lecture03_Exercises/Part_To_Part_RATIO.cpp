//Name: Niki Mardari
//Student ID: B00159642
//GCD - Greatest Common Divisor

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//Function to find smallest, largest, sum, difference, part-to-part ratio (a:b)
void manipulations(int val1, int val2)
{cout<<"\nThe highest is: " << max(val1,val2) << "\nThe lowest is: " << min(val1,val2)
<< "\nThe sum is: " << val1+val2 
<< "\nThe difference is: " << abs(val1-val2) 
<< "\nThe product is: " << val1*val2
<< "\nThe ratio is: " << ((min(val1,val2))/(__gcd(val1,val2))) << ":" << ((max(val1,val2))/(__gcd(val1,val2)));}

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
manipulations(val1, val2);
}
return 0;
}

//Verify Safety of GCD

/*For double type variable ratios:

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//Function to find smallest, largest, sum, difference, Part-to-Part ratio (a:b)
void manipulations(double val1, double val2, int intGCD, int intval1, int intval2)
{cout<<"\nThe highest is: " << max(val1,val2) << "\nThe lowest is: " << min(val1,val2)
<< "\nThe sum is: " << val1+val2 
<< "\nThe difference is: " << abs(val1-val2) 
<< "\nThe product is: " << val1*val2
<< "\nThe ratio is: " << min(intval1,intval2)/(intGCD) << ":" << max(intval1,intval2)/(intGCD);}

int main()
{
int n, scale, intval1, intval2, intGCD;
double val1 ,val2;
cout <<"Please enter the highest number of decimal places in your numbers:\n";
cin >> n;
scale = pow(10,n);
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
intval1 = round(val1*scale);
intval2 = round(val2*scale);
intGCD = __gcd(abs(intval1),abs(intval2));

manipulations(val1, val2, intGCD, intval1, intval2);
}
return 0;
}
//Double values aren't accepted for GCD function!

/*==Sources:== 
https://stackoverflow.com/questions/38333489/c-calculating-the-ratio-of-2-numbers - Helped me learn about the __gcd function (greatest common divider)

https://youtu.be/4w9XnkOabUU?si=p_9dXeKjJU01BMhd - This video helped me figure out how to find the GCD of decimal numbers, hence I declared int scale 
and initialized it as 10^n, where n is the amount of decimal places defined by the user.
*/