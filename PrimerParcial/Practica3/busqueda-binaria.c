
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int busquedaBinaria(int *, int, int, int);
void llenarArray(int *, int); 

int main(){

    int n = 10000000;
    int *arr = malloc(n * sizeof(int));
    llenarArray(arr, n);
    int buscar = 6992;

    clock_t start, end;
    start = clock();
    int indice = busquedaBinaria(arr, buscar, 0, n-1);
    end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo tomado para buscar el numero %d en %d datos fue: %.10f segundos\n", buscar, n, time_taken);
    
    indice == -1 ? printf("No se encontro el valor en el arreglo\n\n") : printf("El valor esta en la posicion %d\n\n", indice);

    return 0;
}

int busquedaBinaria(int *arr, int valor, int menor, int mayor){
    int medio;
    while(menor <= mayor){
        medio = menor + (mayor - menor) / 2;
        
        if(*(arr + medio) == valor)
            return medio;

        if (*(arr + medio) < valor)
            menor = medio + 1;
        else
            mayor = medio - 1;
    }
    return -1;
}

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