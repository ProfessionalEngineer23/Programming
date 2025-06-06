#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
ifstream ifs ;
string fname = "temps.txt" ;
ifs.open( fname ); // default mode: ios::in
if (!ifs.is_open() ) {
cerr << "Can't open " << fname << " for reading - exiting.\n";
exit(-1);
}
int time;
double temperature;
while (ifs >> time >> temperature) {
cout << time << " " << temperature << "\n";
}
ifs.close() ;
return 0;
}