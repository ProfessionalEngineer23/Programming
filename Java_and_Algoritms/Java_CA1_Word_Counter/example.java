import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Rectangle;
import javax.swing.JFrame;
import java.util.Scanner;

public class example extends Canvas {

    // Move drawing logic into the paint method
    @Override
    public void paint(Graphics g) {
        DrawCircles(g, new Rectangle(50, 50, 200, 200));
    }

    public static void DrawCircles(Graphics g, Rectangle bb) {

    int dx = bb.width / 2;
    int dy = bb.height / 2;
    Rectangle half = new Rectangle(bb.x, bb.y, dx, dy);

    half.translate(-dx / 2, -dy / 2);
    g.drawOval(half.x, half.y, half.width, half.height);
    half.translate(dx / 2, 67);
    g.drawOval(half.x, half.y, half.width, 400);
    half.translate(dx / 2 , -  dy / 2 - 15);
    g.drawOval(half.x, half.y, half.width, half.height);
    }

    public static void main(String args[]) {
        JFrame frame = new JFrame("Drawing Example");
        example canvas = new example(); // Correct class name
        canvas.setPreferredSize(new java.awt.Dimension(400, 400));
        
        frame.add(canvas);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        // Console input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name: ");
        String name = sc.nextLine();
        System.out.println("Welcome " + name);
        sc.close();
    }
}
