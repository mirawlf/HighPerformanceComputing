#include <stdio.h>
#include <omp.h>

int main()
{
    const size_t N = 100000;
    double step;

    double x, pi, sum = 0.;
    double start, end;

    step = 1. / (double)N;
    start = omp_get_wtime();   
    #pragma omp parallel for private(x) reduction(+:sum) //takes 0.0104 seconds
    for (int i = 0; i < N; ++i)
    {
        x = (i + 0.5) * step;
#pragma omp critical //without reduction 0.0054 seconds needed
        sum += 4.0 / (1. + x * x);
    }

    pi = step * sum;
    end = omp_get_wtime();
    printf("pi = %.16f\n", pi);
    printf("Time needed: %f seconds\n", end-start); 
    return 0;
}
