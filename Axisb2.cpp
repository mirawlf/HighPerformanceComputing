#include <iostream>
#include <cmath>
#include <omp.h>
#include <chrono>
#include <ctime>

using namespace std;

// Условие окончания
bool converge(double xk[10], double xkp[10], int n, double eps)
{
	double norm = 0;
#pragma omp parallel for  num_threads(4) 
	for (int i = 0; i < n; i++)
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
	return (sqrt(norm) < eps);
}

double okr(double x, double eps)
{
	int i = 0;
	double neweps = eps;
	while (neweps < 1)
	{
		i++;
		neweps *= 10;
	}
	int okr = pow(double(10), i);
	x = int(x * okr + 0.5) / double(okr);

	return x;
}

bool diagonal(double a[10][10], int n)
{
	int i, j, k = 1;
	double sum;

#pragma omp parallel for num_threads(4) 
	for (i = 0; i < n; i++) {
		sum = 0;
#pragma omp parallel for reduction(-:sum)
		for (j = 0; j < n; j++) sum += abs(a[i][j]);
		sum -= abs(a[i][i]);
		if (sum > a[i][i]) 
		{
			k = 0; 
			cout << a[i][i] << " < " << sum << endl;
		}
		else
		{
			cout << a[i][i] << " > " << sum << endl;
		}
		

	}

	return (k == 1);

}




int main()
{
	setlocale(LC_ALL, "");

	double eps, a[10][10], b[10], x[10], p[10];
	int n, i, j, m = 0;
	int method;
	cout << "Введите размер квадратной матрицы: ";
	cin >> n;
	cout << "Введите точность вычислений: ";
	cin >> eps;
	cout << "Заполните матрицу А: " << endl << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << endl << endl;
	cout << "Ваша матрица А: " << endl << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	cout << "Заполните столбец свободных членов: " << endl << endl;
	for (i = 0; i < n; i++)
	{
		cout << "В[" << i + 1 << "] = ";
		cin >> b[i];
	}

	cout << endl << endl;


  
	/*
	Ход метода, где:
	a[n][n] - Матрица коэффициентов
	x[n], p[n] - Текущее и предыдущее решения
	b[n] - Столбец правых частей
	Все перечисленные массивы вещественные и
	должны быть определены в основной программе,
	также в массив x[n] следует поместить начальное
	приближение столбца решений (например, все нули)
	*/
  double start = omp_get_wtime();

	for (int i = 0; i < n; i++)
		x[i] = 1;

	cout << "Диагональное преобладание: " << endl;
	if (diagonal(a, n)) {
		do
		{
			for (int i = 0; i < n; i++)
				p[i] = x[i];
			for (int i = 0; i < n; i++)
			{
				double var = 0;
				for (int j = 0; j < n; j++)
                    if(j!=i) var += (a[i][j] * x[j]);
				
				x[i] = (b[i] - var) / a[i][i];
			}
			m++;
		} while (!converge(x, p, n, eps));



		cout << "Решение системы:" << endl << endl;
		for (i = 0; i < n; i++) cout << "x" << i << " = " << okr(x[i], eps) << "" << endl;
		cout << "Итераций: " << m << endl;
	}
	else {
		cout << "Не выполняется преобладание диагоналей" << endl;
	}

  double end = omp_get_wtime();

  std::cout<<"Elapsed time:"<<(end-start)*1000<<"ms\n";  
  return 0;
}
