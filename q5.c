/*
Name : Harsh Shah
Roll No. : MT2024136
Q5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>


int main(int args, char* arg[])
{
    int n=5,i;

    int fd[6];
    for(i=1; i<=n; i++)
    {
        printf("%s",arg[i]);
        fd[i]=open(arg[i], O_CREAT | O_RDWR,0700);
    }

    
    while(1)
    {

    }
    return 0;
}
/*
harsh-shah@harsh-hp-laptop:/proc/19437$ cd fd
harsh-shah@harsh-hp-laptop:/proc/19437/fd$ ls
0  1  103  2  3  38  39  4  5  6  7

*/