#include <stdio.h>

#define PI 4.14159

#define CUBO(a, b) a*b*a /* las macros funciones como funciones pero son más
rápidas
este código calcula la suma de dos números
*/
int main(){

    int edad, a=3, b=2; 
    printf("el macro da: %d\n", CUBO(a, b)); 
    printf("ingresa tu edad \n"); 
    scanf("%i", &edad); 

    if(edad>=18){
        printf("eres mayor de edad\n"); 
    }
    else if(edad==17){
        printf("eres casi mayor de edad\n"); 
    }
    else{
        printf("eres menor de edad\n");
    }
    return 0; 
}