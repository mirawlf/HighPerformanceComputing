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
 // printf("rank = %d i = %d | %d %d %d | res = %d\n", rank, i,  prev, curr, next, res);
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

  MPI_Barrier(MPI_COMM_WORLD);  

  int left, right;
  int next, prev;

  next = (prank+1)%psize;
  prev = (prank == 0) ? psize - (prank+1)%psize : (prank - 1)%psize;

  if (prank % 2 == 0)
  {
    MPI_Recv(&left, 1, MPI_INT, prev, 9, MPI_COMM_WORLD, &status);
    MPI_Recv(&right, 1, MPI_INT, next, 19, MPI_COMM_WORLD, &status);
    MPI_Ssend(&CellularAutomataNew[N/psize-1], 1, MPI_INT, next, 3, MPI_COMM_WORLD);
    MPI_Ssend(&CellularAutomataNew[0], 1, MPI_INT, prev, 13, MPI_COMM_WORLD);
  }
  else if (prank % 2 == 1)
  {
    MPI_Ssend(&CellularAutomataNew[N/psize-1], 1, MPI_INT, next, 9, MPI_COMM_WORLD);
    MPI_Ssend(&CellularAutomataNew[0], 1, MPI_INT, prev, 19, MPI_COMM_WORLD);
    MPI_Recv(&left, 1, MPI_INT, prev, 3, MPI_COMM_WORLD, &status);
    MPI_Recv(&right, 1, MPI_INT, next, 13, MPI_COMM_WORLD, &status);
  }

  int c = N/psize;
  for (int i = 0; i < c; i++)
  {
    if (i == 0 && i != c-1 && (i + 1) != c-1)
      tmp[i] = rule(left, CellularAutomataNew[i], CellularAutomataNew[i+1], prank, i);
    else if (i == c-1 && i != 0 && (i - 1) != 0)
      tmp[i] = rule(CellularAutomataNew[i-1], CellularAutomataNew[i], right, prank, i);
    else if(i == 0 && (i + 1) == c-1)
      tmp[i] = rule(left, CellularAutomataNew[i], CellularAutomataNew[i+1], prank, i);
    else if(i == c-1 && i-1 == 0)
      tmp[i] = rule(CellularAutomataNew[i-1], CellularAutomataNew[i], right, prank, i);
    else if(i == 0 && i == c-1)
      tmp[i] = rule(left, CellularAutomataNew[i], right, prank, i);
    else
      tmp[i] = rule(CellularAutomataNew[i-1], CellularAutomataNew[i], CellularAutomataNew[i+1], prank, i);
  }
  MPI_Gather(tmp, N/psize, MPI_INT, CellularAutomataRes, N/psize, MPI_INT, 0, MPI_COMM_WORLD);

  if (prank == 0)
  {
    printf("Final cellular automata:\n");
    for (int i = 0; i < N; i++)
      printf("%d ", CellularAutomataRes[i]);
    printf("\n");
  }
  MPI_Finalize();
 }
