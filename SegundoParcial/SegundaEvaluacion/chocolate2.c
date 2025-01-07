#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Hash2.h"

int minCoinsRecur(int i, int longitud, int *coins, int n) {
    // Caso base
    if (longitud == 0) return 0;
    if (longitud < 0 || i == n) return INT_MAX;

    int take = INT_MAX;
    if (coins[i] > 0 && longitud - coins[i] >= 0) {
        take = minCoinsRecur(i, longitud - coins[i], coins, n);
        if (take != INT_MAX) {
            take++;
        }
    }

    if (take != INT_MAX) {
        Nodo3 *nodito3 = BuscarNodo3(coins[i]);
        if (nodito3) {
            nodito3->valor++;
        }
    }

    return take;
}

int minCoins(int *coins, int longitud, int n) {
    int ans = minCoinsRecur(0, longitud, coins, n);
    return ans != INT_MAX ? ans : -1;
}

int main() {
    int coins[] = {4, 6, 8, 10, 12};
    int longitud, resultado;

    printf("Ingrese la longitud de la barra de chocolate: ");
    while (1) {
        resultado = scanf("%d", &longitud);
        if (resultado == 1 && longitud > 2) {
            break;
        } else {
            printf("Entrada invalida. Ingrese un numero mayor que 2: ");
            while(getchar() != '\n');
        }
    }

    int n = sizeof(coins) / sizeof(coins[0]);

    // Inicializar la tabla hash
    Tabla_Hash3 = (Nodo3 **)calloc(t_tam3, sizeof(Nodo3 *));
    insertarNodo3(12, 0);
    insertarNodo3(10, 0);
    insertarNodo3(8, 0);
    insertarNodo3(6, 0);
    insertarNodo3(4, 0);

    int result = minCoins(coins, longitud, n);
    if(result != -1) {
        printf("Es posible cortar la barra de longitud %d\n", longitud);
        Nodo3 *a = BuscarNodo3(12);
        Nodo3 *b = BuscarNodo3(10);
        Nodo3 *c = BuscarNodo3(8);
        Nodo3 *d = BuscarNodo3(6);
        Nodo3 *e = BuscarNodo3(4);

        printf("Se ocuparon %d barras de 12\n", a->valor);
        printf("Se ocuparon %d barras de 10\n", b->valor);
        printf("Se ocuparon %d barras de 8\n", c->valor);
        printf("Se ocuparon %d barras de 6\n", d->valor);
        printf("Se ocuparon %d barras de 4\n", e->valor);
    } else {
        printf("NO es posible cortar una barra de longitud %d\n", longitud);
    }

    verTablaNodo3();
    suprimirTablaHash3();

    return 0;
}
