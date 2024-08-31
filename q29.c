/*
Name : Harsh Shah
Roll No. : MT2024136
Q29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    if (policy == SCHED_FIFO) {
        printf("Current scheduling policy: SCHED_FIFO\n");
    } else if (policy == SCHED_RR) {
        printf("Current scheduling policy: SCHED_RR\n");
    } else if (policy == SCHED_OTHER) {
        printf("Current scheduling policy: SCHED_OTHER (default)\n");
    } else {
        printf("Unknown scheduling policy: %d\n", policy);
    }
}

int main() {
    pid_t pid = getpid(); 
    struct sched_param param;

    int policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return EXIT_FAILURE;
    }

    print_policy(policy);

    param.sched_priority = 1;
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler failed");
        return EXIT_FAILURE;
    }

    printf("Scheduling policy changed to SCHED_FIFO\n");

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return EXIT_FAILURE;
    }

    print_policy(policy);

    param.sched_priority = 1;
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler failed");
        return EXIT_FAILURE;
    }

    printf("Scheduling policy changed to SCHED_RR\n");

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return EXIT_FAILURE;
    }

    print_policy(policy);

    return EXIT_SUCCESS;
}
/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q29
Current scheduling policy: SCHED_OTHER (default)
sched_setscheduler failed: Operation not permitted
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ sudo ./q29
[sudo] password for harsh-shah: 
Current scheduling policy: SCHED_OTHER (default)
Scheduling policy changed to SCHED_FIFO
Current scheduling policy: SCHED_FIFO
Scheduling policy changed to SCHED_RR
Current scheduling policy: SCHED_RR
*/