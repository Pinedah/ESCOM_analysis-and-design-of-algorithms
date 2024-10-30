#include <stdio.h>
#include <stdlib.h>

// Función recursiva para contar el número de ocurrencias de cada elemento
// en el arreglo sin recorrer el arreglo completo
void findFrequencyUtil(int arr[], int low, int high, int freq[]) {
    // Si el elemento en el índice `low` es igual al elemento en el índice `high`
    if (arr[low] == arr[high]) {
        // Incrementar la frecuencia del elemento por la cantidad de elementos
        // entre `high` y `low`
        freq[arr[low]] += high - low + 1;
    } else {
        // Encontrar el punto medio y hacer recursión en el subarreglo izquierdo
        // y derecho
        int mid = (low + high) / 2;
        findFrequencyUtil(arr, low, mid, freq);
        findFrequencyUtil(arr, mid + 1, high, freq);
    }
}

// Función que envuelve la función recursiva `findFrequencyUtil()` y
// muestra el número de ocurrencias de cada elemento en el arreglo
void findFrequency(int arr[], int n) {
    // Crear un arreglo para almacenar las frecuencias e inicializarlo en 0.
    // El tamaño del arreglo es el valor máximo (último valor en el arreglo ordenado) + 1.
    int *freq = (int*)calloc(arr[n - 1] + 1, sizeof(int));

    // Llenar el arreglo con las frecuencias
    findFrequencyUtil(arr, 0, n - 1, freq);

    // Imprimir las frecuencias
    for (int i = 0; i <= arr[n - 1]; i++) {
        if (freq[i] != 0) {
            printf("Elemento %d se repite %d veces\n", i, freq[i]);
        }
    }

    // Liberar la memoria asignada para el arreglo de frecuencias
    free(freq);
}

// Código principal
int main() {
    int arr[] = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Llamada a la función
    findFrequency(arr, n);

    return 0;
}
