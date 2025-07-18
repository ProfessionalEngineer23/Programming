# Define a class called TextAnalyzer
class TextAnalyzer(object):
    
    # Constructor to initialize and preprocess the input text
    def __init__(self, text):
        # Step 1: Remove punctuation (.,!?)
        formattedText = text.replace('.', '').replace('!', '').replace('?', '').replace(',', '')
        
        # Step 2: Convert the entire text to lowercase to standardize
        formattedText = formattedText.lower()
        
        # Store the formatted text as an instance variable
        self.fmtText = formattedText

    # Method to calculate frequency of all unique words in the text
    def freqAll(self):        
        # Step 3: Split the formatted text into a list of words
        wordList = self.fmtText.split(' ')
        
        # Step 4: Create a dictionary to map each word to its frequency
        freqMap = {}
        for word in set(wordList):  # set() removes duplicates for efficiency
            freqMap[word] = wordList.count(word)  # count occurrences in original list
        
        # Return the dictionary of word frequencies
        return freqMap
    
    # Method to return the frequency of a specific word
    def freqOf(self, word):
        # Step 5: Call freqAll() to get full frequency map
        freqDict = self.freqAll()
        
        # Step 6: Return the frequency of the given word if it exists
        if word in freqDict:
            return freqDict[word]
        else:
            return 0

# String input to analyze (includes punctuation and mixed case)
givenstring = "Lorem ipsum dolor! diam amet, consetetur Lorem magna. sed diam nonumy eirmod tempor. diam et labore? et diam magna. et diam amet."

# Step 7: Create an instance of the TextAnalyzer class using the string
analyzed = TextAnalyzer(givenstring)

# Step 8: Print the formatted (cleaned and lowercase) text
print("Formatted Text:", analyzed.fmtText)

# Step 9: Print the frequency of all words in the cleaned text
freqMap = analyzed.freqAll()
print("All Word Frequencies:", freqMap)

# Step 10: Find the frequency of the specific word "lorem"
word = "lorem"
frequency = analyzed.freqOf(word)
print("The word", word, "appears", frequency, "times.")
