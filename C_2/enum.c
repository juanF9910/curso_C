#include <stdio.h>

int main(){

    enum dias{ LUNES=1, MARTES, MIERCOLES, JUEVES,
    VIERNES, SABADO, DOMINGO}; 

    enum dias dia; 
    dia=LUNES; 

    printf("el día es: %i", dia); 
    return 0; 
}