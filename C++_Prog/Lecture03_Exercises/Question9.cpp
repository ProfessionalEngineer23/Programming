    //Name: Niki Mardari
    //Student ID: B00159642
    // Converting Celsius to Fahrenheit or Fahrenheit to Celsius

    #include <iostream>
    using namespace std;

    //Funtion to converting Celsius to Fahrenheit and Fahrenheit to Celsius
    float convfc(double val, double result1, double result2, char unit) 
    { 
    
    cout << "Please input a number value followed by 'C' for Fahrenheit to Celsius conversion or 'F' for Celsius to Fahrenheit conversion:\n";
    while (cin >> val >> unit)  {
    result1 = val*(1.8)+32;  //Celsius to Fahrenheit calculation
    result2 = (val-32)*1.8; //Fahrenheit to Celsius calculation
    if (unit == 'C' || unit == 'c') {cout << val << " Fahrenheit == " << result1 << " \n";} 
    else if (unit == 'F' || unit == 'f') {cout << val << " Celsius == " << result2 << " \n";} 
    else {cout << "Invalid unit. Please use 'C' for Celsius or 'F' for Fahrenheit.\n";}
    }return 0;
    }

    int main() {
    double val, result1, result2;
    char unit;
    convfc(val, unit, result1, result2); 
    return 0;}
