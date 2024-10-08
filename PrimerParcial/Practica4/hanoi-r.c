#include <stdio.h>
#include <time.h>


void hanoi(int num, char origen, char destino, char auxiliar) {
    if (num == 1) {
      //  printf("Mueve el bloque %d desde %c hasta %c \n", num, origen, destino);
    } else {
        hanoi(num - 1, origen, auxiliar, destino);
      //  printf("Mueve el bloque %d desde %c hasta %c \n", num, origen, destino);
        hanoi(num - 1, auxiliar, destino, origen);
    }
}

int main() {
    int n;
    char A, B, C;

    printf("Las clavijas son A B C\n"); 
    printf("Escribe el numero de discos con los que quiere trabajar: ");
    scanf("%d", &n);
    
    clock_t start, end;
    start = clock();
    hanoi(n, 'A', 'C', 'B');
    end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTiempo tomado fue: %.10f segundos\n", time_taken);
    return 0;
}