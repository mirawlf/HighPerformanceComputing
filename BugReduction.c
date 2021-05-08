#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

float dotprod(float * a, float * b, size_t N)
{
    int i, tid;
    float sum;

    //tid = omp_get_thread_num();
    omp_set_dynamic(0);
    omp_set_num_threads(5);

#pragma omp parallel for private(tid) reduction(+:sum) schedule(static)
  
    for (i = 0; i < N; ++i)
    {
        tid = omp_get_thread_num();
        sum += a[i] * b[i];
       // printf("%d %d %d", a[i], b[i], sum);
       // printf("tid = %d i = %d sum = %f\n", tid, i, sum);
    }

    printf("Sum = %f\n", sum);
    return sum;
}

int main (int argc, char *argv[])
{
    const size_t N = 10;
    int i;
    float  sum;
    float a[N], b[N];

    for (i = 0; i < N; ++i)
    {
        a[i] = b[i] = (double)i;
        //printf("%d %f %f\n", i, a[i],b[i]);
    }

    //sum = 0.0;

//#pragma omp parallel for shared(sum)
    
    sum = dotprod(a, b, N);

    printf("Sum = %f\n",sum);

    return 0;
}
