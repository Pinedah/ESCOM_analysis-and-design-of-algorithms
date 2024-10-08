// C program to Find the Factorial Using for Loop
#include <stdio.h>

unsigned int factorial(unsigned int N) {
    int fact = 1, i;

    // Loop from 1 to N to get the factorial
    for (i = 1; i <= N; i++) {
        fact *= i;
    }

    return fact;
}

int main() {
    int N = 5;
    int fact = factorial(N);
    printf("Factorial of %d is %d", N, fact);
    return 0;
}