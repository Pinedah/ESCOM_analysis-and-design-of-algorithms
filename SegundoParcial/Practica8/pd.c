#include <stdio.h>
#include <stdlib.h>

int knapSackRec(int W, int wt[], int val[], int index, int** dp) {
    if (index < 0)
        return 0;

    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) 
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
    else {
        int include = val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp);
        int exclude = knapSackRec(W, wt, val, index - 1, dp);
        dp[index][W] = (include > exclude) ? include : exclude;
    }
    return dp[index][W];
}

// Función auxiliar para imprimir tabla
void reconstructSolution(int W, int wt[], int val[], int n, int** dp, int* selected) {
    int w = W; // Rastrear cuánto espacio le queda a la mochila

    for (int i = n - 1; i >= 0; i--) {
        // Si el beneficio cambia al excluir el objeto, significa que fue incluido
        if (i == 0 || dp[i][w] != dp[i - 1][w]) { // Son diferentes el beneficio máximo con el objeto actual (dp[i][w]) y sin el objeto actual (dp[i-1][w])? -> El objeto actual lo mejora 
            if (w >= wt[i]) { // El objeto cabe en la mochila?
                selected[i] = 1;
                w -= wt[i]; // Reducir la capacidad restante
            }
        } 
        else 
            selected[i] = 0; // No se incluye el objeto
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    int r;
    // Tabla dinámica
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        dp[i] = (int*)malloc((W + 1) * sizeof(int));

    // Inicializar tabla con -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j] = -1;
    r =  knapSackRec(W, wt, val, n - 1, dp);
    // Arreglo de seleccionados
    int selected[n];
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    reconstructSolution(W, wt, val, n, dp, selected);


    // Imprimir tabla
    printf("\nPeso de mochila disponible: %d\n", W);
    printf("Pesos de objetos(P), Beneficios(B), Seleccion(S)\n");

    printf("P:\t|");
    for (int i = 0; i < n; i++)
        printf("\t%d\t| ", wt[i]);
    printf("\n");

    printf("B:\t| ");
    for (int i = 0; i < n; i++)
        printf("\t%d\t| ", val[i]);
    printf("\n");

    printf("S:\t| ");
    for (int i = 0; i < n; i++) {
        if (selected[i] == 1) 
            printf("\t1\t| ");
        else 
            printf("\t0\t| ");
    }
    printf("\n");

    for (int i = 0; i < n; i++)
        free(dp[i]);
    free(dp);

    return r;
}


int main() {
    int profit[] = {60, 60, 20, 30};
    int weight[] = {10, 10, 100, 120};
    int W;
    int n = sizeof(profit) / sizeof(profit[0]);

    printf("Introduce la capacidad de la mochila: ");
    scanf("%d", &W);
    printf("Beneficio maximo: %d\n", knapSack(W, weight, profit, n));
    return 0;
}
