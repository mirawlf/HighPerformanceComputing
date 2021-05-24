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
    <img height="270" align="left" src="https://github.com/samymone/HighPerformanceComputing/blob/master/time.png" />
    <img height="270" align="center" src="https://github.com/samymone/HighPerformanceComputing/blob/master/bandwith.png" />
  </br>


***PingPongArray.cpp:*** in common similar to the previous task, but now not just last one name is sent to the next process, but an array of all previous names is sent

***CellularAutomataConst.cpp:*** 1D array of zeros and ones is divided into number of ranks parts. In this case constant boundary conditions are implemented. This means that each left and right parts communicates with respectively last right element of previous rank's part of array or first left element of next one (exchange ghosts). Staying on the particular element, taking into accout its neighbours, programm changes the value of this element with the help of some rule. My *rule* consists of the following: we have 3 random numbers that makes a binary number. This number is translated from binary to decimal in the order in which they are located. In case this number is even, current element of array becomes 0, otherwise 1. This program is developed for even number of elements in initial array, multiple of even number of processes (e.x. 2/4/8 proc for 8 elems in array).

  <br>
    <img height="50" align="center" src="https://github.com/samymone/HighPerformanceComputing/blob/master/Constant.png">
  </br>
  <br>
    <img height="50" align="center" src="https://github.com/samymone/HighPerformanceComputing/blob/master/Constant_res.png">
  </br>

***CellularAutomataPeriodic.cpp:*** almost the same as the first, but now all calculations are done within the particular rank. So, the are no communications between different ranks. Rule is the same. Requirements for array length and number of processers are also the same.

  <br>
    <img height="50" align="center" src="https://github.com/samymone/HighPerformanceComputing/blob/master/Periodic.png">
  </br>
  <br>
    <img height="50" align="center" src="https://github.com/samymone/HighPerformanceComputing/blob/master/Periodic_res.png">
  </br>





