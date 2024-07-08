#include <stdio.h>
#include <stdbool.h>

int main(){

    /*
    dado un archivo .txt vamos a determinar cuántas filas y columnas tiene.
    */

    FILE *f=fopen("data.txt", "r"); 

    if(!f){
        perror("el archivo no se pudo escribir corretamente");
    }

    int nl=0, nc=0, leido=0;
    bool prim_fila=true;     /*
    vamos a imprimir el archivo ahora sóloocn 
    */

    printf("\n el número de columnas del archivo es: %d \n", nc); 
    //printf("\n el número de filas del archivo es: %d \n", nl); 

    return 0; 

    while((leido=fgetc(f))!= EOF && prim_fila==true){

        if(leido==' ' || leido=='\n'){  
            nc++;
            if(leido=='\n'){
                prim_fila=false;
            }
        }
    }
    
    rewind(f);// es muy importante usar el rebobinador, que sólo se puede usar con archivos. 

    /*
    vamos a usar ahora el comando fgets
    */

    char buffer[40]; 
    while(fgets(buffer, sizeof(buffer), f) != NULL){
        printf("%s", buffer); 
        nl++;

    }
    printf("\n el número de columnas del archivo es: %d \n", nc); 
    printf("el número de filas del archivo es: %d \n", nl); 

    return 0; 
}