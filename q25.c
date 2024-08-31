/*
Name : Harsh Shah
Roll No. : MT2024136
Q25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid, pid1, pid2, pid3;
    int status;

    pid = getpid();
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }
    if (pid1 == 0) 
    {
        printf("First child process (PID: %d) created\n", getpid());
        sleep(2); 
        printf("First child exiting\n");
        exit(0);  
    }

    pid2 = fork();
    if (pid2 < 0) 
    {
        perror("fork failed");
        exit(1);
    }
    if (pid2 == 0) 
    {
        printf("Second child process (PID: %d) created\n", getpid());
        sleep(4); 
        printf("Second child exiting\n");
        exit(0);  
    }

    
    pid3 = fork();
    if (pid3 < 0) 
    {
        perror("fork failed");
        exit(1);
    }
    if (pid3 == 0) 
    {
        printf("Third child process (PID: %d) created\n", getpid());
        sleep(6); 
        printf("Third child exiting\n");
        exit(0);  
    }

    printf("Parent process (PID: %d) is waiting for second child (PID: %d) to finish\n", getpid(), pid2);
    int waited_pid = waitpid(pid2, &status, 0);
    
    if(getpid() == pid)
    {
        if (waited_pid == -1) 
        {
            perror("waitpid failed");
        } 
        else 
        {
            printf("Parent process exiting\n");
        }
    }
    

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q25
First child process (PID: 20823) created
Parent process (PID: 20822) is waiting for second child (PID: 20824) to finish
Second child process (PID: 20824) created
Third child process (PID: 20825) created
First child exiting
Second child exiting
Parent process exiting      --------> Parent process exited after second child since it was waiting for it
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ Third child exiting   ---> third child process exited after parent
*/