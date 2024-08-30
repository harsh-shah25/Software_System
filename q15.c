/*
Name : Harsh Shah
Roll No. : MT2024136
Q15. Write a program to display the environmental variable of the user (use environ).
*/

#include <stdio.h>

extern char **environ; 

int main() {
    char **env = environ; 

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

/*
.
.
.
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
GDMSESSION=ubuntu
ORIGINAL_XDG_CURRENT_DESKTOP=ubuntu:GNOME
.
.
.
*/