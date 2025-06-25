#include <iostream>
#include <cmath>
using namespace std; 

class Circle {       // The class
private:             // Access specifier
double radius;        // Attribute (double variable)

public:
// Setter function to set the radius
void setRadius(double r) 
{
if (r >= 0)  // No negative radius values
radius = r;
else cout << "Invalid radius!" << endl;
}
  
// Getter function to get the radius
double getRadius() const { return radius; }

};

double Area(double radius)
{ return radius * radius * M_PI; }

double Circumference(double radius)
{ return 2 * M_PI * radius;}
  
int main() {
Circle myObj;  // Create an object of Circle

double inputRadius;
  
cout << "Please enter the radius: ";
cin >> inputRadius; //Have to input radius into a double in the main function
myObj.setRadius(inputRadius); //Set radius from double inputRadius in main function
  
// Print attribute values
cout << endl << myObj.getRadius() << "\nArea = " << Area(myObj.getRadius()) 
<< "\nCircumference = " << Circumference(myObj.getRadius());
return 0;
}

  /*==Sources==
  https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c - # define M_PI  
  https://www.w3schools.com/cpp/cpp_classes.asp - Classes
  */