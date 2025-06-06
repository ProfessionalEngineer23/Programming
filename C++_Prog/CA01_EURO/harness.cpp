//Name: Niki Mardari
//ID: B00159642

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cfloat>
#include <assert.h>
#include <vector>


using namespace std;

class Bad_number { };

vector<string> currencies = {"USD","JPY","STG","CNY","RUB","UAH"}; //Vector that stores currency strings, maybe use a fixed size array!
//Function from euro to foreign currency 
float from_euro(float amount, string currency)
{
float answer;
//if (amount < 0 || amount > FLT_MAX) {throw Bad_amount();}
for (int i = 0; i < currencies.size(); ++i)             
{
if (currency == currencies[i]){
switch (i){
    
    case 0:
    answer = amount*1.0424628;
    cout <<"\n€"<< amount << " in Dollars is: ";
    break;
    
    case 1:
    answer = amount*157.91755;
    cout <<"\n€"<< amount << " in Japanese Yen is: ";
    break;
    
    case 2:
    answer = amount*0.82821196;
    cout <<"\n€"<< amount << " in Pounds Sterling is: ";
    break;
    
    case 3:
    answer = amount*7.5925708;
    cout <<"\n€"<< amount << " in Chinese Yuan is: ";
    break;
    
    case 4:
    answer = amount*93.470998;
    cout <<"\n€"<< amount << " in Russian Rubles is: ";
    break;

    case 5:
    answer = amount*43.411627;
    cout <<"\n₴"<< amount << " in Ukrainian Hryvni is ";
    break;

    default: 
    cout << "Sorry, no such currency in stock yet!";
}   }  }
return answer;
}

//Converting from foreign currency to euro
float to_euro(float amount, string currency) 
{
float answer = 0;
//if (amount < 0 || amount > FLT_MAX) {throw Bad_amount();}
for (int i = 0; i < currencies.size(); ++i) //For loop that cycles through vector 
{
if (currency == currencies[i]){
switch (i){
    
    case 0:
    answer = amount/1.0424628;
    cout <<"\n$"<< amount << " is " << answer << " in Euros ";
    break;

    case 1:
    answer = amount/157.91755;
    cout <<"\n¥"<< amount << " is " << answer << " in Euros ";
    break;

    case 2:
    answer = amount/0.82821196;
    cout <<"\n£"<< amount << " in Euros is: ";
    break;

    case 3:
    answer = amount/7.5925708;
    cout << "\nCN¥" << amount << " in Euros is: ";
    break;
    
    case 4:
    answer = amount/93.470998;
    cout << "\n₽" << amount << " in Euros is: ";
    break;

    case 5:
    answer = amount/43.411627;
    cout << "\n₴" << amount << " in Euros is: ";
    break;

    default: 
    cout << "Sorry, no such currency in stock yet!";
}   }   }                            
return answer;
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
    cout << fixed << setprecision(6) << from_euro(3.22,"USD") << endl; 
    //cout << fixed << setprecision(2) << from_euro(23000,"USD") << endl; 

    cout << fixed << setprecision(6) << from_euro(0.001,"JPY") << endl;
    //cout << fixed << setprecision(2) << from_euro(300,"JPY") << endl;

    cout << fixed << setprecision(6) << from_euro(0.967,"STG") <<  endl;
    //cout << fixed << setprecision(2) << from_euro(49.99,"STG") <<  endl;

    cout << fixed << setprecision(6) << from_euro(92113.51,"CNY") << endl;
    //cout << fixed << setprecision(2) << from_euro(89.6345,"CNY") << endl; 

    cout << fixed << setprecision(6) << from_euro(111,"RUB") << endl;
    //cout << fixed << setprecision(2) << from_euro(2323,"RUB") << endl; 

    cout << fixed << setprecision(6) << from_euro(2056,"UAH") << endl;
    //cout << fixed << setprecision(2) << from_euro(0.0101,"UAH") << endl << endl; //Finished with from_euro

    cout << fixed << setprecision(6) << to_euro(3.14,"USD") << endl; 
    //cout << fixed << setprecision(2) << to_euro(5,"USD") << endl; 

    cout << fixed << setprecision(6) << to_euro(0.69,"JPY") << endl;
  //  cout << fixed << setprecision(2) << to_euro(1000,"JPY") << endl;

    cout << fixed << setprecision(6) << to_euro(25,"STG") <<  endl;
   // cout << fixed << setprecision(2) << to_euro(99.99,"STG") <<  endl;

    cout << fixed << setprecision(6) << to_euro(1.667,"CNY") << endl;
    //cout << fixed << setprecision(2) << to_euro(404.44,"CNY") << endl;

    cout << fixed << setprecision(6) << to_euro(5000000,"RUB") << endl;
   // cout << fixed << setprecision(2) << to_euro(1916.61,"RUB") << endl;

    cout << fixed << setprecision(8) << to_euro(43.41,"UAH") << endl;
   // cout << fixed << setprecision(2) << to_euro(2048,"UAH") << endl << endl; //Finished with to_euro
    }
    catch(Bad_number){cerr << "\nThe value entered is above or below the limits!\n";}

    return 0;
}