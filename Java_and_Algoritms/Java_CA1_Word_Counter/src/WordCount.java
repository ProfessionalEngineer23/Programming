/*
Programmer: Niki Mardari, B00159642
Purpose: CA1 Word Counter
*/

import java.util.ArrayList; // For array manipulation
import java.util.Scanner; // For input stream
// import java.util.Collections; // For sort method
// import java.io.FILE; // For file objects
// import java.io IOException; // For exceptions in File opening

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

    // Sort method to sort ArrayList word objects descending order according to numerical occurence
    static void sort(ArrayList<WordCount>a)
    {   // sort method on ArrayList
        a.sort((w1, w2) -> {
            // First compare two object words by their occurence value
            int cmp = Integer.compare(w2.occ, w1.occ);
            // If the occurence comparison is not the same
            if (cmp != 0) {
                return cmp;
            }
            // Otherwise if the difference is 0, then we compare based on alphabetical order
            else {
                return -1 * w1.word.compareTo(w2.word);
            }
        });
    }
    // Sources:

    // https://www.w3schools.com/java/ref_arraylist_sort.asp -> Sort method in reverse alphabetical order
    // https://www.baeldung.com/java-comparator-comparable#:~:text=The%20Integer.,being%20passed%20as%20an%20argument. -> Integer.compare and Word.compare

    // toString method for formatting word and it's occurance
    public String toString() // Public so that it calls automatically
    {
        return this.occ + " " + this.word ;
    }

    public static void main(String[] args)
    {
        // Read words into created array list
        ArrayList<WordCount> a = readWords();
        // Sort words on their occurence
        sort(a);
        // Iterate through processed list
        for(WordCount s1 : a)
        {
            // Print out each word and it's occurance
            System.out.println(s1);
        }
    } // End of main
} // End of class WordCount

// To compile: javac WordCount.java
// To run: java WordCount < ../data/tinyTale.txt
