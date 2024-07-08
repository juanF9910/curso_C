#include <stdio.h>

/*
factorial de un número como función recursiva
*/

long Factorial(long n); /*
definimos el prototipo de la función
*/

int main(){
    long numero;
    printf("ingrese el número");
    scanf("%li", &numero);
    printf("el factorial de %li es: %li \n", numero, Factorial(numero));
    return 0; 
}

long  Factorial(long numero){

    if (numero <=0){
        return 1; 
    }
    else{
        return(numero*Factorial(numero-1));
    }
}