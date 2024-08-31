/*
Name : Harsh Shah
Roll No. : MT2024136
Q19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>   
#include <stdint.h>   
#include <x86intrin.h> 
#include <fcntl.h>

int main() {
    uint64_t start, end;
    pid_t pid;

    start = __rdtsc();

    pid = getpid();

    end = __rdtsc();

    uint64_t cycles = end - start;

    printf("getpid() returned: %d\n", pid);
    printf("Time taken for getpid() in clock cycles: %lu\n", cycles);

    return 0;
}
/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ gcc -o q19 q19.c
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q19
getpid() returned: 26655
Time taken for getpid() in clock cycles: 9222
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q19
getpid() returned: 26670
Time taken for getpid() in clock cycles: 9456
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q19
getpid() returned: 26682
Time taken for getpid() in clock cycles: 9539
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q19
getpid() returned: 26700
Time taken for getpid() in clock cycles: 9675
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ 
*/