#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void llenar(int *arr, int longi);

// An iterative binary search function.
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// Driver code
int main(void)
{
    int n = 100;
    int *arr = malloc(n * sizeof(int));
    llenar(arr, n);
    
    clock_t start, end;
    int x = 16230884;

    start = clock();  // Inicia el cronómetro antes de la búsqueda
    int result = binarySearch(arr, 0, n - 1, x);
    end = clock();  // Finaliza el cronómetro después de la búsqueda

     
    printf("Element is present at index %d\n", result);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo tomado para buscar %d números: %f segundos\n", n, time_taken);
    free(arr);

}

void llenar(int *arr, int longi) {
    FILE *archivo = fopen("sorted100.txt", "r");
    if (archivo == NULL) {
        printf("No se leyó nada\n");
        exit(0);
    }
    
    for(int i = 0; i < longi; i++)  // Inicializa i en 0
        fscanf(archivo, "%d", &arr[i]);

    fclose(archivo);  // Asegúrate de cerrar el archivo después de leer
}
