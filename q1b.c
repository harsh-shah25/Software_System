/*
Name : Harsh Shah
Roll No. : MT2024136
Q1. Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
*/

#include <unistd.h>
#include <stdio.h>
#include<fcntl.h>

int main() {

    int fd1 = open("example.txt",O_CREAT | O_RDONLY, 0644);

    char line[500] ;

    if (link("example.txt", "hard_link") == -1) {
        perror("link");
        return 1;
    }

    printf("Contents of original file : \n");
    while(read(fd1, line, sizeof(line)))
    {
        printf("%s",line);
    }


    int fd2 = open("hard_link",O_RDONLY);

    printf("\nContents of file pointed by hard_link: \n");
    while(read(fd2, line, sizeof(line)))
    {
        printf("%s",line);
    }

    close(fd1);
    close(fd2);

    return 0;
}

/*
SHELL COMMAND: 
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ln example.txt hard_link


SYSTEM CALL:
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q1b
Contents of original file : 
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum lobortis eget sem nec vehicula. Donec feugiat vestibulum lobortis. 
Nulla blandit lacus eget condimentum blandit. Phasellus molestie vulputate orci vel mattis. In elementum egestas tempor. 
Vivamus nec augue elit. Sed finibus ante quis gravida sodales. Nunc eu erat quis lorem consectetur blandit quis sed risus. 
Aliquam vel augue neque. Aliquam vestibulum venenatis quam vel consectetur. Donec faucibus non dolor non accumsan.

Contents of file pointed by hard_link: 
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum lobortis eget sem nec vehicula. Donec feugiat vestibulum lobortis. 
Nulla blandit lacus eget condimentum blandit. Phasellus molestie vulputate orci vel mattis. In elementum egestas tempor. 
Vivamus nec augue elit. Sed finibus ante quis gravida sodales. Nunc eu erat quis lorem consectetur blandit quis sed risus. 
Aliquam vel augue neque. Aliquam vestibulum venenatis quam vel consectetur. Donec faucibus non dolor non accumsan.
*/