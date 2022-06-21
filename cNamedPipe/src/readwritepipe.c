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
int main(nt argc, char* argv[])
{

}