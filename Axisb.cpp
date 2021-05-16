#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int N = 10;
double eps = 0.001;


double error_calculation(double **A, double*X, double*Y)
{
  double *res = new double[N];
  double error = 0.0;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      res[i] += A[i][j]*X[j];


  error = fabs(res[0] - Y[0]);
  for (int i = 1; i < N; i++)
    if (fabs(res[i] - Y[i]) > error)
      error = fabs(res[i] - Y[i]);


  return (error);
}

/*
 * AX = Y; A - square matrix NxN; X and Y - matrices with size Nx1
 */

int main()
{
  double **A = new double*[N]; //square matrix
  double *Y = new double[N]; //resulting matrix
  double *X = new double[N];
  double *tmp = new double[N];

  int start = omp_get_wtime();
  //creating coefficient matrix A
  for (int i = 0; i < N; i++)
    A[i] = new double[N];

  //filling in matrix A
#pragma omp parallel for collapse(2)
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      unsigned int seed = rand();
      A[i][j] = rand_r(&seed)/(double)RAND_MAX;
      if (i == j and A[i][j] == 0)
        std::cout << "Zero element on the diagonal,calculations can't be done" \
          << std::endl;
    }

  /*for (int i = 0; i < N; i++)
    std::cout << A[i][4] << std::endl;*/

  //filling in matrix resulting matrix Y
#pragma omp parallel for 
  for (int i = 0; i < N; i++)
  {
    unsigned int seed = rand();
    Y[i] = rand_r(&seed);
  }

  /*A[0][0] = 1;
  A[0][1] = 2;
  A[0][2] = 3;
  A[1][0] = 4;
  A[1][1] = 5;
  A[1][2] = 7;
  A[2][0] = 6;
  A[2][1] = 8;
  A[2][2] = 10;

  Y[0] = 11;
  Y[1] = 32;
  Y[2] = 5;*/



 /* for (int n = 0; n < N; n++)
    std::cout << Y[n] << std::endl;*/

  omp_set_dynamic(0);
  omp_set_num_threads(16);

  //for the first approximation X is equal to Y
  for (int i = 0; i < N; i++)
    X[i] = Y[i];

  int n = 0;
  while (n < 30)
  {
    for (int i = 0; i < N; i++)
      tmp[i] = X[i];

#pragma omp parallel for shared(X, A, Y) 
    for (int i = 0; i < N; i++)
    {
      double s = 0;
      for (int j = 0; j < N; j++)
        if (j != i)
          s += A[i][j] * tmp[j];
      X[i] = Y[i]/A[i][i] - s/A[i][i];
      /*double upper_sum, lower_sum = 0;
      for (int i = 0; i < N; i++)
      {
        upper_sum += pow((tmp[i] - X[i]), 2);
        lower_sum += pow(tmp[i], 2);
      }
      norm = pow((upper_sum/lower_sum), 0.5);*/


    }
    printf("After calc:\n");
    printf("Error = %f\n", error_calculation(A, X, Y));
    if (error_calculation(A, X,Y) < eps)
    {
      printf("End of calculations!\n");
      double end= omp_get_wtime();
      printf("Elapsed time: %f ms", (end - start)*1000);
      return (0);
    }

    n++;
  }

  double end = omp_get_wtime();
  printf("Elapsed time: %f ms",(end - start)*1000);
  return(0);
}
