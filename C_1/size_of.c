#include <stdio.h>


size_t getsize(float *ptr);

int main(){

    float r[20]; 

    printf("el tamaño del arreglo en Bytes es: %lu \n", sizeof(r));
    printf("el número de bytes es: %lu \n", getsize(r));
    return 0; 
}

size_t getsize(float *ptr){

    return sizeof(ptr);
}