#include <stdio.h>
#include <time.h>

unsigned long long int Fibonacci(unsigned long long int num){
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main() {
    unsigned long long int num;
    printf("Escribe el numero del fibonacci que deseas obtener ");
    scanf("%llu", &num);
    clock_t start, end;
    start = clock();
    unsigned long long int fib = Fibonacci(num);
    end = clock();
    printf("\nFibonacci de %llu es %llu", num, fib);
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo tomado fue: %.10f segundos\n", time_taken);
    return 0;
}