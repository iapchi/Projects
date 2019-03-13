#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <omp.h>
//matrix length
#ifndef A
#define A 16
#endif
//cpu
#define CPU_FREQ 1.39e9
//accuracy loops
#define LOOPS 1
//thread
#ifndef NUM_THREADS
#define NUM_THREADS 1
#endif
int main(void)

{
  double elapsedTime;
  double t, t_end;
  double NumOfAddMul;
  int i, j, k, number;
  double **matrixX, **matrixY, **matrixZ;
  double *X_BLOCK, *Y_BLOCK, *Z_BLOCK;
  double sum;
  omp_set_num_threads(NUM_THREADS);

  /* Allocate the matrices */
  matrixX = (double **)malloc(A * sizeof(double *));
  matrixY = (double **)malloc(A * sizeof(double *));
  matrixZ = (double **)malloc(A * sizeof(double *));
  X_BLOCK = (double *)malloc(A*A * sizeof(double));
  Y_BLOCK = (double *)malloc(A*A * sizeof(double));
  Z_BLOCK = (double *)malloc(A*A * sizeof(double));

  for (i = 0; i<A; i++)
  // Initialize pointers to X
    {matrixX[i] = X_BLOCK + i*A;}
  for (i = 0; i<A; i++)
  // Initialize pointers to Y */
    {matrixY[i] = Y_BLOCK + i*A;}
  for (i = 0; i<A; i++)
  // Initialize pointers to Z */
    {matrixZ[i] = Z_BLOCK + i*A;}

  /* Parallelize filling in the matrices */
  #pragma omp parallel shared(matrixX, matrixY, matrixZ) private(i, j, k)
  {
    // Fill the matrixX
    #pragma omp for collapse(2)
    for (i = 0; i < A; i++)
    {
      for (j = 0; j < A; j++)
      {
        matrixX[i][j] = (1 + rand() % 100);
      }
    }

    // Fill the matrixY
    #pragma omp for collapse(2)
    for (i = 0; i < A; i++)
    {
      for (j = 0; j < A; j++)
      {
        matrixY[i][j] = (1 + rand() % 100);
      }
    }
  }
  //start time omp
  t = omp_get_wtime();

  /* Loop over the iterations for accuracy */
  for(number = 0; number < LOOPS; number++)
  {
    /* Parallelize these two inner loops, collapse them */
    #pragma omp parallel shared(matrixX, matrixY, matrixZ) private(i, j, k)
    {
      /* Do the matrix multiply in parallel */
      #pragma omp for collapse(2)
      for (i = 0; i < A; i++)
      {
        for (j = 0; j < A; j++)
        {
          sum = 0;
          for (k = 0; k < A; k++)
          {
            sum += matrixX[i][k] * matrixY[k][j];
          }
          matrixZ[i][j] = sum;
        }
      }
    }
  }

  //end time omp
  t_end = omp_get_wtime();
  elapsedTime = (double)(t_end - t);
  NumOfAddMul = (((2 * (double)A) - 1)*((double)A * (double)A)); // estimate of ops is (2n-1)*n^2

  printf("Size:%d Total time:%g Estimate number of ops:%g ", A, elapsedTime, NumOfAddMul);
  double perop = elapsedTime/NumOfAddMul;
  printf("one_Op = %0.4e ", perop);
  double cycle = CPU_FREQ*perop;
  printf("Cycles per OP = %0.2f ", cycle);
  double opcycle = 1/cycle;
  printf("Op per cycle = %0.2f\n", opcycle);
  
  /*Excel Friendly print with script
  printf("%d %g %g %0.4e %0.2e %0.2e", A, elapsedTime, NumOfAddMul, perop, cycle, opcycle)*/
  printf("Press enter key to exit..");
  fgetc(stdin);

  free(matrixX);
  free(matrixY);
  free(matrixZ);
  free(X_BLOCK);
  free(Y_BLOCK);
  free(Z_BLOCK);

}
