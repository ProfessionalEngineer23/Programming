// Convert stream error mask to a nice string

// See https://cplusplus.com/reference/ios/ios/exceptions/

#include <iostream>

#include <vector>

#include <fstream>      // std::ifstream

 

using namespace std;

 

string exceptions_to_str( istream &ist ) ;

 

int main() {

    cout << "Before: " << exceptions_to_str(cin) << "\n" ;

    cin.exceptions ( ifstream::failbit | ifstream::badbit );

    cout << "After: " << exceptions_to_str(cin) << "\n" ;

    return 0;

}

 

// print which states will throw an exception

string exceptions_to_str( istream &ist ) {

    string s = "Exception thrown if state is " ;

    if ( (ist.exceptions() & ifstream::eofbit ) != 0 )

        s = s + "eof ";

    if ( (ist.exceptions() & ifstream::failbit ) != 0 )

        s = s + "fail ";

    if ( (ist.exceptions() & ifstream::badbit ) != 0 )

        s = s +"bad ";

    return s;

}