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
int main(nt argc, char* argv[])
{
    
}