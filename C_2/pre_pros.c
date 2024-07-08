#include <stdio.h> /*
lo que hace es buscar el archivo en la dirección dada
cuando en vez de <> de usa "" estos se llaman archivos de cabecera y se buscan en la misma carpeta en la que está el archivo.h 
*/

#include <stdlib.h>
#define LIMITE 100//donde vea LIMITE ponga 100 
#define X Y  /* donde vea X ponga Y 
  
define sustituye texto y números. typedef reemplaza tipos de datos 
*/

#undef X //esto lo que hace es quitarle el valor de Y a X 
 
/*
en el preprocesador también podemos definir funciones que son 
mucho más rápidas (macros).
*/

#define AREA_RECTANGULO(x, y) x*y 
#define PREMIUM //undefine sin especificar por lo que se quiere sustituir. 

/*
#error corta el preprocesador, deja de compilar en ese punto. 
*/

/*
el preprocesador también tiene condicionales, estos condicionesles
solo afectan al código que le entra al compilador, es decir, que
cumplan con las condiciones de compilación impuestas. sólo se compila el código que cumple las 
condiciones de compilación. 
*/

int main(){
 
#if LIMITE > 50
    printf("el límite es mayor que 50 \n");
#elif LIMITE <=50
    printf("el límite es menos que 50 \n");
#endif 

#ifdef PREMIUM
    printf("versión premium"); 
#endif

#ifndef PREMIUM
    printf("versión gratuita"); 
#endif
    return 0; 
}