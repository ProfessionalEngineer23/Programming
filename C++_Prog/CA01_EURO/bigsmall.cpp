//Name: Niki Mardari
//ID: B00159642

#include <iostream>
#include <cfloat>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> currencies = {"USD", "JPY", "STG", "CNY", "RUB", "UAH"}; //Vector that stores currency strings, bank may need to add more currencies in the future!
vector<float>tracker; //Vector to track smallest and largest (euro) values

//Function1 to ensure a valid choice
int security_choice() {
int choice;
cout << "Enter 1 for to Euro conversion\nEnter 2 for from euro conversion to another currency\nEnter 1 or 2 only: ";
cin >> choice;
while (choice != 1 && choice != 2) { //While choice not 1 and not 2, the user will be asked to enter a valid choice
cout << "Invalid choice!\nPlease Enter 1 or 2 only: ";
cin >> choice;}
return choice;} //Returns int choice into the scope of our main function

//Function2 to ensure a valid amount
float security_amount() {
float amount;
cout <<"\nPlease enter amount value: \n";
cin >> amount;
while (amount <= 0 || amount >= FLT_MAX) { //While amount is less than 0 or more than float max value, then the user is warned and asked to enter a valid amount.
if (amount <= 0) { //If the amount is less than or equal to zero, no money can not get converted into money.
cerr <<"\nSorry the amount is too small!";} 
else { //If it's not less than or equal to zewro then it must be above float max value
cerr <<"\nSorry the amount is too big!";
}
cout <<"\nPlease enter a valid amount: ";
cin >> amount;}
return amount;} //Returns float amount into the scope of our main function

//Function3 to ensure a valid currency
string security_currency() {
string currency;
cout << "\nEnter what currecny your converting with:\n(Options: USD, JPY, STG, CNY, RUB, UAH)\nMake sure entered currencies are uppercase!\n";
cin >> currency;
while (find(currencies.begin(),currencies.end(),currency) == currencies.end()) //While currency does not equal to any string stored in vector; the currency is invalid.
{
cout << "Invalid currency! Please enter a valid code: ";
cin >> currency;}
return currency;} //Returns string of currency into the scope of our main function

// Function4: Converting Euro to another currency
float from_euro(float amount, float answer, string currency) {
// For loop that cycles through vector and stops at the string matching currencies string
for (int i = 0; i < currencies.size(); ++i) {
if (currency == currencies[i]) {
switch (i) {    
    case 0: answer = amount * 1.0424628;  break;  // For USD
    case 1: answer = amount * 157.91755;  break;  // For JPY
    case 2: answer = amount * 0.82821196; break;  // For STG
    case 3: answer = amount * 7.5925708;  break;  // For CNY
    case 4: answer = amount * 93.470998;  break;  // For RUB
    case 5: answer = amount * 43.411627;  break;  // For UAH
} } }
return answer;}

// Function5: Converting from foreign currency to euro
float to_euro(float amount, float answer, string currency) {
// For loop that cycles through vector and stops at the string matching currencies string
for (int i = 0; i < currencies.size(); ++i) {
if (currency == currencies[i]) {
switch (i) {
    case 0: answer = amount / 1.0424628;  break;  // For USD
    case 1: answer = amount / 157.91755;  break;  // For JPY
    case 2: answer = amount / 0.82821196; break;  // For STG
    case 3: answer = amount / 7.5925708;  break;  // For CNY
    case 4: answer = amount / 93.470998;  break;  // For RUB
    case 5: answer = amount / 43.411627;  break;  // For UAH
} } }
return answer;}

// Function6: To find keep track of smallest and largest (euro) value
void sorting(float amount)
{
    tracker.push_back(amount); //Pushes the amount value into tracker vector.
    sort(tracker.begin(), tracker.end()); //Sort tracker vector elements in ascending order.
    vector<float>::iterator found = find(tracker.begin(),tracker.end(), amount); //Find 'amount' value through beginning and end of tracker vector and assigns it to an itterator named 'found'
    if (found == tracker.begin()){cout << "The value entered is: " << amount << "\nCongratulations! \nThis is the smallest value entered so far.";}
    //If the iterator is equal to the value at the start of vector 'tracker' then it's the smallest value so far
    else if (found == tracker.end()-1){cout << "The value entered is: " << amount << "\nCongratulations! \nThis is the largest value entered so far.";}
    //If the iterator is equal to the second last value of the vector 'tracker' then it's the largest value so far
}

/* Start of main function.
The main function asks if the user is converting to or from Euros which determines whether to use to_euro or from_euro (conversion functions).  
The user is asked for an amount and a currency input, which are passed to the conversion functions. In the end, the user is asked if they want 
to try again?
*/

int main() {
int again;
do {
int choice = security_choice(); //Choice gets defined after input passes security
float amount = security_amount(); //Amount gets defined after security
sorting(amount); 
string currency = security_currency(); //
if (choice == 1) {
float answer = to_euro(amount, 0, currency); // Converts to Euro
cout << amount <<" "<< currency <<" is "<< answer <<" in Euros.\n";} 
else if (choice == 2) {
float answer = from_euro(amount, 0, currency); // Converts from Euro
cout << amount <<" Euros is "<< answer <<" in "<< currency <<".\n";}
// Loop to validate input for "Try again?" question
do {
cout << "\nWould you like to convert more?\n1 for yes\n0 for no: ";
cin >> again;
if (again != 1 && again != 0) {
cout << "Invalid choice! Please enter 1 for yes or 0 for no.\n";}
} 
while (again != 1 && again != 0); // Repeat if input is not 1 or 0
} 
while (again == 1); //Repeats as long as int again is the same as 1 
return 0;
}

// To Do:

//Done:

//Maybe use a vector to store Currencies and then get their sizes and use that value in Switch cases - It workds X
//Need to convert functions to float and pass in an Answer variable! X
//Need to prevent users from entering negative values! X
//Only have cout in main for conversion functions X
//Replace do whiles with verficaation functions like in an airport X
//Convert largest/smallest into a function... X
//Clean up comments! X

/*
<==Sources==>
Website used for conversion: https://www.xe.com/currencyconverter/convert/?Amount=1&From=EUR&To=UAH
Had to look up: https://www.w3schools.com/cpp/cpp_iterators.asp - Helped me figure out how to find certain values in a vector
*/
