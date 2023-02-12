#include <omp.h>
#include <stdio.h>

static long num_steps = 100000;
#define NUM_THREADS 2
double step;

int main()
{
    int i;
    double pi, sum;
    step = 1.0 / (double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for reduction(+:sum)
    for(i=0; i<num_steps; i++) {
        double x = (i + 0.5)*step;
        sum += 4.0 / (1.0 + x*x);
    }
    pi = sum * step;
    printf("PI is (%f) \n", pi);
}