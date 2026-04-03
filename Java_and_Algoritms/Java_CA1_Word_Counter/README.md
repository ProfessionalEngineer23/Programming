# WordCount Java Program

## Overview
This project was created for CA1. The program reads words of unlimited length from standard input, counts how many times each word occurs, and prints the results as a list.

The input ends when the user enters an EOF character:
- **Ctrl + D** on Linux/macOS
- **Ctrl + Z** on Windows

This program is useful as a basic word frequency counter and could be adapted for larger projects such as document search, text analysis, or keyword processing tools.

---

## Software Requirements Specification

The program must:
- Be written in Java
- Be run using the `java` command
- Read words from **standard input**
- Continue reading until EOF is entered
- Count the number of occurrences of each word
- Output each word with its occurrence count as a list

### Code Requirements
- A `WordCount` class must be used to store:
  - `word` as a `String`
  - `occ` as an `int`
- The list of `WordCount` objects must be stored in a Java `ArrayList`

---

## Design
The design went through multiple iterations before the final version was chosen.

The original idea was to store all input words in a list and then perform filtering and sorting before printing the results. This was later refined to match the assignment requirements more closely.

The project design is shown in the following diagrams:
- **WordCounter2.drawio** – abstract flowchart
- **ClassDiagramWordCount.drawio** – UML class diagram

---

## Build Notes
An `ArrayList` was used so that words and their occurrence counts could be stored dynamically.

To support this design, several methods were created within the class. Some methods were `public`, while others were `static`, depending on whether they operated on object data or class-level logic.

During testing, it was noticed that the expected format was:

```text
occurrence word
```

rather than:

```text
word occurrence
```

So the program output was adapted to match the testing format.

The required ordering was:
1. Sort by occurrence in descending numerical order
2. If occurrences are equal, sort words in reverse alphabetical order

---

## Running the Program

### Compile
```bash
javac WordCount.java
```

### Run
```bash
java WordCount
```

Then type words into standard input and end with EOF.

### Example Input
```text
the cat and the dog
```

### Possible Output
```text
2 the
1 dog
1 cat
1 and
```

---

## Acceptance Testing

The following command was used to test the program output:

```bash
sed 's/ /\n/g' tinytinyTale.txt | sort | uniq -c | sort -nr
```

### What this command does
- `sed 's/ /\n/g'` replaces spaces with newlines
- `sort` sorts all words alphabetically
- `uniq -c` counts repeated consecutive words
- `sort -nr` sorts the counts numerically in reverse order

For easier viewing, expected output was sometimes redirected into a file:

```bash
sed 's/ /\n/g' tinytinyTale.txt | sort | uniq -c | sort -nr > expected0.txt
```

---

## Acceptance Test Results

### tinytinyTale.txt

#### Expected Output
```text
2 was
2 times
2 the
2 of
2 it
1 worst
1 best
```

#### Actual Output
```text
2 was
2 times
2 the
2 of
2 it
1 worst
1 best
```

### tinyTale.txt

#### Expected Output
```text
10 was
10 the
10 of
10 it
2 times
2 season
```

#### Actual Output
```text
10 was
10 the
10 of
10 it
2 times
2 season
```

### tale.txt

#### Expected Output
```text
7989 the
4935 and
4002 of
3460 to
2909 a
2579 in
```

#### Actual Output
```text
7989 the
4935 and
4002 of
3460 to
2909 a
2579 in
```

### mobydick.txt
Early testing showed incorrect results on larger files because punctuation and capitalization caused duplicate word entries.

For example:

```text
whale
whale,
Whale
```

These were initially treated as different words.

This issue was fixed by:
- converting words to lowercase
- removing punctuation and regex-related delimiters before counting

After filtering and normalization, the output became more accurate.

---

## Observations
The program worked correctly for smaller files such as:
- `tinytinyTale.txt`
- `tinyTale.txt`
- `tale.txt`

For larger and more complex text files such as `mobydick.txt`, additional filtering was needed because punctuation, symbols, and capital letters caused words to be counted separately.

This was resolved by cleaning the input before storing and counting words.

---

## Sources
1. **Java & Algorithms CA1 OneDrive** – all CA1 files
2. **WordCounter2.drawio** – abstract flowchart
3. **ClassDiagramWordCount.drawio** – UML class diagram
4. **Notes and Tips** – helpful hints used during development
5. **Tests folder** – expected and actual output files