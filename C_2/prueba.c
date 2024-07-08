#include <stdio.h>
#include <stdint.h>

int main() {
    // Definición de una variable de 32 bits
    int32_t numero32bits;

    // Asignación de un valor
    numero32bits = 123456789;

    // Mostrar el valor
    printf("Valor de numero32bits: %d\n", numero32bits);

    // Tamaño de la variable en bytes
    printf("Tamaño de numero32bits: %zu bytes\n", sizeof(numero32bits));

    return 0;
}