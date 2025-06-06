//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl(100,100);           // top left corner of window
    Simple_window win(tl,600,400,"Canvas");

    Graph_lib::Polygon poly;

    poly.add(Point(300,200));
    poly.add(Point(350,100));
    poly.add(Point(400,200));

    poly.set_color(Color::red);

    win.attach (poly);

    // give control to the display engine
    win.wait_for_button();
}
