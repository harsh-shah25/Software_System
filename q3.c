/*
Name : Harsh Shah
Roll No. : MT2024136
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char *filename = "file0.txt";

    int fd = creat(filename , 0700);

    if (fd == -1) {
        perror("error");
        return 1;  
    }

    printf("File '%s' created successfully with file descriptor: %d\n", filename, fd);

    close(fd);

    return 0;  
}
/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q3.c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./a.out
File 'file0.txt' created successfully with file descriptor: 3
*/