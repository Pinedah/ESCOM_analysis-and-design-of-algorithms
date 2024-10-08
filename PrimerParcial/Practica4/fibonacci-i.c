#include <time.h>
#include <stdio.h>

unsigned long long int Fib(int n) {
    if (n < 1) {
        printf("Invalid Number of terms\n");
        return -1;
    }

    unsigned long long int prev1 = 1;
    unsigned long long int prev2 = 0;

    if (n == 1)
        return 1;

    unsigned long long int curr;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {//93
    int num;
    printf("Escribe el numero del fibonacci que deseas obtener ");
    scanf("%d", &num);
    clock_t start, end;
    start = clock();
    unsigned long long int fib = Fib(num);
    end = clock();
    printf("\nFibonacci de %d es %llu", num, fib);  
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo tomado fue: %.10f segundos\n", time_taken);
    return 0;
}