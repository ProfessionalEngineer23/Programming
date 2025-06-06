//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int a,b,c;
cout<<"Please enter three integers to be ordered in ascending order.\nEnter three integers:";
cin >> a >> b >> c; 
cout << min({a,b,c}) <<", "<< (a+b+c)-max({a,b,c})-min({a,b,c}) <<", "<< max({a,b,c});
//cout << min(a, min(b,c)) <<", "<< (a+b+c)-max(a, max(b,c))-min(a, min(b,c)) <<", "<< max(a, max(b,c));
return 0;
}
/*==Sources== 
https://www.geeksforgeeks.org/stdmin-in-cpp/ - Helped me learn that multiple values in an initializer list.
*/