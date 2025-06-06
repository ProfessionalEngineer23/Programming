#include <iostream>
using namespace std;

class Bad_area { };
int area(int length, int width)
{
if (length<=0 || length==NULL || width <= 0 || width==NULL)
{
throw Bad_area();
}
return length*width;
}

int main(){
try{
int x1 = area(7);
int x2 = area("seven", 2);
int x3 = area(7, 10);
int x5 = area(7.5, 10);
int x = area(10, -7);
}
catch(Bad_area)
{cerr << "Oopsy! Bad area calculation\n";}
return 0;
}

//Work on implementing error checks for this code 
