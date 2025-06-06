// Name: Niki Mardari
// ID: B00159642

#ifndef testing_h
#define testing_h

#include <iostream> 
using namespace std;

// Define a class named Date
class Date {
public:
    // Enum for months
    enum Month {
        jan = 1, feb, mar, apr, may, jun, 
        jul, aug, sep, oct, nov, dec  // Enum values for months
    };

    // Constructor to initialize the date
    Date(int y, Month m, int d) : year(y), month(m), day(d) {}  // Initialize year, month, and day

    // Const-safe Getter functions
    int getYear() const { return year; }            // Getter for year
    Month getMonth() const { return month; }        // Getter for month
    int getDay() const { return day; }              // Getter for day

    // Setter function to add days
    void add(int days) {
        // Function to add a specified number of days to the date
        day += days;  // Increase the day by the given number of days
        if (day > daysInMonth(month, year)) {
            // Check if day exceeds days in the current month
            day = day - daysInMonth(month, year);
            if (month == dec) {
                // Check if current month is December
                month = jan;  // Move to January if it's December
                year++;       // Move to next year
            } else {
                month = Month(month + 1);  // Move to next month
            }
        }
    }

    // Print function
    void print() const {
        // Function to print the date in dd/mm/yyyy format
        cout << day << "/" << month << "/" << year << endl;  // Output date
    }

    // Overload == operator to compare dates
    bool operator==(const Date& other) const {
        // Operator overload for equality check
        return year == other.year && month == other.month && day == other.day;
    }

    // Overload << operator for cout << christmas
    friend ostream& operator<<(ostream& os, const Date& date) {
        // Overload << for output
        os << date.day << '/' << date.month << '/' << date.year;  // Format date as dd/mm/yyyy
        return os;  // Return the stream
    }

    // Overload ++ operator to add a day (prefix)
    Date& operator++() {
        // Prefix increment operator overload
        add(1);  // Simply add one day
        return *this;  // Return reference to the current object
    }

private:
    int year;
    Month month;  
    int day; 

    // Function to get number of days in a month
    int daysInMonth(Month m, int y) const {
        // Function to return number of days in a given month and year
        if (m == apr || m == jun || m == sep || m == nov)
            return 30;  // Months with 30 days
        else if (m == feb)
            return isLeapYear(y) ? 29 : 28;  // February with leap year check
        else
            return 31;  // Months with 31 days
    }

    // Helper function to check for leap year
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
};

#endif

/*==Sources==
https://www.programiz.com/cpp-programming/examples/leap-year - How to calculate leap year
*/

