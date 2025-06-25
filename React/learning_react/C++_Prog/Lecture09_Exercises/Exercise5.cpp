#include <iostream>
#include <fstream>
#include <cctype>  // For character classification functions

using namespace std;

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;  // Read filename from user input

    ifstream file(filename); // Open the file for reading
    if (!file) {
        cerr << "Error: Could not open file " << filename << "\n";
        return 1;
    }

    char ch;
    while (file >> noskipws >> ch) { // Read character by character (Slide 24)
        ch = tolower(ch); // Convert to lowercase for uniformity (Slide 25)
        
        // Check if the character is a vowel and skip it
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            continue; 
        }

        cout << ch; // Print non-vowel characters to standard output
    }

    file.close(); // Close file after reading 
    return 0;
}
