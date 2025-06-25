//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
string a, b, c;
cout<<"Please enter three strings to be ordered.\nEnter the three strings:";
cin >> a >> b >> c; 
cout << c << " " << b << " " << a << endl;
//cout << min(a, min(b,c)) <<", "<< (a+b+c)-max(a, max(b,c))-min(a, min(b,c)) <<", "<< max(a, max(b,c));
return 0;
}

//Store the strings in a vector and store them in a vector.
//Create a sort function to swap the locations of the strings.
/*==Sources== 
https://www.geeksforgeeks.org/stdmin-in-cpp/ - Helped me learn that multiple values in an initializer list.
*/