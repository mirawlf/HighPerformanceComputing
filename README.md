# HighPerformanceComputing
Homeworks from High Performance Computing and Modern Architectures course at Skoltech

**OpenMP part**

---------------

***Axisb.cpp*** - implementation of Jacobi method for solving linear system of equation (matrix of cofficients and array of free coefficients are generatet randomly and this is the problem for the convergence of solution)

***Axisb2.cpp*** - implementation of Jacobi method for solving linear system of equation. The code was brought from <https://ru.wikipedia.org/wiki/Метод_Гаусса_—_Зейделя_решения_системы_линейных_уравнений>, I just added parallelization mechanism

***BugParFor.c, BugReduction.c*** - the task for that programs was to identify and fix the mistakes in code

***MatMul.c*** - ijk algorithm of matrix multiplication realized in parallel manner

***MonteCarloPi.c*** - Monte-Carlo parallel calculation of Pi value 

***Pi.c*** - parallel calculation of Pi value with the help of OpenMP

***Car.cpp*** - code for shifting an image (example: car.ppm -> new_car.ppm)

**MPI part**

------------
***PingPongOneItem.cpp:*** there are N peaople with particular, but random names and they are get acquainted to each other. Different ranks are different people. First starts rank 0. It chooses randomly next rank and passes its name to this next one. One can't choose itself and the rank that was already got acquainted to someone else. There are particular number of ranks and number of iterations during which all acquaintanceships are done. When all iterations are done but unused ranks remained ar vice versa, MPI_ABORT is called. All acquaintances are controlled via *acquaintances* matrix, number of rest iterations and ranks are sent through all processes.

  All names are generated randomly. Here are a couple of dependences conserning the size of the message aka name of the rank. All runnings were done with 6 iterations and 8 processors.
  
  ***Table with all data***
  
  <br>
    <img height="300" align="center" src="https://github.com/samymone/HighPerformanceComputing/blob/master/table.png/">
  </br>
  
  ***Strange time plot (right) and too primitime bandwith plot (left)***
    
  <br>
    <img height="300" align="right" src="https://github.com/samymone/HighPerformanceComputing/blob/master/time.png" />
    <img height="300" align="left" src="https://github.com/samymone/HighPerformanceComputing/blob/master/bandwith.png" />
  </br>
