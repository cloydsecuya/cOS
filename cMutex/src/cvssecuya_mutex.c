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

pthread_t tid[2];
int counter;
  
void* trythis(void* arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("\n Job %d has finished\n", counter);
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
  
    return 0;
}