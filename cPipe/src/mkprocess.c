/*
	Document: mkprocess.c
	Created on: June 14, 2022
	Author: Cloyd  Van S. Secuya
	Description:
		This is a src file of making processes PROPERLY!
		We can see from this c file that we have successfully created and established proper 
		parent and child relationship 
*/


// HEADER FILES
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



// MAIN METHOD
int main()
{

	// Processes
	pid_t pid;		// first child of parent process
	pid_t cpid;		// this will be the grand child

	// Create process using fork()
	pid = fork();


	// Child process (C1)
	if (pid == 0)
	{
		// Get the created child process along with the parent
		printf("I am a child, ID: %d\n", getpid());
		printf("My parent is here, ID: %d\n", getppid());

		// Create a grand child
		cpid = fork();

		// Child process 2 (C2) (created by this child)
		if (cpid == 0)
		{
			printf("I am a grand child, ID: %d\n", getpid());
			printf("My parent is, ID: %d\n", getppid());
		}

		// Parent process 2 (P2)
		else
		{
			printf("I am a parent too, ID: %d\n", getpid());
			printf("This is my child, ID: %d\n", cpid);
			wait(NULL);
		}

	}

	// Parent process (P1)
	else
	{
		// If this is the parent 
		printf("This is my child: %d\n", pid);
		printf("I am a parent: %d\n", getpid());
		wait(NULL);
	}

	return 0;
}
