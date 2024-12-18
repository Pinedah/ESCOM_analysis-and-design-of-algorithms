#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct key {
    int a[3];  
} key;

typedef struct Nodo {
    key clave;           
    int valor;            
    struct Nodo *ptrsig;  
} Nodo;

Nodo **Tabla_Hash;
int t_tam;

int comparar_claves(key k1, key k2) {
    for (int i = 0; i < 3; i++) {
        if (k1.a[i] != k2.a[i]) return 0;
    }
    return 1;
}

int hash1(key clave) {
    int h = 0;
    for (int i = 0; i < 3; i++) {
        h = h * 31 + clave.a[i];
    }
    return abs(h % t_tam);
}

Nodo *NuevoNodo(key clave, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->clave = clave;
    nuevo->valor = valor;
    nuevo->ptrsig = NULL;
    return nuevo;
}

void insertar(key clave, int valor) {
    int indice = hash1(clave);
    Nodo *p = Tabla_Hash[indice];

    while (p) {
        if (comparar_claves(p->clave, clave)) { // Si la clave ya existe
            p->valor = valor; // Actualiza el valor
            return;
        }
        p = p->ptrsig;
    }

    // Si no existe, agrega un nuevo nodo
    Nodo *nuevo = NuevoNodo(clave, valor);
    nuevo->ptrsig = Tabla_Hash[indice];
    Tabla_Hash[indice] = nuevo;
}

Nodo *Buscar(key clave) {
    int indice = hash1(clave);
    Nodo *p = Tabla_Hash[indice];

    while (p) {
        if (comparar_claves(p->clave, clave)) return p;
        p = p->ptrsig;
    }
    return NULL;
}
void suprimir(key clave) {
    int indice = hash1(clave);
    Nodo *p = Tabla_Hash[indice];
    Nodo *anterior = NULL;

    while (p) {
        if (comparar_claves(p->clave, clave)) {
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
            printf("[(");
            for (int j = 0; j < 3; j++) {
                printf("%d", p->clave.a[j]);
                if (j < 2) printf(", ");
            }
            printf("): %d] -> ", p->valor);
            p = p->ptrsig;
        }
        printf("NULL\n");
    }
}
void suprimirTablaHash() {
    for (int i = 0; i < t_tam; i++) {
        Nodo *p = Tabla_Hash[i];
        while (p) {
            Nodo *temp = p;
            p = p->ptrsig;
            free(temp);
        }
        Tabla_Hash[i] = NULL; 
    }
}



