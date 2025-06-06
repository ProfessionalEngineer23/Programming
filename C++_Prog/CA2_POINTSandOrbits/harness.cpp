#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;
using namespace geom; // Ensure we use the geom namespace

int main() 
{
    Point p1(3.0,5.0);  // Now Point is recognized
    p1.translate(-1.0, 1.0);
    cout << p1 << "\n"; // should print (2,6)

    Point p2(p1);  // Copy constructor
    cout << p2 << "\n"; // should print (2,6)

    p2.rotatePoint2(Point(1,1), 90*M_PI/180);
    cout << p2 << "\n"; // should print (-4,2)

    cout << p1.distance(p2) << "\n"; // should print 7.2111

    Point::testing_functions(); //Passing test function from the Point class.

    return 0;
}