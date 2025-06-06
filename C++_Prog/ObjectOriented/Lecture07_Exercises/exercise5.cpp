#include <iostream>
#include <cmath>
using namespace std;

class Triangle { // The class
private:         // Access specifier
    int side1, side2, side3;

public:
    // Setter functions to set the sides
    void setSide1(int A) { side1 = A; }
    void setSide2(int B) { side2 = B; }
    void setSide3(int C) { side3 = C; }

    // Function to check triangle inequality
    void checker() {
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            cerr << "Doesn't obey the triangle inequality\n";
            exit(1); // Exit if the triangle inequality is not satisfied
        } else {
            cout << "Continue, all good!\n";
        }
    }

    // Function to determine the type of triangle
    void triangleType() {
        if (side1 == side2 && side2 == side3)
            cout << "Equilateral triangle\n";
        else if (side1 == side2 || side1 == side3 || side2 == side3)
            cout << "Isosceles triangle\n";
        else
            cout << "Scalene triangle\n";
    }

    // Getter functions to get the sides
    int getSide1() { return side1; }
    int getSide2() { return side2; }
    int getSide3() { return side3; }
};

int main() {
    Triangle myObj; // Create an object of Triangle

    int inputSide1, inputSide2, inputSide3;

    cout << "Please enter sides a, b, c in units of choice: ";
    cin >> inputSide1 >> inputSide2 >> inputSide3; // Input all sides

    myObj.setSide1(inputSide1);
    myObj.setSide2(inputSide2);
    myObj.setSide3(inputSide3);

    myObj.checker();          // Call checker function
    myObj.triangleType();     // Call triangleType function

    // Print attribute values
    cout << "Side 1 = " << myObj.getSide1() << endl
         << "Side 2 = " << myObj.getSide2() << endl
         << "Side 3 = " << myObj.getSide3() << endl;

    return 0;
}

/*==Sources==
https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c - # define M_PI  
https://www.w3schools.com/cpp/cpp_classes.asp - Classes
https://stackoverflow.com/questions/6486888/c-program-on-determining-triangle - Triangle
*/
