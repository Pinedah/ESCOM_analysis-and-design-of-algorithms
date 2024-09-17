#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void quicksort(int*, int, int);
void partition(int*, int, int, int*);
void generarArchivos(int*, int);

int main() {
    int sizes[] = {1000000}; // Define los tamaños de los arreglos a generar
    for (int i = 0; i < 1; i++) { // Itera sobre cada tamaño
        int n = sizes[i]; // Toma el tamaño actual
        int *arr = malloc(n * sizeof(int)); // Reserva memoria para el arreglo
        generarArchivos(arr, n); // Genera números aleatorios y los escribe en un archivo

        clock_t start, end; // Variables para medir el tiempo
        start = clock(); // Toma el tiempo antes de ordenar
        quicksort(arr, 0, n - 1); // Ordena el arreglo
        end = clock(); // Toma el tiempo después de ordenar
        double time_taken = ((double)end - start) / CLOCKS_PER_SEC; // Calcula el tiempo que tardó en ordenar

        char filename[20]; // Buffer para el nombre del archivo
        sprintf(filename, "sorted%d.txt", n); // Genera el nombre del archivo
        FILE *file = fopen(filename, "w"); // Abre el archivo para escritura
        for (int j = 0; j < n; j++) { // Itera sobre cada número en el arreglo
            fprintf(file, "%d\n", arr[j]); // Escribe el número en el archivo
        }
        fclose(file); // Cierra el archivo

        printf("Tiempo tomado para ordenar %d números: %f segundos\n", n, time_taken); // Imprime el tiempo que tardó en ordenar
        free(arr); // Libera la memoria reservada para el arreglo
    }
    return 0; // Termina el programa
}

void quicksort(int *x, int lb, int ub) {
    if (lb >= ub) {
        return;
    }// Si el limite inferior del arreglo es mayor o igual que el limite superior el arreglo o subarreglo esta ordenado
    int pj;
    partition(x, lb, ub, &pj); //llama a partition que logra que el elemento en la primera posicion del arreglo se coloque en la posicion que le corresponde
    // es decir que los elementos a su izquierda son menores y a su derecha mayores o iguales que ese elemento
    quicksort(x, lb, pj - 1);//llamada recursiva para acomodar el subarreglo derecho (menores que el elemento)
    quicksort(x, pj + 1, ub);//llamada recursiva para acomodar el subarreglo izquierdo (mayores que el elemento)
}

void generarArchivos(int *arr, int n) { // Cambio de nombre de la función
    char filename[20]; // Buffer para el nombre del archivo
    sprintf(filename, "random%d.txt", n); // Genera el nombre del archivo
    FILE *file = fopen(filename, "w"); // Abre el archivo para escritura
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios
    for (int j = 0; j < n; j++) { // Itera n veces
        arr[j] = rand(); // Genera un número aleatorio y lo guarda en el arreglo
        fprintf(file, "%d\n", arr[j]); // Escribe el número en el archivo
    }
    fclose(file); // Cierra el archivo
}

void partition(int *x, int lb, int ub, int* pj) {
    int a = *(x+lb);//le asigna a 'a' el elemento en la primera posicon del arreglo o subarreglo
    int up = ub;//asigna a up el limite superior del arreglo o subarreglo
    int down = lb;//asigna a lb el limite inferior del arreglo o subarreglo
    while (down < up) {//mientras que el limite inferior sea menor que el superior
        while (*(x+down) <= a && down < ub) {
            down++;
        }//aumenta down mientras que el elemento en la posicion x[down] sea menor o igual que 'a' y down sea menor que el imite superior del arreglo
        while (*(x+up) > a) {
            up--;
        }//decrementa up mientras que el elemnto de la posicion x[up] sea mayor que a;
        if (down < up) {
            *(x+down) ^= *(x+up);
            *(x+up) ^= *(x+down);
            *(x+down) ^= *(x+up);
        }//si down es menor que up al final de los while intercambia el valor que tengas en x[down] con x[up]
    }
    *(x+lb) = *(x+up);//asigna x[lb] el valor que tengas en x[up]
    *(x+up) = a; //asignale a x[up] el valor de a
    *pj = up; //al puntero pj asignale la direccion de up
}
