#include "mpi.h"
#include <stdio.h>
#include <random>
#include <stdio.h>
#include <iostream>
#include <math.h>

const int N = 8; //length of array

int  rule(int prev, int curr, int next, int rank, int i)
{
  int res = prev * pow(2, 2) + curr * pow(2, 1) + next * pow(2, 0);
  //printf("rank = %d i = %d | %d %d %d | res = %d\n", rank, i,  prev, curr, next, res);
  if (res%2 == 1)
    return (1);
  return (0);

}

int main(int ac, char **av)
{
  int psize;
  int prank;
  int ierr;
  int *CellularAutomata = new int[N];
  int *CellularAutomataNew = new int[N];
  int *tmp = new int[N];
  int *CellularAutomataRes = new int[N];
  MPI_Status  status;

  std::random_device  rd;
  std::mt19937  gen(rd());
  std::uniform_int_distribution<> distr(0, 1);

  ierr = MPI_Init(&ac, &av);
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &prank);
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &psize);

  double start = MPI_Wtime();

  if (prank == 0)
  {
    for (int i = 0; i < N; i++)
      CellularAutomata[i] = distr(gen);

    printf("Initial cellular automata:\n");
    for (int i = 0; i < N; i++)
      printf("%d ", CellularAutomata[i]);
    printf("\n");
  }
  MPI_Scatter(CellularAutomata, N/psize, MPI_INT, CellularAutomataNew, N/psize, \
      MPI_INT, 0, MPI_COMM_WORLD);

  MPI_Scatter(CellularAutomataRes, N/psize, MPI_INT, tmp, N/psize, MPI_INT,  0, \
      MPI_COMM_WORLD);
  
  int c = N/psize;

  for (int i = 0; i < c; i++)
  {
    if (i == 0 && i != c-1 && (i + 1) != c-1)
      tmp[i] = rule(CellularAutomataNew[c-1], CellularAutomataNew[i], CellularAutomataNew[i+1], prank, i);
    else if (i == c-1 && i != 0 && (i - 1) != 0)
      tmp[i] = rule(CellularAutomataNew[i-1], CellularAutomataNew[i], CellularAutomataNew[0], prank, i);
    else if(i == 0 && (i + 1) == c-1)
      tmp[i] = rule(CellularAutomataNew[c-1], CellularAutomataNew[i], CellularAutomataNew[c-1], prank, i);
    else if(i == c-1 && i-1 == 0)
      tmp[i] = rule(CellularAutomataNew[0], CellularAutomataNew[i], CellularAutomataNew[0], prank, i);
    else if(i == 0 && i == c-1)
      tmp[i] = rule(CellularAutomataNew[i], CellularAutomataNew[i], CellularAutomataNew[i], prank, i);
    else
      tmp[i] = rule(CellularAutomataNew[i-1], CellularAutomataNew[i], CellularAutomataNew[i+1], prank, i);
  }

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Gather(tmp, N/psize, MPI_INT, CellularAutomataRes, N/psize, MPI_INT, 0, MPI_COMM_WORLD);

  if (prank == 0)
  {
    printf("Final cellular automata:\n");
    for (int i = 0; i < N; i++)
      printf("%d ", CellularAutomataRes[i]);
    printf("\n");
  }
  MPI_Finalize();
  double end = MPI_Wtime();
  printf("Elapsed time: %f ms\n", (end - start)*1000);
 }
