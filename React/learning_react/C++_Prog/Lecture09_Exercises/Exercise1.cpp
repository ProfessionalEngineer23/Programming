#include <iostream>
#include <iomanip> // std::setprecision
using namespace std;

int main()
{
    
cout << 1234.56789 << '\t'
<< fixed << 1234.56789 << '\t'
<< scientific << 1234.56789 << '\n';

cout << defaultfloat << setprecision(5)
<< 1234.56789 << '\t'
<< fixed << 1234.56789 << '\t'
<< scientific << 1234.56789 << '\n';

cout << defaultfloat << setprecision(8)
<< 1234.56789 << '\t'
<< fixed << 1234.56789 << '\t'
<< scientific << 1234.56789 << '\n';

return 0;
}