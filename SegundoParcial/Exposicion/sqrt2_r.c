#include <stdio.h>

unsigned long long int raizCuadradaEnteraRec(unsigned long long int x, unsigned long long int inicio, unsigned long long int fin) {
    // Caso base: si el rango se reduce a un solo valor
    if (inicio > fin)
        return fin;

    unsigned long long int mitad = (inicio + fin) / 2;

    // Si x es un cuadrado perfecto
    if (mitad * mitad == x)
        return mitad;

    // Si mitad*mitad es menor que x, buscamos en la mitad superior
    if (mitad * mitad < x)
        return raizCuadradaEnteraRec(x, mitad + 1, fin);
    else // Si mitad*mitad es mayor que x, buscamos en la mitad inferior
        return raizCuadradaEnteraRec(x, inicio, mitad - 1);
}

// Función auxiliar para llamar a la versión recursiva
unsigned long long int raizCuadradaEntera(unsigned long long int x) {
    // Casos base
    if (x == 0 || x == 1)
        return x;

    // Llamada inicial a la función recursiva
    return raizCuadradaEnteraRec(x, 1, x / 2);
}

// Método principal
int main() {
    unsigned long long int x;

    printf("Ingresa un número natural:\t");
    scanf("%llu", &x);

    printf("La raíz cuadrada redondeada de %llu es: %llu", x, raizCuadradaEntera(x));
    return 0;
}
