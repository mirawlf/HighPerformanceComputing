//command line arguments: 1 - leftmost point
//*********************** 2 - rightmost point
//*********************** 3 - total number of points
//*********************** 4 - total number of threads

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>

//function to get the timings
unsigned long get_time()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        unsigned long ret = tv.tv_usec;
        ret /= 1000;
        ret += (tv.tv_sec * 1000);
        return ret;
}


//variables to store results of numerical integration
double mutex_res = 0;          // result of calculation using mutex method
double semaphore_res = 0;      // result of calculation using semaphore method
double busy_wait_res = 0;      // result of calculation using busy wait method

// global "flags"
pthread_mutex_t mutex;
sem_t semaphore;
int busy_wait_flag = 0;

// you may need this global variables, but you can make them inside main()
double a;                 // left point
double b;                 // right point
int n;                     // number of discretization points
double h;                 // distance between neighboring discretization points
int TOTAL_THREADS;

//mathematical function that we calculate the arc length (declaration, define it yourselves)
double function(double x);

//function to calculate the integrand
double integrand(double x);

//arc_length on a single thread
double serial_arc_length();

//multithreaded arc_length rule using busy waiting
void* busy_wait_arc_length(void*);
void busy_wait_main();

//multithreaded arc_length using mutex
void* mutex_arc_length(void*);
void mutex_main();

//multrthreaded arc_length using semaphore
void* semaphore_arc_length(void*);
void semaphore_main();

int main( int argc, char *argv[] )
{
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    n = atof(argv[3]);
    h = (b-a)/n;
    TOTAL_THREADS = atoi(argv[4]);
    printf("TOTAL NUMBER OF THREADS: %d\n", TOTAL_THREADS);    
    long start = get_time();
    double duration;
    double result = serial_arc_length(0, n);
    duration = (get_time() - start);
    printf("solution on a single thread: %f, time: %f milliseconds\n", result, duration);
    busy_wait_main();    
    mutex_main();
    semaphore_main();
    return 0;
}

double function(double x)
{
        
}

double integrand(double x)
{
        
}

double serial_arc_length(int start, int n_local)
{

}

void* busy_wait_arc_length(void* rank)
{
    
}

void* mutex_arc_length(void* rank)
{
    
}

void* semaphore_arc_length(void *rank)
{

}

void busy_wait_main()
{
    pthread_t* thread_ptr;
    thread_ptr = malloc( TOTAL_THREADS * sizeof(pthread_t));

    long start = get_time();
    double duration;

    //
    // write here
    //

    duration = (get_time() - start);
    printf("solution using busy waiting: %f, time: %f milliseconds\n", busy_wait_res, duration);

    free(thread_ptr);    
}

void mutex_main()
{
    // write your implementation here
}

void semaphore_main()
{
    // write your implementation here
}
