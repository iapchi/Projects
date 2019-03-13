//libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
//define number of matrix length (N)
#ifndef A
#define A 1024
#endif
//define number of accuracy loops
#ifndef LOOPS
#define LOOPS 1
#endif
//cpu speed in gigahertz
#ifndef CPU_FREQ
#define CPU_FREQ 3.6e9
#endif

//differenciate for different operation systems and their time calculation
#if defined( _WIN32 ) || defined( _WIN64 )
#include <windows.h>
typedef unsigned __int64 tick_t;

#elif defined( __APPLE__ )
#include <mach/mach_time.h>
#include <string.h>

typedef uint64_t         tick_t;
static mach_timebase_info_data_t _timerlib_info;
static void absolutetime_to_nanoseconds (uint64_t mach_time, uint64_t* clock ) { *clock = mach_time * _timerlib_info.numer / _timerlib_info.denom; }
#else
#include <unistd.h>
#include <time.h>
#include <string.h>

typedef uint64_t         tick_t;
#endif

typedef double deltatime_t;
static tick_t _timerlib_freq    = 0;
static double _timerlib_oofreq  = 0;


//linux time calculation clocks
int timer_init()
{
#if defined( _WIN32 ) || defined( _WIN64 )
    tick_t unused;
    if( !QueryPerformanceFrequency( (LARGE_INTEGER*)&_timerlib_freq ) ||
        !QueryPerformanceCounter( (LARGE_INTEGER*)&unused ) )
        return -1;
#elif defined( __APPLE__ )
    if( mach_timebase_info( &_timerlib_info ) )
        return -1;
    _timerlib_freq = 1000000000ULL;
#else
    struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };
    if( clock_gettime( CLOCK_MONOTONIC, &ts ) )
        return -1;
    _timerlib_freq = 1000000000ULL;
#endif

    _timerlib_oofreq = 1.0 / (double)_timerlib_freq;

    return 0;
}

//windows time calculation
tick_t timer_current( void )
{
#if defined( _WIN32 ) || defined( _WIN64 )
    tick_t curclock;
    QueryPerformanceCounter( (LARGE_INTEGER*)&curclock );
    return curclock;

#elif defined( __APPLE__ )
    tick_t curclock = 0;
    absolutetime_to_nanoseconds( mach_absolute_time(), &curclock );
    return curclock;

#else
    struct timespec ts = { .tv_sec = 0, .tv_nsec = 0 };
    clock_gettime( CLOCK_MONOTONIC, &ts );
    return ( (uint64_t)ts.tv_sec * 1000000000ULL ) + ts.tv_nsec;
#endif
}

//conversion of time
deltatime_t ticks_to_time( const tick_t t )
{
    return (deltatime_t)(t * _timerlib_oofreq );
}


//main method
int main()
{
    long i;     // Variables for loops
    long j;
    long k;
    long num;

    double elapsedTime;          // Total computation time
    double elapsedTimePerMatrix; // Total time to compute matrix multiplication
    double elapsedTimePerMatrixElement;  // Avg time associated with a matrix element

    double computationTimeForOperations; // Computation time per arithmetic operation
    double machineCycles;       // No of machine cycles

    long long opsPerInstruction; // Number of arithmetic ops required per element
    
    time_t start_time; 
    time_t end_time;
    
    long** matrixX;
    long** matrixY;
    long** matrixZ;

    opsPerInstruction = 2;

    // Initialize matrix X
    matrixX = (long**) malloc(A * sizeof(long*));
    for (i = 0; i < A; ++i) {
        matrixX[i] = (long*) malloc(A * sizeof(long));
        for (j = 0; j < A; ++j) {
            matrixX[i][j] = (long)1 + rand() % 1000;
        }
    }

    // Initalize matrix Y
    matrixY = (long**) malloc(A * sizeof(long*));
    for (i = 0; i < A; ++i) {
        matrixY[i] = (long*) malloc(A * sizeof(long));
        for (j = 0; j < A; ++j) {
            matrixY[i][j] = (long)1 + rand() % 1000;
        }
    }


    // Initalize matrix Z
    matrixZ = (long**) malloc(A * sizeof(long*));
    for (i = 0; i < A; ++i) {
        matrixZ[i] = (long*) malloc(A * sizeof(long));
        for (j = 0; j < A; ++j) {
            matrixZ[i][j] = (long)1 + rand() % 1000;
        }
    }

    // Start time of multiplication
    start_time = (double)time(0);

    // Accuracy Improvement Loops
    for (num = 0; num < LOOPS; ++num) {
        // Perform matrix multiplication
        for (i = 0; i < A; ++i) {
            for (j = 0; j < A; ++j) {
                matrixZ[i][j] = 0;
                for(k = 0; k < A; ++k) {
                    matrixZ[i][j] = matrixZ[i][j] + matrixX[i][k] * matrixY[k][j];
                }
            }
        }
    }

    // End time of multiplication
    end_time = (double)time(0);

    //elapsed time in double precision format
    elapsedTime = (end_time - start_time); 
    printf("Jacky Li\nProgramming exercise 2\n");
    printf("Matrix Dimension= %d \nAccuracy Loops= %ld \n", A, (long)LOOPS);
    printf ("Total computation time: %lf \n", elapsedTime);
    
    elapsedTimePerMatrix = (double)elapsedTime / (double)LOOPS;
    printf ("Computation time for the complete NxN matrix multiplication: %lf \n", elapsedTimePerMatrix);

    elapsedTimePerMatrixElement = elapsedTimePerMatrix / (A * A * A);
    computationTimeForOperations = elapsedTimePerMatrixElement / opsPerInstruction ;
    printf ("Computation time per arithmetic operation: %0.4e \n", computationTimeForOperations);

    machineCycles = CPU_FREQ * elapsedTimePerMatrixElement / opsPerInstruction;
    printf ("The number of machine cycles per arithmetic operation: %lf \n", machineCycles);
    
    printf("Press enter key to exit..");
    fgetc(stdin);

    for (i = 0; i < A; ++i) {
        free(matrixX[i]);
        free(matrixY[i]);
        free(matrixZ[i]);
    }
    free(matrixX);
    free(matrixY);
    free(matrixZ);
    return 0;
}