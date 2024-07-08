#include <stdio.h>

/*
el comando goto funciona basado en etiquetas. 

cuando ejecuto el comando en el código inmediadamente se para todo y 
transicionamos al código que está en la etiqueta


con el goto puedo saltar adelante o hacia atrás en el código. 
*/
int main(){

    int j=0; 

    while(j < 500){

        for(int i=0; i<10; i++){
            j+=i; 

            if(j>300){
                goto zona_interesante; 
            }
            
        }
        printf("%i\n",j);

    } 
    printf("hemos alcanzado el valor final");
     

zona_interesante:
    printf("estamos en la zona interesante");

    return 0; 
}