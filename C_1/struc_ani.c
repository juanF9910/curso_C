#include <stdio.h>
#define SIZE 1

struct owner{
    char nombre[20]; 
    char direccion[30];

};

struct dog{ 

    char nombre[20];
    int edadMeses;
    struct owner ownerdog; 

} dogs[SIZE];


int main(){

/*
con el siguiente for pedimos la información
*/
    for (int i=0; i<SIZE; i++){

        printf("ingrese el nombre del perro %i \n", i+1 ); 
        scanf("%s", dogs[i].nombre);

        printf("ingrese la edad del perro %i \n", i+1 ); 
        scanf("%i", &dogs[i].edadMeses);

        printf("ingrese el nombre del dueño del perro %i \n", i+1 ); 
        scanf("%s", dogs[i].ownerdog.nombre);

        printf("ingrese la dirección del dueño del perro %i \n", i+1 ); 
        scanf("%s", dogs[i].ownerdog.direccion);
    }

    for(int i=0; i<SIZE; i++){

        printf("el nombre del perro %i es:  %s\n", i+1, dogs[i].nombre);
        printf("la edad del perro %i es:  %i \n", i+1, dogs[i].edadMeses);
        printf("el nombre del dueño del perro %i es:  %s \n", i+1, dogs[i].ownerdog.nombre);
        printf("la direc del dueño del perro %i es:  %s \n", i+1, dogs[i].ownerdog.direccion);
    }


    return 0; 
}