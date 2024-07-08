#include <stdio.h>
#include <stdarg.h>

int suma( int numarg, ...){

    va_list vargs; 
    int cont=0; 
    va_start(vargs, numarg);

    for(int i=0; i<numarg; i++){
        int sig=va_arg(vargs, int); /* lo que devuelve es 
    una variable del tipo que se le entrega, entrega el siguiente argumento*/
        cont+=sig; 
    }
    
    va_end(vargs);
    return cont; 
}

int main(){
    int total=suma(3, 1, 2, 3); 
    printf("el totales: %d \n", total); 
    return 0; 
}