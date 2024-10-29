#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// A utility function to find maximum of two integers 
long long int max2(long long int a, long long int b) { 
	return (a > b) ? a : b; 
} 

// A utility function to find maximum of three integers 
long long int max(long long int a, long long int b, long long int c) { 
	return max2(max2(a, b), c); 
} 

// Find the maximum possible sum in arr[] such that arr[m] 
// is part of it 
long long int maxCrossingSum(int arr[], int l, int m, int h) { 
	// Include elements on left of mid. 
	long long int sum = 0; 
	long long int left_sum = LONG_MIN; 
	for (int i = m; i >= l; i--) { 
		sum = sum + arr[i]; 
		if (sum > left_sum) 
			left_sum = sum; 
	} 

	// Include elements on right of mid 
	sum = 0; 
	long long int right_sum = LONG_MIN; 
	for (int i = m; i <= h; i++) { 
		sum = sum + arr[i]; 
		if (sum > right_sum) 
			right_sum = sum; 
	} 

	// Return sum of elements on left and right of mid 
	// returning only left_sum + right_sum will fail for 
	// [-2, 1] 
	return max(left_sum + right_sum - arr[m], left_sum, right_sum); 
} 

// Returns sum of maximum sum subarray in aa[l..h] 
long long int maxSubArraySum(int arr[], int l, int h) { 
	// Invalid Range: low is greater than high 
	if (l > h) 
		return INT_MIN; 
	// Base Case: Only one element 
	if (l == h) 
		return arr[l]; 

	// Find middle point 
	int m = (l + h) / 2; 

	/* Return maximum of following three possible cases 
			a) Maximum subarray sum in left half 
			b) Maximum subarray sum in right half 
			c) Maximum subarray sum such that the subarray 
	crosses the midpoint */
	return max(maxSubArraySum(arr, l, m - 1), 
			maxSubArraySum(arr, m + 1, h), 
			maxCrossingSum(arr, l, m, h)); 
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

/*Driver program to test maxSubArraySum*/
int main() { 
	int n;
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    llenarArray(arr, n);
    clock_t start, end;

    start = clock();
    long long int max_sum = maxSubArraySum(arr, 0, n - 1); 
    end = clock();
	
	printf("\nLa suma maxima contigua es:  %llu\n", max_sum); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("El tiempo tomado es de %.10f", time_taken);
	return 0; 
} 
