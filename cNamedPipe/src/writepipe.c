/*
	Document: writepipe.c
	Created on: June 22, 2022
	Author: Cloyd Van S. Secuya
	Description:
		Creating and using named pipes to communicate between processes. 
		Moreover, we try to use this file as the write only file which 
		should write onto a generated file by mknod()
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
int main(int argc, char* argv[])
{

	// File Descriptor
	int fd;

	// Variable for writing 
	int n; 

	// File name
	char filename[] = "file";

	// Buffer
	char buffer[BUFFSIZE];

	// Start creating a named pipe and apply error checking
	fd = mknod(filename, 0666, 0);
	if (fd == -1)
	{
		printf("An error occurred at creating the file \n");
		return 1;
	}

	// Start opening
	printf("Opening file... >>> %s\n", filename); 
	fd = open(filename, O_WRONLY);
	// Check for any errors in opening the  file
	if (fd == -1) 
	{
		printf("An error occurred an opening the file >> %s\n", filename);
		return 2;
	}

	// Try and write into the file while this program is running
	while((n = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0) 
	{	// Try and begin writing. Apply error handling and checking
		if (write(fd, buffer, strlen(buffer)) == -1) 
		{
			printf("An error occurred writing into the file!"); 
			return 3;
		}
		printf("Wrote >> %s ( %d ) bytes \n", buffer, strlen(buffer));
	}
	// Close the fd
	close(fd);
	return 0;
}