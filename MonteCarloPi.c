#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(int ac, char **av)
{
  const size_t  N = 10000000;
  int counter = 0;
  double pi;
  double x, y;
  double start, end;

  if (ac < 2)
  {
    printf("You need to write the num of threads\n");
    return (0);
  }

  int num_threads = atoi(av[1]);
  int chunkSize = N/num_threads;

  start = omp_get_wtime();

  omp_set_dynamic(0);
  omp_set_num_threads(num_threads);

  printf("Number of threads equals to %d\n", num_threads);

#pragma omp parallel for private(x, y) reduction(+:counter)

  for (int i = 0; i < N; i++)
  {
    unsigned int seed = rand();
    x = rand_r(&seed)/(double)RAND_MAX;
    y = rand_r(&seed)/(double)RAND_MAX;


    if (x*x + y*y < 1)
      counter += 1;
  }

  end = omp_get_wtime();

  pi = 4.0*counter/N;

  printf("Pi = %f\n", pi);

  printf("Elapsed time: %f ms", (end - start)*1000);

  return(0);
}
