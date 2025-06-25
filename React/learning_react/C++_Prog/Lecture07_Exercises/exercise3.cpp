#include <iostream>

using namespace std; 

class Person {       // The class
private:             // Access specifier
string name, country; 
int age;

public:
// Setter function to set the radius
void setName(string n) 
{
name = n;
}
void setCountry(string c) 
{
country = c;
}  
void setAge(int a) 
{
if (a >= 0)  // No negative age values
age = a;
else cout << "Invalid age value!\n";
}  
// Getter function to get the length and width
string getName() { return name; }
string getCountry() { return country; }
int getAge() { return age; }
};
 
int main() {
Person myObj;  // Create an object of Circle

string inputName, inputCountry;
int inputAge;
  
cout << "Please enter your name, age and country: ";
cin >> inputName; //Have to input name into a string in the main function
myObj.setName(inputName); //Set name from string inputName in main function
cin >> inputAge; //Have to input age into an int in the main function
myObj.setAge(inputAge); //Set age from an int inputAge in main function
cin >> inputCountry; //Have to input country into string in the main function
myObj.setCountry(inputCountry); //Set country from a string inputCountry in main function
  
// Print attribute values
cout << endl 
<< "Name = " << myObj.getName() << endl 
<< "Age = " << myObj.getAge() << endl
<< "Country = " << myObj.getCountry() << endl;
return 0;
}

  /*==Sources==
  https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c - # define M_PI  
  https://www.w3schools.com/cpp/cpp_classes.asp - Classes
  */