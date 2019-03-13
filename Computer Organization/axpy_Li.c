//libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
//define number of vector length
#ifndef A
#define A 10000
#endif
//define number of accuracy loops
#ifndef LOOPS
#define LOOPS 10000
#endif
//define maximum value for random generator, optional existance 
#ifndef MAXRAND
#define MAXRAND 200000
#endif
//cpu speed in hertz (SI base unit 1/seconds) 
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
//random generator to for filling vector
int * random_vector(int size)
{
	int * vec = (int *)malloc(sizeof(int)*size);
	int i;
	for(i=0; i < size; ++i)
		vec[i] = rand() % MAXRAND;
	return vec;
}


//main method
int main(int argc, char * argv[])
{
	srand(time(NULL));
	timer_init();
	//initialization to random int numbers
	int * y = random_vector(A);
	int * x = random_vector(A);
	int a = rand() % 100;

	int i,j;
	
	
	//clocks initialization
	tick_t ticks_total = 0;
	tick_t per_vector_total = 0;
	tick_t per_element_total = 0;
	tick_t start_of_vector, start_of_element;
	//start of total clock
	tick_t start_of_computation = timer_current();
	for(j=0; j < LOOPS; ++j)
	{
		//start of vector clock
		start_of_vector = timer_current();
		for(i=0; i < A; ++i)
		{
			//start of element clock
			start_of_element = timer_current();
			y[i] = a*x[i] + y[i];
			//end of element clock
			per_element_total += timer_current()-start_of_element;
		}
		//end of vector clock
		per_vector_total += timer_current()-start_of_vector;
	}
	//end of total clock 
	ticks_total = timer_current()-start_of_computation;
	deltatime_t total_sec = ticks_to_time(ticks_total);
	deltatime_t per_vector_msec = ticks_to_time(per_vector_total)/LOOPS*1000.;
	deltatime_t per_element_usec = ticks_to_time(per_element_total)*1000000./(LOOPS*A);
	double cycles_per_operation = CPU_FREQ*total_sec/(LOOPS*A);
	
	printf("Jacky Li\nProgramming exercise 1\n");
	printf("VectorLength= %d\nAccuracy Loops= %d\n", A, LOOPS);
	printf("Total computation time= %fs\nComputation time per axpy vector= %fms\n", total_sec, per_vector_msec);
	printf("Computation time per vector element= %fμs\nMachine cycles per operation= %f\n",per_element_usec, cycles_per_operation);
	//free memory from x,y
	free(x);
	free(y);

	printf("Press enter key to exit..");
	fgetc(stdin);
	
	return 0;
}