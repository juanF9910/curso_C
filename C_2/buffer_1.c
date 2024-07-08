#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    // Abrir el archivo en modo texto para escritura
    FILE *f = fopen("array.txt", "w");
    if (f == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }
    
    // Escribir el array en el archivo
    for (size_t i = 0; i < array_size; i++) {
        fprintf(f, "%d\n", array[i]);
    }

    // Usar fflush para volcar el buffer
    if (fflush(f) != 0) {
        perror("Error al volcar el buffer");
        fclose(f);
        return EXIT_FAILURE;
    }

    // Cerrar el archivo
    fclose(f);
    printf("Datos escritos correctamente en array.txt y buffer volcado\n");

    return 0;
}