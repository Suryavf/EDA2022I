#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Variables globales
int     thread_count;
int     m, n;
float** A;
float*  x;
float*  y;

void* AX_Y(void* rank);

/*
| 2 3 4 | |1|   |20|
| 5 6 7 | |2| = |38|
| 1 9 2 | |3|   |25|

*/

int main() {
    long       hilo;
    pthread_t* thread_handles;

    thread_count = 3;
    thread_handles = (pthread_t*)malloc(thread_count*sizeof(pthread_t));

    m = 3;
    n = 3;

    A = (float**)malloc(m*sizeof(float*));
    for(int i = 0; i < m; i++) 
        A[i] = (float *)malloc(n * sizeof(float));

    x = (float* )malloc(  n*sizeof(float ));
    y = (float* )malloc(  m*sizeof(float ));

    A[0][0] = 2; A[0][1] = 3; A[0][2] = 4;
    A[1][0] = 5; A[1][1] = 6; A[1][2] = 7;
    A[2][0] = 1; A[2][1] = 9; A[2][2] = 2;
    

    x[0] = 1; x[1] = 2; x[2] = 3;

    // Fork
    for (hilo = 0; hilo < thread_count; hilo++)
        pthread_create(&thread_handles[hilo], NULL, AX_Y, (void*) hilo);

    // Join
    for (hilo = 0; hilo < thread_count; hilo++)
        pthread_join(thread_handles[hilo], NULL);

    printf("Y:\n");
    printVector(y, m);

    free(A);
    free(x);
    free(y);
    free(thread_handles);

    return 0;
} 


void* AX_Y(void* hilo) {
    long hiloLocal = (long) hilo;

    int localM = m/thread_count;



    return NULL;
}

void printMatriz( float A[], int m, int n) {
   int i, j;
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
         printf("%4.1f ", A[i*n + j]);
      printf("\n");
   }
}
void printVector(float y[], int m) {
   int   i;
   for (i = 0; i < m; i++)
      printf("%4.1f ", y[i]);
   printf("\n");
}