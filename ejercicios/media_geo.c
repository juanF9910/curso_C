#include <stdio.h>
#include <math.h>

/*
vamos a calcular la media geométrica de un vector numérico.
para compilar la función pow es necesario llamar durante la compilación la
librería -lm
*/

float media_geo(float *numeros, int size){
    float mult=1.0; 

    for(int i=0; i<size; i++){
        mult*=numeros[i];
    }

    return pow(mult, 1.0/size);
}

int main(){
    float vect[]={1,2,3,4,5,6};
    float *v=vect;
    int SIZE=sizeof(vect)/sizeof(float);
    printf("la media geométrica es: %f\n", media_geo(v, SIZE));
    return 0; 
}