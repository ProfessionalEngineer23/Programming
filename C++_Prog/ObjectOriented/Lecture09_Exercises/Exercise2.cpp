#include <iostream>
#include <iomanip> // std::setprecision
using namespace std;

int main()
{
    
cout << 123456 <<'|'
<< setw(4) << 123456 << '|'
<< setw(8) << 123456 << '|'
<< 123456 << "|\n";
cout << 1234.56 <<'|'
<< setw(4) << 1234.56 << '|'
<< setw(8) << 1234.56 << '|'
<< 1234.56 << "|\n";
cout << "asdfgh" <<'|'
<< setw(4) << "asdfgh" << '|'
<< setw(8) << "asdfgh" << '|'
<< "asdfgh" << "|\n";

return 0;
}