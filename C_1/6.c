#include  <stdio.h>

/*
vamos a definir una matriz, break y continue
*/

int main(){

    int M[2][3]={{1, 2},{3,4}}; /*
    las matrices tambien inician a contar desde 0
    */ 
   int num=0; 

   while(num<=5){

      num++;

        if(num==3){
            break; //termine con el while y sigue con el código debajo del while
            //continue; // no hace nada y vuelve a dar la vuelta, empezando desde el inicio del while
        }
        else{
            printf("%i ", num);
        }

        printf("pasé por acá \n");
        
   }

   printf("terminado \n");

    return 0; 
}