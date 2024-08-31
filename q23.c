/*
Name : Harsh Shah
Roll No. : MT2024136
Q23. Write a program to create a Zombie state of the running program.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int pid = fork();
    // int flag=0;

    if(pid==0)
    {
        printf("Printed by child\n");
    }
    else if(pid>0)
    {
        printf("Printed by parent\n");
        printf("Parent PID : %d\nChild PID : %d\n",getpid(),pid);
        sleep(50);
        // flag=1;

    }

    

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q23
Printed by parent
Parent PID : 14544
Child PID : 14545
Printed by child

harsh-shah@harsh-hp-laptop:/proc$ cd 14545
harsh-shah@harsh-hp-laptop:/proc/14545$ cat status
Name:   q23
State:  Z (zombie)  <-------------------------------------------- state of child process
Tgid:   14545
Ngid:   0
Pid:    14545
PPid:   14544
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 0
Groups: 4 24 27 30 46 100 118 1000 
NStgid: 14545
NSpid:  14545
NSpgid: 14544
NSsid:  7731
.
.
.
*/