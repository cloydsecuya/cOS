/**
	Document: processes.c
	Created on: June 8, 2022
	Author: Cloyd Van S. Secuya
	Description:
		This is a C source file responsible for creating processes using the fork() method.
		We are then going to get the process ID of both the parent and child processes
*/



// HEADER FILES
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>




// MAIN METHOD
int main(int argc, char* argv[])
{
	int status;			// return status
	pid_t pid;			// process id
	int pid_p;			// assigning the parent process id
	int pid_c;			// assigning the child process id

	// First, we create a process through the fork() method
	pid = fork();

	// Next, we want to retrieve both the process IDs of both parent and child through getpid() and getppid()
	pid_c = getpid();		// here we try to assign the process id of the child
	pid_p = getppid();		// while in here, we try to assign the process id of the parent


	/*NOTE: if fork() is successful, it should have generated a child process calling from its parent*/

	// Now,  according to what I searched.
	// The parent is alive if the pid == 0
	// and should have a value of 0 in the child process
	if (pid == 0)
	{
		printf("Child is alive and active! \n");
		printf("Child has started along with parent \n \n");

		// Get the process ID of the parent process
		pid_p = getppid(); 
		printf("Parent Process ID: %d\n", pid_p);	// then, just simply print it on our console
		// And  get the ID of the child here
		pid_c = getpid(); 
		printf("Child process ID: %d\n", pid_c);	// then print as well
	}


	else if (pid < 0)
	{
		// We can only get inside this block if the value returned is  not an integer or may be a  negative number
		printf("Starting of processes through fork() failed!");
		status = -1;
	}

return status = 0;
}
