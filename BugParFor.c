#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    const size_t N = 100;
    const size_t chunk = 3;

    int i, tid;
    float a[N], b[N], c[N];

    omp_set_num_threads(20);
    printf("Current number of threads is %d\n",omp_get_max_threads());
    omp_set_dynamic(0);

    for (i = 0; i < N; ++i)
    {
        a[i] = b[i] = (float)i;
    }

#pragma omp parallel
   // shared(a,b,c,chunk) \
   // private(i,tid) \
    //schedule(static,chunk)
    {
        tid = omp_get_thread_num();

#pragma parallel omp for shared(a,b,c,chunk) private(i,tid) schedule(static,chunk)
        for (i = 0; i < N; ++i)
        {
            c[i] = a[i] + b[i];
            printf("tid = %d, c[%d] = %f\n", tid, i, c[i]);
        }
    } 

    return 0;
}
