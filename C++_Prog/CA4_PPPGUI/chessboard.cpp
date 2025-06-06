//Name: Niki Mardari
//ID: B00159642

#include "Simple_window.h"  // Provides window functionality
#include "Graph.h"          // Provides shapes like Rectangle
using namespace Graph_lib;  // Avoids writing Graph_lib:: everywhere

// Exception type for invalid chessboard parameters
struct BadChessboardException {};

// Function to draw a chessboard directly onto a window
void draw_chessboard(Simple_window& win, Point top_left, int width = 200, int height = 200,
                     int squares = 8, Color c1 = Color::black, Color c2 = Color::white)
{
    if (width <= 0 || height <= 0 || squares <= 0) throw BadChessboardException();

    int square_w = width / squares;
    int square_h = height / squares;

    for (int row = 0; row < squares; ++row) {
        for (int col = 0; col < squares; ++col) {
            // Calculate position of each square
            Point p(top_left.x + col * square_w, top_left.y + row * square_h);

            // Create a square rectangle
            Rectangle* r = new Rectangle(p, square_w, square_h);

            // Set fill color depending on row+col parity
            if ((row + col) % 2 == 0)
                r->set_fill_color(c1);
            else
                r->set_fill_color(c2);

            // Attach the rectangle to the window
            win.attach(*r);
        }
    }
}

int main()
{
    // Create a window at screen position (100,100), size 700x500
    Simple_window win(Point(100, 100), 700, 500, "Chessboard");

    try {
        // Draw 3 spaced-out chessboards with different configurations
        draw_chessboard(win, Point(20, 20));                                // Default 8x8, black/white
        draw_chessboard(win, Point(260, 20), 160, 160, 10);                 // 10x10, black/white
        draw_chessboard(win, Point(480, 20), 120, 120, 6, Color::red, Color::yellow); // 6x6, red/yellow
    }
    catch (BadChessboardException) {
        cerr << "Bad chessboard.\n";
    }

    // Display window and wait for user
    win.wait_for_button();
}
