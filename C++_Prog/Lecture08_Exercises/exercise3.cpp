#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to count words in a file
int countWordsInFile() {
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    ifstream file(fileName);  // Open file for reading
    if (!file) {  // Check if file opened successfully
        cerr << "Error: Cannot open file.\n";
        return -1;
    }

    string word;  // Temporary variable to store each word
    int wordCount = 0;  // Counter for words

    // Read each word one by one and count
    while (file >> word) {
        wordCount++;  // Increment word count for each word read
    }

    file.close();  // Close the file

    // Print the total number of words found
    cout << "Total number of words in file: " << wordCount << "\n";

    return 0;  // Return 0 for success
}

int main() {
    return countWordsInFile();  // Call function to count words in file
}
