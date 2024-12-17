#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int dato;
    struct Nodo *ptrSig;};

struct Nodo* crearNodo(int elem);
void meterNodo(struct Nodo *ptrRef, int elem); //no va a regresar nada bc ptrRef
void recorrerLista(struct Nodo* ptrRef);
void eliminarNodo(struct Nodo* ptrRef);

int menu(){
    int opcion;
    printf("1. Crear Nodo\n");
    printf("2. Meter Nodo\n");
    printf("3. Eliminar Nodo\n");
    printf("4. Recorrer Lista\n");

    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    return opcion;

}
int main(){
    struct Nodo *miptrRef;
    int mielem;


    for(;;){
        switch(menu()){

    case 1:
        miptrRef=crearNodo(-1000);
        break;
    case 2:
        printf("\nIngrese un entero: ");
        scanf("%d", &mielem);
        meterNodo(miptrRef, mielem);
        break;
    case 3:
        eliminarNodo(miptrRef);
        break;
    case 4:
        recorrerLista(miptrRef);
        break;
    case 5:
        exit(0);
}
}
return 0;}
/*
    miptrRef=crearNodo(-1000);
    meterNodo(miptrRef, 10);
    meterNodo(miptrRef, 20);
    printf("RECORRER\n");
    recorrerLista(miptrRef);*/



struct Nodo* crearNodo(int elem){
    struct Nodo *ptrN;
    ptrN=(struct Nodo*)malloc(sizeof(struct Nodo));
    ptrN->dato=elem;
    ptrN->ptrSig=NULL;
    return ptrN;
};
void meterNodo(struct Nodo* ptrRef, int elem){
    struct Nodo* ptrN1;
    ptrN1=crearNodo(elem);
    if(ptrRef->ptrSig==NULL)
        ptrRef->ptrSig=ptrN1; //creamos Nodo de cabecera
    else
        ptrN1->ptrSig=ptrRef->ptrSig; //Un nodo comun ahora apunta al Nodo de cabecera //!SIEMPRE PRIMER ENLACE DESDE LA DERECHA(del nodo nuevo)
        ptrRef->ptrSig=ptrN1;
};



void recorrerLista(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    ptrRec=ptrRef->ptrSig;
    while(ptrRec!=NULL){
        printf("%d\n", ptrRec->dato);
        ptrRec=ptrRec->ptrSig;
    }
    printf("\n");
};


void eliminarNodo(struct Nodo* ptrRef){
    struct Nodo *ptrBorr;
    if(ptrRef->ptrSig!=NULL){
       ptrBorr=ptrRef->ptrSig;
   // printf("El dato recuperado es %d", ptrBorr->dato);
        ptrRef->ptrSig=ptrBorr->ptrSig;
        free(ptrBorr);
        printf("\n");}
    else{
        printf("La pila esta vacia :(\n");
    }
};
