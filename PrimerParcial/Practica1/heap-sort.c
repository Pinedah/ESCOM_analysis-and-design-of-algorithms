#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b);
void heapify(int arr[], int n, int raiz);
void heapSort(int arr[], int n);
void llenarDesendente(int *arr, int longi);
void llenarAscendente(int *arr, int longi);
void printArray(int arr[], int n);
int main(){
    clock_t start, end;
    srand(time(NULL));

    int longi;
    printf("Ingrese longitud del array: ");
    scanf("%d", &longi);

    int *arr = (int*)malloc(longi * sizeof(int));

    llenarDesendente(arr, longi);
    printf("Ordenado usando HeapSort: \n");
    start = clock();
    heapSort(arr, longi);
    end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;


   // printArray(arr, longi);
    printf("\nTiempo: %.20f", time_taken);

    free(arr);
    return 0;
}
  // Intercambio
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
  }

void heapify(int arr[], int n, int raiz) {
    int mayorNodo = raiz; // Suponemos que el mayor nodo es la raiz
    int hijoIzq = raiz * 2 + 1; // Accedemos a su primer hijo
    int hijoDer = raiz * 2 + 2; // Accedemos a su segundo hijo

    // Se supone que la raiz es el mayor, si no, los intercambiamos
    if (hijoIzq < n && arr[hijoIzq] > arr[mayorNodo]) // n marca el límite de los ya ordenados hasta el final, a partir de ahí se acaba el "árbol"
      mayorNodo = hijoIzq;

    if (hijoDer < n && arr[hijoDer] > arr[mayorNodo])
      mayorNodo = hijoDer;

    if (mayorNodo != raiz) { //Si sí se hizo el cambio
      swap(&arr[raiz], &arr[mayorNodo]);
      heapify(arr, n, mayorNodo);
    }
  }

void heapSort(int arr[], int n) { int k=1;
    //Heapificamos la primera vez (es necesario para el siguiente paso, que ya es el Heap sort)
    for (int ultimoPadre = n / 2 - 1; ultimoPadre >= 0; ultimoPadre--) // i = n / 2 - 1 es el ultimo padre
        heapify(arr, n, ultimoPadre); // Con ultimoPadre estamos calculando el último mayor (supuestamente), y así se lo mandamos al heapify



    // Heap sort (intercambio la raiz (el mayor) y el último hijo)
    for (int ultimoHijo = n - 1; ultimoHijo >= 0; ultimoHijo--) {
        swap(&arr[0], &arr[ultimoHijo]); // Ya heapificado, sabemos que arr[0] es el mayor
        heapify(arr, ultimoHijo, 0); // Lo dejamos heapificado para la siguiente iteración
                                   // Ahora en la función Heapify n = ultimoHijo
                                   // Ahora ya es seguro que la raiz será el [0]

    }
  }

  // Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}



void llenarAscendente(int *arr, int longi) {
    int *ptr;
    int i=1;
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
    FILE *archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL){
        printf("No se leyó nada\n");
        return 0;
    }
    for(int i; i<longi; i++)
        fscanf(archivo,"%d", &arr[i]);
};
