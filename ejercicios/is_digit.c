#include <stdio.h>
#include <ctype.h>

int con_carac(float *v, int size){

    int cont=0;

    for(int i=0; i<size; i++){

        if(!(isdigit(v[i]))){
            cont++;
        }
    }
    return cont; 
}

int main(){
    //float v[]={1, 2, 3, 4, 5, 6, 'a'};
    
    //printf("%i", con_carac(v, 7));

    /*vamos a determinar si en un vestor hay caracteres y cuántos*/

    printf("%i \n", isdigit('a'));
    return 0; 
}