
# include <stdio.h>
# include <stdlib.h>
# include "Hash.h"
# include "Hash2.h"

int posiblesCortes(int cortes[5], int longitud, int demanda, struct Nodo3** Tabla_Hash3, int indice, Nodo** Tabla_Hash);
int menu();

int main(){

    int longitud, longitudp, demanda, resultado, num, valor;
    int cortes[5] = {0, 0, 0, 0, 0};
    num = 0;

    switch(menu()){
        case(1):
            cortes[0] = 12;
            cortes[1] = 10;
            cortes[2] = 8;
            cortes[3] = 6;
            cortes[4] = 4;
            num=5;
            break;
        case(2):
            do {
            printf("Introduzca el numero de cortes personalizados (mayor a 0, menor a 6): ");
            scanf("%d", &num);
            } while (num <= 0 || num > 5); 
        
            printf("Introduzca cada una de sus medidas seguidas por presionar 'enter' ");
            for (int i = 0; i < num; i++) {
                scanf("%d", &valor);
                cortes[i] = valor;
            }
            break; 
    }

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
    longitudp = longitud;
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
        longitudp = longitud - 3; 
    }
    t_tam = 26;
    t_tam3=13;
    Tabla_Hash = (Nodo **)calloc(t_tam, sizeof(Nodo *));
    Tabla_Hash3 = (Nodo3 **)calloc(t_tam3, sizeof(Nodo3 *));
    for(int i=0; i<num; i++){
        insertarNodo3(cortes[i], 0);
    }

    int flag = posiblesCortes(cortes, longitudp, demanda, Tabla_Hash3, 0, Tabla_Hash);
    if(flag){
        printf("Es posible cortar la barra de longitud %d con %d barras distintas\n", longitud, demanda);

        for(int i=0; i<num; i++){
            Nodo3 *a = BuscarNodo3(cortes[i]);
            printf("Se ocuparon %d barras de %d\n", a->valor, cortes[i]);
        }

        if(longitud&1)
            printf("Con un sobrante de longitud 3\n");

    }else{
        printf("NO es posible cortar %d barras para una barra de longitud %d\n", demanda, longitud);
    }
    
    suprimirTablaHash3();
    suprimirTablaHash();
    return 0;
}

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

int menu(){
    int opcion;
    printf("Para utilizar las medidas de cortes predeterninadas [4,6,8,10,12] escriba 1\n");
    printf("Para introducir  medidas de demandas personalizadas escriba 2\n");
    scanf("%d", &opcion);
    return opcion;
}