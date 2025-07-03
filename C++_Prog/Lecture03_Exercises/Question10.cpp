    //Name: Niki Mardari
    //Student ID: B00159642
    // Converting degrees Celsius to degrees Kelvin

    #include <iostream>
    using namespace std;

    void convkc() //Reference location of CelsiustoFahrenheit
    { 
    double val, result;
    cout << "Please input degrees celsius that will be converted to degrees Kelvin\n";
    while (cin >> val)  {
    result = 273.15+val;  
    if (result < 0){cout << "Error";}
    else
    {cout << result;}   }
    }

    int main() {
    convkc(); 
    return 0;}
