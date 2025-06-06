#include <iostream>

 

using namespace std;

 

string state_to_str(istream &) ;

 

int main() {

    int tot = 0 ;

    int i = 0;

    cout << "Before: " << state_to_str(cin) << "\n";

    while (cin >> i) {

        tot +=i ; // do something

    }

    cout << "After: " << state_to_str(cin) << "\n";

    return 0;

}

 

string state_to_str(istream &ist) {

    string s = "Stream state: " ;

    if ( ist.eof() )

        s = s + "eof ";

    if ( ist.fail() )

        s = s + "fail ";

    if ( ist.bad() )

        s = s + "bad ";

    return s;

}