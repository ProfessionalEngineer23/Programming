#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

// Smiley class that extends Circle
class Smiley : public Circle {
private:
    Lines features;           // for eyes
    Open_polyline mouth;      // for curved mouth

public:
    Smiley(Point cc, int rr) : Circle(cc, rr) {
        // Vertical eyes
        features.add(Point(cc.x - 20, cc.y - 20), Point(cc.x - 20, cc.y - 5)); // left eye
        features.add(Point(cc.x + 20, cc.y - 20), Point(cc.x + 20, cc.y - 5)); // right eye

        // Simulated curved smile using parabolic points
        for (int x = -30; x <= 30; x += 5) {
            int y = int(20 - 0.02 * x * x);  // smile shape (curve)
            mouth.add(Point(cc.x + x, cc.y + y));
        }
    }

    void draw_lines() const override {
        Circle::draw_lines();     // draw the face
        features.draw_lines();    // draw the eyes
        mouth.draw_lines();       // draw the smile
    }
};

int main() {
    Simple_window win(Point(100, 100), 600, 400, "Smiley Face");

    Smiley s(Point(300, 200), 100); // center (300, 200), radius 100
    win.attach(s);

    win.wait_for_button();
}
