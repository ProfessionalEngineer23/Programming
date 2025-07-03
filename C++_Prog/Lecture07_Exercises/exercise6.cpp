//Name: Niki Mardari
//ID: B00159642

#include <iostream> 
using namespace std;

// Define a class named Date
class Date {

public:
// Enum for months
enum Month {
jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec  // Enum values for months
};

// Constructor to initialize the date
Date(int y, Month m, int d) : year(y), month(m), day(d) {}  // Initialize year, month, and day

// Const-safe Getter functions
int getYear() const { return year; }  // Getter for year
Month getMonth() const { return month; }  // Getter for month
int getDay() const { return day; }  // Getter for day
/*Returns a member variable without modifying the state of the object.
  Is marked with the const keyword at the end of the function declaration.
  Guarantees that the function will not modify any member variables of the object
  Allows the function to be called on const objects.
*/

// Setter function to add days
void add(int days) {  // Function to add a specified number of days to the date
day += days;  // Increase the day by the given number of days
if (day > daysInMonth(month, year)) {  // Check if day exceeds days in the current month
day = day - daysInMonth(month, year);
// Adjust day and move to the next month

else if (month == dec) {  // Check if current month is December
month = jan;  // Move to January if it's December
year++;        // Move to next year
} else {
month = Month(month + 1);  // Move to next month
}
}
}

// Print function
void print() const {  // Function to print the date in dd/mm/yyyy format
cout << day << "/" << month << "/" << year << endl;  // Output date
}

// Overload == operator to compare dates
bool operator==(const Date& other) const {  // Operator overload for equality check
return year == other.year && month == other.month && day == other.day;  // Compare year, month, and day
}

// Overload << operator for cout << christmas
friend ostream& operator<<(ostream& os, const Date& date) {  // Overload << for output
os << date.day << '/' << date.month << '/' << date.year;  // Format date as dd/mm/yyyy
return os;  // Return the stream
}

// Overload ++ operator to add a day (prefix)
Date& operator++() {  // Prefix increment operator overload
add(1);  // Simply add one day
return *this;  //Returns a pointer to the current object instead of a reference.
}

private:
int year;
Month month;  
int day; 

// Function to get number of days in a month
int daysInMonth(Month m, int y) const {  // Function to return number of days in a given month and year
if (m == apr || m == jun || m == sep || m == nov)  // Check for months with 30 days
return 30;  // Months with 30 days
else if (m == feb)  // Check if month is February
return isLeapYear(y) ? 29 : 28;  // February with leap year check
else
return 31;  // Months with 31 days
}

// Function to check for a leap year
bool isLeapYear(int y) const {  // Function to check if a year is a leap year
return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));  // Return true if leap year, false otherwise
}
};

// Main function
int main() {
Date christmas(2023, Date::dec, 25);  // Create a Date object for Christmas
cout << "Christmas date: " << christmas << endl;  // Print the initial Christmas date

++christmas;  // Add one day to Christmas object using overloaded ++ operator
cout << "Day after Christmas: " << christmas << endl;  // Print the date after increment

christmas.add(5);  // Add 5 days to Christmas object using add function
cout << "Five days later: " << christmas << endl;  // Print the date after adding 5 days

christmas.print();  // Print the Christmas object using the print function

return 0;  // Return 0 to indicate successful execution
}

/*==Sources==
https://www.programiz.com/cpp-programming/examples/leap-year - How to calculate leap year
*/
