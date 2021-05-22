#include "mpi.h"
#include <iostream>
#include <stdio.h>
#include <random>
#include <unistd.h>
#include <string.h>

const int NUM_PASSES = 5;

int get_random_process(int max)
{
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  std::uniform_int_distribution<> distr(0, max); // define the range

  int p =  distr(gen); // generate numbers

  return (p);
}

char *get_random_name(char *name)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr('a', 'z');

  int i = 0;

  name = new char[6];

  while (i < 6)
    name[i++] = distr(gen);

  return (name);
}

int rank_was_used(int **matrix, int rank, int psize)
{
  int j = 0;

  while(j < psize)
  {
    if (matrix[rank][j] == 1)
      return (1);
    j++;
  }
  return(0);
}

int main(int ac, char **av)
{
  int psize;
  int prank;
  int ierr;

  ierr = MPI_Init(&ac, &av);
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &prank);
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &psize);
  MPI_Status status;

  char  **names = new char*[psize]; //names of processes
  int   **acquaintances = new int*[psize]; //matrix of acquaintances

  double start = MPI_Wtime();
  if (prank == 0)
  {
    //creating names for all processors
    char  **names = new char*[psize]; //names of processes

    printf("Generated names:\n");

    for (int i = 0; i < psize; i++)
    {
      names[i] = get_random_name(names[i]);
      printf("%s\t", names[i]);
      printf("\n");
      acquaintances[i] = new int[psize];
      for (int j = 0; j < psize; j++)
        acquaintances[i][j] = 0; //initially nobody knows each other
    }
    
    int next_process;

    while ((next_process = get_random_process(psize)) == 0 or next_process >= psize)
      next_process = get_random_process(psize-1);
    
    MPI_Ssend(names[0], 6, MPI_CHAR, next_process, 9, MPI_COMM_WORLD);
    printf("Current rank = %d Number of remaining iterations: %d\n", prank, NUM_PASSES);
    int num_processors = psize - 1;
    printf("Current rank = %d Number of remaining processors: %d\n", prank, num_processors);
    MPI_Ssend(&NUM_PASSES, 1, MPI_INT, next_process, 25, MPI_COMM_WORLD);

    MPI_Ssend(&num_processors, 2, MPI_INT, next_process, 98, MPI_COMM_WORLD);
    for (int i = 0; i < psize; i++)
      for (int j = 0; j <psize; j++)
        MPI_Ssend(&acquaintances[i][j], 1, MPI_INT, next_process, 10, MPI_COMM_WORLD);

    int array_size;
    (NUM_PASSES <= num_processors) ? array_size = NUM_PASSES : array_size=num_processors;

    MPI_Ssend(&array_size, 1, MPI_INT, next_process, 3, MPI_COMM_WORLD);

    char **array_names = new char*[array_size];
    for (int i = 0; i < array_size; i++)
      array_names[i] = new char[6];
    array_names[0] = names[0];

    for (int i = 0; i < array_size; i++)
      MPI_Ssend(array_names[i], 6, MPI_CHAR, next_process, 16, MPI_COMM_WORLD);

    for (int i = 0; i < psize; i++)
      MPI_Ssend(names[i], 6, MPI_CHAR, next_process, 19, MPI_COMM_WORLD);
  }
  else
  {
    new int*[psize]; //matrix of acquaintances
    char  **names = new char*[psize];
    char  *buf = new char[6];
    int   buf_size;
    int   num_iter;
    int   started;
    int   remained_processors;
    MPI_Request *request;

    for (int i = 0; i < psize; i++)
    {
      acquaintances[i] = new int[psize];
      names[i] = new char[6];
    }

    MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

    MPI_Recv(buf, 6, MPI_CHAR, status.MPI_SOURCE, 9, MPI_COMM_WORLD, &status);

    MPI_Recv(&num_iter, 1, MPI_INT, status.MPI_SOURCE, 25, MPI_COMM_WORLD, &status);
    num_iter--;
    printf("Current rank = %d Number of remaining iterations: %d\n", prank, num_iter);

    MPI_Recv(&remained_processors, 2, MPI_INT, status.MPI_SOURCE, 98, MPI_COMM_WORLD, &status);
    remained_processors--;
    printf("Current rank = %d Number of remaining processors: %d\n", prank, remained_processors);
 
    for (int i = 0; i < psize; i++)
      for (int j = 0; j < psize; j++)
        MPI_Recv(&acquaintances[i][j], 1, MPI_INT, status.MPI_SOURCE, 10, MPI_COMM_WORLD, &status);

    int array_size;

    MPI_Recv(&array_size, 1, MPI_INT, status.MPI_SOURCE, 3, MPI_COMM_WORLD, &status);

    char **array_names = new char*[array_size];
    for (int i = 0; i < array_size; i++)
      array_names[i] = new char[6];

    for (int i = 0; i < array_size; i++)
      MPI_Recv(array_names[i], 6, MPI_CHAR, status.MPI_SOURCE, 16, MPI_COMM_WORLD, &status);

    for (int i = 0; i < psize; i++)
      MPI_Recv(names[i], 6, MPI_CHAR, status.MPI_SOURCE, 19, MPI_COMM_WORLD, &status);

    array_names[num_iter-1] = names[num_iter-1];
    
    acquaintances[status.MPI_SOURCE][prank]++;
    acquaintances[prank][status.MPI_SOURCE]++;

    if (remained_processors == 0)
    {
      printf("All sent names:\n");
      for (int i = 0; i < array_size; i++)
        printf("%s\t", array_names[i]);
      printf("\nProcessors are over\n");
      double end  = MPI_Wtime();
      printf("Elapsed time: %f ms\n", end - start);
      MPI_Abort(MPI_COMM_WORLD, MPI_ERR_OTHER);
    }

    if (num_iter > 0)
    {
      //sending to other processes
      int next_process;

      while ((next_process = get_random_process(psize)) == prank or next_process== 0 or next_process >= psize or acquaintances[prank][next_process] or rank_was_used(acquaintances, next_process, psize))
        next_process = get_random_process(psize-1);
      
      MPI_Ssend(names[prank], 6, MPI_CHAR, next_process, 9, MPI_COMM_WORLD);
      MPI_Ssend(&num_iter, 1, MPI_INT, next_process, 25, MPI_COMM_WORLD);
      MPI_Ssend(&remained_processors, 2, MPI_INT, next_process, 98, MPI_COMM_WORLD);
      for (int i = 0; i < psize; i++) 
        for (int j = 0; j <psize; j++)
          MPI_Ssend(&acquaintances[i][j], 1, MPI_INT, next_process, 10, MPI_COMM_WORLD);


      MPI_Ssend(&array_size, 1, MPI_INT, next_process, 3, MPI_COMM_WORLD);

      for(int i = 0; i < array_size; i++)
        MPI_Ssend(array_names[i], 6, MPI_CHAR, next_process, 16, MPI_COMM_WORLD);

      for (int i = 0; i < psize; i++)
        MPI_Ssend(names[i], 6, MPI_CHAR, next_process, 19, MPI_COMM_WORLD);
      delete[]buf;

    }
    else if (num_iter == 0)
    {
      printf("Rank = %d Iterations are over\n", prank);
      double end  = MPI_Wtime();
      printf("All sent names:\n");
      for (int i = 0; i < array_size; i++)
        printf("%s\t", array_names[i]);
      printf("\nElapsed time: %f ms\n", end - start);
      MPI_Abort(MPI_COMM_WORLD, MPI_ERR_OTHER );
    }
  }
  MPI_Finalize();
  double end  = MPI_Wtime();
  printf("Elapsed time: %f ms\n", end - start);

  return (0);
}
