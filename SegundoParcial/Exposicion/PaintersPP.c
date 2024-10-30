#include <stdio.h>
#include <limits.h>

// Máximo valor del arreglo representa el tiempo mínimo que un pintor puede tomar
// Cada valor del arreglo representa la cantidad de tiempo que una tabla toma en ser pintada
int getMax(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Obtener la suma de los elementos del arreglo
// Representa la mayor cantidad de horas que un pintor puede tomar (en el caso donde k=1)
int getSum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Número mínimo de pintores requeridos para una carga máxima dada
// Recorre el arreglo y va sumando hasta que ese valor excede la carga máxima por pintor
// Una vez que esto sucede aumenta el contador del núm de pintores y hace lo mismo para el siguiente pintor
int numberOfPainters(int arr[], int n, int mid) {
    int total = 0, numPainters = 1;
    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (total > mid) {
            total = arr[i];
            numPainters++;
        }
    }

    return numPainters;
}

// Encuentra el tiempo mínimo para pintar todos los tableros usando búsqueda binaria
int partition(int arr[], int n, int k) {
    int lo = getMax(arr, n);
    int hi = getSum(arr, n);

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2; // Cantidad tentativa para trabajo máximo
        int requiredPainters = numberOfPainters(arr, n, mid);

        // Reducimos el rango superior para poner menor trabajo por pintor
        // mid se incluye porque tal vez no mejore
        if (requiredPainters <= k)  
            hi = mid;

        // Aumentamos el rango inferior para permitir más trabajo por pintor.
        // no incluimos a mid porque ya vimos que lo que da es inválido 
        else
            lo = mid + 1; 
        
    }
    // Mínimo tiempo necesario para que los k pintores pinten todos los tableros de la manera óptima.
    return lo;
}

// Función principal
int main() {
    int arr[] = { 10, 2, 7, 4, 5, 2, 2, 9, 9};
    //          
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Tiempo minimo para pintar todos los tableros con %d pintores: %d\n", k, partition(arr, n, k));
    return 0;
}
