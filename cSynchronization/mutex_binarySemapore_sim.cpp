/**
 * @Author: Cloyd Van S. Secuya
 * Date of Creation: July 11, 2022
 * Description:
 *	This src file is simulating the use of mutex locks or binary semaphores.
 * 
*/


#include <iostream>

int counter = 5; 
int lock; 

void producer() 
{
    lock = 0;   // lock the critical section
    counter = counter + 1; 
    printf("Lock VAL: %d\n", lock); 
    printf("%d\n",counter);
}

void consumer() 
{
    lock = 1;   // unlock the critical section
    counter = counter - 1; 
    printf("Lock VAL: %d\n", lock); 
    printf("%d\n",counter);
}


int main()
{
    // Loop through according to the assigned lock as it exists
    while(true) 
    {
        // if (lock == 0)
            producer(); 
            
        // else if (lock == 1)
            consumer();
    }
    
    return 0;
}
