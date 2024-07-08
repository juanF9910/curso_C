#include "opaco.c"
#include <stdio.h>


int main(){

    foo_t *f; 
    f=nuevo_foo(); 
    set_foo(f, 4, 2); 
    puts("imprimir");
    printf( "mi foo vale %d \n", suma_foo(f)); 
    borrar_foo(f); 

    return 0; 
}