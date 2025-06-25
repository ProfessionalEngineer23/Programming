//Name: Niki Mardari
//ID: B00159642
#include "Simple_window.h"
#include "Graph.h"

int main() 
{
    using namespace Graph_lib;

    // Create a window
    Simple_window win(Point(100, 100), 600, 400, "Window");

    // Create a rectangle
    Rectangle r(Point(150, 150), 200, 100);
    r.set_color(Color::blue);
    r.set_fill_color(Color::green);
    win.attach(r);

    // Create and attach text
    Text hello(Point(200, 190), "BOB"); 
    hello.set_color(Color::black);
    hello.set_font(Font::helvetica_bold);
    hello.set_font_size(20);
    win.attach(hello);

    // Show window
    win.wait_for_button();
}
