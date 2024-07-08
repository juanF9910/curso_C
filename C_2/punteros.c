#include <stdio.h>
#include <math.h>

/*
siempre que se pasa un puntero el valor de la variable se 
modifica con el asterísco, no de forma directa.

la función puede devolver alguna cosa que no sea la variable pasada por
referencia, pero si se modifica la variable dentro de la función 
esta va a cambiar de forma global 

si se tiene una estructura y un puntero a ella, 
se puede acceder a los elementos de la estructura usando (*c) o c->
*/

int jugar (int* n);


int main(){

    int x=10, s; 
    int* ptr_x=&x; 
    printf("%i \n", x);
    s=jugar(ptr_x); 
    printf("%i\n", x);
 
    return 0; 
}

int jugar (int* n){
    int y=*n; 
    y=y+3;
    *n=y;

    return y+4; 
}