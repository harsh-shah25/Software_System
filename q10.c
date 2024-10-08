/*
Name : Harsh Shah
Roll No. : MT2024136
Q10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = open("exampleQ10.txt",O_RDWR | O_CREAT, 0644);
    
    write(fd,"0123456789",10);       //only first 10 char will be written into the file

    off_t offset = lseek(fd,10,SEEK_CUR);

    printf("Return value of lseek : %ld\n",offset);
    
    write(fd,"dddddddddd",10);

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q10.c -o q10
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q10
Return value of lseek : 20

// exampleQ10.txt

// 0123456789          dddddddddd

harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ od -c "exampleQ10.txt"
0000000   0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   d   d   d   d   d   d   d   d   d   d
0000036

*/