#include <stdio.h>

int main() {
    char buffer[20];
    int num = 42;

    // Usando snprintf para formatear una cadena
    int written_chars = snprintf(buffer, sizeof(buffer), "El número es: %d", num);

    // Verificando si la cadena se truncó
    if (written_chars >= sizeof(buffer)) {
        printf("La cadena se truncó.\n");
    }

    // Imprimiendo el resultado
    printf("Buffer: %s\n", buffer);

    return 0;
}