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
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


pthread_t tid[2];		// thread id
pthread_mutex_t lock; 	// mutex
  
void* mutexLock(void* arg)
{	
	// Job Counter
	int counter;
	
	printf("Press <ENTER> key to initialize!"); 
	getchar(); 

	// Create a mutex lock on thread
	pthread_mutex_lock(&lock); 

	// Since we want to allow an input of ENTER key...
    printf("Press <ENTER> key");
	getchar(); 
	printf("Lock has been acquired!");
	
	unsigned long i = 0;
    counter += 1;
    
	printf("\n Job %d has started\n", counter);
	printf("Trying to get lock...\n");
    // for (i = 0; i < (0xFFFFFFFF); i++);
	printf("Got lock...currently holding...\n");

	// Try to unlock the created lock
	printf("Press <ENTER> key");
	getchar(); 
	pthread_mutex_unlock(&lock); 
    printf("\n Job %d has finished\n", counter);
	printf("Releasing lock....\n");
	printf("Locked Released....\n");

    return NULL;
}
  
int main(void)
{
	int n;
	int err; 
    int i = 0;
    int thread_handle;
	
	// Start to create a POSIX thread.
	/**
	 * @note 
	 * 		Construct a new pthread create object
	 * 		Furthermore, to make things much easier. 
	 * 		We will be using the using a reference operator to our function to point back to it.  
	 */
	thread_handle = pthread_create(&(tid[i]), NULL, &mutexLock, NULL); 	

	// Error checking 
	if (thread_handle != 0)
	{
		printf("\nAn error occurred while trying to initialize a pthread!"); 
		err = 1; 
		return err; 
	}	


    // while ((n = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0) {
    //     thread_handle = pthread_create(&(tid[i]), NULL, &mutexLock, NULL);
    //     if (thread_handle != 0)
    //         printf("\nThread can't be created : [%s]", strerror(thread_handle));
    //     i++;
    // }
  
    pthread_join(tid[0], NULL);		// open thread
    pthread_join(tid[1], NULL);		// close thread

    return 0;
}