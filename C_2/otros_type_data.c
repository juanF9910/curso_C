/* en este código se exploran otros tipos de datos como union, enum, typedef */
#include <stdio.h>


union mi_union_t{ // todos los campos que están en una unión tienen la misma dirección de memoria, es decir, todos los campos
                 // tienen el mismo puntero.  
    int entero; 
    float flotante; 

} r;   

enum meses{
    lunes=1, martes, 
    miercoles, jueves, 
    sabado, domingo}k; //se usa para asignar una identificación a un valor, por ejemplo 1=lunes, 2=martes y así. con NÚMEROS ENTEROS.    

struct Empleado{ // en una estructura cada campo tiene su posición de memoria independiente. 
    int entero; 
    float flotante; 
};

typedef struct Empleado empleado; //el comando typedef se usa para darle pseudónimos a los tipos de datos

typedef struct cuenta{  //cuando se usa el comando typedef con la estructura ent el tipo de dato de la estructura será lo que está después de la llave
// es decir, en vez de usar struct cuenta nombre para definir una estructura. usamos c nombre. 
    char nombre[30]; 
    char apellido[40]; 
    int identificador; 
    int saldo; 
} c; 

int main(){

    k=lunes; //lo que nos va a guardar k es el número asociado a lunes,  no el string.
    printf("%i \n", k);
    empleado u; 
    u.entero=1233; 
    u.flotante=23.34; 

    r.flotante= 2324.337; 
    r.entero=12334; 

    //printf("%d\n", r.entero);
    printf("%f\n", r.flotante);

    printf("****************************\n");

    printf("%d\n", u.entero); //la notación con e(científica) y g(inteligente) sólo es para números flotantes. 
    printf("%g \n", u.flotante); 

    return 0; 
}