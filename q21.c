/*
Name : Harsh Shah
Roll No. : MT2024136
Q21. Write a program, call fork and print the parent and child process id.
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
    
    int pid; 
	printf("Before fork\n");
	printf("Parent pid(as received by parent) : %d\n",getpid());
	pid = fork(); 
	printf("PID returned by fork() : %d\n",pid);

	if (pid == 0) 
	{ 
		printf("Parent Process id : %d\n", getppid()); 
		printf("Child Process id : %d\n",getpid()); 
	} 

	printf("After fork\n");
    return 0;
}
/*
harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q21
Before fork
Parent pid(as received by parent) : 6128
PID returned by fork() : 6129
After fork
PID returned by fork() : 0
Parent Process id : 1539	//this is the PID of 'systemd' as in this case parent had exited the program so 'systemd' becomes the new parent of child
Child Process id : 6129
After fork

harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q21
Before fork
Parent pid(as received by parent) : 6132
PID returned by fork() : 6133
After fork
PID returned by fork() : 0
Parent Process id : 6132
Child Process id : 6133
After fork
*/


	

 
