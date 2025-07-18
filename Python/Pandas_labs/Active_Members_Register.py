# Importing randint from random and renaming it as rnd for shorter usage
from random import randint as rnd

# File names for current members and inactive members
memReg = 'members.txt'
exReg = 'inactive.txt'

# Tuple representing whether a member is active ('yes') or inactive ('no')
fee = ('yes', 'no')

# Function to generate random membership files
def genFiles(current, old):
    # Open or create the current members file for writing and reading
    with open(current, 'w+') as writefile:
        writefile.write('Membership No  Date Joined  Active  \n')  # header line
        data = "{:^13}  {:<11}  {:<6}\n"  # format for each member entry

        for rowno in range(20):  # generate 20 random active/inactive members
            date = str(rnd(2015, 2020)) + '-' + str(rnd(1, 12)) + '-' + str(rnd(1, 25))
            writefile.write(data.format(rnd(10000, 99999), date, fee[rnd(0, 1)]))

    # Open or create the inactive members file
    with open(old, 'w+') as writefile:
        writefile.write('Membership No  Date Joined  Active  \n')  # header line
        data = "{:^13}  {:<11}  {:<6}\n"

        for rowno in range(3):  # add 3 known inactive members
            date = str(rnd(2015, 2020)) + '-' + str(rnd(1, 12)) + '-' + str(rnd(1, 25))
            writefile.write(data.format(rnd(10000, 99999), date, fee[1]))  # fee[1] = 'no'

# Generate files
genFiles(memReg, exReg)

# Function to clean out inactive members from the current file and append them to the inactive file
def cleanFiles(currentMem, exMem):
    with open(currentMem, 'r+') as writeFile:
        with open(exMem, 'a+') as appendFile:
            writeFile.seek(0)
            members = writeFile.readlines()  # read all lines

            header = members[0]  # keep the header
            members.pop(0)  # remove header from list

            # List of inactive members (those with 'no' in their line)
            inactive = [member for member in members if 'no' in member]

            # Reset write file and write only active members
            writeFile.seek(0)
            writeFile.write(header)  # write header again

            for member in members:
                if member in inactive:
                    appendFile.write(member)  # move inactive to other file
                else:
                    writeFile.write(member)  # keep active in current file

            writeFile.truncate()  # remove leftover old lines

# Clean the original files
cleanFiles(memReg, exReg)

# Print the current active members
with open(memReg, 'r') as readFile:
    print("Active Members: \n\n")
    print(readFile.read())

# Print the current inactive members
with open(exReg, 'r') as readFile:
    print("Inactive Members: \n\n")
    print(readFile.read())

# Function to return pass/fail messages for testing
def testMsg(passed):
    if passed:
        return 'Test Passed'
    else:
        return 'Test Failed'

# Testing file names
testWrite = "testWrite.txt"
testAppend = "testAppend.txt"
passed = True  # Assume test passes unless conditions fail

# Generate new test files
genFiles(testWrite, testAppend)

# Read original data
with open(testWrite, 'r') as file:
    ogWrite = file.readlines()

with open(testAppend, 'r') as file:
    ogAppend = file.readlines()

# Try to clean files (move inactive members)
try:
    cleanFiles(testWrite, testAppend)
except:
    print('Error')

# Read data after cleaning
with open(testWrite, 'r') as file:
    clWrite = file.readlines()

with open(testAppend, 'r') as file:
    clAppend = file.readlines()

# Validate total number of lines is the same
if (len(ogWrite) + len(ogAppend) != len(clWrite) + len(clAppend)):
    print("The number of rows do not add up. Make sure your final files have the same header and format.")
    passed = False

# Check for any remaining inactive members in cleaned file
for line in clWrite:
    if 'no' in line:
        passed = False
        print("Inactive members in file")
        break
    else:
        if line not in ogWrite:
            print("Data in file does not match original file")
            passed = False

# Final test result
print("{}".format(testMsg(passed)))
