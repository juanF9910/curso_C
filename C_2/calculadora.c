#include "calculadora.h"

int restar(int a, int b){

    return a-b; 
}

int dividir(int a, int b, int *res){

    if(b==0){
        return 0; 
    }else{
        *res=a/b;
        return 1; 
    }

}   

int sumar( int a, int b){
    return a+b; 
}

int multiplicar(int a,int b){

    return a*b;
}



