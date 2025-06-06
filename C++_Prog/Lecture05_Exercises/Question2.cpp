//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
using namespace std;

class Bad_area { };
int area(int length, int width)
{
if (length<=0 || width<=0)
{
throw Bad_area();
}
return length*width;
}
int main()
{
try 
{
cout << area(10, 3) << '\n' ; // 30
cout << area(5, -7) << '\n' ; // The pre-condition is triggered because -3 is a negative int
cout << area(10, 3) << '\n' ; // never gets to here
}

catch(Bad_area)
{cerr << "oops! Bad area calculation\n";}

cout << "Continuing with the rest of the program\n";
return 0;
}