#include <stdio.h>
#include <stdlib.h>
#include "opaco.h"


/*definimos las estructuras y las funciones*/
struct foo{
    int a;  char b; 
};

foo_t *nuevo_foo(){

    foo_t *f=( foo_t*) malloc(sizeof(foo_t )); /*
    malloc entrega un puntero vacío, a una estructura
    no es necesario castearlo. 
    */
        set_foo(f, 0, 0);
        return f; 
}

void borrar_foo( foo_t *foo){

    free(foo);
}

void set_foo( foo_t *foo, int a, int b){

    foo->a=a; foo->b=b; 
}

int suma_foo(foo_t *foo){

    return foo->a+foo->b; 
}

