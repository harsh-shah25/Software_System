/*
Name : Harsh Shah
Roll No. : MT2024136
Q4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/

#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <errno.h>  

int main() {
    
    const char *filename = "ques4.txt";

    int fd;
    // fd = open(filename, O_RDWR);
    fd = open(filename, O_RDWR | O_EXCL | O_CREAT);




    if (fd == -1) {
        perror("error"); 
        return 1;       
    }

    printf("File '%s' opened successfully with file descriptor: %d\n", filename, fd);

    close(fd);

    return 0; 
}

/*
Run 1:
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q4.c 
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./a.out 
File 'ques4.txt' opened successfully with file descriptor: 3

Run 2:
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./a.out 
error: File exists
*/