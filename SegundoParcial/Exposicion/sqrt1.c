#include <stdio.h>

// Función que regresa la raíz cuadrada redondeada hacia abajo de un número
unsigned long long int raizCuadradaEntera(unsigned long long int x) {
    // Casos base
    if (x == 0 || x == 1)
        return x;

    // Comenzando desde 1, probar todos los números hasta que
    // i*i sea mayor o igual que X.
    unsigned long long int i = 1, resultado = 1;
    while (resultado <= x) {
        i++;
        resultado = i * i;
    }
    return i - 1;
}

// Programa principal
int main() {
    unsigned long long int x;

    printf("Ingresa un número natural:\t");
    scanf("%llu", &x);

    printf("La raíz cuadrada redondeada de %llu es: %llu", x, raizCuadradaEntera(x));
    return 0;
}
