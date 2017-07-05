#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

//take input params as the size of the square matrix
int main(int argc, char *argv[])
{
    int N;
    srand(time(NULL));
    //validate for the number of arguments for the programme.
    if (argc != 2)
    {
        printf("Wrong number of input params.. Please set the N. \n");
    }
    N = atoi(argv[1]);
    //allocate memory in the heap for A, B and C matrices
    double *matrix_a;
    double *matrix_b;
    double *matrix_result;

    matrix_a = (double *)malloc(sizeof(double) * N * N);
    matrix_b = (double *)malloc(sizeof(double) * N * N);
    matrix_result = (double *)malloc(sizeof(int) * N * N);

    // fill matrix A and B with random ints
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix_a[i * N + j] = (double)rand() / RAND_MAX;
            matrix_b[i * N + j] = (double)rand() / RAND_MAX;
        }
    }
    printf("MAT A \n");
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < N; b++)
        {
            printf("%f ", matrix_a[a * N + b]);
        }
        printf("\n");
    }
    printf("\nMAT B \n");
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < N; b++)
        {
            printf("%f ", matrix_b[a * N + b]);
        }
        printf("\n");
    }
    //lets find the time spent to multiply A and B
    clock_t begin = clock();
    int local_sum = 0;
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < N; b++)
        {
            for (int c = 0; c < N; c++)
            {
                local_sum += matrix_a[a * N + c] * matrix_b[N * c + b];
            }
            matrix_result[a * N + b] = local_sum;
            local_sum = 0;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nMAT RESULT \n");
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < N; b++)
        {
            //  printf("%d ", matrix_result[a * N + b]);
        }
        //  printf("\n");
    }
    printf("\nTIME SPENT %f\n", time_spent);
}