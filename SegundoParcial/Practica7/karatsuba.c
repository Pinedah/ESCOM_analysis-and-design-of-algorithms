#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Función auxiliar para hacer que ambas cadenas tengan la misma longitud
int makeEqualLength(char **str1, char **str2) {
    int len1 = strlen(*str1);
    int len2 = strlen(*str2);
    if (len1 < len2) {
        char *temp = (char *)malloc(len2 + 1);
        for (int i = 0; i < len2 - len1; i++)
            temp[i] = '0';
        strcpy(temp + (len2 - len1), *str1);
        free(*str1);
        *str1 = temp;
        return len2;
    } else if (len1 > len2) {
        char *temp = (char *)malloc(len1 + 1);
        for (int i = 0; i < len1 - len2; i++)
            temp[i] = '0';
        strcpy(temp + (len1 - len2), *str2);
        free(*str2);
        *str2 = temp;
    }
    return len1;
}

// Función para sumar dos cadenas de bits
char *addBitStrings(char *first, char *second) {
    makeEqualLength(&first, &second);
    int length = strlen(first);
    char *result = (char *)malloc(length + 2);
    result[length + 1] = '\0';
    int carry = 0;

    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';
        int sum = (firstBit ^ secondBit ^ carry);
        result[i + 1] = sum + '0';
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry) {
        result[0] = '1';
        return result;
    } else {
        memmove(result, result + 1, length + 1);
        return result;
    }
}

// Multiplicación de un solo bit
int multiplyiSingleBit(char *a, char *b) {
    return (a[0] - '0') * (b[0] - '0');
}

// Función principal para multiplicar dos cadenas de bits
long int multiply(char *X, char *Y) {
    makeEqualLength(&X, &Y);
    int n = strlen(X);

    if (n == 0) return 0;
    if (n == 1) return multiplyiSingleBit(X, Y);

    int fh = n / 2;
    int sh = n - fh;

    char *Xl = (char *)malloc(fh + 1);
    strncpy(Xl, X, fh);
    Xl[fh] = '\0';
    char *Xr = X + fh;

    char *Yl = (char *)malloc(fh + 1);
    strncpy(Yl, Y, fh);
    Yl[fh] = '\0';
    char *Yr = Y + fh;

    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    char *sumX = addBitStrings(Xl, Xr);
    char *sumY = addBitStrings(Yl, Yr);
    long int P3 = multiply(sumX, sumY);

    free(Xl);
    free(Yl);
    free(sumX);
    free(sumY);

    return P1 * (1L << (2 * sh)) + (P3 - P1 - P2) * (1L << sh) + P2;
}

// Programa principal
int main() {

    char num1[30], num2[30];
    printf("Ingrese el primer numero: ");
    scanf("%s", num1);
    printf("Ingrese el segundo numero: ");
    scanf("%s", num2);

    clock_t start, end;

    start = clock();
    long int resultado = multiply(num1, num2);
    end = clock();
    printf("El resultado de la multiplicacion es: %ld\n", resultado);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("El tiempo tomado es de %.10f", time_taken);

    return 0;
}
