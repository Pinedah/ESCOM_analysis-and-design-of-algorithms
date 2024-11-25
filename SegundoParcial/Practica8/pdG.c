# include<stdio.h>
#include<stdlib.h>
#include "sort.h"
typedef struct{
    int profit, weight;

} Item;
int cmp(const void* a, const void* b);
float fractionalKnapsack(int, Item*, int, float*);

int main(){
    int W;
    float *sol;
    float benefFinal=0.0;
    Item arr[] = { { 40, 200 }, { 20, 100 }, { 30, 120 },{ 40, 200 } };
    int N = sizeof(arr) / sizeof(*(arr));
    sol = (float*)malloc(N*sizeof(float));
    printf("Introduce la capacidad de la mochila: ");
    scanf("%d", &W);
    for(int i=0; i<N;i++){
        *(sol+i)=0.0;
    }
    benefFinal=fractionalKnapsack(W, arr, N, sol);
    printf("\nPeso de mochila disponible: %d\n", W);
    printf("Pesos de objetos(P), Beneficios(B), Seleccion(S)\n");
    printf("P:\t|");
    for(int i=0; i<N;i++){
        printf("\t%d\t|",(*(arr+i)).weight);
    }
    printf("\n");
    printf("B:\t|");
    for(int i=0; i<N;i++){
        printf("\t%d\t|",(*(arr+i)).profit);
    }
    printf("\n");
    printf("S:\t|");
    for(int i=0; i<N;i++){
        printf("\t%.2f\t|",(*(sol+i)));
    }
    printf("\n");
    printf("Beneficio maximo: %.2f", benefFinal);
    free(sol);
    return 0;
}


int cmp(const void* a, const void* b) {
    const Item* item1 = (const Item*)a;
    const Item* item2 = (const Item*)b;
    float r1 = (float)item1->profit / (float)item1->weight;
    float r2 = (float)item2->profit / (float)item2->weight;

    if (r1 > r2) return -1;
    if (r1 < r2) return 1;
    return 0;
}
float fractionalKnapsack(int W, Item *arr, int N, float *sol){

    sort(arr, N, sizeof(Item), cmp);
    float finalvalue=0.0;
    for (int i = 0; i < N; i++) {

        if ((*(arr+i)).weight <= W) {
            (*(sol+i)) = 1.0;
            W -= (*(arr+i)).weight;
            finalvalue += (*(arr+i)).profit;
        }
        else {
            finalvalue += (*(arr+i)).profit*((float)W / (float)(*(arr+i)).weight);
            (*(sol+i)) =(float)((float)W / (float)(*(arr+i)).weight);
            break;
        }
    }
    return finalvalue;

}
