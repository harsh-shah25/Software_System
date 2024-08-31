/*
Name : Harsh Shah
Roll No. : MT2024136
Q11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    ssize_t fd = open("ques11.txt",O_RDWR | O_APPEND | O_CREAT, 0644);

    if(fd==-1)
    {
        perror("no such file");
        return 0;
    }

    char text[] = "ABCDEFGHIJ";
    
    printf("Initial file descriptor : %ld\n",fd);
    write(fd,text,strlen(text));


    int newfd = dup(fd);
    printf("New file descriptor : %d\n",newfd);
    write(newfd,text,strlen(text));
    close(newfd);

    int dup2fd = dup2(fd,10);
    printf("New file descriptor modified using dup2() : %d\n",dup2fd);
    write(dup2fd,text,strlen(text));
    close(dup2fd);

    int fcntl_fd = fcntl(fd,F_DUPFD);
    printf("New file descriptor modified using fcntl() : %d\n",dup2fd);
    write(fcntl_fd,text,strlen(text));
    close(fcntl_fd);

    close(fd);

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q11.c -o q11
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q11 
Initial file descriptor : 3
New file descriptor : 4
New file descriptor modified using dup2() : 10
New file descriptor modified using fcntl() : 10

ques11.txt

ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ

*/