#include <iostream>
#include <cmath>
using namespace std; 

class Rectangle {       // The class
private:             // Access specifier
double length, width;        // Attribute (double variable)

public:
// Setter function to set the radius
void setLength(double l) 
{
if (l >= 0)  // No negative length and width values
length = l;
else cout << "Invalid length value!\n";
}
void setWidth(double w) 
{
if (w >= 0)  // No negative length and width values
width = w;
else cout << "Invalid width value!\n";
}  
// Getter function to get the length and width
double getLength() const { return length; }
double getWidth() const { return width; }

};

double Area(double length, double width)
{ return length*width; }

double Perimeter(double length, double width)
{ return (2*length)+(2*width);}
  
int main() {
Rectangle myObj;  // Create an object of Circle

double inputLength, inputWidth;
  
cout << "Please enter the length and width of the rectangle in Units of choice: ";
cin >> inputLength; //Have to input length into a double in the main function
myObj.setLength(inputLength); //Set length from double inputLength in main function
cin >> inputWidth; //Have to input width into a double in the main function
myObj.setWidth(inputWidth); //Set width from double inputWidth in main function
  
// Print attribute values
cout << endl 
<< "length = " << myObj.getLength() << endl 
<< "width = " << myObj.getWidth() << endl
<< "\nArea = " << Area(myObj.getLength(),myObj.getWidth()) 
<< "\nPerimeter = " << Perimeter(myObj.getLength(),myObj.getWidth());
return 0;
}

  /*==Sources==
  https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c - # define M_PI  
  https://www.w3schools.com/cpp/cpp_classes.asp - Classes
  */