#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void namefinder(vector<string> &names2, vector<int> &scores2)
{
    string searchname;
    cout << "\n\nEnter a name to search: ";
    cin >> searchname;
    
    auto it = find(names2.begin(),names2.end(), searchname);
    if (it != names2.end())
    cout << endl << "(" << distance(names2.begin(), it) << ") "<< "Name: " << searchname << " --> " << "Score: " 
    << scores2[distance(names2.begin(), it)];  
    else {cout << "Name not found";}
}

void scorefinder(vector<string>names2, vector<int>scores2)
{
    int searchscore;
    cout << "\n\nEnter a score to search: ";
    cin >> searchscore;

    auto it = find(scores2.begin(),scores2.end(), searchscore);
    if (it != scores2.end())
    cout << endl << "(" << distance(scores2.begin(), it) << ") "<< "Name: " << names2[distance(scores2.begin(), it)] << " --> " << "Score: " 
    << searchscore;  
    else {cout << "Score not found";}
}

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

else {
//For loop to cycle through each elements of vectors names2 and scores2 and output each value
for (unsigned i = 0; i<names2.size(); ++i){cout << endl << "(" << i << ") "<< "Name: " <<names2[i] << " --> " << "Score: " << scores2[i]; }
}
namefinder(names2, scores2);
scorefinder(names2, scores2); 

return 0;
}

/*==Sources==
https://www.geeksforgeeks.org/passing-vector-function-cpp/ - Helped me make functions to search for elements within a vector.
*/