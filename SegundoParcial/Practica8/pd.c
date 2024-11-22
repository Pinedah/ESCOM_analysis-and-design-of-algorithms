#include <stdio.h>
#include <stdlib.h>

// Función para encontrar el máximo entre dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función recursiva para encontrar el máximo beneficio
int knapSackRec(int W, int wt[], int val[], int index, int** dp, int* selected) {
    // Condición base
    if (index < 0)
        return 0;

    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) {
        // No incluimos este objeto por su peso individual
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp, selected);
    } else {
        // Dos opciones: incluir o no incluir el objeto
        int include = val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp, selected);
        int exclude = knapSackRec(W, wt, val, index - 1, dp, selected);

        if (include > exclude) {
            dp[index][W] = include;
            selected[index] = 1; // Seleccionamos el objeto
        } else {
            dp[index][W] = exclude;
            selected[index] = 0; // No seleccionamos el objeto
        }
    }

    return dp[index][W];
}

// Función principal para resolver el problema de la mochila
int knapSack(int W, int wt[], int val[], int n) {
    // Declarar la tabla dinámica
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc((W + 1) * sizeof(int));
    }

    // Inicializar la tabla con -1
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= W; j++) 
            dp[i][j] = -1;
        
    // Creo un arreglo para registrar los elementos seleccionados y se llena de 0s
    int selected[n];
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    // Resolver el problema
    int result = knapSackRec(W, wt, val, n - 1, dp, selected);

    // Imprimir resultados
    printf("Peso de mochila disponible: %d\n", W);
    printf("Pesos de objetos(P), Beneficios(B), Seleccion(S)\n");
    printf("P: ");
    for (int i = 0; i < n; i++) {
        printf("\t%d ", wt[i]);
    }
    printf("\n");

    printf("B: ");
    for (int i = 0; i < n; i++) {
        printf("\t%d ", val[i]);
    }
    printf("\n");

    printf("S: ");
    for (int i = 0; i < n; i++) {
        if (selected[i] == 1) {
            printf("\t%d ", wt[i]); // Imprimir peso del objeto seleccionado
        } else {
            printf("\t0 ");
        }
    }
    printf("\n");

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < n; i++) 
        free(dp[i]);
    
    free(dp);

    return result;
}

// Código principal
int main() {
    int profit[] = {60, 60, 20, 30};
    int weight[] = {10, 10, 100, 120};
    int W = 100;
    int n = sizeof(profit) / sizeof(profit[0]);

    printf("Beneficio maximo: %d\n", knapSack(W, weight, profit, n));
    return 0;
}
