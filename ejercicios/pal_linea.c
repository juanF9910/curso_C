/*Escriba un program a que imprima a su entrada una palabra por
línea.*/

#include <stdio.h>

int main(){

    char c; 
    while((c=getchar())!='\n'){

        if(c!=' '){
            putchar(c);
        }else{
            putchar('\n');
        }
    }
    return 0; 
}