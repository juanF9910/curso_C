#include <stdio.h>

int main(){

    // el unsigned char puede almacenar números en el intervalo    0, 255
    unsigned char num=100; //el complemente en este caso sería (número más grande que se puede guardar)-num
    printf("%i \n", (unsigned char)~num); 

    return 0; 
}