/**
	Document: cvssecuya_mutex.c
	Created on: July 12, 2022
	Author: Cloyd Van S. Secuya
	Description:
		Simulating the concept of mutex locks.
		By holding and releasing processes based on keys.
		A process may take hold of a lock, upon ENTER key, it will release it. 
		On the other hand, this process who currently holds the lock, is in possession of the lock.

		Another process may take hold of the lock, but it has to wait from 
		the process who currently holds to releast the lock.

		Example:
		* Creating lock....

		Process 1: Get and hold lock....
		* Lock in possession of Process 1
		Process 2: I must wait for process 1 to release it.

		Process 1: Release and let go lock....
		* Lock...released
		Process 2: Now, I can get the lock.
		Process 2: Get and hold the lock
		* Lock in possession of Process 2
*/

// HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

// Define struct
/* We need to define a flock structure to set up file locking */
/**
 * @brief 
 *      Setting the lock consists of filling out a struct flock (declared in fcntl.h) 
 *      that describes the type of lock needed, 
 *      open()ing the file with the matching mode, and calling fcntl() with the proper arguments
 *      Reference:  https://www.ict.griffith.edu.au/teaching/2501ICT/archive/guide/ipc/flock.html
 */
// Init this flock before main
struct flock fl = {
    F_WRLCK,            // l_type 
    SEEK_SET,           // l_whence
    0,                  // l_start
    0,                  // l_len
    0                   // l_pid
};

int main(int argc, char *argv[]) 
{
    // Declare struct obj
    fl.l_pid = getpid(); 

    // File Descriptor for using opening and closing
    int fd; 

    // Start reading if some parameters are passed in cli
    if (argc > 1) 
    {
        fl.l_type = F_RDLCK;
        printf("\nReading some arguments in execution!\n");
    }
    
    // Start opening some file with read and write mode
    /** Our source file can be opened 
     *  Then implement error handling. 
     *  if this returns a negative int. Something went wrongs
    */
    printf("\nOpening file...\n");
    fd = open("../src/cvssecuya_Mutex-Sim.c", O_RDWR);
    if (fd == -1) 
    {
        perror("File may not exist or may be renamed!");        // this is alternative to stderr in debugging error
        printf("An error occurred in opening the file\n");
        return 1; 
    }

    else
    {
        printf("Source file opened successfull! \n");
    }

    /**
     * START LOCKING! Upon pressing Enter key
     */
    printf("Press <RETURN> to try to get lock: ");
    getchar();
    printf("Trying to get lock...");

    int setlkw = fcntl(fd, F_SETLKW, &fl); 
    if (setlkw == -1)
    {
        perror("Problem with sytem call to ammend read-write lock!");
        printf("An error occurred in getting the lock\n");
        return 2; 
    }

    else 
    {        
        printf("Lock hold!\n");
        printf("Press <RETURN> to release lock: ");
        getchar();
    }

    /**
     * START UNLOCKING! 
     */
    fl.l_type = F_UNLCK;  /* set to unlock same region */
    int setlk = fcntl(fd, F_SETLK, &fl);
    if (setlk == -1) 
    {
        perror("Problem with sytem call to ammend read-write lock!");
        printf("An error occurred in releasing the lock\n");
        return 2; 
    }

    printf("Unlocked.\n");
    close(fd);
}
