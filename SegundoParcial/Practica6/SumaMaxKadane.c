// C Program to find the maximum subarray sum using nested loops
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to find the sum of subarray with maximum sum
long long int maxSubarraySum(int arr[], int size) {
   long long int maxSum = (long long int)arr[0];
  
    // Outer loop for starting point of subarray
    for (int i = 0; i < size; i++) {
        long long int currSum = 0;
      
        // Inner loop for ending point of subarray
        for (int j = i; j < size; j++) {
            currSum = currSum + (long long int)arr[j];
          
            // Update maxSum if currSum is greater than maxSum
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}

void llenarArray(int *arr, int longi) {
    FILE *file = fopen("../../PrimerParcial/Practica2/numeros10millones.txt", "r");

    if (file == NULL){
        printf("No se leyo nada\n");
        exit(0);
    }
    for(int i = 0; i<longi; i++)
        fscanf(file,"%d", &arr[i]);
}


int main() {
    int n;
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    llenarArray(arr, n);

    clock_t start, end;
    start = clock();
    long long int max_sum = maxSubarraySum(arr, n); 
    end = clock();

	printf("\nLa suma maxima contigua es:  %llu\n", max_sum); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("El tiempo tomado es de %.10f", time_taken);

    return 0;
}
