import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.Queue;
import java.util.Scanner;

/*
Tested File used: tinyTale.txt

it was the best of times it was the worst of times
it was the age of wisdom it was the age of foolishness
it was the epoch of belief it was the epoch of incredulity
it was the season of light it was the season of darkness
it was the spring of hope it was the winter of despair

 */

public class TailTest {

    // Test loadTailQueue when k = 1 the output is the last line of the input
    @Test
    public void loadTailQueue_kEquals1_returnsLastLine() throws Exception {
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        Queue<String> result = Tail.loadTailQueue(scanner, 1);

        assertEquals(1, result.size());
        assertEquals("it was the spring of hope it was the winter of despair", result.poll());

        scanner.close();
    }

    // Test loadTailQueue when k = 3 the output is the last three lines of the input
    @Test
    public void loadTailQueue_kEquals3_returnsLastThreeLines() throws Exception {
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        Queue<String> result = Tail.loadTailQueue(scanner, 3);

        assertEquals(3, result.size());
        assertEquals("it was the epoch of belief it was the epoch of incredulity", result.poll());
        assertEquals("it was the season of light it was the season of darkness", result.poll());
        assertEquals("it was the spring of hope it was the winter of despair", result.poll());

        scanner.close();
    }

    // Test loadTailQueue when k is greater than the number of lines in the input, the output should be all lines
    @Test
    public void loadTailQueue_kGreaterThanInputSize_returnsAllLines() throws Exception {
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        Queue<String> result = Tail.loadTailQueue(scanner, 15);

        assertEquals(5, result.size());
        assertEquals("it was the best of times it was the worst of times", result.poll());
        assertEquals("it was the age of wisdom it was the age of foolishness", result.poll());
        assertEquals("it was the epoch of belief it was the epoch of incredulity", result.poll());
        assertEquals("it was the season of light it was the season of darkness", result.poll());
        assertEquals("it was the spring of hope it was the winter of despair", result.poll());

        scanner.close();
    }

    // Test runTail when k = 2 the output should be the last two lines of the input
    @Test
    public void runTail_kEquals2_printsLastTwoLines() throws Exception{
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        Tail.runTail(2, scanner, out);

        String expected = "it was the season of light it was the season of darkness" + System.lineSeparator() +
                          "it was the spring of hope it was the winter of despair" + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
    }

    // Test runTailApp when k = 3 the output should be the last three lines of the input
    @Test 
    public void runTailApp_kEquals5_printsLastFiveLines() throws Exception {
        Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        PrintStream out = new PrintStream(outContent);

        String[] args = {"3"};
        Tail.runTailApp(args, scanner, out);

        String expected =
                "it was the epoch of belief it was the epoch of incredulity" + System.lineSeparator() +
                "it was the season of light it was the season of darkness" + System.lineSeparator() +
                "it was the spring of hope it was the winter of despair" + System.lineSeparator();

        assertEquals(expected, outContent.toString());

        scanner.close();
        out.close();
    }

    // Test runTailApp when k = 0 the output should be an error message
    @Test
    public void runTailApp_zero_printsErrorMessage() throws Exception {
    Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
    ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    PrintStream out = new PrintStream(outContent);

    String[] args = {"0"};
    Tail.runTailApp(args, scanner, out);

    String expected = "Error: k must be greater than 0." + System.lineSeparator();

    assertEquals(expected, outContent.toString());

    scanner.close();
    out.close();
    }

    @Test
    public void runTailApp_negative_printsErrorMessage() throws Exception {
    Scanner scanner = new Scanner(new java.io.File("data/tinyTale.txt"));
    ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    PrintStream out = new PrintStream(outContent);

    String[] args = {"-1"};
    Tail.runTailApp(args, scanner, out);

    String expected = "Error: k must be greater than 0." + System.lineSeparator();

    assertEquals(expected, outContent.toString());

    scanner.close();
    out.close();
    }

}
// Excecuted from root dir
// To compile: javac -cp "lib\junit-platform-console-standalone-6.0.3.jar;src" -d bin src\Tail.java src\TailTest.java
// To run: java -jar lib\junit-platform-console-standalone-6.0.3.jar execute --class-path bin --scan-class-path
