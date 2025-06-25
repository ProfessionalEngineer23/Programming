#include <iostream>
#include <fstream>
#include <cmath>
#include "Point.h"

using namespace std;
using namespace geom;

// Initializing and defining constant values so that they are not changed accidentally further in the code.
const double EARTH_ORBIT_RADIUS = 193000000; // Earth's Distance from origin
const double MOON_ORBIT_RADIUS = 384000; // Moon's distance from origin
const int DAYS_IN_YEAR = 365;
const int MOON_CYCLE_DAYS = 27; // Days it takes for Moon to fully rotate around Earth. It is needed in order to calculate the change in the Moon's angle each day.

int main() {
    ofstream myFile("test.csv");

    if (!myFile) // If myFile output file stream does not open file test.csv, then print an error message
    {
        cerr << "Error: Unable to open test.csv\n";
        return -1; // Return code -1
    }

    myFile << "Day,Earth_X,Earth_Y,Moon_X,Moon_Y\n"; // Write Earth and Moon X,Y coordinates labels into test.csv

    // Point class object for Sun's position (Origin)
    Point sun(0, 0);

    //For loop to cycle through 365 days and calcultate the Earth's X,Y coordinates and Moon's X,Y coordinates relative to the Earth
    for (int day = 0; day <= DAYS_IN_YEAR; day++) 
    {
        // Calculating Earth's position
        double earth_angle = (360.0 / DAYS_IN_YEAR) * day;  // Calculating Earth's angle in degrees, assuming it changes in equal intervals each day.
        double earth_angle_rad = earth_angle * (M_PI / 180.0); // Converting Earth angle to radians

        // Point class object for Earth, calculates X and Y using Earth's orbital radius and angle
        Point earth(
            EARTH_ORBIT_RADIUS * cos(earth_angle_rad), //Use cos to calculate X value because it's a circular motion. 
            EARTH_ORBIT_RADIUS * sin(earth_angle_rad)); ////Use sin to calculate Y value because it's a circular motion. 

        // Calculating Moon's position
        double moon_angle = (360.0 / MOON_CYCLE_DAYS) * day;  // Moon's angle in degrees
        double moon_angle_rad = moon_angle * (M_PI / 180.0) //Converting to Moon angle to radians
        
        // Point class object for Moon, calculates X and Y relative to Earth's position
        Point moon(
            earth.getX() + MOON_ORBIT_RADIUS * cos(moon_angle_rad),
            earth.getY() + MOON_ORBIT_RADIUS * sin(moon_angle_rad)
        );
        // Writing to test.csv using myFile OSTREAM
        myFile << day << "," << earth.getX() << "," << earth.getY() << "," 
               << moon.getX() << "," << moon.getY() << "\n";
    }

    myFile.close(); // Close file using OFSTREAM, usually it does this automatically without this line of code. Good Practice.
    cout << "\nWriting Successful!\n";

    return 0;
}

/*==Sources==
https://www.youtube.com/watch?v=x2niMA5tzGo - Helped me learn how to output from C++ code into an Excel file.   
https://www.geeksforgeeks.org/program-convert-radian-degree/ - Helped me learn how to convering Degrees to Radians, and lectures too.
https://courses.lumenlearning.com/precalculus/chapter/unit-circle-sine-and-cosine-functions/ - Helped me understand and learn how to calculate Earth's X,Y coordinates.
https://stackoverflow.com/questions/16594194/moon-orbit-in-relation-to-sun - Answer by Eser Aygün helped me figure out how the Moon coordinates change.
*/
