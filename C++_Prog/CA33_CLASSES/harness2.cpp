//Name: Niki Mardari
//ID: B00159642

#include "scheduler2.h"

// Brings in the standard library and scheduler namespace so we don't need to prefix types
using namespace std;
using namespace scheduler;

// Helper function to display any Event object (including derived types)
void show(const Event& e) 
{
    cout << e << "\n";  // This uses the overloaded << operator which calls print()
}

int main() {
    try {
        // Create a sample Date and Time range for all test events
        Date date(2024, Date::mar, 12); // March 12, 2024
        Time start(15, 0), end(16, 0);  // 15:00 to 16:00

        //Events Test
        cout << "\nEvents Test\n";
        Event e(date, start, end, "Boardroom A");
        e.add_attendee("Russel");
        e.add_attendee("Joe");
        e.add_attendee("Dovydas");
        e.add_attendee("Sumeer");
        e.add_attendee("Niki");
        show(e);  // Display Event details

        // Meeting Test
        cout << "\nMeeting Test\n";
        Meeting m(date, start, end, "Room B", "Dr. Smith");
        m.add_attendee("Carol");
        m.add_attendee("DanTDM");
        show(m);  // Display Meeting details including chair

        // Lecture Test
        cout << "\nLecture Test\n";
        Lecture l(date, start, end, "Lecture Hall", "Group 42");
        l.add_attendee("Eve");
        l.add_attendee("Frank");
        show(l);  // Display Lecture details including group

        cout << "\nSchedule 10 Events\n";
        // Load function for events from File
        // This reads event/meeting/lecture records from a text file
        vector<Event*> events = load("schedule_10events.txt");

        // Loop through the dynamically loaded events and display each
        for (Event* ev : events) {
            show(*ev);  // Calls virtual print() for correct type
            delete ev;  // Clean up memory allocated in load()
        }

    } catch (Bad_time) { // Catch invalid time input
        cerr << "Invalid time.\n";

    } catch (Bad_day& err) { // Catch invalid date input
        cerr << "Date error: " << err.message << "\n";
    }
}
