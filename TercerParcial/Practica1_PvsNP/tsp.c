#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 8 // Número de ciudades

// Función para encontrar la ciudad más cercana no visitada
int ciudadMasCercana(int graph[][N], bool visitado[], int ciudadActual) {
    int minDistancia = INT_MAX;
    int ciudadCercana = -1;

    for (int i = 0; i < N; i++) {
        if (!visitado[i] && graph[ciudadActual][i] < minDistancia && i != ciudadActual) {
            minDistancia = graph[ciudadActual][i];
            ciudadCercana = i;
        }
    }

    return ciudadCercana;
}

// Función para resolver TSP usando enfoque Greedy
int tspGreedy(int graph[][N]) {
    bool visitado[N] = {false}; // Arreglo para rastrear las ciudades visitadas
    int ciudadActual = 0;       // Empezamos desde la ciudad 0
    visitado[ciudadActual] = true;

    int costoTotal = 0;
    int siguienteCiudad;

    printf("Recorrido: Nodo %d -> ", ciudadActual+1);

    for (int i = 0; i < N - 1; i++) {
        siguienteCiudad = ciudadMasCercana(graph, visitado, ciudadActual);

        if (siguienteCiudad == -1) {
            break;
        }

        printf("Nodo %d -> ", siguienteCiudad+1);

        costoTotal += graph[ciudadActual][siguienteCiudad];
        visitado[siguienteCiudad] = true;
        ciudadActual = siguienteCiudad;
    }

    // Regresar a la ciudad inicial
    costoTotal += graph[ciudadActual][0];
    printf("Nodo 1\n");

    return costoTotal;
}

// Función principal
int main() {
    // Matriz de distancias entre ciudades
    int graph[N][N] = {
        {0, 3, 4, 8, 8, INT_MAX, INT_MAX, INT_MAX},
        {3, 0, 4, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {4, 4, 0, 6, 5, 5, 5, 10},
        {8, 4, 6, 0, INT_MAX, INT_MAX, 8, 3},
        {8, INT_MAX, 5, INT_MAX, 0, 4, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 5, INT_MAX, 4, 0, 6, INT_MAX},
        {INT_MAX, INT_MAX, 5, 8, INT_MAX, 6, 0, 4},
        {INT_MAX, INT_MAX, 10, 3, INT_MAX, INT_MAX, 4, 0}
    };

    int costo = tspGreedy(graph);
    printf("El costo total del recorrido es: %d\n", costo);

    return 0;
}
