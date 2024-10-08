
#include <stdio.h>
#include <time.h>
unsigned int factorial(unsigned int N)
{
    int fact = 1, i;

    for (i = 1; i <= N; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int N;
    printf("Escribe el numero para calcular su factorial ");
    scanf("%d", &N);
    clock_t start, end;
    start = clock();
    int fact = factorial(N);
    end = clock();
    printf("\nFactorial de %d es %d", N, fact);
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo tomado fue: %.10f segundos\n", time_taken);
    return 0;
} 
