#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

// Define the Smiley class before main
class Smiley : public Circle 
{
    public:
        Smiley(Point cc, int rr) : Circle(cc, rr) {}
};

int main() {
    Simple_window win(Point(100, 100), 600, 400, "Canvas");
    Smiley s(Point(150, 150), 100);  // Using your new Smiley class
    win.attach(s);
    win.wait_for_button();
}   