
#include <stdio.h>
#include <time.h>

unsigned int factorial(unsigned int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {

    int num;
    printf("Escribe el numero para calcular su factorial ");
    scanf("%d", &num);
    clock_t start, end;
    start = clock();
    int fact = factorial(num);
    end = clock();
    printf("\nFactorial de %d es %d", num, fact);
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo tomado fue: %.10f segundos\n", time_taken);
    return 0;




    return 0;
}
