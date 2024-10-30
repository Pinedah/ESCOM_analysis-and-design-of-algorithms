#include <stdio.h>
#include <limits.h>

int minPages = INT_MAX;

// Función auxiliar para calcular el máximo de dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función recursiva para encontrar todas las particiones posibles
void findMinPages(int arr[], int n, int m, int index, int studentsLeft, int currMax) {
    // Caso base: Si solo queda un estudiante, asignar todos los libros restantes a este estudiante
    if (studentsLeft == 1) {
        int remainingPages = 0;
        for (int i = index; i < n; i++) {
            remainingPages += arr[i];
        }
        currMax = max(currMax, remainingPages);
        if (currMax < minPages) {
            minPages = currMax;
        }
        return;
    }

    // Suma de las páginas asignadas hasta el momento en esta partición
    int sum = 0;
    for (int i = index; i < n - studentsLeft + 1; i++) {
        sum += arr[i];
        // Llamada recursiva para probar la siguiente partición
        findMinPages(arr, n, m, i + 1, studentsLeft - 1, max(currMax, sum));
    }
}

int main() {
    int arr[50] = {
    10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
    110, 120, 130, 140, 150, 160, 170, 180, 190, 200,
    210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
    310, 320, 330, 340, 350, 360, 370, 380, 390, 400,
    410, 420, 430, 440, 450, 460, 470, 480, 490, 500
    };

    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 10;

    findMinPages(arr, n, m, 0, m, 0);
    
    printf("La mínima cantidad máxima de páginas asignadas a un estudiante es: %d\n", minPages);
    
    return 0;
}
