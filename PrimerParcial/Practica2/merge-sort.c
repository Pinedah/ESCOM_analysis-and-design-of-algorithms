#include <stdio.h>
#include <time.h>
#include<stdlib.h>

void mergeSort(int *, int , int );
void merge(int *, int, int , int );
void generarArchivoOrden(int *, int);
void llenarArray(int *, int);
void llenarArrayPeorCaso(int *, int);
void llenarArrayMejorCaso(int *, int);

int main(){
    int n = 10000000;
    int *arr = malloc(n * sizeof(int));
    //llenarArray(arr, n);
    //llenarArrayMejorCaso(arr, n);
    llenarArrayPeorCaso(arr, n);
    //for (int i = 0; i < n; i++){
    //    printf("%d ", arr[i]);
    //}
    
    clock_t start, end;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    //generarArchivoOrden(arr,n);
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tiempo tomado para ordenar %d numeros: %f segundos\n", n, time_taken);
    free(arr);

    return 0;
}

void mergeSort(int *arr, int p, int r){
    int q;
    if (p < r){
        q = p + (r - p) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);
    }
}

void merge(int *arr, int p, int q, int r){

    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));


    for (int i = 0; i < n1; i++){
        *(L+i) = *(arr + p + i);
    }
    for (int j = 0; j < n2; j++){
        *(R+j) = *(arr + q + j + 1);
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2){
        if (*(L+i) <= *(R+j)){
            *(arr+k) = *(L+i);
            i++;
        }else{
            *(arr+k)= *(R+j);
            j++;
        }
        k++;
    }

    while (i < n1){
        *(arr+k) = *(L+i);
        i++;
        k++;
    }
    while (j < n2){
        *(arr+k) = *(R+j);
        j++;
        k++;
    }
    free(L);
    free(R);
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

void generarArchivoOrden(int *arr, int n) {
    char filename[20];
    sprintf(filename, "sorted%d.txt", n);
    FILE *file = fopen(filename, "w");
    for (int j = 0; j < n; j++) {
        fprintf(file, "%d\n", arr[j]);
    }
    fclose(file);
}
