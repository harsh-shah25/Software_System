/*
Name : Harsh Shah
Roll No. : MT2024136
Q8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    FILE * fptr = fopen("example.txt","r");

    char line[500];
    printf("Using fopen() : \n");
    if(fptr!=NULL)
    {
        while(fgets(line, sizeof(line),fptr))
        {
            printf("%s",line);
        }
        fclose(fptr);
    }
    else
    {
        printf("failed to open the file");
    }

    printf("\nUsing open() and fd : \n");

    int fd = open("example.txt",O_RDONLY);

    while(read(fd, line, sizeof(line)))
    {
        printf("%s",line);
    }

    return 0;
}


/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q8.c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./a.out
Using fopen() : 
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum lobortis eget sem nec vehicula. Donec feugiat vestibulum lobortis. 
Nulla blandit lacus eget condimentum blandit. Phasellus molestie vulputate orci vel mattis. In elementum egestas tempor. 
Vivamus nec augue elit. Sed finibus ante quis gravida sodales. Nunc eu erat quis lorem consectetur blandit quis sed risus. 
Aliquam vel augue neque. Aliquam vestibulum venenatis quam vel consectetur. Donec faucibus non dolor non accumsan.

Using open() and fd : 
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum lobortis eget sem nec vehicula. Donec feugiat vestibulum lobortis. 
Nulla blandit lacus eget condimentum blandit. Phasellus molestie vulputate orci vel mattis. In elementum egestas tempor. 
Vivamus nec augue elit. Sed finibus ante quis gravida sodales. Nunc eu erat quis lorem consectetur blandit quis sed risus. 
Aliquam vel augue neque. Aliquam vestibulum venenatis quam vel consectetur. Donec faucibus non dolor non accumsan.
*/