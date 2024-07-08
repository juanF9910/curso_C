#include <stdio.h>

/*
este código calcula la suma de dos números
*/

/*
cuando se pide un char se usa ampersand
cuando se pide un string no se usa ampersand 
*/
int main(){
    int num1, num2; 
    char nombre;

    printf("ingrese los dos números a operar \n"); 
    scanf("%i %i", &num1, &num2); 

    printf("ingrese su nombre"); 
    scanf("%c", &nombre);
 
    printf("la suma es: %i \n", num1+num2); 
    printf("la resta es: %d \n", num1-num2 ); 
    printf("la multiplicación es: %i \n ", num1*num2); 
    printf("la división es: %i \n ", num1/num2); 

    return 0; 
}
