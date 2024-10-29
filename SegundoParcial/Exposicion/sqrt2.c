#include <stdio.h>

unsigned long long int raizCuadradaEntera(unsigned long long int x) {
    // Casos base
    if (x == 0 || x == 1)
        return x;

    // Realizar búsqueda binaria para floor(sqrt(x))
    unsigned long long int inicio = 1, fin = x / 2, respuesta = 0;

    
    while (inicio <= fin) {

        printf("\n\nInicio = %llu, Fin = x/2 = %llu, Respuesta = %llu\n", inicio, fin, respuesta);
        
        unsigned long long int mitad = (inicio + fin) / 2;
        printf("Mitad = %llu", mitad);

        // Si x es un cuadrado perfecto
        if (mitad * mitad == x)
            return (unsigned long long int)mitad;

        // Dado que necesitamos el piso, actualizamos la respuesta cuando
        // mitad*mitad es menor que x, y nos acercamos a sqrt(x)
        if (mitad * mitad < x) {
            inicio = mitad + 1;
            respuesta = mitad;
        }else // Si mitad*mitad es mayor que x
            fin = mitad - 1;
    }
    return (unsigned long long int)respuesta;
}

// Método principal
int main() {
    unsigned long long int x;

    printf("Ingresa un número natural:\t");
    scanf("%llu", &x);

    printf("\nLa raíz cuadrada redondeada de %llu es: %llu", x, raizCuadradaEntera(x));
    return 0;
}
