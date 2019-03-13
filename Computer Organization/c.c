//C program for multiplication of two square matrices
// SIZE define dimensions of the arrays
// RAN sets the range of random numbers generated to fill arrays
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#ifndef SIZE
#define SIZE 1024
#endif

#define CPU_CLK 2.4E9 //you must fill in CPU clock frequency for the machine code is being run on
// SIZE is dimensin ot the square matrix
#define RAN 10
#define MAX_CTR 1
#define NUM_THREADS 4

int main(void)

{
	double total_time;
  double t, t_end;
	double scale;
	double NumOfElements;
	double NumOfAddMul;
	double FLOPS;
	double CPI;
	int	i, j, k, ctr;
	double **a, **b, **c;
	double *a_block, *b_block, *c_block;
	double ExeTimePerOp;
  double sum;
  omp_set_num_threads(NUM_THREADS);

  /* Allocate the matrices */
	a = (double **)malloc(SIZE * sizeof(double *));
	b = (double **)malloc(SIZE * sizeof(double *));
	c = (double **)malloc(SIZE * sizeof(double *));
	a_block = (double *)malloc(SIZE*SIZE * sizeof(double)); /* Storage for matrices */
	b_block = (double *)malloc(SIZE*SIZE * sizeof(double));
	c_block = (double *)malloc(SIZE*SIZE * sizeof(double));

	for (i = 0; i<SIZE; i++)
	{/* Initialize pointers to a */
		a[i] = a_block + i*SIZE;
	}
	for (i = 0; i<SIZE; i++)
	{/* Initialize pointers to b */
		b[i] = b_block + i*SIZE;
	}

	for (i = 0; i<SIZE; i++)
	{/* Initialize pointers to c */
		c[i] = c_block + i*SIZE;
	}

  /* Parallelize filling in the matrices */
  #pragma omp parallel shared(a, b, c) private(i, j, k)
  {
    /* Fill the a matrix */
    #pragma omp for collapse(2)
    for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
      {

        a[i][j] = (1 + rand() % RAN);
      }
    }

    /* Fill the b matrix */
    #pragma omp for collapse(2)
    for (i = 0; i < SIZE; i++)
    {
      for (j = 0; j < SIZE; j++)
      {

        b[i][j] = (1 + rand() % RAN);
      }
    }
  }

  t = omp_get_wtime();

  /* Loop over the iterations for accuracy */
  for(ctr = 0; ctr < MAX_CTR; ctr++)
  {
    /* Parallelize these two inner loops, collapse them */
    #pragma omp parallel shared(a, b, c) private(i, j, k)
    {
      /* Do the matrix multiply in parallel */
      #pragma omp for collapse(2)
      for (i = 0; i < SIZE; i++)
      {
        for (j = 0; j < SIZE; j++)
        {
          sum = 0;
          //#pragma omp for reduction(+:sum)
          for (k = 0; k < SIZE; k++)
          {
            sum += a[i][k] * b[k][j];
          }
          c[i][j] = sum;
        }
      }
    }
  }

  /* Print out the results in an Excel-friendly format */
  t_end = omp_get_wtime();
  total_time = ((double)(t_end - t) / (double)CLOCKS_PER_SEC);
  NumOfAddMul = (((2 * (double)SIZE) - 1)*((double)SIZE * (double)SIZE)); // estimate of ops is (2n-1)*n^2

  printf("%d %g %g\n", SIZE, total_time, 
                       NumOfAddMul);

	free(a);
	free(b);
	free(c);
	free(a_block);
	free(b_block);
	free(c_block);

}
