// Name: Niki Mardari
// ID: B00159642

#include "scheduler2.h"  // Header file containing all class declarations

namespace scheduler 
{
// Constructor for Date
// Validates the day by checking if it falls within the correct range for the given month and year
Date::Date(int y, Month m, int d) : year(y), month(m), day(d) 
{
    if (d < 1 || d > daysInMonth(m, y)) 
    {
        throw Bad_day("Invalid day for this month/year.");
    }
}

// Helper function to return the number of days in a specific month of a given year
int Date::daysInMonth(Month m, int y) {
    // April, June, September, and November have 30 days
    if (m == apr || m == jun || m == sep || m == nov) return 30;

    // Determine if the year is a leap year
    bool leap = false;
    if (y % 400 == 0) leap = true;
    else if (y % 100 == 0) leap = false;
    else if (y % 4 == 0) leap = true;

    // February has 29 days in a leap year, 28 otherwise
    if (m == feb) return leap ? 29 : 28;

    // All other months have 31 days
    return 31;
}

// Overloads the << operator to print Date in dd/mm/yyyy format
std::ostream& operator<<(std::ostream& os, const Date& date) 
{
    os << std::setfill('0') << std::setw(2) << date.day << "/"
       << std::setw(2) << date.month << "/" << date.year;
    return os;
}

// Constructor for Time
// Throws Bad_time if any of the time values are out of valid range
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) 
{
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) 
    {
        throw Bad_time();
    }
}

// Overloads the << operator to print Time in hh:mm:ss format
std::ostream& operator<<(std::ostream& os, const Time& t) 
{
    os << std::setfill('0') << std::setw(2) << t.hour << ":"
       << std::setw(2) << t.minute << ":" << std::setw(2) << t.second;
    return os;
}

// Constructor for Event
// Initializes the date, time range, and location
Event::Event(Date d, Time start, Time end, const std::string& loc)
    : date(d), start_time(start), end_time(end), location(loc) {}

// Adds an attendee to the attendee list
void Event::add_attendee(const std::string& name) 
{
    attendees.push_back(name);
}

// Prints the event details: date, time, location, and attendee list
void Event::print(std::ostream& os) const 
{
    os << date << "\n"
       << "Duration Time: " << start_time << "-" << end_time << "\n"
       << "Location: " << location << "\n";
    for (const auto& a : attendees) 
    {
        os << "attendee: " << a << "\n";
    }
}

// Overloads the << operator to call the virtual print function
std::ostream& operator<<(std::ostream& os, const Event& e) 
{
    e.print(os);  // Polymorphic: will call derived class print if applicable
    return os;
}

// Constructor for Meeting
// Calls the base Event constructor and also sets the chair
Meeting::Meeting(Date d, Time start, Time end, const std::string& loc, const std::string& ch)
    : Event(d, start, end, loc), chair(ch) {}

// Overrides the Event print function to include the chair
void Meeting::print(std::ostream& os) const 
{
    Event::print(os);  // Call base class to print common event info
    os << "Chair: " << chair << "\n";
}

// Constructor for Lecture
// Calls the base Event constructor and also sets the group name
Lecture::Lecture(Date d, Time start, Time end, const std::string& loc, const std::string& grp)
    : Event(d, start, end, loc), group(grp) {}

// Overrides the Event print function to include the group
void Lecture::print(std::ostream& os) const 
{
    Event::print(os);  // Call base class to print common event info
    os << "Group: " << group << "\n";
}

nt records from a CSV file and returns a list of Event pointers
std::vector<Event*> load(const std::string& filename) 
{
    std::vector<Event*> events;  // Vector to store dynamically created Event objects
    std::ifstream file(filename);  // Open the file for reading
    std::string line;

    while (std::getline(file, line)) 
    {
        if (line.empty()) continue;  // Skip blank lines

        std::stringstream ss(line);  // Convert line into a stream for parsing
        std::string type, temp;

        // Parse date in format yyyy-mm-dd
        std::getline(ss, type, ',');         // First field: M or L (Meeting or Lecture)
        std::getline(ss, temp, '-'); int y = std::stoi(temp);
        std::getline(ss, temp, '-'); int m = std::stoi(temp);
        std::getline(ss, temp, ','); int d = std::stoi(temp);
        Date date(y, static_cast<Date::Month>(m), d);

        // Parse start time in format hh:mm
        std::getline(ss, temp, ':'); int sh = std::stoi(temp);
        std::getline(ss, temp, ','); int sm = std::stoi(temp);
        Time start(sh, sm);

        // Parse end time in format hh:mm
        std::getline(ss, temp, ':'); int eh = std::stoi(temp);
        std::getline(ss, temp, ','); int em = std::stoi(temp);
        Time end(eh, em);

        // Parse location
        std::string loc;
        std::getline(ss, loc, ',');

        // Handle Meeting records
        if (type == "M") {
            std::string chair;
            std::getline(ss, chair, ',');
            Meeting* m = new Meeting(date, start, end, loc, chair);

            // Add attendees (remaining fields)
            while (std::getline(ss, temp, ',')) 
            {
                m->add_attendee(temp);
            }

            events.push_back(m);  // Add meeting to list
        }

        // Handling Lecture records
        else if (type == "L") 
        {
            std::string group;
            std::getline(ss, group, ',');
            Lecture* l = new Lecture(date, start, end, loc, group);

            // Add attendees (remaining fields)
            while (std::getline(ss, temp, ',')) {
                l->add_attendee(temp);
            }

            events.push_back(l);  // Adding lecture to list
        }
    }
    return events;
}// Reads eve
}
/* Sources:
https://docs.vultr.com/cpp/examples/check-leap-year - Helped me learn how to calculate leap years.
https://www.geeksforgeeks.org/getline-string-c/ - Helped me learn how to get line strings from input.
*/
