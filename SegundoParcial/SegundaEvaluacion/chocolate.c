
# include <stdio.h>
# include <stdlib.h>
# include "Hash.h"


struct Nodo2{
    int dato;
    struct Nodo2 *ptrSig;};

struct Nodo2* crearNodo(int elem);
void meterNodo(struct Nodo2 *ptrRef, int elem); //no va a regresar nada bc ptrRef
int recorrerLista(struct Nodo2* ptrRef, int valorBuscado);


int posiblesCortes(int cortes[5], int longitud, int demanda, struct Nodo2 *queCortes, int indice, struct Nodo* Tabla_Hash){
    
    

    int corte = posiblesCortes(cortes, longitud - cortes[indice], demanda - 1, queCortes, indice, Tabla_Hash); 
    
    if(corte){
        meterNodo(queCortes, cortes[indice]);
    }

}

int main(){

    int cortes[5] = {4, 6, 8, 10, 12};

    struct Nodo2 *miptrRef;
    int mielem;
    miptrRef=crearNodo(-1000);

    int longitud, demanda;
    printf("Ingrese la longitud de la barra de chocolate: ");
    scanf("%d", &longitud);
    printf("Ingrese la demanda (cantidad de barras deseadas): ");
    scanf("%d", &demanda);


    
    t_tam = 5;
    Tabla_Hash = (Nodo **)calloc(t_tam, sizeof(Nodo *));

    int flag = posiblesCortes(cortes, longitud, demanda, miptrRef, 0, Tabla_Hash);



    if(flag){
        printf("Es posible cortar la barra de longitud %d con %d barras distintas", longitud, demanda);
        int a = recorrerLista(miptrRef, 12);
        int b = recorrerLista(miptrRef, 10);
        int c = recorrerLista(miptrRef, 8);
        int d = recorrerLista(miptrRef, 6);
        int e = recorrerLista(miptrRef, 4);

        printf("Se ocuparon %d barras de 12", a);
        printf("Se ocuparon %d barras de 10", b);
        printf("Se ocuparon %d barras de 8", c);
        printf("Se ocuparon %d barras de 6", d);
        printf("Se ocuparon %d barras de 4", e);

    }else{
        printf("NO es posible cortar %d barras para una barra de longitud %d", demanda, longitud);
    }

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