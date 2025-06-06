// Getting access to the graphics system (don’t forget to install):
// stuff to deal with your system’s windows
#include "Simple_window.h"
// graphical shapes
#include "Graph.h"
using namespace Graph_lib;
// screen coordinate (100,100) top left of window
// window size(600*400)
// title: Canvas
int main() {
Simple_window win(Point(100,100),600,400,"Canvas");
// Display!
win.wait_for_button();
return 0;
}