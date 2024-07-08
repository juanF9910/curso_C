#include <stdio.h>

int main(){

    int valores[]={5, 14, 9, 6, 11, 19, 17, 18, 9, 8};

    for(int i=0; i<(sizeof(valores)/sizeof(int)); i++){
                
        if(valores[i] % 2 ==0){
            //break; 
             continue; 
            /* el comando continue lo que hace es saltarse todo lo que hay desde
            que se llamó hasta el final del corchete del ciclo (for, while
            , do while, sw itch)
            en el que se está usando cuando se cumpla la condición.
            En este caso va hasta el final del for y evalúa el siguiente i. 

            El comando break funciona como el continue, la diferencia es que
            termina la ejecución del ciclo, no evalúa más i-es.
             */
        }

        /*
        los continue seguidos lo que hacen es filtrar, es equi
        valente a poner las condiciones con &&. 

        estos dos continue juntos serían los números impares
        y que son múltiplos de tres. Dentro del if sólo se ejecuta lo que es 
        verdadero
        */ 

        if(valores[i] % 3 != 0 ){ //si no es múltiplo de tres no haga el if
            continue;
        }
            
        printf("valor[%i]= %i\n", i, valores[i]);
    }

    
    return 0; 
}