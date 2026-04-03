# Java_CA2_Fuel_Efficiency
Github repository for collaborative work during the Java &amp; Algorithms CA2

---

## Introduction:

I keep a file with details of my car's mileage. Whenever I fill up with petrol I enter the odometer reading (the total km the car has travelled) and the amount of petrol (in litres) 
I've just bought, beside each other on a single line. 
A sample of the text file’s contents might look as follows. 
NB I always fill my tank right to the top. 
However, I am a careless record keeper – the readings are not necessarily in increasing date order! 

## Project Requirements:

### Functional Requirements

- User must run the program with a command and filename
- Read mileage data from a file (parsing)
- Store the data in a suitable data structure
- Include suitable exception handling (file opening/closing errors)
- Read each entry from the file
- Calculate fuel efficiency for each fill
- Store the calculated results
- Calculate minimum, maximum, and average efficiency
- Perform the statistical calculations in a separate thread

### Non-Functional Requirements

- The program should be memory-efficient and modular
- Java code should be properly formatted and indented (e.g., using `astyle`)

---

---
# The Big picture
<img src="images/example.png" width="500" />

# Design
## UML Class Diagram
Below is a Class Diagram representing all currently accounted for classes and their members/methods:
<img src="images/UML_Class_Diagram.png" width="800" />

## Hand-Drawn UML Class Diagram
Below is the hand drawn version of the UML Class diagram requested by the professor at the start of the next Lab session:
	<img src="images/UML_Class_diagram_HandDrawn.png" width="800" />

## High-Level Activity Diagram
The activity diagram shown below describes the functional flow of the program.
It illustrates the overall sequence of operations without defining the internal implementation details of each method.
	<img src="images/UML_Activity_Diagram_HighLvl.png" width="800" />

A lower-level activity diagram is currently being developed. This diagram will include explicit method calls and detailed internals to complement the high-level overview shown above.

**TODO:** 
- [ ] Description of the program design and reasoning behind it.  
- [ ] Create **Low-Level Activity Diagram** including method calls and their definitions.
- [ ] Add the **Hand drawn Activity Diagram** requested by the professor.
- [ ] Implement a **Test Harness** for the program including definitions for expected inputs and outputs of each test.
- [ ] Include UML diagrams where appropriate.


## Ideas: 
The program may:

- Sort records by date
- Calculate fuel efficiency (L/100km)
- Compute minimum, maximum, and average efficiency
- Perform statistical calculations in a separate thread
- Include proper exception handling
- Be modular and memory-efficient


## Build
**TODO:** 
Brief description of any notable coding features or implementation details used in the program.

## Results and Discussion
**TODO:** 
Presentation and discussion of test results that were introduced in the requirements section.
