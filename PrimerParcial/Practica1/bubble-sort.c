//!! PROYECTO ALGORITMOS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *arr, int longi);
void llenar(int *arr, int longi);
void recorrer(int *arr, int longi);

int main() {

    srand(time(NULL));
    
    int longi;
    printf("Ingrese longitud del array: ");
    scanf("%d", &longi);
    
    int *arr = (int *)malloc(longi * sizeof(int));

    llenar(arr, longi);

    printf("Ordenado usando bubble: \n");
    bubble(arr, longi);
    recorrer(arr, longi);

    free(arr);
    return 0;
}

void llenarAscendente(int *arr, int longi) {
    int *ptr;
    int i;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr=i++;
    }
};

void llenarDesendente(int *arr, int longi) {
    int *ptr;
    int i=longi;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr=i--;
    }
};

void llenar(int *arr, int longi) {
    int *ptr;
    for(ptr = arr; ptr < &arr[longi]; ptr++) {
        *ptr = rand() % 1000;
    }
};



void recorrer(int *arr, int longi) {
    int *ptr;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
};

void bubble(int *arr, int longi) {
    
    int *i, *j;
    for (i = arr + longi; i >= arr; i--){
        for (j = arr; j <= (i - 1); j++){
            if(*j > *(j + 1)){
                *j ^= *(j + 1);
                *(j + 1) ^= *j;
                *j ^= *(j + 1);
            }
        }   
    }
}