/*
vamos a leer nombres con espacios usando scanf
*/

#include <stdio.h>

int main(){
    puts("ingrese su nombre y apellido"); 
    char buffer[30]; 
    scanf("%[^\n]s", buffer); // esto sifnigica que lea todo excepto lo que tenga un salto de línea. 
    printf("nombre: %s", buffer);
    return 0; 
}