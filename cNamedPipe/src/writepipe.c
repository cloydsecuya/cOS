/*
	Document: writepipe.c
	Created on: June 22, 2022
	Author: Cloyd Van S. Secuya
	Description:
		Creating and using named pipes to communicate between processes
*/



// HEADER FILES
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

// DEFINE ATTRIBUTES
#define BUFFSIZE 512


// MAIN METHOD
int main()
{
	// Process
	pid_t pid;

	// File Descriptor
	int fd;

	// File name
	char filename[] = "write.fifo";

	// Buffer
	char buffer[BUFFSIZE];

	// Start creating a named pipe and apply error checking
	if (mknod(filename, 0666, 0) == -1)
	{
		printf("An error occurred at creating the file \n");
		return 1;
	}


	// Start forking
	pid = fork();


	// Check if there are any errors if returned -1
	if(pid == -1)
	{
		printf("Error occurred on spawning a process \n");
		return 2;
	}


	// CHILD PROCESS	where we are supposed to write
	if (pid == 0)
	{
		// Check to see if there are any errors for opening the named pipe
		printf("Checking... \n");
		if (fd = open("write.fifo", O_WRONLY) < 0)
		{
			printf("An error occurred at opening the named pipe \n");
			return 3;
		}

		else
		{
			printf("Success in creating a named pipe \n");
		}

		printf("Opening... \n");
		int x = 97;
		if( write(fd, &x, sizeof(x)) == -1)
		{
			printf("Error occurred at opening \n");
			return 4;
		}
		printf("Wrote into file \n");
		close(fd);
		printf("Closed \n");

	}











}
