#include <stdio.h>

/*
La función fwrite se utiliza para escribir datos  en a un archivo binario, acá vamos a pasar una estructura a un archivo binario
*/

struct medicion{
    int anio,  mes, dia, uv; 
    float temperatura, viento;  

} medida={ .anio=2020, .mes=11, .dia=9,
   .uv=4,  .temperatura=12.5, .viento=15.0 }; /*
   la estructura se debe llenar en orden, esta es otra forma de definirla. 
   */


int main(){ 


    FILE *f= fopen( "bin_struct.bn", "wb"); 

    if (!f) {
        perror("Error al abrir el archivo"); 
        return 1; 
    }

    int veces = fwrite(&medida, sizeof(medida),1,f ); 

    if(veces !=1){
        perror("error al escribir archivo"); 
        fclose(f);
        return 1; 

    }

    fclose(f); 
    /*
    esta función devuelve el número de veces que ha copiado la estructura 
    en el archivo binario. los parámetros son un puntero a la estructura, el tamaño de la estructura, el num de veces que se copia y en donde lovoy a copiar. 
    */
    printf("Datos escritos correctamente en bin_struct.bn\n");


    return 0; 
}