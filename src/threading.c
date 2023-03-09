#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThread(void *vargp)
{
    static int s = 0;
    printf("Inside Thread! Looped %d times.\n", ++s);
    return NULL;
}

void main()
{
    pthread_t tid;

    printf("Before Thread \n");

    pthread_create(&tid, NULL, myThread, NULL);
    
    pthread_join(tid, NULL);

    printf("After Thread \n");

    exit(0);
    return;
}