#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

long thread_count;
long n;
int flag;
float sum;

void* Thread_sum(void* rank);

int main() {
    long       thread;
    pthread_t* thread_handles;

    n = 1000000;
    thread_count = 4;
    thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t)); 

    sum = 0.0;
    flag = 0;
    for (thread = 0; thread < thread_count; thread++)  
        pthread_create(&thread_handles[thread], NULL,Thread_sum, (void*)thread);  

    for (thread = 0; thread < thread_count; thread++) 
        pthread_join(thread_handles[thread], NULL); 


    printf("Pi=%f\n", sum);

    free(thread_handles);
    return 0;
}

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    
    
    return NULL;
}


