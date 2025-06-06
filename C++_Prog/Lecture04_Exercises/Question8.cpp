#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
//vectors to store string names and int scores
vector<string> names;
string n;
vector<int> scores;
int s;
while(n!="ctrl-d"){
cout << "Please enter a name: ";
cin >> n;
if(n=="ctrl-d"){continue;} //If ctrl^d is entered, the while loop for entering values is exited
names.push_back(n);
cout << "Please enter a score for the name: ";
cin >> s; 
scores.push_back(s);
}
sort(names.begin(), names.end());
sort(scores.begin(), scores.end());

//names2 vector for filtered names, a vector free from duplicates
vector<string> names2;
vector<int> scores2;

//Transfer names vector to new non-duplicate vector
if (names.size()>0){names2.push_back(names[0]);
for (unsigned i=1; i<names.size(); ++i)
{if(names[i-1] != names[i]) names2.push_back(names[i]);}
}
//Transfer scores vector to new non-duplicate vector
if (scores.size()>0){scores2.push_back(scores[0]);
for (unsigned i=1; i<scores.size(); ++i)
{if(scores[i-1] != scores[i]) scores2.push_back(scores[i]);}
}
//If a duplicate name is found an error message is outputted
if ((names.size()-names2.size())>0){cout << "Error duplicates found!";}
else 
{
//For loop to cycle through each elements of vectors names2 and scores2 and output each value
for (unsigned i = 0; i<names2.size(); ++i){cout << endl << "(" << i << ") "<< "Name: " <<names2[i] << " --> " << "Score: " << scores2[i]; }
}

return 0;
}