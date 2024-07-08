#include <stdio.h>

int leer_numero(char *txt){
    int n; 
    printf("%s  \n", txt); 
    scanf("%d", &n); 
    return n; 
}

int main(){

    printf("vamos a sumar\n"); 
    int a=leer_numero("introduce el número a"); 
    int b=leer_numero("introduce el número b"); 
    int res=a-b;
    printf("el resultado es %i: ", res);  

    return 0; 
}