    //Name: Niki Mardari
    //Student ID: B00159642
    // Converting Degrees Celsius to degrees Fahrenheit

    #include <iostream>
    using namespace std;

    //Funtion to convert degrees Celsius to degrees Fahrenheit
    void conversion()
    { 
    double val, result;
    cout << "Please input degrees celsius\n";
    while (cin >> val)  {
    
    //Celsius to Fahrenheit calculation
    result = val*(1.8)+32;  
    cout << result;
    }
    }

    int main() {
    conversion(); 
    return 0;}
