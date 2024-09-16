#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaración de funciones
void swap(int *a, int *b);
void heapify(int arr[], int n, int raiz);
void heapSort(int arr[], int n);
void llenarDesendente(int *arr, int longi);
void llenarAscendente(int *arr, int longi);
void printArray(int arr[], int n);

int main(){
    clock_t start, end;
    srand(time(NULL));

    //Ingresar e tamaño del arreglo
    int longi;
    printf("Ingrese longitud del array: ");
    scanf("%d", &longi);

    int *arr = (int*)malloc(longi * sizeof(int));

    //Llenar el arreglo de manera desordenada
    llenar(arr, longi);
    printf("Ordenado usando HeapSort: \n");

    //Empieza el contador
    start = clock();

    //Se ordena con el algoritmo Heap sort
    heapSort(arr, longi);

    //Finaliza el contador
    end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;

    //Se imprime el arreglo ordenado y el tiempo de ordenamiento
    printArray(arr, longi);
    printf("\nTiempo: %.20f", time_taken);

    free(arr);
    return 0;
}

// Función que hace un intercambio
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
  }

//Funcion que "heapifica"
void heapify(int arr[], int n, int raiz) {
    int mayorNodo = raiz; // Suponemos que el mayor nodo es la raiz
    int hijoIzq = raiz * 2 + 1; // Accedemos a su primer hijo
    int hijoDer = raiz * 2 + 2; // Accedemos a su segundo hijo

    // Se supone que la raiz es el mayor, si no, se intercambia hasta llegar a la marca (n) de los elementos ya ordenados
    if (hijoIzq < n && arr[hijoIzq] > arr[mayorNodo]) 
      mayorNodo = hijoIzq;

    if (hijoDer < n && arr[hijoDer] > arr[mayorNodo])
      mayorNodo = hijoDer;

    //Si sí se hizo algún cambio se ordena el elemento mayor en la posición que le corresponde y se vuelve a "heapificar"
    if (mayorNodo != raiz) { 
      swap(&arr[raiz], &arr[mayorNodo]);
      heapify(arr, n, mayorNodo);
    }
  }

//Funcion de ordemnamiento Heap sort
void heapSort(int arr[], int n) { int k=1;
    //Heapificamos por primera vez (es necesario para el siguiente paso, que ya es el Heap sort)
    for (int ultimoPadre = n / 2 - 1; ultimoPadre >= 0; ultimoPadre--) // i = n / 2 - 1 es el ultimo padre
        heapify(arr, n, ultimoPadre); // Con ultimoPadre estamos calculando el último mayor (supuestamente), y así se lo mandamos al heapify

    // Heap sort (intercambio la raiz (el mayor) y el último hijo)
    for (int ultimoHijo = n - 1; ultimoHijo >= 0; ultimoHijo--) {
        swap(&arr[0], &arr[ultimoHijo]); // Ya heapificado, se tiene que arr[0] es el mayor
        // Se deja heapificado para la siguiente iteración, 
        heapify(arr, ultimoHijo, 0); 
    }
  }

//  Funcion para imprimir un array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}

//Función para llenar ascendentemente
void llenarAscendente(int *arr, int longi) {
    int *ptr;
    int i=1;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr=i++;
    }
}

//Función para llenar descendentemente
void llenarDesendente(int *arr, int longi) {
    int *ptr;
    int i=longi;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr=i--;
    }
}

//Función para llenar desde un archivo
void llenar(int *arr, int longi) {
    FILE *archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL){
        printf("No se leyó nada\n");
        return 0;
    }
    for(int i; i<longi; i++)
        fscanf(archivo,"%d", &arr[i]);
};
