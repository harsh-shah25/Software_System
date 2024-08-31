/*
Name : Harsh Shah
Roll No. : MT2024136
Q26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)   
*/
#include<stdio.h>
#include<unistd.h>

int main(int args, char* argv[] )
{
    int i=0;
    execl("/usr/bin/ls","ls","-l",NULL);
    for(i=1;i<args; i++)
    {
        printf("argv[%d] : %s\n",i,argv[i]);
    }
    printf("Execl failed to execute\n");
    return 0;
}

/*OUTPUT 1: If there is some error in the execl() function call or in the path mentioned

harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q26 hello world!
argv[1] : hello
argv[2] : world!
Execl failed to execute

OUTPUT 2:
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q26.c -o q26
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q26
total 208
-rwxrwxr-x 1 harsh-shah harsh-shah 16000 Aug 29 08:45  a.out
-rwx------ 1 harsh-shah harsh-shah     0 Aug 29 08:48 'COLORTERM=truecolor'
------x--T 1 harsh-shah harsh-shah    20 Aug 29 01:42  exampleQ10.txt
-rw-r--r-- 1 harsh-shah harsh-shah   497 Aug 29 01:21  example.txt
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f1
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f2
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f3
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f4
-rwx------ 1 harsh-shah harsh-shah     0 Aug 27 17:24  f5
-rwx------ 1 harsh-shah harsh-shah     0 Aug 29 08:47  file0.txt
-rwxrwxr-x 1 harsh-shah harsh-shah 16336 Aug 23 19:07  p9
-rw-rw-r-- 1 harsh-shah harsh-shah   898 Aug 29 01:49  q10.c
-rwxrwxr-x 1 harsh-shah harsh-shah 15776 Aug 29 08:46  q2
-rwxrwxr-x 1 harsh-shah harsh-shah 16000 Aug 29 09:07  q26
-rw-rw-r-- 1 harsh-shah harsh-shah   561 Aug 29 09:07  q26.c
-rw-rw-r-- 1 harsh-shah harsh-shah  1799 Aug 27 15:44  q2.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16088 Aug 29 08:47  q3
-rw-rw-r-- 1 harsh-shah harsh-shah   691 Aug 27 15:53  q3.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16088 Aug 29 08:48  q4
-rw-rw-r-- 1 harsh-shah harsh-shah   894 Aug 27 15:38  q4.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16000 Aug 29 08:48  q5
-rw-rw-r-- 1 harsh-shah harsh-shah   641 Aug 27 17:55  q5.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16096 Aug 29 08:49  q6
-rw-rw-r-- 1 harsh-shah harsh-shah   548 Aug 28 00:07  q6.c
-rw-rw-r-- 1 harsh-shah harsh-shah   111 Aug 28 00:11  q7.sh
-rwxrwxr-x 1 harsh-shah harsh-shah 16240 Aug 29 08:52  q8
-rw-rw-r-- 1 harsh-shah harsh-shah  1967 Aug 29 00:29  q8.c
-rwxrwxr-x 1 harsh-shah harsh-shah 16232 Aug 29 08:55  q9
-rw-rw-r-- 1 harsh-shah harsh-shah  3311 Aug 29 08:54  q9.c
-rwx------ 1 harsh-shah harsh-shah     0 Aug 29 08:48 'QT_ACCESSIBILITY=1'
-r-x--x--T 1 harsh-shah harsh-shah     0 Aug 27 15:31  ques4.txt
-rw-rw-r-- 1 harsh-shah harsh-shah     0 Aug 22 08:43  README.md
*/
