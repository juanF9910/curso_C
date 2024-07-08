#include<stdio.h>
/*
en este código se exploran los diferentes tipos de datos 
*/
int main(){

    char y='y'; //1 byte desde cero hasta 255 caracteres

    //los siguinetes no admiten punto decimal

    int a=20; // 2 bytes desde -32768 hasta 32767 %i
    unsigned int u=25; // 2 bytes desde 0 hasta 65535 %i
    short e=-1; // 2 bytes desde -128 hasta 127 %i
    long  l=50; // 4 bytes  %li
    unsigned long k; // %lu

    //los siguientes sí admiten punto decimal
    float f=73.2345; //4 bytes %f
    double d=3453; //8 bytes %f, %lf

    //long double

    printf("el char %c \n", y); 
    printf("el unsigned int %i\n", u); 
    return 0; 
}