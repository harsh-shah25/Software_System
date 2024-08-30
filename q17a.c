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
    int train_num;
    int ticket_num;
} db[3];

int main() 
{
    int i;
    
    for (i=0; i<3; i++) 
    {
        db[i].train_num = i+1;
        db[i].ticket_num = 0;
    }

    ssize_t fd = open("ticket.txt", O_CREAT | O_RDWR, 0744);
    write(fd, db, sizeof(db));
    
    printf("Tickets created\n");
    close(fd);
    return 0;
}
/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc -o q17a q17a.c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q17a
Tickets created
*/