//Name: Niki Mardari
//Student ID: B00159642
// Exception demo

#include <iostream>
using namespace std;

class Bad_area { }; // a class is a user defined type
// Bad_area is a type to be used as an exception
int area(int length, int width)
{
if (length<=0 || width<=0) throw Bad_area(); // note the ()
return length*width;
}

int main() {
	int x = -4, y = 3 ;
try {
	int z = area(x,y); // if area() doesn�t throw an exception
} // make the assignment and proceed

catch(Bad_area) { // if area() throws Bad_area(), respond
	cerr << "oops! Bad area calculation � fix program\n";
}
	return 0 ;
}