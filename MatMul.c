#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void zero_init_matrix(double ** matrix, size_t N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}

void rand_init_matrix(double ** matrix, size_t N)
{
    unsigned int seed = rand();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand_r(&seed) / (double)RAND_MAX;
        }
    }
}

double ** malloc_matrix(size_t N)
{
    double ** matrix = (double **)malloc(N * sizeof(double *));
    
    for (int i = 0; i < N; ++i)
    {   
        matrix[i] = (double *)malloc(N * sizeof(double));
    }
    
    return matrix;
}

void free_matrix(double ** matrix, size_t N)
{
    for (int i = 0; i < N; ++i)
    {   
        free(matrix[i]);
    }
    
    free(matrix);
}

int main()
{
    const size_t N = 5000; // size of an array

    double start, end;   
 
    double ** A, ** B, ** C; // matrices

    int i,j,k;

    omp_set_dynamic(0);
    omp_set_num_threads(6);

    printf("Starting:\n");
    A = malloc_matrix(N);
    B = malloc_matrix(N);
    C = malloc_matrix(N);    

    rand_init_matrix(A, N);
    rand_init_matrix(B, N);
    zero_init_matrix(C, N);

    start = omp_get_wtime();

#pragma omp parallel for collapse(3)
    for (i = 0; i<N; i++)
    {
      for (j = 0; j<N; j++)
      {
        for (k = 0; k<N; k++)
        {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }


    end = omp_get_wtime();
    printf("Time elapsed (ijk): %f seconds.\n", (double)(end - start));

    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C, N);

    return 0;
}
