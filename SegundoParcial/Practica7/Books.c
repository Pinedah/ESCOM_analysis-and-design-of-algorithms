#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Funcion que valida si el valor actual es factible o no
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;

    // iterar todos los libros
    for (int i = 0; i < n; i++) {
        //Si el número actual de páginas es mayor que curr_min, 
        //significa que necesitamos más de mid páginas para una asignación válida
        if (arr[i] > curr_min)
            return false;

        //cuenta cuantos alumnos son requeridos para distribuir el curr_min de paginas
        if (curr_sum + arr[i] > curr_min) {
            // aumenta el numero de estudiantes requeridos
            studentsRequired++;

            //actualiza current_sum
            curr_sum = arr[i];
            //si los estudiantes requeridos se hacen mas grandes que el 
            //numero de estudiantes retorna falso
            if (studentsRequired > m)
                return false;
        }

        // si no actualiza curr_sum
        else
            curr_sum += arr[i];
    }
    return true;
}

// Funcion para hallar el numero minimo de paginas
int findPages(int arr[], int n, int m)
{
    long long sum = 0;

    //retorna -1 si el numero de libros es menor de que numero de estudiantes
    if (n < m)
        return -1;
    int mx = arr[0];

    // Cuenta el numero total de paginas
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        mx = (arr[i] > mx ? arr[i] : mx);
    }

    // inicializar start como 0  y end con el total de paginas
    // total pages
    int start = mx, end = sum;
    int result = INT_MAX;

    // moverse hasta start <= end
    while (start <= end) {
        // verifica si es posile distribuir los libros usando mid como el minimo actual
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            // actualiza el resultado de la actual distribución como si fuera
            // el mejor que hemos encontrado hasta el momento
            result = mid;

            
            //Como estamos buscando el mínimo y los libros están ordenados, 
            //al reducir el límite superior con end = mid - 1, 
            //significa que estamos ajustando nuestro rango de búsqueda hacia la izquierda. 
            end = mid - 1;
        }

        else
            //si no es posible implica que las paginas deben incrementar en mid+1
            start = mid + 1;
    }

    //al ultimo returna el numero de paginas
    return result;
}

void llenarArray(int *arr, int longi) {
    int *ptr;
    int i;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        *ptr = (rand() % 100) + 10;
    }
}
void recorrer(int *arr, int longi) {
    int *ptr;
    for(ptr=arr; ptr < &arr[longi]; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main()
{
    //Numero de paginas en los libros
    int n;
    printf("Ingrese la cantidad de libros: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    llenarArray(arr, n);
    int m = 10;//numero de estudiantes
    recorrer(arr,n);
    clock_t start, end;

    start = clock();
    int a = findPages(arr, n, m);
    end = clock();

    printf("Minimo numero de paginas = %d\n", a );
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("El tiempo tomado es de %.10f", time_taken);
    free(arr);
    return 0;
}
