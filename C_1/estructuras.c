#include <stdio.h>

#define SIZE 2

/*
un arreglo tal que en cada componente se tiene una estructura
*/
struct perro{
    char nombre[30]; 
    int edadMeses; 
    float peso;       
} perro1={"luna", 4, 2.5}, perros[3];

/*perros[3] es un arreglo con 3 componentes y 
 cada componente es una estructura. 
*/

/*
una estructura anidada es una estructura 
que en sus componentes tiene otras estructuras 
*/

int main(){
    /*
    en esta parte del código lo que hacemos es llenar las componentes del
    vector y a la misma vez las componenetes de cada una de las estructuras
    */
    for(int i=0; i<SIZE; i++){
        printf("ingrese el nombre del perro %i ", i+1); 
        scanf("%s", perros[i].nombre); 
        printf("ingrese la edad \n"); 
        scanf("%i", &perros[i].edadMeses);
        printf("ingrese el peso\n"); 
        scanf("%f", &perros[i].peso); 
    }
    /*
    vamos a mmostrar la información contenida en las estructuras
    */
   for(int i=0; i<SIZE; i++){
    printf("el nombre del perro %i es %s \n", i+1, perros[i].nombre);
    printf("la edad del perro %i es %i", i+1, perros[i].edadMeses);
    printf("el nombre del perro %i es %f", i+1, perros[i].peso);
   }

    return 0; 
}