#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

// A smiley face with eyes and a smile
class Smiley : public Circle {
private:
    Lines eyes;
    Lines smile;

public:
    Smiley(Point center, int radius) : Circle(center, radius) {
        // Two vertical lines for eyes
        eyes.add(Point(center.x - 20, center.y - 20), Point(center.x - 20, center.y - 5));
        eyes.add(Point(center.x + 20, center.y - 20), Point(center.x + 20, center.y - 5));

        // Draw a smile with small connected lines
        for (int x = -30; x < 30; x += 5) {
            int y1 = 20 - 0.02 * x * x;
            int y2 = 20 - 0.02 * (x + 5) * (x + 5);
            smile.add(Point(center.x + x, center.y + y1), Point(center.x + x + 5, center.y + y2));
        }
    }

    void draw_lines() const override {
        Circle::draw_lines();  // draw the face
        eyes.draw_lines();     // draw eyes
        smile.draw_lines();    // draw smile
    }
};

// A smiley face with a hat
class SmileyHat : public Smiley {
private:
    Rectangle hat;

public:
    SmileyHat(Point center, int radius)
        : Smiley(center, radius),
          hat(Point(center.x - radius, center.y - radius - 10), radius * 2, 10)
    {}

    void draw_lines() const override {
        Smiley::draw_lines();  // draw smiley face
        hat.draw();            // draw the hat
    }
};

int main() {
    Simple_window win(Point(100, 100), 600, 400, "Smiley Faces");

    Smiley smiley(Point(150, 200), 50);
    SmileyHat smiley_with_hat(Point(400, 200), 50);

    win.attach(smiley);
    win.attach(smiley_with_hat);

    win.wait_for_button();  // Show window until user clicks
}
