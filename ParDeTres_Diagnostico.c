
/*
Fecha: Septiembre 3, 2024
Nombre de Equipo:  PAR de tres
Integrantes: Andrea Acevedo Medina, Francisco Pineda Hernandez, Rodrigo Vidal Ramirez Aguilar
*/

#include <stdio.h>
#include <stdlib.h>


int generarAleatorio(int menor, int mayor){
    return rand() % (mayor - menor + 1) + menor;
}

int main(){

    int intMayor = 10, intMenor = 0;

    printf("\nElige un numero entre el 0 y el 500\n");
    int aleatorio = generarAleatorio(intMenor, intMayor);

    int opcion = 2, contador = 0;
    do{
        printf("\nTu numero es: %d \n0 -> Si es tu numero \n1 -> Es mayor \n2 -> Es menor\n\n", aleatorio);
        scanf("%d", &opcion);
        if (opcion == 1){
            intMenor = aleatorio + 1;
            aleatorio = generarAleatorio(intMenor, intMayor);
            contador++;
        }else if(opcion == 2){
            intMayor = aleatorio - 1;
            aleatorio = generarAleatorio(intMenor, intMayor);
            contador++;
        }
        
    }while (opcion != 0);
    
    printf("\nEl numero de iteraciones fueron %d\n\n", contador);
    
    

    return 0;
}