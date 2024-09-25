#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void quicksort(int*, int, int);
void partition(int*, int, int, int*);
void generarArchivos(int*, int);
void llenarArray(int *, int);
void llenarArrayPeorCaso(int *, int);
void llenarArrayMejorCaso(int *, int);

int main() {
        int n = 10000000;
        int *arr = malloc(n * sizeof(int));
        llenarArray(arr, n);
        //llenarArrayPeorCaso(arr, n);
        //llenarArrayMejorCaso(arr, n);
        clock_t start, end;
        start = clock();
        quicksort(arr, 0, n - 1);
        end = clock();
        //generarArchivos(arr,n);
        double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
        printf("Tiempo tomado para ordenar %d numeros: %f segundos\n", n, time_taken);
        free(arr);
    return 0;
}

void quicksort(int *x, int lb, int ub) {
    if (lb >= ub) {
        return;
    }
    int pj;
    partition(x, lb, ub, &pj);
    quicksort(x, lb, pj - 1);
    quicksort(x, pj + 1, ub);
}

void partition(int *x, int lb, int ub, int* pj) {
    int random_index = lb + rand() % (ub - lb + 1);
    int temp = *(x + lb);
    *(x + lb) = *(x + random_index);
    *(x + random_index) = temp;
    int a = *(x+lb);
    int up = ub;
    int down = lb;
    while (down < up) {
        while (*(x+down) <= a && down < ub) {
            down++;
        }
        while (*(x+up) > a) {
            up--;
        }
        if (down < up) {
            int temp_swap = *(x + down);
            *(x + down) = *(x + up);
            *(x + up) = temp_swap;
        }
    }
    *(x+lb) = *(x+up);
    *(x+up) = a;
    *pj = up;
}
void llenarArray(int *arr, int longi) {
    FILE *archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL){
        printf("No se leyó nada\n");
        exit(0);
    }
    for(int i = 0; i<longi; i++)
        fscanf(archivo,"%d", &arr[i]);

}

void llenarArrayPeorCaso(int *arr, int longi) {
    int *ptr = arr;
    for (long unsigned int i = longi; i > 0; i--) {
        *ptr = i;
        ptr++;
    }
}
void llenarArrayMejorCaso(int *arr, int longi) {
    int *ptr = arr;
    for (int i = 1; i <= longi; i++) {
        *ptr = i;
        ptr++;
    }
}


void generarArchivos(int *arr, int n) {
    char filename[20];
    sprintf(filename, "sorted%d.txt", n);
    FILE *file = fopen(filename, "w");
    for (int j = 0; j < n; j++) {
        fprintf(file, "%d\n", arr[j]);
    }
    fclose(file);
}
