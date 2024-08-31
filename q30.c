// /*
// Name : Harsh Shah
// Roll No. : MT2024136
// Q30. Write a program to run a script at a specific time using a Daemon process.
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <time.h>
// #include <sys/types.h>
// #include <sys/stat.h>



// int main() 
// {
//     pid_t pid = fork();  
   
//     if(!pid)
//     {
//         setsid();

//         chdir("/");

//         umask(0);

//         close(STDIN_FILENO);
//         close(STDOUT_FILENO);
//         close(STDERR_FILENO);

//         while (1) 
//         {
//             time_t now = time(NULL);                 
//             struct tm *timeinfo = localtime(&now);   

//             if (timeinfo->tm_hour == 17 && timeinfo->tm_min == 52) 
//             {
//                 printf("The time is 5:38 pm");    
//                 sleep(60);    
//             }

//             sleep(60); 
//         }
//     }
//     else
//     {
//          exit(0);
//     }
//     return 0;
// }
#include<stdio.h>
#include<unistd.h> 
#include<sys/types.h>
#include<sys/stat.h>

int main() {
    pid_t child = fork();
    if(!child) {
        //child process
        setsid(); //new session + deatch from the terminal
        while(1) {
            sleep(2);
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n", getppid());
            printf("Daemon process is running...\n");
        }
    } else {
        printf("Parent process exiting\n");
        return 0;
    }
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q30 
Parent process exiting
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ PID: 32427
PPID: 1539
Daemon process is running...
PID: 32427
PPID: 1539
Daemon process is running...
.
.
.
*/