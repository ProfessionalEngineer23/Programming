//Name: Niki Mardari
//ID: B00159642
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include<assert.h>

using namespace std;

class Bad_number { };
class Bad_currency { };

//Function from euro to foreign currency
float from_euro(float amount, string currency)
{
if (amount < 0 || amount >= 3.40282e+38) {throw Bad_number();}
else if (currency != "USD" && currency != "JPY" && currency != "STG" && currency != "CNY" && currency != "RUB" && currency != "UAH")
{throw Bad_currency();}
return 1.0;
}
//Converting from foreign currency to euro
float to_euro(float amount, string currency)
{
if (amount < 0 || amount >= 3.40282e+38) {throw Bad_number();}
else if (currency != "USD" && currency != "JPY" && currency != "STG" && currency != "CNY" && currency != "RUB" && currency != "UAH")
{throw Bad_currency();}
return 2.0;
}
int main ()
{
float amount;
string currency;
cout << endl << "Float limits are: " << FLT_MIN << " to " << FLT_MAX << endl << endl;
/*
cout << "\nPlease enter amount value: \n";
cin >> amount;
assert(amount > 0 && amount <= 3.40282e+38);
*/
try{
cout << fixed << setprecision(2) << from_euro(3.22,"USD") << endl;
cout << fixed << setprecision(2) << from_euro(3.402823263e+37,"USD") << endl;

cout << fixed << setprecision(2) << from_euro(0.001,"JPY") << endl;
cout << fixed << setprecision(2) << from_euro(1.17,"JPY") << endl;

cout << fixed << setprecision(2) << from_euro(0.967,"STG") << endl;
cout << fixed << setprecision(2) << from_euro(49.99,"STG") << endl;

cout << fixed << setprecision(2) << from_euro(92113.51,"CNY") << endl;
cout << fixed << setprecision(2) << from_euro(89.6345,"CNY") << endl;

cout << fixed << setprecision(2) << from_euro(111,"RUB") << endl;
cout << fixed << setprecision(2) << from_euro(2323,"RUB") << endl;

cout << fixed << setprecision(2) << from_euro(2056,"UAH") << endl;
cout << fixed << setprecision(2) << from_euro(0.00000101,"UAH") << endl << endl; //Finished with from_euro

cout << fixed << setprecision(2) << to_euro(3.14,"USD") << endl;
cout << fixed << setprecision(2) << to_euro(3.40282e+34,"USD") << endl;

cout << fixed << setprecision(2) << to_euro(0.69,"JPY") << endl;
cout << fixed << setprecision(2) << to_euro(1.17549e-33,"JPY") << endl;

cout << fixed << setprecision(2) << to_euro(100.11,"STG") << endl;
cout << fixed << setprecision(2) << to_euro(99.99,"STG") << endl;

cout << fixed << setprecision(2) << to_euro(1.667,"CNY") << endl;
cout << fixed << setprecision(2) << to_euro(404.44,"CNY") << endl;

cout << fixed << setprecision(2) << to_euro(5000000,"RUB") << endl;
cout << fixed << setprecision(2) << to_euro(1916.61,"RUB") << endl;

cout << fixed << setprecision(2) << to_euro(43.41,"UAH") << endl;
cout << fixed << setprecision(2) << to_euro(2048,"UAH") << endl << endl; //Finished with to_euro
}
catch(Bad_number){cerr << "\nThe value entered is above or below the limits!\n";return 3;}
catch(Bad_currency){cerr << "\nThe currency entered not a specified one!\n";return 4;}
cout << "All numbers are within range. Test Successful!\nAll currencies are specified. Test Successful!";
return 0;
}