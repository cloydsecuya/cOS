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
// #include <sys/wait.h>
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

    // Try and write into the file while this program is running
	while((n = read(fd, buffer, BUFFSIZE)) > 0) 
	{	fgets(buffer, sizeof(buffer), stdin);
		// Try and begin writing. Apply error handling and checking
		if (read(fd, buffer, strlen(buffer)) == -1) 
		{
			printf("An error occurred reading into the file!"); 
			return 3;
		}
		//printf("Wrote >> %s ( %d ) bytes \n", buffer, strlen(buffer));
		printf("Read success");
        printf(buffer);
	}
    // Close the fd
    close(fd);
    return 0;
}