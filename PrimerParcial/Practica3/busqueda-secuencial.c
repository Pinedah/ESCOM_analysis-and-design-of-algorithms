#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void llenarArray(int *arr, int longi);
int buscSec(int *arr, int n, int x);

int main(void)
{
    int n = 10000000, x;
    int *arr = malloc(n * sizeof(int));
    llenarArray(arr, n);
    
    clock_t start, end;
    //Mejor caso
    //x = arr[0];

    //Caso medio
    x = arr[n/2];

    //Peor caso
    //x = -1;

    start = clock();  // Inicia el cronómetro antes de la búsqueda
    int result = buscSec(arr, n , x);
    end = clock();  // Finaliza el cronómetro después de la búsqueda
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    if (result != -1)
        printf("El elemento buscado esta en el indice %d\n", result);
    else
        printf("El elemento no se encontro\n");

    
    printf("Tiempo tomado para hacer la busqueda en un conjunto de %d numeros: %f segundos\n", n, time_taken);
    free(arr);

}

// Función para leer los datos
void llenarArray(int *arr, int longi) {
    char filename[20];
    sprintf(filename, "sorted%d.txt", longi);
    FILE *file = fopen(filename, "r");

    if (file == NULL){
        printf("No se leyó nada\n");
        exit(0);
    }
    for(int i = 0; i<longi; i++)
        fscanf(file,"%d", &arr[i]);
}

// Función de la busqueda secuencial
int buscSec(int *arr, int n, int x){
    int *ptr;
    for (ptr=arr; ptr < &arr[n]; ptr++){
        if (*ptr == x)
            return ptr - arr;
    }
    return -1;
}
