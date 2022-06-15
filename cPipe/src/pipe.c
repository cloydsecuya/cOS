/*
	Document: pipe.c
	Created on: June 14, 2022
	Author: Cloyd Van S. Secuya
	Description:
		Using an ordinary pipe, we are to create parent-child processes that are
		able to communicate and access each other.
		Then, produce an output
		coming from the input of the child which will be the output of the parent
*/


// HEADER FILES
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


// MAIN METHOD
int main()
{

	// File Descriptor needed by pipe
	int fd[2];

	// Define a buffer
	char buffer[50];

	// Create a string of characters for my name initials
	char name[] = "CVSS-OL162";		// This will be also the input

        // Length
        int length = (strlen(name)+1);

	// Process
	pid_t pid;

	// Pipes
	// file_desc[0]   read
	// file_desc[1]   write

	// Open the pipe and check for errors
	if(pipe(fd) == -1)
	{
		printf("Error occured opening a pipe \n");
		return 1;
	}

	// Fork a process
	pid = fork();


	// CHILD PROCESS	this is where we want to write
	if (pid == 0)
	{
		// Close the other end of the pipe because no reading
		close(fd[0]);

		// Start writing at the write end of the pipe
		/* NOTE: REMEMBER IN A STRING OF CHARACTERS A \0 IS NEEDED IS THERE IS AN EXTRA SPACE */
		write(fd[1], name, length);
		close(fd[1]);		// close the write end after writing

		// Get the process ID
		printf("I am a child, ID: %d\n", getpid());
	}

        // PARENT PROCESS
	else
	{
		// Close the write end because we want to read
		close(fd[1]);

		// Read from the input of the child. Here we NEED the buffer. Refer to documentation.
		read(fd[0], buffer, sizeof(buffer));		// Documentation: https://man7.org/linux/man-pages/man2/read.2.html
		close(fd[0]);		// Close the pipe after reading

		// Get the parent ID
                printf("I am a parent, ID: %d\n", getpid());

                // Print the message of my name
                printf("Message from child: %s\n", buffer);

                // We need this as both parent and child processes are switching
                wait(NULL);
	}


        // Check errors at the creation of the process
        if (pid == -1)
        {
                printf("Failed to create process \n");
        }       return 2;

	return 0;
}
