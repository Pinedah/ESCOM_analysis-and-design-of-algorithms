#include <stdio.h>

int Fibonacci(int num){
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main() {
    int n = 6;
    printf("El fibonacci de %d es: \n", n);
    printf("%d", Fibonacci(n));
    return 0;
}