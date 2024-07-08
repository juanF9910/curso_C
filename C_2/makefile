#receta para compilar un archivo y crear librerías

contable: contable.o calculadora.a
	gcc -o contable contable.o calculadora.a

calculadora.a: calculadora.o
	ar rcs calculadora.a calculadora.o 

calculadora.o: calculadora.c
	gcc -c calculadora.c -o calculadora.o 

contable.o: contable.c
	gcc -c contable.c -o contable.o

#el makefike se ejecutaría con el comando (make contable)

## si hay varios archivos Makefile se usa el comando:
## make -f Makefile1 contable 