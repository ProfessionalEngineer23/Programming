// Name: Niki Mardari
// ID: B00159642

#include "scheduler.h"

namespace scheduler 
{

// Constructor for Date class
// Initializes a date and checks if the day is valid
Date::Date(int y, Month m, int d) : year(y), month(m), day(d) 
{
    if (d < 1 || d > daysInMonth(m, y)) //If the day is less than 1 or more than days in the current month 
    {
        throw Bad_day("Invalid day for this month/year."); //Throw Bad_day
    }
}

// Returns the number of days in a month, accounting for leap years
int Date::daysInMonth(Month m, int y) {
    if (m == apr || m == jun || m == sep || m == nov) return 30;
    if (m == feb) return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
    return 31;
}

// Overloads << to print Date in dd/mm/yyyy format
ostream& operator<<(ostream& os, const Date& date) 
{
    os << setfill('0') << setw(2) << date.day << "/"
       << setw(2) << date.month << "/" << date.year;
    return os;
}

// Constructor for Time class
// Initializes a time and checks if it is valid
Time::Time(int h, int m, int s) 
{
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {throw Bad_time();}

    hour = h;
    minute = m;
    second = s;
}

// Returns the hour value
int Time::getHour() const { return hour; }

// Returns the minute value
int Time::getMinute() const { return minute; }

// Returns the second value
int Time::getSecond() const { return second; }

// Overloads << to print Time in hh:mm:ss format
ostream& operator<<(ostream& os, const Time& t) 
{
    os << setfill('0') << setw(2) << t.hour << ":"
       << setw(2) << t.minute << ":"
       << setfill('0') << setw(2) << t.second;
    return os;
}

// Constructor for Event class
// Stores the date, time range, and location of the event
Event::Event(Date d, Time start, Time end, const string& loc)
    : date(d), start_time(start), end_time(end), location(loc) {}

// Adds a person to the list of attendees
void Event::add_attendee(const string& name) {
    attendees.push_back(name);
}

// Prints the event’s basic info and attendee list
void Event::print(ostream& os) const {
    os << date << " " << start_time << "-" << end_time << " " << location << "\n";
    for (const auto& name : attendees) {
        os << "attendee: " << name << "\n";
    }
}

// Overloads << to print any Event (calls print method)
ostream& operator<<(ostream& os, const Event& e) {
    e.print(os);
    return os;
}

// Constructor for Meeting class
// Inherits Event and adds a chairperson
Meeting::Meeting(Date d, Time start, Time end, const string& loc, const string& ch)
    : Event(d, start, end, loc), chair(ch) {}

// Overrides print() to include the chairperson
void Meeting::print(ostream& os) const {
    Event::print(os);
    os << "Chair: " << chair << "\n";
}

// Constructor for Lecture class
// Inherits Event and adds a group name
Lecture::Lecture(Date d, Time start, Time end, const string& loc, const string& grp)
    : Event(d, start, end, loc), group(grp) {}

// Overrides print() to include the group name
void Lecture::print(ostream& os) const {
    Event::print(os);
    os << "Group: " << group << "\n";
}

// Loads events from a file and returns a list of pointers to Event objects
vector<Event*> load(const string& filename) {
    vector<Event*> events;
    ifstream file(filename);
    string line;

    while (getline(file, line)) 
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string type;
        getline(ss, type, ',');

        string temp;

        // Read and construct Date
        getline(ss, temp, '-'); int y = stoi(temp);
        getline(ss, temp, '-'); int month = stoi(temp);
        getline(ss, temp, ','); int d = stoi(temp);
        Date date(y, static_cast<Date::Month>(month), d);

        // Read and construct Start Time
        getline(ss, temp, ':'); int sh = stoi(temp);
        getline(ss, temp, ','); int sm = stoi(temp);
        Time start(sh, sm, 0);

        // Read and construct End Time
        getline(ss, temp, ':'); int eh = stoi(temp);
        getline(ss, temp, ','); int em = stoi(temp);
        Time end(eh, em, 0);

        // Read location
        string location;
        getline(ss, location, ',');

        // Handle Meetings
        if (type == "M") 
        {
            string chair;
            getline(ss, chair, ',');
            Meeting* m = new Meeting(date, start, end, location, chair);

            string attendee;
            while (getline(ss, attendee, ',')) 
            {
                m->add_attendee(attendee);
            }

            events.push_back(m);
        }
        // Handle Lectures
        else if (type == "L") 
        {
            string group;
            getline(ss, group, ',');
            Lecture* l = new Lecture(date, start, end, location, group);

            string student;
            while (getline(ss, student, ',')) {
                l->add_attendee(student);
            }

            events.push_back(l);
        }
    }

    return events;
}

} // namespace scheduler
