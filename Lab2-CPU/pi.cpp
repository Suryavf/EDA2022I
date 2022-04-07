#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long n;
float pi_approx;

int main(){
    // Variables
    float factor = 1.0;
    float sum = 0.0;
    int k;

    int thread_count = 4;
    n = 10000000;

#   pragma omp parallel for num_threads(thread_count) reduction(+:sum) private(k,factor) shared(n)
    for (k = 0; k < n; k++){
        if (k % 2 == 0) factor =  1.0;
        else            factor = -1.0;
        sum += factor/(2*k+1);
    }
    
    pi_approx = 4.0*sum;
    return 0;
}

