#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaración de funciones
void llenarArray(int *arr, int longitud);
void imprimirArreglo(int *arr, int longitud);
void ordenarSeleccion(int *arr, int longitud);

int main() {
    srand(time(NULL));

    int longitud;
    printf("\nIngrese la longitud del array: ");
    scanf(" %d", &longitud);

    // Asignar memoria dinámicamente para el array
    int *arr = (int *)malloc(longitud * sizeof(int));
    
    // Llenado del arreglo con números aleatorios
    llenarArray(arr, longitud);
    
    // Comenzar a medir el tiempo
    clock_t tiempo_inicio, tiempo_fin;
	double segundos;
	tiempo_inicio = clock();
    
    // Ordenar usando el Algoritmo de Selección
    ordenarSeleccion(arr, longitud);
    
    // Finalizar la medición del tiempo e imprimir los segundos totales de ejecución
    tiempo_fin = clock();
	segundos = (double)(tiempo_fin - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("\nTIEMPO TOTAL DE EJECUCIÓN: %f segundos\n", segundos);

    // Liberar la memoria asignada dinámicamente
    free(arr);
    
    return 0;
}

// Función para llenar el array con números de un archivo txt
void llenarArray(int *arr, int longi) {
    FILE *archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL){
        printf("No se leyó nada\n");
        return 0;
    }
    for(int i; i<longi; i++)
        fscanf(archivo,"%d", &arr[i]);

};

// Función para recorrer e imprimir el array
void imprimirArreglo(int *arr, int longitud) {
    int *ptr;
    for(ptr = arr; ptr < &arr[longitud]; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

// Función para realizar el ordenamiento por selección
void ordenarSeleccion(int *arr, int longitud) {
    int *ptr_i, *ptr_j, *min_ptr;
    int temp;
    for(ptr_i = arr; ptr_i < &arr[longitud - 1]; ptr_i++) {
        min_ptr = ptr_i;
        for(ptr_j = ptr_i + 1; ptr_j < &arr[longitud]; ptr_j++) {
            if(*ptr_j < *min_ptr) {
                min_ptr = ptr_j;
            }
        }
        // Intercambiar elementos
        temp = *min_ptr;
        *min_ptr = *ptr_i;
        *ptr_i = temp;
    }
}
