#include <iostream>
#include <fstream>
#include <cctype>  // For tolower()

using namespace std;

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;  // Get the filename from user input

    ifstream file(filename); // Open file for reading
    if (!file) {
        cerr << "Error: Could not open file " << filename << "\n";
        return 1;
    }

    char ch;
    while (file.get(ch)) {  // Read file character by character
        cout << (char)tolower(ch);  // Convert to lowercase and print
    }

    file.close();  // Close the file
    return 0;
}
