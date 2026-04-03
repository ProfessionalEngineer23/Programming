# Makefile for CA3 Tail program

# Usage:
# make all: compiles java and runs on all txt files
# make compile: makes bin dir and "javacs" all ca3 java files
# make run-harness: runs TailTestHarness
# make run-tests:  Copies all data txt files specified 
# make clean: removes all .class files in bin directory

# Directories
SRC = src
BIN = bin
DATA = data
MAIN = Tail1
HARNESS = TailTestHarness
# make all 
all: compile
	make run-tests > Testing.txt

# Compile CA3 Java files, automatically creates bin folder if it doesn't exist
compile:
	mkdir -p $(BIN)
	javac -d $(BIN) \
	$(SRC)/Tail1.java \
	$(SRC)/TailTestHarness.java
	echo "Compiled!"
# If want to compile any java file then uncomment:
# javac -d $(BIN) $(wildcard $(SRC)/*.java)

# To run program with harness code
run-harness: compile
	java -cp $(BIN) $(HARNESS) $(DATA)
	echo "Testing!"

# To run program with all test files
run-tests: compile

	echo ""
	echo "Running sample.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/sample.txt
	echo ""

	echo "Running 1Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/1Kints.txt
	echo ""

	echo "Running 2Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/2Kints.txt
	echo ""

	echo "Running 4Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/4Kints.txt
	echo ""

	echo "Running 8Kints.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/8Kints.txt
	echo ""

	echo "Running largeT.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/largeT.txt
	echo ""

	echo "Running largeW.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/largeW.txt
	echo ""

	echo "Running medTale.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/medTale.txt
	echo ""

	echo "Running MobyDick.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/MobyDick.txt
	echo ""

	echo "Running tinyT.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinyT.txt
	echo ""

	echo "Running tinyTale.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinyTale.txt
	echo ""

	echo "Running tinytinyTale.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinytinyTale.txt
	echo ""

	echo "Running tinyW.txt"
	java -cp $(BIN) $(MAIN) 20 < $(DATA)/tinyW.txt
# for file in $(DATA)/*.txt; do \
# echo "Running $$file"; \
# java -cp $(BIN) $(MAIN) $$file; \
# echo ""; \
# done

# remove compiled class files
clean:
	rm -f $(BIN)/*.class