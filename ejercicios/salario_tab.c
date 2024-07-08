/*
dada una tabla con los nombres de los trabajadores, las horas trabajadas y
ek valor de la hora, generar una tabla con el nombre de la persona y el salario */

#include <stdio.h>

int main(){

/*primero leemos el archivo con los datos*/

    FILE *f=fopen("trabajo.txt", "r");

    /*verificamos si el archuivo se abrió de forma adecuada*/

    if(!f){
        perror("error al abrir el archivo");
    }

    /* para leer datos con formato de un archivo usamos el comando fscanf.
    El salario de cada empleado lo podemos calcular en vuelo, es decir, sin 
    necesidad de guardar los valores en vectores, depositándolos de forma 
    automática en otro archivo. 
     */
    FILE *f1=fopen("salarios.txt", "w");
    char nombre[40]; 
    int horas=0; 
    float valor=0; 
    /*
    como nuestra tabla tiene encabezado vamos mover el puntero hasta la segunda fila que es donde están los datos de interes
    */

   char buffer[50]; 
   fgets(buffer, sizeof(buffer), f); //movimos el puntero asociado a f hasta la segunda línea, pues fgets lee hasta que se encuentra un salto de línea. 
    fputs("nombre\tsalario\n", f1);
    while(fscanf(f, "%s %i %f", nombre, &horas, &valor)==3){
        /*
        para imprimir en un archivo datos con formato usamos el comando fprintf
        */

       fprintf(f1, "%s %f \n", nombre, horas*valor);
    }

    fclose(f); 
    fclose(f1);

    return 0; 
}