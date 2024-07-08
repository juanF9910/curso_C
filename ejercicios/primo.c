/*
vamos a determinar si un número es primo o no 
*/


#include <stdio.h>
#include <stdbool.h>

/*
prototipo de la función
*/

void primo(int a){

    int cont=0;
    //un número es primo si no tiene más dividores que el 1 y él mismo    

    for(int i=2; i<a; i++){

        if(a%i==0){
            cont++;
            break; //basta con que haya uno más, no es necesario seguir evaluando. 
        }
    }

    if(cont==0){
        puts("primo");
    }else{
        puts("no primo");
    }
}

int main(){

    int num; 
    puts("ingrese el número que desea saber si es primo o no, ingrese cero para salir del programa"); 

    while(num!=0){
        scanf("%i", &num); 
        if(num!=0){
            primo(num); 
        }
        
    }
    return 0; 
}