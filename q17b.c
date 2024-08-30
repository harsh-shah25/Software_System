/*
Name : Harsh Shah
Roll No. : MT2024136
Q17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include<string.h>

struct 
{
    int ticket_num;
} db;

int main() 
{
    int fd;

    fd = open("ticketQ17.txt", O_RDWR);

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sizeof(db);

    
    read(fd, &db, sizeof(db));
    printf("Before entering critical section\n");

    fcntl(fd, F_SETLKW, &lock);
    printf("Current ticket number: %d", db.ticket_num);
    db.ticket_num++;
    
    lseek(fd, -1 * sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));
    printf("\nTo book ticket, press enter\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Ticket booked with number %d\n", db.ticket_num);
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q17b
Before entering critical section
Current ticket number: 100
To book ticket, press enter

Ticket booked with number 101
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q17b
Before entering critical section
Current ticket number: 101
To book ticket, press enter

Ticket booked with number 102
*/