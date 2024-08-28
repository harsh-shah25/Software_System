/*
Name : Harsh Shah
Roll No. : MT2024136
Q9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

/*
the following code is taken from the manual of 'stat' system call using the command 'man 2 stat'
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[])
{
       struct stat sb;

       if (argc != 2) {
              fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
              exit(EXIT_FAILURE);
       }

       if (lstat(argv[1], &sb) == -1) {
              perror("lstat");
              exit(EXIT_FAILURE);
       }

       // printf("ID of containing device:  [%x,%x]\n",
       //        major(sb.st_dev),
       //        minor(sb.st_dev));

       printf("File type:                        ");

       switch (sb.st_mode & S_IFMT) {
       case S_IFBLK:  printf("block device\n");            break;
       case S_IFCHR:  printf("character device\n");        break;
       case S_IFDIR:  printf("directory\n");               break;
       case S_IFIFO:  printf("FIFO/pipe\n");               break;
       case S_IFLNK:  printf("symlink\n");                 break;
       case S_IFREG:  printf("regular file\n");            break;
       case S_IFSOCK: printf("socket\n");                  break;
       default:       printf("unknown?\n");                break;
       }

       printf("a. I-node number:                 %ju\n", (uintmax_t) sb.st_ino);
       printf("b. Number of Hard Links:          %ju\n", (uintmax_t) sb.st_nlink);
       printf("c. userid:                        %ju\n"
              "d. groupid:                       %ju\n", (uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);
       printf("e. File size:                     %jd bytes\n", (intmax_t) sb.st_size);
       printf("f. Blocks size:                   %jd\n",(intmax_t) sb.st_blocks*(intmax_t) sb.st_size);
       printf("g. Number of blocks:              %jd\n",  (intmax_t) sb.st_blocks);
       printf("h. Time of last access:           %s", ctime(&sb.st_atime));
       printf("i. Time of last modification:     %s", ctime(&sb.st_mtime));
       printf("j. Time of last change:           %s", ctime(&sb.st_ctime));
       
       // printf("Preferred I/O block size:         %jd bytes\n", (intmax_t) sb.st_blksize);
       // printf("Mode:                             %jo (octal)\n", (uintmax_t) sb.st_mode);

      


       exit(EXIT_SUCCESS);
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc q9.c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./a.out example.txt
File type:                        regular file
a. I-node number:                 2248254
b. Number of Hard Links:          1
c. userid:                        1000
d. groupid:                       1000
e. File size:                     497 bytes
f. Blocks size:                   3976
g. Number of blocks:              8
h. Time of last access:           Wed Aug 28 16:03:58 2024
i. Time of last modification:     Wed Aug 28 16:03:58 2024
j. Time of last change:           Wed Aug 28 16:03:58 2024
*/