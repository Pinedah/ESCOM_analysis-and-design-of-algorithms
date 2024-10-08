
#include <stdio.h>

int Fib(int n) {
    if (n < 1) {
        printf("Invalid Number of terms\n");
        return -1;
    }

    int prev1 = 1;
    int prev2 = 0;

    if (n == 1)
        return 1;

    int curr;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n = 6;
    printf("El fibonacci de %d es: \n", n);
    printf("%d", Fib(n));
    return 0;
}