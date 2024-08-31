/*
Name : Harsh Shah
Roll No. : MT2024136
Q27. Write a program to execute ls -Rl by the following system calls

b. execlp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Using execlp to execute 'ls -Rl'\n");
    execlp("ls", "ls", "-Rl", NULL);

    perror("execlp failed");
    return 1;
}


/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q27b
Using execlp to execute 'ls -Rl'
.:
total 604
-rwxrwxr-x 1 harsh-shah harsh-shah 16000 Aug 29 08:45  a.out
-rwx------ 1 harsh-shah harsh-shah     0 Aug 29 08:48 'COLORTERM=truecolor'
-rw-r--r-- 1 harsh-shah harsh-shah    30 Aug 29 09:21  exampleQ10.txt
-rw-r--r-- 1 harsh-shah harsh-shah     6 Aug 30 15:43  exampleQ16.txt
-rwxr--r-- 1 harsh-shah harsh-shah    45 Aug 31 12:29  exampleQ22.txt
-rw-r--r-- 1 harsh-shah harsh-shah   497 Aug 30 22:50  example.txt
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f1
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f2
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f3
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f4
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f5
-rwx------ 1 harsh-shah harsh-shah     0 Aug 29 08:47  file0.txt
-rwxrwxr-x 1 harsh-shah harsh-shah 16336 Aug 23 19:07  p9
-rwxrwxr-x 1 harsh-shah harsh-shah 16088 Aug 29 09:20  q10
-rw-rw-r-- 1 harsh-shah harsh-shah  1155 Aug 29 09:26  q10.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16344 Aug 29 11:33  q11
-rw-rw-r-- 1 harsh-shah harsh-shah  1484 Aug 29 11:36  q11.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16040 Aug 29 19:16  q12
-rw-rw-r-- 1 harsh-shah harsh-shah   834 Aug 29 19:16  q12.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16224 Aug 29 22:18  q13
.
.
.
*/