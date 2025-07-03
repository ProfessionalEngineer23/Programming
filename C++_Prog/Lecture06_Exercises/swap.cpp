//Name: Niki Mardari
//ID: B00159642

#include <iostream>
using namespace std;

void swap_i(int a, int b) 
{
    int temp;
    temp = a ;
    a = b;
    b = temp;
}

void swap_r( int&, int& )
{
    int temp;
//  temp = a ;
//  a = b;
//   b = temp;
}

void swap_cr( const int&, const int& )
{
    int temp;
//  temp = a ;
//   a = b;
//   b = temp;
}

int main()
{

int x = 7, y = 9 ;

swap_i(x, y);

swap_i(7, 9);

 

const int cx = 7, cy = 9 ;

swap_i(cx, cy) ;

swap_i(7.7, 9.3) ;

 

double dx = 7.7, dy = 8.2 ;

swap_i( dx, dy );

return 0;

}
/*
DESKTOP-6OEFS7V_Lecture06_Exercises_$_[22:04:27]: gdb swap
GNU gdb (GDB) 14.2
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-msys".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from swap...
(gdb) list
17      //   b = temp;
18      }
19
20      void swap_cr( const int&, const int& )
21      {
22          int temp;
23      //  temp = a ;
24      //   a = b;
25      //   b = temp;
26      }
(gdb) list
27
28      int main()
29      {
30
31      int x = 7, y = 9 ;
32
33      swap_i(x, y);
34
35      swap_i(7, 9);
36
(gdb) list
37
38
39      const int cx = 7, cy = 9 ;
40
41      swap_i(cx, cy) ;
42
43      swap_i(7.7, 9.3) ;
44
45
46
(gdb) list
47      double dx = 7.7, dy = 8.2 ;
48
49      swap_i( dx, dy );
50
51      return 0;
52
53      }
(gdb) break 51
Breakpoint 1 at 0x14000153b: file C:/Users/nikit/Documents/GitHub/PROG2.MARDARI.Niki/src/ObjectOriented/Lecture06_Exercises/swap.cpp, line 51.
(gdb) run
Starting program: /c/Users/nikit/Documents/GitHub/PROG2.MARDARI.Niki/src/ObjectOriented/Lecture06_Exercises/swap
[New Thread 600.0x55e8]

Thread 1 hit Breakpoint 1, main ()
    at C:/Users/nikit/Documents/GitHub/PROG2.MARDARI.Niki/src/ObjectOriented/Lecture06_Exercises/swap.cpp:51
51      return 0;
(gdb) local info
Undefined command: "local".  Try "help".
(gdb) info locals
x = 7
y = 9
cx = 7
cy = 9
dx = 7.7000000000000002
dy = 8.1999999999999993
(gdb)
*/