// C program to find factorial of given number
// using recursion
#include <stdio.h>

unsigned int factorial(unsigned int n) {
  
    // Base Case:
    if (n == 1) {
        return 1;
    }

    // Multiplying the current N with the previous product
    // of Ns
    return n * factorial(n - 1);
}

int main() {
    int num = 5;
    printf("Factorial of %d is %d", num, factorial(num));
    return 0;
}
