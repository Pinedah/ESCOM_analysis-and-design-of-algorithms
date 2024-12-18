#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Nodo3 {
    int clave;           
    int valor;            
    struct Nodo3 *ptrsig;  
} Nodo3;

Nodo3 **Tabla_Hash3;
int t_tam;

int hash3(int clave) {
    return (clave % t_tam);
}

Nodo3 *NuevoNodoNodo3(int clave, int valor) {
    Nodo3 *nuevo = (Nodo3 *)malloc(sizeof(Nodo3));
    nuevo->clave = clave;
    nuevo->valor = valor;
    nuevo->ptrsig = NULL;
    return nuevo;
}

void insertarNodo3(int clave, int valor) {
    int indice = hash3(clave);
    Nodo3 *p = Tabla_Hash3[indice];

    while (p) {
        if (p->clave == clave) {
            p->valor = valor; 
            return;
        }
        p = p->ptrsig;
    }

    
    Nodo3 *nuevo = NuevoNodoNodo3(clave, valor);
    nuevo->ptrsig = Tabla_Hash3[indice];
    Tabla_Hash3[indice] = nuevo;
}

Nodo3 *BuscarNodo3(int clave) {
    int indice = hash3(clave);
    Nodo3 *p = Tabla_Hash3[indice];

    while (p) {
        if (p->clave == clave) 
            return p;
        p = p->ptrsig;
    }
    return NULL; 
}

void suprimirNodo3(int clave) {
    int indice = hash3(clave);
    Nodo3 *p = Tabla_Hash3[indice];
    Nodo3 *anterior = NULL;

    while (p) {
        if (p->clave == clave) {
            if (anterior) anterior->ptrsig = p->ptrsig;
            else Tabla_Hash3[indice] = p->ptrsig;
            free(p);
            return;
        }
        anterior = p;
        p = p->ptrsig;
    }
}

void verTablaNodo3() {
    for (int i = 0; i < t_tam; i++) {
        Nodo3 *p = Tabla_Hash3[i];
        printf("Hash %d: ", i);
        while (p) {
            printf("[%c: %d] -> ", p->clave, p->valor);
            p = p->ptrsig;
        }
        printf("NULL\n");
    }
}



