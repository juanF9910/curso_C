#include <stdio.h>

//este código deterina si un número es par o impar usando 
//punteros. 

int main(int argc, char *argv[]){

    int num, *dir_num;

    printf("numero");
    scanf("%d", &num);

    dir_num=&num; 

    if( *dir_num % 2 ==0){

        printf("par, dir: %p", dir_num);
    }
    else{

        printf("impar, dir: %p", dir_num);
    }


    return 0; 
}