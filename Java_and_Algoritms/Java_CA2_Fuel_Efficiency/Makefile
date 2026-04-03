# Makefile for CA2 car mileage

# Usage:
# make all: compiles java and runs on all txt files
# make compile: makes bin dir and "javacs" all ca2 java files
# make run-harness: runs MileageTestHarness
# make run-tests:  Copies all data txt files specified 
# make clean: removes all .class files in bin directory

# Directories
SRC = src
BIN = bin
DATA = data
MAIN = Mileage
HARNESS = MileageTestHarness
# make all 
all: compile
	make run-tests > Testing.txt

# Compile CA2 Java files, automatically creates bin folder if it doesn't exist
compile:
	mkdir -p $(BIN)
	javac -d $(BIN) \
	$(SRC)/EfficiencyStatsTask.java \
	$(SRC)/Mileage.java \
	$(SRC)/MileageRecord.java \
	$(SRC)/MileageTestHarness.java
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
	echo "Running mileage_tiny.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/mileage_tiny.txt
	echo ""

	echo "Running mileage_4months.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/mileage_4months.txt
	echo ""

	echo "Running mileage_15months.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/mileage_15months.txt
	echo ""

	echo "Running mileage_10years.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/mileage_10years.txt
	echo ""

	echo "Running empty.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/empty.txt
	echo ""

	echo "Running mileage_uno.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/mileage_uno.txt
	echo ""

	echo "Running negative_distance.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/negative_distance.txt
	echo ""

	echo "zero_distance.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/zero_distance.txt
	echo ""	

	echo "blank_lines_mileage.txt"
	java -cp $(BIN) $(MAIN) $(DATA)/blank_lines_mileage.txt
	echo ""	
	
# Later if any text file testing is needs testing use for loop in shell
# run-all: compile
# for file in $(DATA)/*.txt; do \
# echo "Running $$file"; \
# java -cp $(BIN) $(MAIN) $$file; \
# echo ""; \
# done

# remove compiled class files
clean:
	rm -f $(BIN)/*.class
