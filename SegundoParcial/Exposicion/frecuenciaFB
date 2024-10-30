#include <stdio.h>

void findFrequencies(int ele[], int n) {
    int freq = 1;
    int idx = 1;
    int element = ele[0];

    while (idx < n) {
        // Verificar si el elemento actual es igual al elemento anterior
        if (ele[idx - 1] == ele[idx]) {
            freq++;
            idx++;
        } else {
            printf("Elemento %d se repite %d veces\n", element, freq);
            element = ele[idx];
            idx++;

            // Reiniciar la frecuencia
            freq = 1;
        }
    }

    // Imprimir el último elemento y su frecuencia
    printf("Elemento %d se repite %d veces\n", element, freq);
}

// Código principal
int main() {
    printf("--- Frecuencias en un arreglo ordenado ---\n");
    int arr[] = {10, 20, 30, 30, 30, 40, 50, 50, 50, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Llamada a la función
    findFrequencies(arr, n);

    return 0;
}
