/*
	Document: readwritepipe.c
	Created on: June 22, 2022
	Author: Cloyd Van S. Secuya
	Description:
		The other end of the named pipe where we try to 
        open the file with read and write permissions
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

	// Variable for reading-writing permissions 
	int n; 

    // Buffer 
    char buffer[BUFFSIZE];

    // Start opening the file with read-write permission
    printf("Opening file... >>> file"); 
    fd = open("file", O_RDWR);
    if (fd == -1) 
	{
		printf("An error occurred an opening the file >> file");
		return 2;
	}

    

    return 0;
}