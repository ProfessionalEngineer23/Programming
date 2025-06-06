/*
ArchlinuxN23_Lecture05_Exercises_$_[12:27:12]: g++ -g Question2.cpp -o Question2.exe
ArchlinuxN23_Lecture05_Exercises_$_[12:27:36]: gdb ./Question1.exe
GNU gdb (GDB) 16.2
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./Question1.exe...

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.archlinux.org>
Enable debuginfod for this session? (y or [n]) y
Debuginfod has been enabled.
To make this setting permanent, add 'set debuginfod enabl--Type <RET> for more, q to quit, c to continue without paging--
ed on' to .gdbinit.


(No debugging symbols found in ./Question1.exe)
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) break area
Breakpoint 1 at 0x11ad
(gdb) run
Starting program: /home/N23L/Documents/GitHub/PROG2.MARDARI.Niki/src/ObjectOriented/Lecture05_Exercises/Question1.exe 
Downloading 1.09 M separate debug info for /lib64/ld-linux-x86-64.so.2
Downloading 3.01 M separate debug info for /usr/lib/libm.so.6
Downloading 9.67 M separate debug info for /usr/lib/libc.so.6
[Thread debugging using libthread_db enabled]            
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 1, 0x00005555555551ad in area(int, int) ()
(gdb) quit
A debugging session is active.

        Inferior 1 [process 51972] will be killed.

Quit anyway? (y or n) y
ArchlinuxN23_Lecture05_Exercises_$_[12:29:48]: ls
exception.cpp  Question1.exe  Question3.cpp
exeption.exe   Question2.cpp
Question1.cpp  Question2.exe
ArchlinuxN23_Lecture05_Exercises_$_[12:29:50]: g++ -g -o bad_area.exe bad_area.cpp
cc1plus: fatal error: bad_area.cpp: No such file or directory
compilation terminated.
ArchlinuxN23_Lecture05_Exercises_$_[12:36:00]: g++ -g -o Question2.exe Question2.cpp
ArchlinuxN23_Lecture05_Exercises_$_[12:36:21]: gdb Question2.exe
GNU gdb (GDB) 16.2
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from Question2.exe...
(gdb) 
(gdb) break area
Breakpoint 1 at 0x11b7: file Question2.cpp, line 7.
(gdb) run
Starting program: /home/N23L/Documents/GitHub/PROG2.MARDARI.Niki/src/ObjectOriented/Lecture05_Exercises/Question2.exe 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.archlinux.org>
Enable debuginfod for this session? (y or [n]) y
Debuginfod has been enabled.
To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 1, area (length=10, width=3) at Question2.cpp:7
7       if (length<=0 || width<=0)
(gdb) step
11      return length*width;
(gdb) next
12      }
(gdb) print length
$1 = 10
(gdb) continue
Continuing.
30

Breakpoint 1, area (length=5, width=-3) at Question2.cpp:7
7       if (length<=0 || width<=0)
(gdb) 
*/