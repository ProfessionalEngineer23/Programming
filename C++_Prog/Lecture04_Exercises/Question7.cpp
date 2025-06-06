//Name: Niki Mardari 
//Student ID: B00159642

#include <iostream>
using namespace std;

int main() {
int number, response;
cout << "This program will guess a your number between 0 and 100.\nAnswer 1 for Yes and 0 for No.\nIs the number >= 50?";
cin >> response;

if (response == 1) //The number is >= 50
{
cout << "\nIs the number >= 75?";
cin >> response;
if (response == 1) //The number is >= 75
{
cout << "\nIs the number >= 88?";
cin >> response;
if (response == 1) //The number is >= 88
{
cout << "\nIs the number >= 94?";
cin >> response;
if (response == 1) //The number is >= 94
{
cout << "\nIs the number >= 97?";
cin >> response;
if (response == 1) //The number is >= 97
{
cout << "\nIs the number >= 99?";
cin >> response;
if (response == 1) //The number is >= 99
{
cout << "\nIs the number 100?";
cin >> response;
if (response == 1)
cout << "\nThe number is 100";
else
cout << "\nThe number is 99";
}
else //The number is 97 or 98
{
cout << "\nIs the number 98?";
cin >> response;
if (response == 1)
cout << "\nThe number is 98";
else
cout << "\nThe number is 97";
}}

else //The number is 94, 95, or 96
{
cout << "\nIs the number >= 95?";
cin >> response;
if (response == 1)
{
cout << "\nIs the number 96?";
cin >> response;
if (response == 1)
cout << "\nThe number is 96";
else
cout << "\nThe number is 95";
}
else
cout << "\nThe number is 94";
}}

else //The number is 88-93
{
cout << "\nIs the number >= 91?";
cin >> response;
if (response == 1)
{
cout << "\nIs the number >= 92?";
cin >> response;
if (response == 1)
cout << "\nThe number is 93";
else
cout << "\nThe number is 91 or 92";
}
else //The number is 88-90
{
cout << "\nIs the number >= 89?";
cin >> response;
if (response == 1)
cout << "\nThe number is 89 or 90";
else
cout << "\nThe number is 88";
}}}

else //The number is 75-87
{
cout << "\nIs the number >= 81?";
cin >> response;
if (response == 1) //The number is 81-87
{
cout << "\nIs the number >= 84?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 84 and 87";
else
cout << "\nThe number is between 81 and 83";
}
else //The number is 75-80
{
cout << "\nIs the number >= 78?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 78 and 80";
else
cout << "\nThe number is between 75 and 77";
}}}

else //The number is 50-74
{
cout << "\nIs the number >= 62?";
cin >> response;
if (response == 1) //The number is 62-74
{
cout << "\nIs the number >= 68? ";
cin >> response;
if (response == 1)
cout << "\nThe number is between 68 and 74";
else
cout << "\nThe number is between 62 and 67";
}
else //The number is 50-61
{
cout << "\nIs the number >= 56?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 56 and 61";
else
cout << "\nThe number is between 50 and 55";
}}}

else if (response == 0) //The number is < 50
{
cout << "\nIs the number >= 25?";
cin >> response;
if (response == 1) //The number is 25-49
{
cout << "\nIs the number >= 37?";
cin >> response;
if (response == 1) //The number is 37-49
{
cout << "\nIs the number >= 43?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 43 and 49";
else
cout << "\nThe number is between 37 and 42";
}
else //The number is 25-36
{
cout << "\nIs the number >= 31?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 31 and 36";
else
cout << "\nThe number is between 25 and 30";
}
}
else //The number is 1-24
{
cout << "\nIs the number >= 13?";
cin >> response;
if (response == 1) //The number is 13-24
{
cout << "\nIs the number >= 19?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 19 and 24";
else
cout << "\nThe number is between 13 and 18";
}
else //The number is 1-12
{
cout << "\nIs the number >= 7?";
cin >> response;
if (response == 1)
cout << "\nThe number is between 7 and 12";
else
cout << "\nThe number is between 1 and 6";
}}}
return 0;}