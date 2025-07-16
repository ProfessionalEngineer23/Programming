# Write line to file
exmp2 = 'example2.txt'
with open(exmp2, 'w') as writefile:
    writefile.write("This is line A")

# Read file to see if it worked
with open(exmp2, 'r') as testwritefile:
    print(testwritefile.read())

# Write lines to file
with open(exmp2, 'w') as writefile:
    writefile.write("This is line A\n")
    writefile.write("This is line B\n")

# Check whether write to file
with open(exmp2, 'r') as testwritefile:
    print(testwritefile.read())

# Sample list of text
Lines = ["This is line A\n", "This is line B\n", "This is line C\n"]

# Write the strings in the list to text file
with open('example2.txt', 'w') as writefile:
    for line in Lines:
        print(line)
        writefile.write(line)

# Verify if writing to file is successfully executed
with open('example2.txt', 'r') as testwritefile:
    print(testwritefile.read())

with open('example2.txt', 'w') as writefile:
    writefile.write("Overwrite\n")
with open('example2.txt', 'r') as testwritefile:
    print(testwritefile.read())

# Write a new line to text file without losing any of the existing data
with open('example2.txt', 'a') as testwritefile:
    testwritefile.write("This is line C\n")
    testwritefile.write("This is line D\n")
    testwritefile.write("This is line E\n")

# Verify if the new line is in the text file
with open('example2.txt', 'r') as testwritefile:
    print(testwritefile.read())

# r+ : Reading and writing. Cannot truncate the file.
# w+ : Writing and reading. Truncates the file.
# a+ : Appending and Reading. Creates a new file, if none exists. 

# a+ mode (Appending and reading)
with open('example2.txt', 'a+') as testwritefile:
    testwritefile.write("This is line E\n")
    print(testwritefile.read())

# .tell() - returns the current position in bytes
# .seek(offset,from) - changes the position by 'offset' bytes with respect to 'from'. 
# From can take the value of 0,1,2 corresponding to beginning, relative to current position and end

with open('example2.txt', 'a+') as testwritefile:
    print("Initial Location: {}".format(testwritefile.tell()))
    
    data = testwritefile.read()
    if (not data):  #empty strings return false in python
            print('Read nothing') 
    else: 
            print(testwritefile.read())
            
    testwritefile.seek(0,0) # move 0 bytes from beginning.
    
    print("\nNew Location : {}".format(testwritefile.tell()))
    data = testwritefile.read()
    if (not data): 
            print('Read nothing') 
    else: 
            print(data)
    
    print("Location after read: {}".format(testwritefile.tell()) )

    with open('example2.txt', 'r+') as testwritefile:
        testwritefile.seek(0,0) #write at beginning of file
        testwritefile.write("Line 1" + "\n")
        testwritefile.write("Line 2" + "\n")
        testwritefile.write("Line 3" + "\n")
        testwritefile.write("Line 4" + "\n")
        testwritefile.write("finished\n")
        testwritefile.seek(0,0)
        print(testwritefile.read())

with open('example2.txt', 'r+') as testwritefile:
    testwritefile.seek(0,0) #write at beginning of file
    testwritefile.write("Line 5" + "\n")
    testwritefile.write("Line 6" + "\n")
    testwritefile.write("Line 7" + "\n")
    testwritefile.write("Line 8" + "\n")
    testwritefile.write("finished\n")
    #Uncomment the line below
    testwritefile.truncate()
    testwritefile.seek(0,0)
    print(testwritefile.read())
    
# Copy file to another
with open('example2.txt','r') as readfile:
    with open('example3.txt','w') as writefile:
          for line in readfile:
                writefile.write(line)

# Verify if the copy is successfully executed
with open('example3.txt','r') as testwritefile:
    print(testwritefile.read())