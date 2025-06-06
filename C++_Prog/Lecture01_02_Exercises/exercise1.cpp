//Lecture 01-02 Exercises 
//Programmer: Niki Mardari
//Student Id: B00159642

#include <iostream>
#include <iomanip> // For fixed, setprecision and other manipulator functions
#include <string> //For getting length of string in case 7 
#include <cstring> //Used for strlen() in case 7
#include <vector>
using namespace std;

//Function to add 3 double(float) numbers and return the sum
double sum(double Number1, double Number2, double Number3){return Number1+Number2+Number3;}

int main(){
int decision = 1, number;	
do{ cout<<"Options:\nExercise 2.1: (1)\nExercise 2.2: (2)\nExercise 2.3: (3)\nExercise 2.4: (4)\nExercise 2.5: (5)\nExercise 2.6: (6)\nExercise 2.7: (7)\nExercise 2.8: (8)\n\nPlease enter a selection number\nbetween 1 and 8:";
    cin >> number;
    
switch(number){
	case 1:{
	cout<<"Hello World!";
	break;}
	
	case 2:{
	cout<<"2/5="<<2/5<<endl; //The answer is 0 becasause the numbers are stored as integers and the remainder is truncated.
	break;}
	
	case 3:{
	cout<<"2.0/5.0 = "<<2.0/5.0<<endl; //The answer is 0.4 because the numbers are floats and the answer is a float.
	break;}
	
	case 4:{
	char name[747]; //Longest name was 747 letters, according to Quora
    //string name;
	cout<<"Please enter your name:";
	cin>>name;
	cout<<endl<<"Hello "<< name;
	break;}
	
	case 5:{
	double number1, number2, number3;
	cout<<"Please input 3 double float numbers;"<<endl<<"number1:";
	cin>>number1;
    cout<<"number2:"<<endl;
    cin>>number2;
    cout<<"number3:"<<endl;
    cin>>number3;
    cout << fixed << setprecision(6); //To 6 decimal places
    cout<<endl<<"The sum is: "<<(number1+number2+number3);
	break;}
	
	case 6:{
	double Number1, Number2, Number3;
	cout<<"Please input 3 double float numbers;"<<endl<<"Number1:";
	cin>>Number1;
    cout<<"Number2:"<<endl;
    cin>>Number2;
    cout<<"Number3:"<<endl;
    cin>>Number3;
    cout << fixed << setprecision(6);  //To 6 decimal place
    cout<<endl<<"The sum is: "<<sum(Number1,Number2,Number3); //Call sum function
	break;}

//cout << sum(sum(a+b),c)

    case 7:{
    char wordle[50];
    string str;
    cout<<"Please enter the wordle of the day:";
    cin>>wordle;
    cout<<"Please enter the string:";
    cin>>str;
    cout<<endl<<"The wordle "<<wordle<<" has "<< strlen(wordle) <<" letters."<<endl;
    cout<<"The size of the entered string ("<<str<<") is: "<<str.length()<<" bytes.";
    break;}
    //strlen() counts up to the null terminator(\o) in arrays.
    //str.length()/str.size() counts all the characters of the string only.
    
    case 8:{
    char middle[747];
    string vorname;
    string family;
    cout<<"Please enter the first name:";
    cin>>vorname;
    cout<<"Please enter the middle name:";
    cin>>middle;
    cout<<"Please enter the surname:";
    cin>>family;
    vorname += ' ';
    vorname += middle[0];      
    vorname += '.';	
    vorname += ' ';
    vorname += family;      
    vorname += '\n';
    cout <<endl<<"Hello "<<vorname;
    break;}
    
    default: {cout<<"Wrong input, please try again!";break;}
}

do{
cout<<endl<<endl<<"Try again? Enter 1 for yes and 0 for no:";
cin>>decision;}
while(decision>1||decision<0);
}
while(decision!=0);
return 0;
}
/*==Sources==
case 5 and 6: https://www.geeksforgeeks.org/precision-of-floating-point-numbers-in-c-floor-ceil-trunc-round-and-setprecision/ -Helped me learn how to cout to specific decimal places in C++
case 7: https://cplusplus.com/reference/string/string/length/ -Helped me figure out how to get string lengths in C++
case 8: https://cplusplus.com/reference/string/string/operator+=/ -Helped me learn about addition assignment in C++
*/