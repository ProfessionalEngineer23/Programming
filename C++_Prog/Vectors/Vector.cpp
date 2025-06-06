#include <iostream>
using namespace std;

int main(){
vector<string> words;
string s;
while (cin>>s && s!= "quit") {
words.push_back(s);
}
sort(words.begin(), words.end());
for (unsigned i=1; i<words.size(); ++i) {
if(words[i-1]==words[i])
“get rid of words[i]”
 // (pseudocode)
}
for (int i=0; i<words.size(); ++i)
cout<<words[i]<< "\n";

return 0;
}