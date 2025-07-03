// Name: Niki Mardari
// ID: B00159642

#include "scheduler.h"
using namespace std;
using namespace scheduler;

int main() 
{
    try 
    {
        // Date and Time test
        Date d(2005, Date::dec, 25);
        Time t(12, 22);
        cout << "Date & Time Test:\n" << d << " " << t << "\n\n";

        // Event test
        Event e(Date(2024, Date::mar, 12), Time(15, 0, 0), Time(16, 0, 0), "Boardroom A");
        e.add_attendee("Dovydas");
        e.add_attendee("Niki");
        e.add_attendee("Russel");
        e.add_attendee("Joe");
        e.add_attendee("Sumeer");
        cout << "Event Test:\n" << e << "\n";

        // Meeting test
        Meeting m(Date(2024, Date::mar, 12), Time(15, 0, 0), Time(16, 0, 0), "Boardroom A", "Patti Higgins");
        m.add_attendee("Jedidiah");
        m.add_attendee("James");
        m.add_attendee("Matas");
        cout << "Meeting Test:\n" << m << "\n";

        // Load all events from file
        vector<Event*> events = load("schedule_10events.txt");
        cout << "Loaded Events from File:\n";
        for (auto ev : events) {
            cout << *ev << "\n";
        }

        // Clean up
        for (auto ev : events) delete ev;
    }
    catch (Bad_time) 
    {
        cerr << "Bad time.\n";
    }
    catch (Bad_day& e) 
    {
        cerr << "Date error: " << e.message << "\n";  
    }

    return 0;
}
