/*
Programmer: Niki Mardari, B00159642
Purpose: CA1 Word Counter
*/

/**
 * Package: CA1
 * 
 * This package organizes related classes for Continuous Assessment 1 (CA1).
 * Packages in Java provide a namespace to avoid naming conflicts and improve
 * code organization by grouping related classes together.
 * 
 * Why you need the package statement here:
 * - The package declaration must match your file's directory structure
 * - Since your file is in the CA1 folder, the package must be declared as "CA1"
 * - Without it, the class would be in the default (unnamed) package
 * 
 * What is a Package in Java?
 * A package is a namespace mechanism that:
 * - Groups related classes logically
 * - Prevents naming conflicts (e.g., two classes named "WordCount" in different packages)
 * - Controls access visibility via access modifiers (public, protected, private, package-private)
 * - Maps to your file system directory structure
 * 
 * Why you usually don't need to type it:
 * - Simple practice programs often use the default package (no package statement)
 * - However, professional projects always use packages for better organization
 * - Your CA1 assignment likely requires proper package structure for submission
 */
package CA1; // Package name
import java.util.ArrayList; // For array manipulation
import java.util.Scanner; // For input stream
// import java.io.FILE; // For file objects
// import java.io.IOException; // For exceptions in File opening

// Class for representing a single word and it's occurence as an object
public class WordCount
{
    private String word; // The word
    private int occ; // Its occurence
    // Constructor
    WordCount(String w, int n) {
        word = w;
        occ = n;
    }
    // Default occurence of a word object is 1

    // Method to find if the word exists in the list
    static WordCount search(String s2, ArrayList<WordCount> arrayEnd)
    {
        for(WordCount s1: arrayEnd)
        {
            // If words are equal return the targeted word
            if(s1.word.equals(s2))
            {
                return s1;
            }
        }
        return null; // Otherwise nothing
    }
    // Add method to add new word to list or increment its count
    static void add(String w, ArrayList<WordCount> a)
    {
        WordCount s1 = search(w,a); // Try to find the word in the list
        // If not found add it as a new object
        if(s1 == null) {
            a.add(new WordCount(w,1));
        }
        // Otherwise it exists and increment occurence count
        else {
            s1.occ++;
        }
    }

    // ReadWords method to read words from user input
    // + Clean up
    public static ArrayList<WordCount> readWords()
    {
        ArrayList<WordCount> a = new ArrayList<WordCount>(); // List where words will be stored
        Scanner Reader = new Scanner(System.in); // Scanner for input stream
        // Read until ctrl+d or ctrl+z or EOF
        Reader.useDelimiter("[,;|:\\s.\"'\\-?!]+");
        while(Reader.hasNext()) {
            add(Reader.next().toLowerCase(), a);
            // Convert to lowercase to not get duplicates
            // Sources: https://en.wikipedia.org/wiki/Regular_expression ,
            // https://medium.com/@AlexanderObregon/javas-scanner-usedelimiter-method-explained-8e09e2baf83
        }
        Reader.close();
        return a; // Retrurn list of words
    }

    // toString method for formatting word and it's occurance
    public String toString() // Public so that it calls automatically
    {
        return this.word + " " + this.occ ;
    }

    public static void main(String[] args)
    {
        // Read words into created array list
        ArrayList<WordCount> a = readWords();
        // Iterate through processed list
        for(WordCount s1 : a)
        {
            // Print out each word and it's occurance
            System.out.println(s1);
        }
    } // End of main
} // End of class WordCount
