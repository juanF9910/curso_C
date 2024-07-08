#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo /*este tipo de lista 
se conoce como simplemente enlazada*/{ 
    int valor; 
    struct Nodo *siguiente; 
} Nodo;

struct nodo_2{ //este tipo de listas permite enlazar con cualquier tipo de objetos, arrays, strcuturas
    char valor; 
    void *siguiente; 
};

int main(){

    /*
    el siguiente es un ejemplode una lista simplemente enlazada (serie de nodos conectados con un puntero) con tres valores
    */

    Nodo primero;
    Nodo segundo; 
    Nodo tercero; 

    primero.valor=12; 
    segundo.valor=99;
    tercero.valor=37;
    primero.siguiente=&segundo;
    segundo.siguiente=&tercero;
    tercero.siguiente=NULL; 

    printf("valor %i \n  ",primero.valor); 
    printf("valor %i \n  ",primero.siguiente->valor); 
    printf("valor %i \n  ",segundo.siguiente->valor); 

    /*
    para interar sobre una lista simplemente enlazada debemos 
    definir un puntero al primero elemento de la lista.  
    */
   Nodo *iteracion = &primero; 

   while(iteracion){ //mientras el iterador apunte a algo que no sea null. 
   
        printf("%i \n", iteracion->valor); 
        iteracion= iteracion->siguiente;
   }


    return 0; 
}