/**
	Document: creatingMutexLock.c
	Created on: July 12, 2022
	Author: Cloyd Van S. Secuya
	Description:
        This is how we can write code for creating mutex locks to handle race conditions and
        allow process sychronization
*/

// HEADER FILES
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

