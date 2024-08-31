/*
Name : Harsh Shah
Roll No. : MT2024136
Q28. Write a program to get maximum and minimum real time priority.
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_fifo = sched_get_priority_max(SCHED_FIFO);
    int min_fifo = sched_get_priority_min(SCHED_FIFO);

    int max_rr = sched_get_priority_max(SCHED_RR);
    int min_rr = sched_get_priority_min(SCHED_RR);

    printf("FIFO Scheduling:\n");
    printf("Maximum Priority: %d\n", max_fifo);
    printf("Minimum Priority: %d\n", min_fifo);

    printf("Round Robin Scheduling:\n");
    printf("Maximum Priority: %d\n", max_rr);
    printf("Minimum Priority: %d\n", min_rr);

    return 0;
}

/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q28
FIFO Scheduling:
Maximum Priority: 99
Minimum Priority: 1
Round Robin Scheduling:
Maximum Priority: 99
Minimum Priority: 1
*/