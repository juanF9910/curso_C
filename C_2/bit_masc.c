#include <stdio.h>

/*

la máscara de bits actúa como un filtro que controla qué partes de la variable se ven afectadas por la operación de enmascaramiento

La enmascaración de bits implica manipular bits individuales dentro de un byte, la idea de enmascarar es guardar en un byte
la información relacionada con 8 colores

los operadores desplazamiento  << >> sirven para desplazar hacia la iz
quierda o la derecha los bits de un número, por ejemplo: 

    x= 101001
    x << 1 = 010010 

los bits que queden faltanto a la derecha se llenan con ceros. 
*/

/*
todas las definicines siguientes son de máscaras, las máscaras también se pueden definir como variables, no sólo como macros. 

por ejemplo: 

unsigned char mascara = 1<<7; y funciona de la misma manera. 
int AZUL; 
unsugned int;  el tipo de dato de la máscara debe ser del mismo tipo que de la variable sobre la que va a actuar. 
*/

#define AZUL 1<<7 // la ventaja de definirlo así es que se puede aplicar a una diversidad de tipos de datos
/*
al final de cuentas lo que estamos haciendo acá es definir a AZUL como una variable que toma cierto valor, 
cada color toma un valor diferente. 
*/
#define VERDE  1<<6
#define ROJO  1<<5
#define NARANJA  1<<4 
#define AMARILLO 1<<3 
#define PARDO  1<2
#define BLANCO  1<<1 
#define NEGRO  1<<0
  
void espectro(unsigned char colores){

    printf("color ingresado  = %u \n", colores);  
    /*
    si queremos apagar (quitar un bit) un color lo que hacemos es poner su complemento: 
    */
   colores &= ~(VERDE); //ponemos un filtro que quita el bit verde de colores. 

   //añadir un color sería:
    colores |= NEGRO; //añadir una fuente de luz adicional. 

    

    if(colores & AZUL){ //esta operación verifica si la más cara está incluida en colores, funciona como un polarizador, la máscara es polarizador. 

        printf("azul presente \n");
    }
    if(colores & VERDE){

        printf("verde presente \n");
    }
    printf("color analizado = %u \n", colores);         
}

int main(){
    espectro(AZUL | VERDE | PARDO | NEGRO ); //en esta parte estamos generando un número que está compuesto por diferentes máscaras. combinación de dif fuentes de luz.
    return 0; 
}