/*
queremos escribir un código que elimine los 
espacios de blanco repetidos de una cadena
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void quitar(char *cadena){

    int i=0, leido=0;
    char last_char=0;
    int cont=0; 

    while( (leido=cadena[i]) != '\0'){

        if( leido !=' '){
            putchar(leido);
        }else{
            if(last_char!=' '){
                putchar(leido);
            }  
        }
        last_char=leido; i++;
    }
}

int main(){

    char c, last_char; 
    while( (c=getchar())!='\n'){

        if( c!=' '){
            putchar(c); 
        }else{

            if( last_char!=' '){
                putchar(c);
            }
        }
        last_char=c; 
    }
    return 0; 
}