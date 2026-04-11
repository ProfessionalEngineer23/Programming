/*
 * Name: Niki Mardari
 * Student number: B00159642
 * Email Address: B00159642@mytudublin.ie
 * Date: 11/04/2026
 * Module: ELTC H3028 Java and Algorithms
 * Purpose of code: Java Tail program that prints the last k lines from standard input using the Queue interface.
 */
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Tail {

    /*
     * Parse and validate command-line argument k.
     * Arg 1: args, command-line arguments
     * Returns: positive integer k
     */
    public static int parseK(String[] args) {
        if (args.length != 1) {
            throw new IllegalArgumentException("Usage: java Tail <k> < inputfile");
        }

        int k;
        try {
            k = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException(
                "Error: k must be a positive integer.\nUsage: java Tail <k> < inputfile"
            );
        }

        if (k <= 0) {
            throw new IllegalArgumentException("Error: k must be greater than 0.");
        }

        return k;
    }

    /*
     * Read all lines and keep only the last k.
     * Arg 1: scanner, source of input
     * Arg 2: k, number of lines to keep
     * Returns: queue containing last k lines
     */
    public static Queue<String> loadTailQueue(Scanner scanner, int k) {
        Queue<String> lines = new LinkedList<>();

        while (scanner.hasNextLine()) {
            lines.add(scanner.nextLine());

            if (lines.size() > k) {
                lines.poll();   // discard oldest line
            }
        }

        return lines;
    }

    /*
     * Print all lines in queue order.
     * Arg 1: lines, queue of lines to print
     * Arg 2: out, output stream
     */
    public static void printQueue(Queue<String> lines, PrintStream out) {
        while (!lines.isEmpty()) {
            out.println(lines.poll());
        }
    }

    /*
     * Reusable core tail logic for other developers.
     * Arg 1: k, number of lines to print
     * Arg 2: scanner, source of input
     * Arg 3: out, output stream
     */
    public static void runTail(int k, Scanner scanner, PrintStream out) {
        Queue<String> lines = loadTailQueue(scanner, k);
        printQueue(lines, out);
    }

    /*
     * Command-line application wrapper.
     * Handles argument parsing and user-friendly error messages.
     * Arg 1: args, command-line arguments
     * Arg 2: scanner, source of input
     * Arg 3: out, output stream
     */
    public static void runTailApp(String[] args, Scanner scanner, PrintStream out) {
        try {
            int k = parseK(args);
            runTail(k, scanner, out);
        } catch (IllegalArgumentException e) {
            out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        runTailApp(args, scanner, System.out);
        scanner.close();
    }
}
