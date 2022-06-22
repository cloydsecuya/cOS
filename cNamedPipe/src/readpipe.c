/*
	Document: readwritepipe.c
	Created on: June 22, 2022
	Author: Cloyd Van S. Secuya
	Description:
		The other end of the named pipe where we try to 
        open the file with read permissions
*/



// HEADER FILES
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


// DEFINE ATTRIBUTES
#define BUFFSIZE 512


// MAIN METHOD
int main(int argc, char* argv[])
{
    // File Descriptor
	int fd;

    // Buffer 
    char buffer[BUFFSIZE];

    // Byte size entered from stdin
    int byte_size; 

	// Bytes as message
	int bytes;

	// Line end to determine until next input is finished
	char line_end[10]; 
	int nextLine;

	// File name
	char filename[] = "file";

	// Start a named pipe
	mknod(filename, S_IFIFO|0640, 0);
	strcpy(line_end, "end");
    // Try and read into the file while this program is running
	while(1) 
	{	
		// Start opening the file with read permission
		printf("Opening file... >>> %s\n", filename); 
		fd = open(filename, O_RDWR);
		if (fd == -1) 
		{
			printf("An error occurred an opening the file >> file");
			return 1;
		}

		// Read the stdin in buffer
		/**
		 * @NOTE: REMEMBER THAT WE ARE USING CHAR ARRAYS AS THERE 
		 * 		  ARE NO STRING TYPE TO C. 
		 * 		  SO \0 IS NEEDED!!!!!!
		 * 
		 */
		bytes =  read(fd, buffer, sizeof(buffer));
		buffer[bytes] = '\0'; 				// this is needed for printing later on
		byte_size = (int)strlen(buffer);	// cast to int
		printf("Read >>> %s with %d\n  in size", buffer, byte_size);

		nextLine = strcmp(buffer, end);
      	if (nextLine == 0) {
			close(fd);
			break;
      	}
	}

    return 0;
}