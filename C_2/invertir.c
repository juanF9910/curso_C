#include <stdio.h>


/*vamos a crear un programa para invertir una cadena*/

void invertir(char *cadena); //función con parámetro por referencia. 


int main(){
    puts("ingrese la cadena que quiere invertir: "); 
    char cadena[30]; 
    fgets(cadena, sizeof(cadena), stdin); 
    invertir(cadena); 
    printf("%s", cadena); 

    return 0; 
}


void invertir(char *cadena){ //pasamos la cadena por referencia, 
/*por este motivo no necesitamos devolverla de nuevo*/

    char *ptr=cadena; //dos punteros a la misma cadena. 
    char *ptr1=cadena; 
    char c; 

    while((*ptr1) !='\0'){
        ptr1++; 
    }

    ptr1--; //nos movemos una casilla antes del final del string. 

    while(ptr1 > ptr){// modificamos la misma cadena desde ambos extremos hasta llegar al centro. 
        c=*ptr; 
        *ptr=*ptr1; 
        *ptr1=c; 

        ptr++; 
        ptr1--; 
    }


}