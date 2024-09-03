
/*
Fecha: Septiembre 3, 2024
Nombre de Equipo:  PAR de tres
Integrantes: Andrea Acevedo Medina, Francisco Pineda Hernandez, Rodrigo Vidal Ramirez Aguilar
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generarAleatorio(int menor, int mayor, int parImpar){

    if(parImpar == 1){
        // int num = rand() % (mayor - menor + 1) + menor;
        return (rand() % (mayor - menor + 1) / 2) * 2 + 1;     
    }else{
        return (rand() % (mayor - menor + 1) / 2) * 2;     
    }

}

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
    
    printf("\n\nEl peor caso fue: %d \nEl mejor caso fue: %d \nEl promedio fue: %0.3f", peorCaso, mejorCaso, promedio);
    

    return 0;
}