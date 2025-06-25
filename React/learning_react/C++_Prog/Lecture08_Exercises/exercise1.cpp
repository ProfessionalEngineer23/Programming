//Name: Niki Mardari
//ID: B00159642

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MyClass 
{
public:
    int saveToFile() {
        try {
            string name;
            cout << "Enter file name: ";
            cin >> name;

            ofstream ost(name);  // Output file stream to write to the file directly 
            if (!ost) throw string("Cannot open file."); //If file was not opened then a message "Cannot open file." is thrown.

            int hour = 21;
            double temperature = 32.5;

            //OST is the stream to output to a file
            ost << "Hour: " << hour << "\n"; 
            ost << "Temperature: " << temperature << "\n";

            cout << "Data written to " << name << " successfully.\n";
        } 
        //Catching reference to a message string (directly edits it)
        catch (const string& message) { 
        cerr << "Error: " << message << "\n";
        return -1;
        }

        return 0;
    }
};

int main() {
    MyClass obj; //Making an obj of class MyClass
    return obj.saveToFile(); //Returning called public function that writes to a file that is an object of a class MyClass 
}
