#include  <stdio.h>

/*
cuando trabajamos con números estos tiene una representación binaria 1000010
el primer dígito a la izquierda lo conocemos como MSB o el bit más
significativo y al más a la derecha lo conocemos como el LSB o bit menos significativo
*/

int main(){

    /*operación not ~X: el complemento de un número binario es tomar el número y cambiar ceros por 1, por ejemplo, 
    complemento de 10001 es 01110 

    1 es verdadero, 0 es falso
    */

    unsigned char X=156, a=185, b=52; 

    printf("el complemento de %u es %u\n", X, (unsigned char) ~X); 
    printf("X=  %u; X << 1 = %u\n", X, X<<1); //moverse n bits a la izquierda es multiplicar el número por 2*n
    printf("X=  %u; X >> 1 = %u\n", X, X>>1); //moverse n bits a la derecha es dividir el número por 2*n
    printf("a & b= %u \n", a & b); //conjunción (x y y)
    printf("a | b=  %u \n", a|b); //disjunción (x o y )
    printf("a xor b=  %u \n", a^b); //disjunción exclusiva (o x o y) 

    /*operador a & b): genera otro num binario que se arma comparando 
    la forma binaria de a y b, con el operador conjunción. 1 y 1 ent 1, 1 y 0 ent 0
    */

    // operador a | b): hace lo propio pero con el operador O

    //XOR(a, b): sólo pone un 1 si hay 1 uno en la comparación de los número. 

    return 0; 
}