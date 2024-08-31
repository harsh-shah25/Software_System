/*
Name : Harsh Shah
Roll No. : MT2024136
Q12. Write a program to find out the opening mode of a file. Use fcntl.
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
    ssize_t fd = open("example.txt",O_RDWR);

    int flags = fcntl(fd,F_GETFL);

    int mode = flags & O_ACCMODE;
    switch (mode) {
        case O_RDONLY:
            printf("Read only mode\n");
            break;
        case O_WRONLY:
            printf("Write only mode\n");
            break;
        case O_RDWR:
            printf("Read-Write mode\n");
            break;
        default:
            printf("Unknown mode\n");
            break;
    }
    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q12.c -o q12
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q12
Read-Write mode
*/