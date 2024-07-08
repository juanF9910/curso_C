#include <stdio.h> // los símbolos <> significan que el archivo está
//incluido en la librería estándar de C 
#include <stdlib.h>  //esta librería nos va a permitir trabajar de forma dinámica con la memoria. 

int main(){
 
    int size;
    printf("cuántos  elementos quiere almacenar"); 
    scanf("%d", &size);

    float *valores= (float *)malloc(size*sizeof(float)); /* malloc(tamaño en bytes) reserva el espacio de memoria en bytes y entrega un array con capacidad del tamaño especificado. 
    la función sizeof() entrega el tamaño en bytes del objeto que se le ingrese.  

    la función malloc() entrega un puntero vacío, es decir, puede ser un puntero de cualquier tipo de dato, por esta razón debemos especificar a qué tipo de dato
    apunta el puntero. eso lo hacemos con (float *) o también (int *) o (char *)

    malloc significa memeory allocation, es decir, asignación de memoria. 
    */ 

   float *valores1=calloc(4, sizeof(float)); 
   
    if(valores==NULL){ //si no se asignó bien la memoria en valores se guarda el valor NULL. 
        printf("hay un error, no hay tanta memoria");
        return 1; //esto significa que algo no fue bien con el códigos y termina de ejecutar el programa. 
    }
    
    //ya que tenemos reservado el espacio vamos a llenarlo. s
    for(int i=0; i<size; i++){
        valores[i]=1;
    }

    for(int i=0; i<size; i++){
        printf("%.f\n", valores[i]);
    }

    free(valores); /* todas las variables que sean asignadas con malloc no se borran por si solas al terminar de ejecutar el código, es por esto que hay que 
    eliminar las variables antes de que termine el código y así no ensuciar la memoria.
    Después de usar free no se puede volver a usar la palabra valores de nuevo
    */

    return 0; 
}