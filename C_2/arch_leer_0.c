#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *f=fopen("binario.txt", "rb");/*  fopen devuelve un puntero de tipo archivo llamado descriptor. el puntero se puede igualar como si fuera array. 

    r leer, r+ leer y escribir, w escribir (si no existe el archivo lo crea)
    , w+ escribir y leer (si no existe el archivo lo crea), a para añadir 
    información al final del archivo (si no existe lo crea), a+ para añadir 
    información al final del archivo, también para leer (si no existe lo crea)
    */

   if(!f){
    perror("no se pudo abrir el archivo"); 
    return 1; 
   }
   
    char lei; 

    //fseek(f, 20, SEEK_SET);  //SEEK_SET, SEEK_END, SEEK_CUR
    /*
    lo que hace este comando es tomar el texto al que apunta f, 
    ubicarse en el principio y moverse 20 bytes a la derehca del principio.

    fseek(f, 0, SEEK_SET) = rewind(f); 
    */

   /*
   lo anterior es muy útil para conocer el tamaño de un archivo: 
   */

  fseek(f, 0, SEEK_END);
  long SIZE= ftell(f);
  rewind(f);
  printf("el tamaño son %li Bytes \n", SIZE); 
  char buffer[30]; //lo podemos leer también con fgetc 

    while( (fgets(buffer,sizeof(buffer), f )) != NULL ){ /*
    fgetc lo que hace es leer caracter a caracter. 
    */

    //long pos =ftell(f); 
    /*
    la función ftell te dice en qué parte del
    archivo está el puntero. devuelve el número 
    de bytes desde el inicio hasta la posición
    */
    //printf("%li, %c \n", pos, lei);
    
    printf("%s",buffer); 
  }

    fclose(f); 

    return 0; 
}