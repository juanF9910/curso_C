/*
determinar si un número es primo o no usando punteros 
e indicar la dirección de memoria
*/

#include <stdio.h>

int main(){

    int num, *ptr_num; 
    printf("ingrese el número \n");
    scanf("%i", &num); 
    ptr_num=&num; 

    int cont=0; 

    for(int i=2; i<num; i++){

        if(num%i==0){
            cont++;
            printf("el número no es primo, dir %p", ptr_num);
            break;
        }
    } 

    if(cont==0){
        printf("el número es primo, dir %p", ptr_num);
    }

    return 0; 
}