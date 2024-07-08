/*dado un vector con número vamos a determinar si son positivos o negativos, pares o impares y su raiz cuadrada, si es negativo que diga raiz imaginaria*/
#include <stdio.h>
#include <string.h>
#include <math.h>

const char*par_impar(int num);
const char*pos_neg(int num); 
void raiz(int num);


int main(){
    int num; 
    puts("ingrese un número"); 
    scanf("%i", &num); 
    fprintf("el número %i es %s,  %s y su raiz es %f", num,  par_impar(num), pos_neg(num) );

    raiz(34);
    return 0; 
}


const char *par_impar(int num){

    if((num%2)==0){ //el operador % sólo funciona 
        return("par");
    }else{
        return("impar");
    }
}

const char *pos_neg(int num){
    if(num<0){
        return "negativo";
    }else{
        return "positivo";
    }
}

void raiz(int num){

    if(strcmp(pos_neg(num),"negativo")==0){
        printf("imaginario");
    }else{
        printf("%.2f", (float) sqrt(num));
    }
}

