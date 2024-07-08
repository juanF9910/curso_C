#include <stdio.h>

void imprimir(char *v){ //siempre que se quiera pasar un array o una estructura es mejor hacerlo con punteros. 
/*
si se pasa un número ya depende de si lo queremos pasar por valor o por referencia. 
*/

    printf("%s \n", v); 
}

int main(){

   imprimir("juan felipe zapata");

    /*
    vamos a definir un puntero a una función sencilla
    */

   void (*p)(char *v)=imprimir; //es muy importante tener los paréntesis. 
   p("juan felipe zapata"); 


    return 0; 
}