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




// MAIN METHOD
int main()
{

	// Processes
	pid_t pid;

	// Create process using fork()
	pid = fork();


	// Child process
	if (pid == 0)
	{
		// Get the created child process along with the parent
		printf("I am a child, ID: %d\n", getpid());
		printf("My parent is here, ID: %d\n", getppid());

	}

	// Parent process
	else
	{
		// If there are other values greater than 0 return
		printf("This is my child: %d\n", pid);
		printf("I am a parent: %d\n", getpid());
		sleep(8);
	}

	return 0;
}
