#include <omp.h>
#include <stdio.h>

int main() {
    double sum = 0.0;
    int i;
    double pi_approx;
    #pragma omp parallel for reduction(+:sum) private(factor)
        for(i=0; i<1000000; i++) {
            if (i % 2 == 0) {
                factor = 1.0;
            } else {
                factor = -1.0;
            }
            sum += factor / (2*i+1);
        }
    pi_approx = 4.0*sum;
    printf("Pi approximation is %f \n", pi_approx);
}