#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// Una estructura para representar un Punto en un plano 2D
typedef struct {
    int x, y;
} Punto;

/* Las siguientes dos funciones son necesarias para la función de biblioteca qsort().
Referencia: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */

// Necesaria para ordenar el arreglo de puntos según la coordenada X
int compararX(const void* a, const void* b) {
    Punto *p1 = (Punto *)a, *p2 = (Punto *)b;
    return (p1->x - p2->x);
}

// Necesaria para ordenar el arreglo de puntos según la coordenada Y
int compararY(const void* a, const void* b) {
    Punto *p1 = (Punto *)a, *p2 = (Punto *)b;
    return (p1->y - p2->y);
}

// Función de utilidad para encontrar la distancia entre dos puntos
float distancia(Punto p1, Punto p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Método de Fuerza Bruta para devolver la distancia mínima entre dos puntos
// en P[] de tamanio n
float fuerzaBruta(Punto P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distancia(P[i], P[j]) < min)
                min = distancia(P[i], P[j]);
    return min;
}

// Función de utilidad para encontrar el mínimo de dos valores float
float minimo(float x, float y) {
    return (x < y) ? x : y;
}

// Función de utilidad para encontrar la distancia entre los puntos más cercanos de
// una franja de tamanio dado. Todos los puntos en strip[] están ordenados según
// la coordenada y. Tienen un límite superior en la distancia mínima como d.
float stripMasCercano(Punto strip[], int tamanio, float d) {
    float min = d; // Inicializa la distancia mínima como d

    qsort(strip, tamanio, sizeof(Punto), compararY);

    // Tomar todos los puntos uno por uno y probar los siguientes puntos
    // hasta que la diferencia entre las coordenadas y sea menor que d.
    for (int i = 0; i < tamanio; ++i)
        for (int j = i + 1; j < tamanio && (strip[j].y - strip[i].y) < min; ++j)
            if (distancia(strip[i], strip[j]) < min)
                min = distancia(strip[i], strip[j]);

    return min;
}

// Función recursiva para encontrar la distancia mínima. El arreglo P contiene
// todos los puntos ordenados según la coordenada x
float masCercanoUtil(Punto P[], int n) {
    // Si hay 2 o 3 puntos, usar fuerza bruta
    if (n <= 3)
        return fuerzaBruta(P, n);

    // Encontrar el punto medio
    int medio = n / 2;
    Punto puntoMedio = P[medio];

    // Calcular la menor distancia dl a la izquierda del punto medio y
    // dr en el lado derecho
    float dl = masCercanoUtil(P, medio);
    float dr = masCercanoUtil(P + medio, n - medio);

    // Encontrar la menor de las dos distancias
    float d = minimo(dl, dr);

    // Construir un arreglo strip[] que contiene puntos cercanos (más cercanos que d)
    // a la línea que pasa por el punto medio
    Punto strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - puntoMedio.x) < d)
            strip[j] = P[i], j++;

    // Encontrar los puntos más cercanos en strip. Retornar el mínimo de d y la distancia
    // más cercana en strip[]
    return minimo(d, stripMasCercano(strip, j, d));
}

// Función principal que encuentra la distancia mínima
// Este método usa principalmente masCercanoUtil()
float masCercano(Punto P[], int n) {
    qsort(P, n, sizeof(Punto), compararX);

    // Usar la función recursiva masCercanoUtil() para encontrar la distancia mínima
    return masCercanoUtil(P, n);
}

// Programa principal para probar las funciones anteriores
int main() {
    Punto P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("La distancia mínima es %f ", masCercano(P, n));
    return 0;
}
