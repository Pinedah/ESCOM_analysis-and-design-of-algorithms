
# include <stdio.h>
# include <stdlib.h>
# include "Hash.h"
# include "Hash2.h"

struct Nodo2{
    int dato;
    struct Nodo2 *ptrSig;};

struct Nodo2* crearNodo(int elem);
void meterNodo(struct Nodo2 *ptrRef, int elem); //no va a regresar nada bc ptrRef
int recorrerLista(struct Nodo2* ptrRef, int valorBuscado);

int posiblesCortes(int cortes[5], int longitud, int demanda, struct Nodo3** Tabla_Hash3, int indice, Nodo** Tabla_Hash){
    if(longitud==0 && demanda ==0){
        return 1;
    }
    if(longitud<0 || demanda<0 || indice>= 5){
        return 0;
    }
    key clave; 
    clave.a[0]=longitud;
    clave.a[1]=demanda;
    clave.a[2]=indice;
    Nodo *nodoExistente = Buscar(clave);
    if(nodoExistente){
        return nodoExistente->valor;
    }
    int corte = posiblesCortes(cortes, longitud - cortes[indice], demanda - 1, Tabla_Hash3, indice, Tabla_Hash); 
    
    if(corte){
        key clave2;
        clave2.a[0]=longitud;
        clave2.a[1]=demanda;
        clave2.a[2]=indice;

        // agregar al hashmap ñ
        //insertarNodo3(cortes[indice], 1);
        //no encuentra nodoexistente
        Nodo3 *nodito3 = BuscarNodo3((int)cortes[indice]);
        if (nodito3) {
            nodito3->valor=(nodito3->valor)+1;
        }
        insertar(clave2,1);
        return 1;
    }
    int no_usar_corte = posiblesCortes(cortes, longitud, demanda,Tabla_Hash3,indice+1,Tabla_Hash);
    key clave3;
    clave3.a[0]=longitud;
    clave3.a[1]=demanda;
    clave3.a[2]=indice;
    insertar(clave3,no_usar_corte);
    return no_usar_corte;

}

int main(){

    int cortes[5] = {4, 6, 8, 10, 12};

    //struct Nodo2 *miptrRef;

    struct Nodo3 *miptrRef;

    int mielem;
    //miptrRef=crearNodo(-1000);

    int longitud, demanda, resultado;
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
    printf("Ingrese la demanda (cantidad de barras deseadas): ");
    while (1) {
        int resultado = scanf("%d", &demanda);

        if (resultado == 1 && demanda > 0) {
            break;
        } else {
            
            printf("Entrada invalida. Ingrese un numero mayor que 0: ");
            while(getchar() != '\n');
        }
    }
    if(longitud&1){
        printf("NO Es posible cortar la barra de longitud %d con %d barras distintas pues la longitud es impar\n", longitud, demanda);
        exit(0);
    }
    t_tam = 26;
    t_tam3=13;
    Tabla_Hash = (Nodo **)calloc(t_tam, sizeof(Nodo *));
    Tabla_Hash3 = (Nodo3 **)calloc(t_tam3, sizeof(Nodo3 *));
    insertarNodo3(12, 0);
    insertarNodo3(10, 0);
    insertarNodo3(8, 0);
    insertarNodo3(6, 0);
    insertarNodo3(4, 0);
    int flag = posiblesCortes(cortes, longitud, demanda, Tabla_Hash3, 0, Tabla_Hash);
    if(flag){
        printf("Es posible cortar la barra de longitud %d con %d barras distintas\n", longitud, demanda);
        Nodo3 *a = BuscarNodo3(12);
        Nodo3 *b = BuscarNodo3(10);
        Nodo3 *c = BuscarNodo3(8);
        Nodo3 *d = BuscarNodo3(6);
        Nodo3 *e = BuscarNodo3(4);

        //printf("%d", a);
        printf("Se ocuparon %d barras de 12\n", a->valor);
        printf("Se ocuparon %d barras de 10\n", b->valor);
        printf("Se ocuparon %d barras de 8\n", c->valor);
        printf("Se ocuparon %d barras de 6\n", d->valor);
        printf("Se ocuparon %d barras de 4\n", e->valor);

    }else{
        printf("NO es posible cortar %d barras para una barra de longitud %d\n", demanda, longitud);
    }
    //printf("Tabla \n\n");
    //verTablaNodo3(Tabla_Hash3);
    suprimirTablaHash3();
    suprimirTablaHash();
    return 0;
}

struct Nodo2* crearNodo(int elem){
    struct Nodo2 *ptrN;
    ptrN=(struct Nodo2*)malloc(sizeof(struct Nodo2));
    ptrN->dato=elem;
    ptrN->ptrSig=NULL;
    return ptrN;
};
void meterNodo(struct Nodo2* ptrRef, int elem){
    struct Nodo2* ptrN1;
    ptrN1=crearNodo(elem);
    if(ptrRef->ptrSig==NULL)
        ptrRef->ptrSig=ptrN1; //creamos Nodo2 de cabecera
    else
        ptrN1->ptrSig=ptrRef->ptrSig; //Un nodo comun ahora apunta al Nodo2 de cabecera //!SIEMPRE PRIMER ENLACE DESDE LA DERECHA(del nodo nuevo)
        ptrRef->ptrSig=ptrN1;
};

/*
int recorrerLista(struct Nodo2 *ptrRef, int valorBuscado){
    struct Nodo2 *ptrRec;
    int contador;
    ptrRec=ptrRef->ptrSig;
    while(ptrRec!=NULL){
        if (ptrRec->dato == valorBuscado){
            contador++;
        }
        //printf("%d\n", ptrRec->dato);
        ptrRec=ptrRec->ptrSig;
    }
    return contador;
    //printf("\n");
};
*/


/*
def PosibleCambio(monedas, importe, num_monedas, queMonedas, index=0, memo=None):
    if memo is None:
        memo = {}
    if importe == 0 and num_monedas == 0:
        return True
    if importe < 0 or num_monedas < 0 or index >= len(monedas):
        return False
    if (importe, num_monedas, index) in memo:
        return memo[(importe, num_monedas, index)]

    usar_moneda = PosibleCambio(monedas, importe - monedas[index], num_monedas - 1,queMonedas, index, memo)

    if(usar_moneda):
        queMonedas.append(monedas[index])
        print(memo)
        memo[(importe, num_monedas, index)] = True
        return True

    no_usar_moneda = PosibleCambio(monedas, importe, num_monedas,queMonedas, index + 1, memo)
    memo[(importe, num_monedas, index)] = no_usar_moneda
    return no_usar_moneda


def main():
  tiposDeMonedas = [400, 600, 800, 1000, 1200]
  queMonedas=[]
  try:
    dolares=float(input("\nIngrese los dolares: "))
    importe = int(dolares*100)
    num_monedas = int(input("Ingrese la cantidad de monedas: "))
  except ValueError:
    print("\nPor favor ingrese un valor válido.\n")
    return

  monedas = PosibleCambio(tiposDeMonedas, importe,num_monedas, queMonedas)

  if monedas:
    print(f"Es posible formar ¢{importe} con {num_monedas} monedas")
    a=queMonedas.count(1)
    b=queMonedas.count(5)
    c=queMonedas.count(10)
    d=queMonedas.count(25)
    print(f"Se ocuparon {a} monedas de 1 centavo")
    print(f"Se ocuparon {b} monedas de 5 centavos")
    print(f"Se ocuparon {c} monedas de 10 centavos")
    print(f"Se ocuparon {d} monedas de 25 centavos")
  else:
    print(f"NO es posible formar ¢{importe} con {num_monedas} monedas")

if __name__ == '__main__':
    main()
*/