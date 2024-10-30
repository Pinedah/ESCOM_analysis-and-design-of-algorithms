#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

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


int main()
{
    //Numero de paginas en los libros
    int arr[50] = {
    10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
    110, 120, 130, 140, 150, 160, 170, 180, 190, 200,
    210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
    310, 320, 330, 340, 350, 360, 370, 380, 390, 400,
    410, 420, 430, 440, 450, 460, 470, 480, 490, 500
    };
    int n = sizeof arr / sizeof arr[0];
    int m = 10;//numero de estudiantes

    printf("Minimum number of pages = %d\n",
           findPages(arr, n, m));
    return 0;
}
