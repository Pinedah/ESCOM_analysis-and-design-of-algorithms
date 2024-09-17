
#include <stdio.h>

void mergeSort (int A[], int p, int r);
void merge(int A[], int p, int q, int r);

int main(){

    int arr[] = {5,4, 2, 1, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);
    
    printf("\n\n\n\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void mergeSort (int A[], int p, int r){
    int q;
    if (p < r){

        for (int i = 0; i < r; i++){
            printf("%d ", A[i]);
        

        }
        printf("\n");

        //q = ((p + r) / 2);
        q = p + (r - p)/2;
        printf("\nQ: %d\n", q);
        
        mergeSort (A, p, q);
        mergeSort (A, q + 1, r);

        merge (A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r){
    
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];

    int i = 0, j = 0, k = p;

    for(i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
    }

    printf("\nLeft: ");
    for(int l = 0; l < n1; l++){
        printf("%d ", L[l]);
    }
    printf("\nRight: ");
    for(int r = 0; r < n2; r++){
        printf("%d ", R[r]);
    }

   // for(k = p; k < r; k++){
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }else{
                A[k] = R[j];
                j++;
            }
            k++;
        }
    
            while(i < n1){
                A[k] = L[i];
                i++;
                k++;

            }
            while(j < n2){
                A[k] = R[j];
                j++;
                k++;
            }
        
}