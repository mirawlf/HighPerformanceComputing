#include <iostream>
#include <omp.h>
#include <random>
#include <stdio.h>

int main()
{

  std::cout << "Input: a coefficient, b coefficient; for distribution: mean, std (4 params)" << std::endl;

  int N = 100;
  double a;
  double b;
  double mean;
  double std;
  double err = 1e-3;
  double* y = new double[N];
  double* x = new double[N];

  std::cin >> a;
  std::cin >> b;
  std::cin >> mean;
  std::cin >> std;
 // std::cout << "\n" << std::endl;

  printf("a = %f, b = %f, mean = %f, std = %f\n", a, b, mean, std);
    
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> distr(0.0, 10.0);

  omp_set_dynamic(0);
  omp_set_num_threads(50);

  double start = omp_get_wtime();

#pragma omp parallel for 

  for (int i = 0; i < N; i++)
  {
    x[i] = gen();
    //y[i] = gen();
  }

  std::default_random_engine gen2;
  std::normal_distribution<double> dist(mean, std);

#pragma omp parallel for
  for (int i = 0; i < N; i++)
    y[i] = a*x[i] + b + gen2();

  double x1, y1, x2, xy;

  x1 = 0;
  y1 = 0;
  x2 = 0;
  xy = 0;

#pragma omp parallel for
  for (int i = 0; i < N; i++) 
  {
	   x1 += x[i];
	   y1 += y[i];
	   x2 += x[i]*x[i];
	   xy += x[i]*y[i];
   }

  x1 = x1/N;
  y1 = y1/N;
  x2 = x2/N;
  xy = xy/N;

  double a_eval = (xy - x1*y1) / (x2 - x1*x1);
  double b_eval = y1 - a_eval * x1;

  double end = omp_get_wtime();

  std::cout << "Evaluated a = " << a_eval << " " << "Real a = "<< a << std::endl;
  std::cout << "Evaluated b = " << b_eval << " " << "Real b =  "<< b << std::endl;
  std::cout << "Elapsed time: " << (end - start)*1000 << "ms" << std::endl;

  return (0);
} 
