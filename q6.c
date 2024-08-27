/*
Name : Harsh Shah
Roll No. : MT2024136
Q6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>


int main(int args, char* arg[])
{
    char str[100];
    printf("Just for testing");
    ssize_t size = read(0,str,100);


    write(1,str,size);

    // printf("%s\n",str);
    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./a.out
hey there!
hey there!
Just for testing
*/