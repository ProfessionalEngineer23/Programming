#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class randNum
{
    public:
    int number;
    string wordle;
};

int main()
{
    vector<string> wordles = {"rebus" , "siege" , "banal" , "gorge" , "query" , "abbey" , "proxy" , "aloft"};

    srand(time(0));  // Seed random number generator

    randNum dice;
    dice.number = rand() % wordles.size();
    dice.wordle = wordles[dice.number];


cout << "The wordle is " << dice.wordle << "\nThe random number is " << dice.number;


return 0;
}