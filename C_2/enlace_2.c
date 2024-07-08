#include <stdio.h>

typedef struct Nodo{

    int valor; 
    struct Nodo *anterior; 
    struct  Nodo *siguiente; 

} Nodo; 


(Nodo *) nodo_nuevo( const int valor, Nodo *anterior){

    Nodo *nuevo= (Nodo *) calloc(1, sizeof(Nodo)); 
    nuevo->valor=valor; 
    nuevo->anterior=anterior; //puntero

    return nuevo;
}

int main(){

 
    return 0; 
}