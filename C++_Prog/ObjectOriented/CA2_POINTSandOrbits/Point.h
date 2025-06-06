#ifndef Point_h
#define Point_h

#include <iostream>
#include <cmath>
using namespace std;

namespace geom 
{
    //Point class that has doubles x,y for coordinates.
    class Point 
    {
    private:
        double x, y;

    public:
        // Constructor functions for Points
        Point() : x(0), y(0) {}  // Origin point member
        Point(double x, double y) : x(x), y(y) {} // Constructor for first point member
        Point(const Point &p) : x(p.x), y(p.y) {} // Constructor for second point member. Copies x and y from first point 
        
        // The ':' passes an initializer list x(p.x) initializes x with the x value from p (First point)
        /*Could use:
        Point(const Point &p) 
        {x = p.x; y = p.y;}
        //instead, however it is less efficient because, 
        x and y are initialized and then assigned, 
        which invloves more steps. Used when class members are not const type
        */

        // Getters for x and y of first point
        double getX() const {return x;}
        double getY() const {return y;}

        // angle function - Calculates the angle between the point and the x-axis 
        double angle() const 
        {
        return atan2(y, x); //Atan2 - Inverse tan, trigonometry, returns angle in radians
        }

        //radius function - calculates the distance drom origin to a point
        double radius() const 
        {
        return hypot(x, y); //hypot - gets the distance of the hypotenuse of a right angled triangle wiht points: origin and first point 
        //Pythagoras Theorem c = sqrt((x*x)+(y*y))
        }

        // distance function - calculates the distance from fisrt point to second point
        double distance(const Point p2) const 
        {
        return hypot(x - p2.x, y - p2.y);
        //Distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        }

        // translate function - Moves the x and y values by input x and y amounts
        void translate(double dx, double dy) 
        {
        x += dx; //Adds dx to x value and assigns the result to double x
        y += dy; //Adds dy to a value and assigns the result to double y
        }

        // rotateOrigin function - Rotates a point counterclockwise around the origin by theta degrees(variable for an angle in radians) 
        void rotateOrigin(double theta) 
        {
        double newX1 = x * cos(theta) - y * sin(theta);
        double newY1 = x * sin(theta) + y * cos(theta);
        x = newX1;
        y = newY1;
        }

        // rotatePoint2 function - Rotates a point around tempPoint. Similar to rotateOrigin but instead of 0 we add the tempPoint (Point of rotation)
        void rotatePoint2(const Point& tempPoint, double theta) 
        {
        double newX2 = tempPoint.x + (x - tempPoint.x) * cos(theta) - (y - tempPoint.y) * sin(theta);
        double newY2 = tempPoint.y + (x - tempPoint.x) * sin(theta) + (y - tempPoint.y) * cos(theta);
        x = newX2;
        y = newY2;
        }
        //operator function - Overloads the stream insertion (<<) operator for outputing point values
        friend ostream& operator<<(ostream& os, const Point& p) 
        //Non member Friend functions allow access to private members from other classes
        //os is the reference to an ostream object, made os like cout
        //The second parameter is 'p' , an object of class Point, referenced to avoid unnecessary copying  
        //Returns a reference of ostream which allows chaining of output operators and output multiple objects
        {
        os << "("<< p.x <<", "<< p.y <<")";
        return os;
        }
        /*Could use:
        ostream& operator<<(ostream& os, const Point& p) {
        os <<"("<< p.getX() <<", "<< p.getY() <<")"; // Using getter functions
        return os;
        }
        //Instead
        */

         // testing_functions() - Function to output and test the values of all the functions in this library
         static void testing_functions() //Static so that 
         {
            cout << "\n==TESTS==\n";

            // Sample first point
            Point p1(3.0, 5.0);
            cout << "\np1: " << p1; // Should be 3,5

            // Testing translate function
            p1.translate(-1.0, 1.0);
            cout << "\np1 after translation: " << p1;  // Should be 2,6

            // Testing copy constructor
            Point p2(p1);
            cout << "\np2 (copy of p1): " << p2; // Should be 2,6

            // Testing rotateOrigin function
            p1.rotateOrigin(90 * M_PI / 180);
            cout << "\np1 after rotating 90 degrees: " << p1; // Should be -6,2

            // Testing rotation around another point
            p2.rotatePoint2(Point(1,1), 90 * M_PI / 180);
            cout << "\np2 after rotating 90 degrees around (1,1): " << p2; // Should be -4,2

            // Testing distance function
            double dist = p1.distance(p2);
            cout << "\nDistance between p1 and p2: " << dist; // (Expected: 7.2111)

            // Testing angle function
            cout << "\nAngle of p1 (degrees): " << (p1.angle() * 180 / M_PI); // Should be 161.565 degrees
            cout << "\nAngle of p1 (radians): " << (p1.angle()); // Should be 2.81984 radians

            // Testing radius function
            cout << "\nRadius of p1: " << p1.radius();

            // Extreme values test
            Point extremePoint(1e6, -1e6);
            cout << "\nExtreme Point: " << extremePoint;

            Point negativePoint(-64, -1024);
            cout << "\nNegative Point: " << negativePoint;

            cout << "\nTesting Complete successfully!\n";
        }
    };
}

#endif

/*==Sources==
https://www.w3schools.com/cpp/ref_math_hypot.asp - Helped me learn how to use the hypot function. In <cmath> header file
https://cplusplus.com/forum/beginner/79863/ - Helped me learn about a formula to rotate a point in a 2D space 
https://stackoverflow.com/questions/2259476/rotating-a-point-about-another-point-2d - Answer by gsamaras helped me learn how to rotate a point about another point
https://www.geeksforgeeks.org/friend-class-function-cpp/ - Helped me learn about friend class functions
https://www.geeksforgeeks.org/static-member-function-in-cpp/ - Helped me learn how to use static member functions.
*/