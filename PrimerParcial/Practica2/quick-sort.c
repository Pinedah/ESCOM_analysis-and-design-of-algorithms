#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void quicksort(int*, int, int);
void partition(int*, int, int, int*);
void generarArchivos(int*, int);

int main() {
    int n;
    printf("Cuantos datos quieres ingresar? \n");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    generarArchivos(arr, n);

    char randomFilename[20];
    sprintf(randomFilename, "random%d.txt", n);
    printf("Contenido del archivo \"random%d.txt\":\n", n);
    FILE *randomFile = fopen(randomFilename, "r");
    if (randomFile) {
        int num;
        while (fscanf(randomFile, "%d, ", &num) != EOF) {
            printf("%d ", num);
        }
        fclose(randomFile);
    } else {
        printf("Error al abrir el archivo \"random%d.txt\"\n", n);
    }

    printf("\n\n");
    clock_t start, end;
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;

    char sortedFilename[20];
    sprintf(sortedFilename, "sorted%d.txt", n);

    FILE *sortedFile = fopen(sortedFilename, "r");
    if (sortedFile) {
        printf("Contenido del archivo \"%s\":\n", sortedFilename);
        int num;
        while (fscanf(sortedFile, "%d, ", &num) != EOF) {
            printf("%d ", num);
        }
        fclose(sortedFile);
    } else {
        printf("Error al abrir el archivo \"%s\"\n", sortedFilename);
    }
    printf("\n\nTiempo tomado para ordenar %d numeros: %f segundos\n", n, time_taken);

    free(arr);
    return 0;
}
// Resto del c�digo (quicksort, generarArchivos, partition) permanece igual...


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

void generarArchivos(int *arr, int n) { // Cambio de nombre de la funci�n
    char filename[20]; // Buffer para el nombre del archivo
    sprintf(filename, "random%d.txt", n); // Genera el nombre del archivo
    FILE *file = fopen(filename, "w"); // Abre el archivo para escritura
    srand(time(0)); // Inicializa la semilla del generador de n�meros aleatorios
    for (int j = 0; j < n; j++) { // Itera n veces
        arr[j] = rand()%10000000; // Genera un n�mero aleatorio y lo guarda en el arreglo
        fprintf(file, "%d, ", arr[j]); // Escribe el n�mero en el archivo
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
