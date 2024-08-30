/*
Name : Harsh Shah
Roll No. : MT2024136
Q14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <linux/stat.h>

int main(int argc, char *argv[])
{
    struct stat sb;

    if (argc != 2) 
    {
        fprintf(stderr, "write the name of a file after %s\n" , argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) 
    {
        perror("lstat");
        exit(EXIT_FAILURE);
    }


    printf("File type : ");

    switch (sb.st_mode & S_IFMT) 
    {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }
    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q14.c -o q14
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q14
write the name of a file after ./q14
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q14 example.txt
File type : regular file
*/