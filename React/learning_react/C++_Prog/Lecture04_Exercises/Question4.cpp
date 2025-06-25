//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
vector<double> distance; //Vector to store distances.
double s, sum; //s is the variable for the distance value, sum is a variable to store the summation.

cout << "Enter distances:";
while (cin>>s && s>0) { 
//While s gets values and the value is not a zero, keep adding the values into the vector array.
distance.push_back(s);
}
sort(distance.begin(), distance.end());

//distance.back() gets the last element of the vector
double last = distance.back(), mean;

for (int i=0; i<distance.size(); ++i){
cout<<distance[i]<< "\n";
//sum adds each element of the vector. Cycled by the for loop
sum += distance[i];
}
//mean initialized
mean = sum/distance.size();
cout << "\nThe total distance is: " << sum << "\nThe smallest distance is: " << distance[0] << "\nThe greatest distance is: " << last
<< "\nThe mean is: " << mean;
return 0;
}