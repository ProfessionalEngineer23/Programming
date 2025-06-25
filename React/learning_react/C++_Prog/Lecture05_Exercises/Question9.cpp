//Name: Niki Mardari
//Student ID: B00159642

#include <iostream>
#include <vector>
using namespace std;

vector<int>v1;

int main()
{
    int N, values, sum=0;
    cout << "\nEnter int values: " << endl;
    while (cin >> values){v1.push_back(values);}

    cin.clear();  //Clears error message 
    cin.ignore(10000, '\n');  //ignores up to 10000 letters entered into values until a newline.
    
    cout << "\nHow many lines to sum? \nEnter number: ";
    cin >> N;
    //Need to give an error meassage if the input is not a number!
    
    else{
    for (int i=0; i < N; ++i){
    cout<<v1[i]<< " ";
    //sum adds each element of the vector up to 'N'. Cycled by the for loop
    sum += v1[i];
    }
    cout << "\nThe sum is: " << sum;
    }
    return 0;
}

//Save Everything!
/*==SOURCES==
https://www.geeksforgeeks.org/cin-ignore-function-in-cpp/ - Helped me understand lines 12 and 13
*/