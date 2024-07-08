#include <stdio.h>

/*
para imprimir la posición de memoria se usa %p 
*/

/*
pasar por valor y por referencia,
punteros

cuando se pasa por referencia se modifica la variable
por si sola, no es necesario igualarla 
a alguna función.
*/


void cubo(int *num); //prototipo de una función que pide valores por referencia. 

int main(){
    int a=2; 

    /*int *apt=&a; //definición del apuntador
    printf("%i \n", *apt);
    printf("%p\n", &a);
    printf("%p \n", apt);*/

    int num=5; 
    printf("%i \n", num);
    cubo(&num); //acá se cambia el valor
    printf("%i \n", num);
    return 0; 
}

void cubo(int *num){

   *num= *num * *num * *num;
}