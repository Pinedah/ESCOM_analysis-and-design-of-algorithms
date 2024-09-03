
/*
Fecha: Septiembre 3, 2024
Nombre de Equipo:  PAR de tres
Integrantes: Andrea Acevedo Medina, Francisco Pineda Hernandez, Rodrigo Vidal Ramirez Aguilar

Tras 5 iteraciones: 

El peor caso fue: 8
El mejor caso fue: 0
El promedio fue: 4.000
*/

// SUPONGASE QUE EL USUARIO NO ES IMBECIL:  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarAleatorio(int menor, int mayor, int parImpar);

int main(){

    srand(time(NULL));

    float promedio = 0;
    int mejorCaso = 0, peorCaso = 0, iteraciones = 5;
    for (int i = 0; i < iteraciones; i++){

        
        int intMayor = 100, intMenor = 0, parImpar = 0;
        printf("\nIteracion: %d \nElige un numero entre el 0 y el %d\n", i + 1,  intMayor);

        printf("Indica si es impar(1) par(2): ");
        scanf("%d", &parImpar);

        int aleatorio = generarAleatorio(intMenor, intMayor, parImpar);

        int opcion = 2, contador = 0;
        do{
            printf("\nTu numero es: %d \n0 -> Si es tu numero \n1 -> Es mayor \n2 -> Es menor\n\n", aleatorio);
            scanf("%d", &opcion);
            if (opcion == 1){
                intMenor = aleatorio + 1;
                aleatorio = generarAleatorio(intMenor, intMayor, parImpar);
                contador++;
            }else if(opcion == 2){
                intMayor = aleatorio - 1;
                aleatorio = generarAleatorio(intMenor, intMayor, parImpar);
                contador++;
            }
            
        }while (opcion != 0);
        printf("\nEl numero de iteraciones fueron: %d\n\n", contador);

        if(contador > peorCaso){
            peorCaso = contador;
        }
        if(contador < mejorCaso){
            mejorCaso = contador;
        }

        promedio += contador;
    }
    
    promedio /= iteraciones;
    printf("\n\nEl peor caso fue: %d \nEl mejor caso fue: %d \nEl promedio fue: %0.3f\n\n", peorCaso, mejorCaso, promedio);
    

    return 0;
}


int generarAleatorio(int menor, int mayor, int parImpar){

    int num;
    if(parImpar == 1){
        
        do{
            num = rand() % (mayor - menor + 1) + menor;
        }while(num % 2 == 0);
        return num;
    
    }else{

        do{
            num = rand() % (mayor - menor + 1) + menor;
        }while(num % 2 != 0);
        return num;
    }
}