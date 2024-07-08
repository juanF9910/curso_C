#include  <stdio.h>

/*
strlen("juan felipe zapata")
*/
int main(){

    int edades[8]={0}; 
    /*
    esta es una forma de inicializar los vestores con valor cero, 
    para un mejor desempeño de los algoritmos
    */

    for(int i=0; i<8; i++){

        printf("%d \n", edades[i]);
    }
    return 0; 
}