#include <stdio.h>

/* 
los comandos fputc y fputs funcionando completamente 
análogo a lo que son fgetc fgets
*/
 
int main(){

    FILE *f= fopen("binario_1.txt", "w+"); //lo que hace w es que elimina todo lo que hay en el archivo para que escribamos desde cero. 

    if(!f){

        printf("error al leer el archivo"); 
        return 1; 
    }

    char result = fputc('h', f); 
    
    /*
    printf("%c", result); 
    fputc devuelve un valor numérico igual 
    a lo que le ingresamos, si todo sale bien. si 
    algo sale mal lo que entrega es  EOF 
    */

    fputs("hola como estás?", f); 

    /*
    esta función devuelve un valor positivo si todo 
    funcionó bien, en el caso contrario devuelve EOF
    */

    return 0; 
}