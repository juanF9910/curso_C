/*
en este programa vamos tomar un vector que tiene un registro de temperaturas en °C y los vamos a convertir a °F

LOS PUNTEROS A ARRAYS ES MEJOR MANEJARLOS SIEMPRE POR COMPONENTES Y NO POR PUNTEROS. 
*/
#include <stdio.h>
#include <stdlib.h>

float *convertir(float *celcius, int tam){

    float *farenheit=(float *)calloc(tam,sizeof(float)); 

    for( int i=0; i<tam; i++){
        farenheit[i]=celcius[i]*9/5+32;
    }

    return farenheit; 
}

int main(){
/*
si se usa el comando sizeof(puntero) sale el tamaño del puntero no del array 
al que apunta
*/
    float array[]={0, 2,3 , 4, 5, 6, 7, 8, 9, 10}; //conjunto de datos en celcius
    float *celcius=array; 
    int tam=sizeof(array)/sizeof(float); // a la función sizeof le debemos pasar el array, no el puntero al array. 
    float *farenheit=convertir(celcius, tam); 
    printf(" celcius \t farenheit\n");
    
    for(int i=0; i<tam; i++){
        printf("%f \t %f\n", celcius[i],farenheit[i]);
    }

    free(farenheit); 

    return 0; 
}