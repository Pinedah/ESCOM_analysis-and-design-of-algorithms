#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Nodo {
    char clave;           
    int valor;            
    struct Nodo *ptrsig;  
} Nodo;

Nodo **Tabla_Hash;
int t_tam;

int hash1(char clave) {
    return (clave % t_tam);
}

Nodo *NuevoNodo(char clave, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->clave = clave;
    nuevo->valor = valor;
    nuevo->ptrsig = NULL;
    return nuevo;
}

void insertar(char clave, int valor) {
    int indice = hash1(clave);
    Nodo *p = Tabla_Hash[indice];

    while (p) {
        if (p->clave == clave) {
            p->valor = valor; 
            return;
        }
        p = p->ptrsig;
    }

    
    Nodo *nuevo = NuevoNodo(clave, valor);
    nuevo->ptrsig = Tabla_Hash[indice];
    Tabla_Hash[indice] = nuevo;
}

Nodo *Buscar(char clave) {
    int indice = hash1(clave);
    Nodo *p = Tabla_Hash[indice];

    while (p) {
        if (p->clave == clave) return p;
        p = p->ptrsig;
    }

    return NULL; 
}
void suprimir(char clave) {
    int indice = hash1(clave);
    Nodo *p = Tabla_Hash[indice];
    Nodo *anterior = NULL;

    while (p) {
        if (p->clave == clave) {
            if (anterior) anterior->ptrsig = p->ptrsig;
            else Tabla_Hash[indice] = p->ptrsig;
            free(p);
            return;
        }
        anterior = p;
        p = p->ptrsig;
    }
}

void verTabla() {
    for (int i = 0; i < t_tam; i++) {
        Nodo *p = Tabla_Hash[i];
        printf("Hash %d: ", i);
        while (p) {
            printf("[%c: %d] -> ", p->clave, p->valor);
            p = p->ptrsig;
        }
        printf("NULL\n");
    }
}



