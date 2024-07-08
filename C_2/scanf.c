#include <stdio.h>

int main(){

    char nombre[10]; /*
    9 caracteres más el cero al final
    */
    printf("ingrese su nombre");
    scanf("%9s", nombre); 
    printf("%s", nombre); 
    /*
    para leer con salto de línea usamos el comando fgets
    */

    fgets(nombre, 9, stdin); // es mejor usar este cuando de trata de strings. 
    return 0; 
}