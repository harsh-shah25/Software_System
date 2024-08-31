/*
Name : Harsh Shah
Roll No. : MT2024136
Q16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fd = open("exampleQ16.txt",O_RDWR | O_CREAT,0644);
    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before locking\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Lock acquired press enter to unlock\n");
    
    getchar();
    ssize_t written_bytes =  write(fd,"ABC123",6);

    if(written_bytes==-1)
    {
        perror("Unable to write");
    }
    else
    {
        printf("Written successfully\n");
    }

    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("Lock released\n");

    close(fd);

    return 0;
}
    
/*
Terminal 1 :                                                                Terminal 2 :

harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q16         
Before locking
Lock acquired press enter to unlock

                                                                            harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q16
                                                                            Before locking

//pressing Enter button
Written successfully                                                            

                                                                            Lock acquired press enter to unlock
                                                                            //pressing Enter button
                                                                            Written successfully
*/
