/*
Name : Harsh Shah
Roll No. : MT2024136
Q24. Write a program to create an orphan process.
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
        printf("Parent PID before sleep: %d\n",getppid());
        sleep(5);
        printf("Parent PID after sleep: %d\n",getppid());
    }
    else if(pid>0)
    {
        printf("Printed by parent\n");
        sleep(1);
        // printf("PID : %d\nChild PID : %d\n",getpid(),pid);
        // flag=1;

    }

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q24
Printed by parent
Printed by child
Parent PID before sleep: 18640
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ Parent PID after sleep: 1539      //since parent id has changed we can say the child process has become orphan
*/