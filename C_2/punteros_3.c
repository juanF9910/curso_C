#include <stdio.h>
#include <stdlib.h> // para usar system("clear") y también new, delete

/*
para definir el puntero a un vector 
lo que se hace es igualar el puntero al vector, 
sumar un número a un puntero es hacer que se mueva 
ciertas posiciones en la memoria. 
*/

/*
si tengo un puntero a un arreglo puedo acceder a los elemtos 
como puntero[i] o como *puntero++, es más, puedo definir el puntero
como el array y no ponerle nombre al array. 
*/

int main(){

    int num[]={1, 2, 3, 4,5 }, *dir_num; 

    dir_num=num; 


    for(int i=0; i<5; i++){

        printf("%i \n", *dir_num++);
    }

    return 0; 
}