/*
Name : Harsh Shah
Roll No. : MT2024136
Q1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkfifo("fifo", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q1c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ mkfifo fifo
mkfifo: cannot create fifo 'fifo': File exists

*/