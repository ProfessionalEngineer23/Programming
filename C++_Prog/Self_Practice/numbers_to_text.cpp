#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
    int a, b;
    cin >> a >> b; 
    string array[9] = {"one","two","three","four","five","six","seven","eight","nine"};
    
    for(int i = a; i <= b; i++)
    {
        if(i>=1 && i <= 9)
        {
        printf("%s\n", array[i-1].c_str());
        }
        else if(i % 2 == 0)
        {
            printf("even\n");
        }
        else 
        {
            printf("odd\n");
        }
    }
    return 0;
}
