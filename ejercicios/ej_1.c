/*
vamos a contar espacios en blanco,tab y saltos de línea
*/

#include <stdio.h>

int main(){

    int leido; 

    int cont=0; 

    while( (leido=getchar())!= '\n'){ //en el teclado en EOF se escribe como ctrl+d

        if( leido==' ' | leido== '\t' | leido=='\n'){
            cont++;
        }
    }
    printf("el número es: %i", cont); 

    return 0; 
}