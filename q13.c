/*
Name : Harsh Shah
Roll No. : MT2024136
Q13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
    fd_set fds;        
    struct timeval timeout; 
    int return_val;
    
    FD_ZERO(&fds);
    
    FD_SET(0, &fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");

    return_val = select(1, &fds, NULL, NULL, &timeout);

    if (return_val == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } 
    else if (return_val) 
    {
        printf("Data is available now.\n");
        char buffer[100];
        read(0, buffer, sizeof(buffer));
        printf("You entered: %s\n", buffer);
    } 
    else 
    {
        printf("No data within 10 seconds.\n");
    }

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q13 
Waiting for input on STDIN for 10 seconds...
harsh
Data is available now.
You entered: harsh

harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q13 
Waiting for input on STDIN for 10 seconds...
No data within 10 seconds.
*/
