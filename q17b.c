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
} db;

int main() 
{
    int fd, input;

    fd = open("ticket.txt", O_RDWR);

    printf("Select train number: 1, 2, 3\n");

    scanf("%d", &input);

    if(input>3 || input<1)
    {
        printf("Wrong train number\n");
        exit(EXIT_FAILURE);
    }

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);

    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));
    printf("Before entering critical section\n");

    fcntl(fd, F_SETLKW, &lock);
    printf("Current ticket number: %d", db.ticket_num);
    db.ticket_num++;
    
    lseek(fd, -1 * sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));
    printf("\nTo book ticket, press enter\n");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Ticket booked for train %d with number %d\n", input, db.ticket_num);
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc -o q17b q17b.c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q17b
Select train number: 1, 2, 3
2
Before entering critical section
Current ticket number: 0
To book ticket, press enter

Ticket booked for train 2 with number 1
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q17b
Select train number: 1, 2, 3
2
Before entering critical section
Current ticket number: 1
To book ticket, press enter

Ticket booked for train 2 with number 2
*/