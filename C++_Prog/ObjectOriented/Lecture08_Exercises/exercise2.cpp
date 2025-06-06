#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// A temperature reading structure
struct Reading {
    int hour;
    double temperature;

    // Constructor with member initializer list
    Reading(int h = 0, double t = 0.0) : hour(h), temperature(t) { }
};

// Overloaded >> operator for Reading
// Allows reading (hour, temperature) pairs directly into a Reading object
istream& operator>>(istream& is, Reading& r) {
    is >> r.hour >> r.temperature;
    return is;
}

// Function to read data from a file
// Opens the file, reads (hour, temperature) pairs, validates them, and stores them in a vector
int readFromFile() {
    string name;
    cout << "Enter file name: ";  // Prompt user for file name
    cin >> name;

    ifstream ist(name);  // Open file for reading
    if (!ist) {  // Check if file opened successfully
        cerr << "Error: Cannot open file.\n";
        return -1;  // Return -1 for file open error
    }

    vector<Reading> temps;  // Vector to store temperature readings
    Reading r;  // Reading object to hold each record temporarily

    // Read directly into Reading objects using overloaded >>
    while (ist >> r) {
        if (r.hour < 0 || r.hour > 23) {  // Check if hour is within valid range
            cerr << "Error: Hour out of range.\n";
            return -2;  // Return -2 for invalid hour error
        }
        temps.push_back(r);  // Store valid reading
    }

    // Check for other errors (e.g., bad data format)
    if (!ist.eof()) {  // If reading ended due to error, not end of file
        cerr << "Error: Invalid data format in file.\n";
        return -3;  // Return -3 for bad data format
    }

    // Print the stored readings
    cout << "Readings from file:\n";
    // For loop that goes through all const (read only) objects in vector temps
    // auto means it automatically deduces the type of objects r
    // Could use const Reading& instead (abstraction I guess)
    // Use & (reference) to avoid copying each object. This is more efficient 
    for (const auto& r : temps) {
        // Accessing the hour member through r.hour member of the reading object that r refers to 
        // Accessing the temperature member through r.temperature member of the reading object that r refers to 
        cout << "Hour: " << r.hour << ", Temperature: " << r.temperature << "\n";
    }

    return 0;  // Return 0 for success
}

int main() {
    return readFromFile();  // Call function to read data from file
}
