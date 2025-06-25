//Name: Niki Mardari
//ID: B00159642

// scheduler.h
// Header file for the event scheduling system
// Contains declarations for Date, Time, Event, Meeting, and Lecture classes
// Also includes a function to load events from a file
#ifndef SCHEDULER2_H
#define SCHEDULER2_H

// Include necessary standard libraries
#include <iostream>   // For std::ostream
#include <string>     // For std::string
#include <vector>     // For std::vector to store attendees
#include <iomanip>    // For output formatting
#include <fstream>    // For file reading
#include <sstream>    // For parsing CSV lines

namespace scheduler 
{
// Exception class for invalid time input
class Bad_time {};

// Exception class for invalid date input
class Bad_day 
{
public:
    std::string message;  // Stores an error message
    Bad_day(const std::string& msg) : message(msg) {}  // Constructor to set message
};

// Represents a calendar date
class Date 
{
public:
    // Enum listing all months by name
    enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

    // Constructor to initialize a date using year, month, and day
    Date(int y, Month m, int d);

    // Allows printing the Date using the << operator
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

private:
    int year;
    Month month;
    int day;

    // Returns the number of days in a month, including leap year handling
    int daysInMonth(Month m, int y);
};

// Represents a specific time of day
class Time 
{
public:
    // Constructor to initialize time with hour, minute, and optional second
    Time(int h, int m, int s = 0);

    // Allows printing the Time using the << operator
    friend std::ostream& operator<<(std::ostream& os, const Time& t);

private:
    int hour, minute, second;
};

// Base class for all event types
class Event 
{
public:
    // Constructor to set event details
    Event(Date d, Time start, Time end, const std::string& loc);
    // Virtual destructor to allow proper cleanup in derived classes
    virtual ~Event() {}
    // Virtual print function that can be overridden by child classes
    virtual void print(std::ostream& os) const;
    // Adds a person to the attendee list
    void add_attendee(const std::string& name);
    // Allows using << to print Event details
    friend std::ostream& operator<<(std::ostream& os, const Event& e);

protected:
    Date date;
    Time start_time, end_time;
    std::string location;
    std::vector<std::string> attendees;
};

// A Meeting is a type of Event with a chairperson
class Meeting : public Event 
{
public:
    // Constructor adds the chair to the event information
    Meeting(Date d, Time start, Time end, const std::string& loc, const std::string& ch);
    // Overrides the base print function to include chair
    void print(std::ostream& os) const override;
private:
    std::string chair;
};

// A Lecture is a type of Event with an assigned group
class Lecture : public Event 
{
public:
    // Constructor adds the group to the event information
    Lecture(Date d, Time start, Time end, const std::string& loc, const std::string& grp);
    // Overrides the base print function to include group
    void print(std::ostream& os) const override;
private:
    std::string group;
};

// Reads events from a text file and returns them as Event pointers
std::vector<Event*> load(const std::string& filename);
}
#endif
