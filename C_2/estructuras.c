#include <stdio.h>
#include <string.h>

/*
siempre al final de una cadena de caracteres o string hay
un 0
*/


typedef struct cuenta{  //cuando se usa el comando type def con la estructura ent el tipo de dato de la estructura será lo que está después de la llave
    char nombre[30]; 
    char apellido[40]; 
    int identificador; 
    int saldo; 
} c; 

/*struct cuenta{  en este caso como no se pode typedef lo que está después de la llave es un estructura de este tipo que se llama c1
    char nombre[30]; 
    char apellido[40]; 
    int identificador; 
    int saldo; 
} c1; */

void imprimir_datos( struct cuenta* c ){
    printf("el cliente %s %s tiene %d en la cuenta\n", c->nombre, c->apellido, c->saldo); // también se puede desreferenciar con (*c)
}

void imprimir_dat(int* c){
    printf("el cliente tiene %d + %d en la cuenta\n", c[0], c[1]); 
}

void imprimir(int* c){
    printf("el cliente tiene %d en la cuenta\n", c[0]); 
}

void imp(char* c){
    printf("%s", c); 
}

int main(){
    c c1; 
    int prueb[]={1,2}; 
    char r[]="juan felipe";
    int A=40; 
    c1.identificador=1235; 
    c1.saldo=400; 
    strncpy(c1.nombre , "juan felipe", strlen("juan felipe")+1); /* para poder ingresar cadenas en una estructura necesitamos 
    usar el comando strncpy() si especificamos además el tamaño(número de caracteres), el 1 es para que incluya el cero al final*/
    strcpy(c1.apellido, "zapata arenas");  //si no especificamos el tamaño entonces usamos strcpy()

    //también se puede llenar la parte numérica de una estructura así: 

    c h={ .identificador=1235, .saldo=5};

    strcpy(h.nombre, "juan sebastian");  

    imprimir_datos(&c1); //cuando es un puntero a estructura se debe pasar con el &
    imprimir_dat(prueb); //cuando es un puntero a array (de números o caracteres) se pasa sólo el nombre del array.
    imprimir(&A);  // los números también se pasan con &
    imp(r); //como es un array tipo char lo pasamos sólo con el nombre. 

    return 0; 
}