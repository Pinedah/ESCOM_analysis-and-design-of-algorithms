//! Bubble Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaración de funciones
void bubble(int *arr, int longi);
void llenar(int *arr, int longi);
void recorrer(int *arr, int longi);

int main() {
    clock_t start, end;
    srand(time(NULL));
    int longi;

    //Determinar la longitud del arreglo
    printf("Ingrese longitud del array: ");
    scanf("%d", &longi);

    int *arr = (int*)malloc(longi * sizeof(int));

    //Llenar el arreglo desordenado
    llenar(arr, longi);
    printf("Ordenado usando bubble: \n");
    
    //Empezamos el contador de tiempo
    start = clock();
    
    //Se realiza el ordenamiento
    bubble(arr, longi);
    
    //El contador termina
    end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    //Se imprime el arreglo ordenado y el tiempo de ordenamiento
    recorrer(arr, longi);
    printf("\nTiempo: %f", time_taken);
    
    free(arr);
    return 0;
}

//Función para llenar ascendentemente
void llenarAscendente(int *arr, int longi) {
    int *ptr;
    int i;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr=i++;
    }
}

//Función para llenar descendentemente
void llenarDescendente(int *arr, int longi) {
    int *ptr;
    int i=longi;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr=i--;
    }
}

//Función para llenar desde un archivo
void llenar(int *arr, int longi) {
    FILE *archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL){
        printf("No se leyó nada\n");
        return 0;
    }
    for(int i; i<longi; i++)
        fscanf(archivo,"%d", &arr[i]);
}

//Función para imprimir un arreglo
void recorrer(int *arr, int longi) {
    int *ptr;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

//Función del algoritmo de ordenamiento
void bubble(int *arr, int longi) {
    int *i, *j;
    for (i = arr + longi; i >= arr; i--){
        for (j = arr; j < (i - 1); j++){
            if(*j > *(j + 1)){
                *j ^= *(j + 1);
                *(j + 1) ^= *j;
                *j ^= *(j + 1);
            }
        }   
    }
}
