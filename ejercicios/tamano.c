/*
en este código vamos a determinar el tamaño en bytes de diferentes tipos de datos. 
*/

#include <stdio.h>


int main(){

/////////////////////////////////////// 1 byte
    char x1; 
    printf("char %zu \n", sizeof(x1)); 
//////////////////////////////////////////// 2 bytes
    short x8; 
    printf("short %zu \n", sizeof(x8));   
////////////////////////////////////////// 4 bytes
    int x2; 
    printf("int %zu \n", sizeof(x2)); 
    unsigned int x3; 
    printf("unsigned int %zu \n", sizeof(x3)); 
    float x5; 
    printf("float %zu \n", sizeof(x5));
//////////////////////////////////////////////// 8 bytes 
    long x7; 
    printf("long %zu \n", sizeof(x7));
    long int x4; 
    printf("long int %zu \n", sizeof(x4)); 
    double x6; 
    printf("double %zu \n", sizeof(x6));
///////////////////////////////////////////////// 16 bytes    
    long double x10; 
    printf("long double %zu \n", sizeof(x10));
    
    return 0; 
}