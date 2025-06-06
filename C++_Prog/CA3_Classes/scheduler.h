// Name: Niki Mardari
// ID: B00159642

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

namespace scheduler 
{
using namespace std;

// Exception for invalid time
class Bad_time {};

// Exception for invalid dates
class Bad_day 
{
public:
    string message;
    Bad_day(const string& msg) : message(msg) {}
};


// Represents a calendar date
class Date 
{
public:
    enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
    Date(int y, Month m, int d);
    friend ostream& operator<<(ostream& os, const Date& date);
private:
    int year;
    Month month;
    int day;
    int daysInMonth(Month m, int y);
};

// Represents a specific time (hour, minute, second)
class Time 
{
public:
    Time(int h, int m, int s = 0);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    friend ostream& operator<<(ostream& os, const Time& t);
private:
    int hour, minute, second;
};

// Base class for all events
class Event 
{
public:
    Event(Date d, Time start, Time end, const string& loc);
    virtual ~Event() {}
    virtual void print(ostream& os) const;
    void add_attendee(const string& name);
    friend ostream& operator<<(ostream& os, const Event& e);
protected:
    Date date;
    Time start_time, end_time;
    string location;
    vector<string> attendees;
};

// Represents a meeting with a chairperson
class Meeting : public Event 
{
public:
    Meeting(Date d, Time start, Time end, const string& loc, const string& ch);
    void print(ostream& os) const override;
private:
    string chair;
};

// Represents a lecture with a group
class Lecture : public Event 
{
public:
    Lecture(Date d, Time start, Time end, const string& loc, const string& grp);
    void print(ostream& os) const override;
private:
    string group;
};

// Loads meetings and lectures from a file
vector<Event*> load(const string& filename);

} // namespace scheduler bracket

#endif
