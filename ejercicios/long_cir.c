/*
vamos a calcular la longitud de una circenferencia dados el ángulo y el radio
*/

#include <stdio.h>

void longitud(float angulo, float radio){

    printf("la longitud del sector de circunferencia es: %f \n", angulo*radio);
}
int main(){
    float ang=0, r=0; 
    puts("ingrese en ángulo y el radio de la sección de circunferencia");
    scanf("%f %f", &ang, &r); 
    longitud(ang, r);


    return 0; 
}