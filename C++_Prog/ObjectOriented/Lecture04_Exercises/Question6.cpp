//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double mean(vector<double> &temperature)
{   double sum = 0;
    for (int i=0; i<temperature.size(); ++i){
        cout<<temperature[i]<< "\n";
        //sum adds each element of the vector. Cycled by the for loop
        sum += temperature[i];
        }
        //mean declared and initialized
        double mean = sum/temperature.size();
        cout << "\nThe mean is: " << mean;
        return mean;
}

double median(vector<double> &temperature)
{
    sort(temperature.begin(), temperature.end());
    if (temperature.size() % 2 == 0) //If the size of the vector divided by 2 leaves a remaineder of 0. It is even.
    {
    //Adds two middle values and divides them by 2
    cout << "\nThe median temperature is: " << ((temperature[(temperature.size()/2)-1]+temperature[temperature.size()/2])/2);
    return ((temperature[(temperature.size()/2)-1]+temperature[temperature.size()/2])/2); 
    }

    else {cout << "\nThe median temperature is: "<< temperature[(temperature.size())/2] << endl;
    //else {cout << "\nThe median temperature is: "<< temperature[(temperature.size()-1)/2] << endl;
    return temperature[((temperature.size()-1)/2)]; //Turns number of elements into an even number and divides by 2
    } //Else it is odd.
}

int main()
{
vector<double> temperature;
double value;
cout << "Enter temperature values:";
while (cin >> value){
//While value gets values, keep adding the values into the vector array.
temperature.push_back(value);
} 
mean(temperature);
median(temperature);
return 0;
}