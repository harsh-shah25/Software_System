/*
Name : Harsh Shah
Roll No. : MT2024136
Q22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main()
{
    int fd = open("exampleQ22.txt",O_CREAT | O_RDWR | O_APPEND | O_TRUNC , 0744);
    if(fd==-1)
    {
        perror("unable to open file\n");
    }
    char text[] = "text written by parent\n";

    int pid = fork();

    if(pid==0)
    {
        strcpy(text,"text written by child\n");
        write(fd, text, strlen(text));
    }
    else if(pid>0)
    {
        strcpy(text,"text written by parent\n");
        write(fd, text, strlen(text));
    }
    else
    {
        perror("child process not created\n");
    }
    

    close(fd);

    return 0;

}

/*
TERMINAL                                                                        
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q22
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$

exampleQ22.txt
text written by parent
text written by child

*/