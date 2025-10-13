#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d)
{
    //int greatest = max(max(a, b), max(c, d));
    // or you can use ternary operator:
    double Max1, Max2, Max3;

    // bigger number among a and b
    Max1 = (a > b) ? a : b;
    // bigger number among c and d
    Max2 = (c > d) ? c : d;

    // comparing the numbers from first and second
    // comparison to get the max among all four numbers
    Max3 = (Max1 > Max2) ? Max1 : Max2;

    //cout << Max3 << endl;

    // Another way but it is too long
    // cout << (a < b ? ((b > c)? ((b > d)? b:d) :((c > d)?
    // c: d))  : ((a < c)? ((c > d)? c: d) : ((a > d) ? a :
    // d))) << endl;

    
    return Max3;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}