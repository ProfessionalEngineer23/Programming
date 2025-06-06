#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{   //At 100,100, size 400*400 
    Simple_window win(Point(100,100), 400, 400, "Minecraft Block");

    Rectangle block(Point(100, 100), 100, 100);

    block.set_fill_color(Color::green);
    block.set_color(Color::black);

    win.attach(block);

    win.wait_for_button();

    return 0;

}