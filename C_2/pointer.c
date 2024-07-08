#include  <stdio.h>

#define size 4 //para poner tamaño es mejor usar un macros. 

int main(){
   int array[size]={0}; 
    int *p=array;
    for(int c=0; c<size; c++){

        printf("%d \n", *p);
        p++;
    }

    return 0; 
}