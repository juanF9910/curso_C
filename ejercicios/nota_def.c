/*
queremos calcular la nota final de un curso teniedo en cuenta ciertos porcentajes.
*/
#include <stdio.h>

int main(){

    /*vamos a leer el archivo con las notas*/

    FILE *f=fopen("notas.txt", "r"); 

    /*vamos a generar otro archivo en donde vamos a poner el nombre del alumno y la nota definitiva*/

    FILE *f1=fopen("nota_def.txt", "w"); 

    if(!f || !f1){
        perror("error en alguno de los archivos");
    }

    /*para leer archivos con formato usamos fscanf y para imprimir en archivos con formato usamos fprintf*/
    float par1, par2, par3, ef, tf, def; 
    char nombre[30];  

    /*recorremos la primera fila del archivo para evitar leer los encabezados y que hayan problemas*/
    char buffer[100]; 
    fgets(buffer, sizeof(buffer), f); //corremos el puntero hasta la primera fila. 
    fputs("nombre\tdefinitiva\n", f1);

    while( fscanf(f, "%s %f %f %f %f %f", nombre, &par1, &par2, &par3, &ef, &tf)==6){

        def=0.55*(par1+par2+par3)/3+ 0.3*ef+0.15*tf;
        fprintf(f1, "%s\t%6.2f\n", nombre, def); 
    }

    fclose(f1); 
    fclose(f);

    return 0; 
}