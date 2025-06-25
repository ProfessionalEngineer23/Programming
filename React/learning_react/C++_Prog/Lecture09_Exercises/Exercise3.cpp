#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
// Sources:
// https://www.cplusplus.com/doc/tutorial/files/
// https://www.cplusplus.com/reference/cstdlib/rand/
int main()
{
ofstream ofs ;
string fname = "temps.txt" ;
// default mode: ios::out
ofs.open( fname );
if (!ofs.is_open() ) {
cerr << "Can't open " << fname << "for writing - exiting.\n";
exit(-1);
}
// rand() generates a pseudo-random number between 0 and RAND_MAX
for (int i=0; i<24; i++) {
ofs << i << " " << 15.0+rand()%10 << "\n";
}
ofs.close() ;
return 0;
} 