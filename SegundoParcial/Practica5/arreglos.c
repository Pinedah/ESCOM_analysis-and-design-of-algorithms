#include <stdio.h>
#include <time.h>
#include<stdlib.h>

void llenarArray(int*,int);
void MaxMin_I(int*, int, int*, int*);
void MaxMin_R(int*,int,int,int*,int*);



int main(){
    int n = 10000000, x;
    int *arr = malloc(n * sizeof(int));
    llenarArray(arr, n);
    
    clock_t startI, endI;
    clock_t startR, endR;

    int ma, mi;
    int *max;
    int *min;

    max = &ma;
    min = &mi;
    startR = clock();
    MaxMin_R(arr, 0, n-1, max, min);
    endR = clock();
    double time_takenR = ((double)(endR - startR)) / CLOCKS_PER_SEC;
    printf("Tiempo tomado para hacer la busqueda del maximo y minimo en un conjunto de forma recursiva de %d numeros: %f segundos\n", n, time_takenR);
    printf("max: %d, min: %d\n", ma, mi);
    startI = clock();
    MaxMin_I(arr, n, max, min);
    endI = clock();
    double time_takenI = ((double)(endI - startI)) / CLOCKS_PER_SEC;
    printf("Tiempo tomado para hacer la busqueda del maximo y minimo en un conjunto de forma iterativa de %d numeros: %f segundos\n", n, time_takenI);
    printf("max: %d, min: %d\n", ma, mi);
    free(arr);
    return 0;
}
void llenarArray(int *arr, int longi) {
    FILE *file = fopen("numeros10millones.txt", "r");

    if (file == NULL){
        printf("No se leyo nada\n");
        exit(0);
    }
    for(int i = 0; i<longi; i++)
        fscanf(file,"%d", &arr[i]);
}
void MaxMin_R(int *A, int i, int j, int *max, int *min){
    if(i < j - 1){
        int mit = (i + j)/2;
        
        int ma1, ma2, mi1, mi2;
        int *max1;
        int *max2;
        int *min1;
        int *min2;

        max1 = &ma1;
        max2 = &ma2;
        min1 = &mi1;
        min2 = &mi2;

        *max1 = A[0];
        *min1 = A[0];
        *max2 = A[mit + 1];
        *min2 = A[mit + 1];

        MaxMin_R(A, i, mit, max1, min1);
        MaxMin_R(A, mit + 1, j, max2, min2);
        if(*max1 > *max2){
            *max = *max1;
        }else{
            *max = *max2; 
        }

        if(*min1 < *min2){
            *min = *min1;
        }else{
            *min = *min2; 
        }

    }else if( i == j - 1){
        if(A[i] > A[j]){
            *max = A[i];
            *min = A[j];
        }else{
            *max = A[j];
            *min = A[i];
        }
    }else{
        *max = A[i];
        *min = *max;
    }
}
void MaxMin_I(int *A, int longi, int *max, int *min){
    *max = A[0];
    *min = A[0];
    
    int *ptr;
    for(ptr = A; ptr < A + longi; ptr++){
        if(*ptr > *max)
            *max = *ptr;
        
        if(*ptr < *min)
            *min = *ptr;
    }
}