#include <stdio.h>


int main(int argc, char *argv[]){

      /*
    el \n lo que hace es volcar el buffer, se conoce como line buffer. 
    */
    //fflush(stdout); // esta función vacía el buffer tal y cómo esté. en el punto que lo ponga
    int SIZE=100; 
    char buffer[SIZE]; 
    setvbuf(stdout, buffer, _IOFBF, SIZE); /*
    esta función vuelva el buffer en stdout cada que llegue a los 2000 byes. 
    _IOFBF: FILE BUFFER VUELQUESE CUANDO SE LLENE HASTA EL TAMAÑO SIZE
    _IOLBF: VUELQUESE CUANDO HAYA UN SALTO DE LÍNEA (MODO POR DEFAULT)
    _IONBF: QUE NO HAYA BUFFER. 
    */
   printf("hola mundo\n cómo estás");
   /* setbuf(stdout, NULL);  
   este comando quiere decir que no quiero tener buffer
   */

    while(1){
 
    }
    return 0; 
}