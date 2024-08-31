/*
Name : Harsh Shah
Roll No. : MT2024136
Q20. Find out the priority of your running program. Modify the priority with nice command.
*/

#include<stdio.h>

int main()
{
    while(1);

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~$ top
.
.
.
PID   USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND  
27485 harsh-s+  20   0    2484    896    896 R 100.0   0.0   1:10.91 q20 
.
.
.   
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ nice -n 10 ./q20

harsh-shah@harsh-hp-laptop:~$ top

PID   USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND           
28169 harsh-s+  30  10    2484    896    896 R  99.3   0.0   0:16.62 q20        
*/