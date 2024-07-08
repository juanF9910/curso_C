/*
dado un vector vamos a calcular la media aritmética de sus componentes
*/

#include <stdio.h>

float media(float *x, int tam){

    float med=0;
    for(int i=0; i<tam; i++){
        med+=x[i];
    }
    return med/tam; 
}
int main(){

    float vector[]={1,2,3,4,5,6,7,8,9,0,10,13,2};
    float *x=vector;
    int SIZE=sizeof(vector)/sizeof(float);
    printf("la media del vector ingresado es: %f\n", media(x, SIZE));
    return 0; 
}