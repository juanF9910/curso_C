#include <stdio.h>

int main(){

    FILE *f= fopen( "binario.txt", "r"); 

    if (!f){
        perror("no se puede abrir el archivo"); 
        return 1; 
    }

    char buffer[80]; 

   /* fgets() función recibe un puntero al array en donde se va a guardar
    la información, luego se pone el tamaño máximo de información que va a leer,
    y el puntero al archivo. fgets devuelve el mismo puntero buffer, por esto no hay que igualarlo.
    */

    while(fgets(buffer, sizeof(buffer), f) != EOF){ //fgets deja de leer caracteres cuando llega al tamaño máximo especificado. 

        printf("%s", buffer);
    }

    fclose(f);


    return 0; 
}