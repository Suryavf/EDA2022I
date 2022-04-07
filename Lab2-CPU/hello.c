#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int cantidadHilos;
void* Hello(void* hilo);


int main() {
    long hilo;   // 64 bits
    cantidadHilos = 4;
    
    pthread_t* handles;
    handles = (pthread_t*)malloc( cantidadHilos*sizeof(pthread_t) );

    for (hilo=0;hilo<cantidadHilos;hilo++){
        // Fork
        pthread_create(&handles[hilo],NULL,Hello,(void*)hilo);
    }
    printf("Lanzamos a todos :D\n");
    for (hilo=0;hilo<cantidadHilos;hilo++){
        // Join
        pthread_join(handles[hilo],NULL);
    }

    free(handles);
    return 0;
}

void* Hello(void* hilo) {
    long hiloLocal = (long) hilo;
    printf("Hola hilo %ld, como estas?\n",hiloLocal);
    return NULL;
}

