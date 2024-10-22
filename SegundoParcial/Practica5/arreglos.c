#include <stdio.h>

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


int main(){

    int arregloequis[3] = {100,50,70};

    int ma, mi;
    int *max;
    int *min;

    max = &ma;
    min = &mi;

    MaxMin_R(arregloequis, 0, 2, max, min);
    printf("max: %d, min: %d", ma, mi);

    return 0;
}