#include <stdio.h>
/*fprintf se usa para escribir en archivos datos con formato*/
int main(){

    FILE *f=fopen("lineas.txt", "w" ); 

    if(!f){

        perror("no se pudo abrir el archivo"); 
        return 1; 
    }
    int valor=50;
    char cadena[30]; 
    fprintf(f, "el resultado es %d", valor);
    snprintf(cadena, 29, "el resultado es: %d", valor ); 


    fclose(f); 
    return 0; 
}