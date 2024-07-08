#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MASK1 1<<7 // Máscara para el género, si coincide (1) es femenino, sino (0) es masculino
#define MASK2 1<<6 // Máscara para el nivel de estudios, si coincide (1) es posgrado, si no coincide (0) es pregrado

/* Queremos imprimir nombre, edad y género de los estudiantes, filtrando de acuerdo a edades */

#pragma pack(push, 1)
// Definimos una estructura para el encabezado del archivo
struct Header { // variables globales
    uint16_t magic_string;  // Cadena mágica de 16 bits
    uint32_t student_count; // Número de estudiantes (32 bits, little endian)
    uint32_t course_count;  // Cantidad de cursos (32 bits, little endian)
    uint32_t enrollment_count; // Cantidad de matrículas (32 bits, little endian)
} header;

/* Definimos la estructura de los otros datos */
struct Estudiantes { // variables globales
   uint32_t std_id; // 32 bits enteros para la identificación del estudiante
   unsigned char bandera; // 8 bits=byte contiene la información del género y del nivel educativo
   char nombre[23]; // Nombre con 23 bytes, 22 del nombre más 1 de caracter nulo. 
   uint32_t edad; // La edad como un entero de 32 bits en formato little endian.
}; 

#pragma pack(pop)

void filtrar(int min, int max, const char *archivo); // prototipo de la función
int is_little_endian(); //función que determina si 
uint32_t to_little_endian(uint32_t value);

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Uso: %s <min> <max> <archivo>\n", argv[0]);
        return 1;
    }

    char *archivo = argv[1];
    int32_t min = strtol(argv[2], NULL, 10); // convierte de string a long
    int32_t max = strtol(argv[3], NULL, 10);

    if (min < 0 || max < 0 || max <= min || min > 100 || max > 100) {
        printf("Error, verificar el rango de edad.\n");
        return 1;
    }

    filtrar(min, max, archivo);

    return 0;
}

void filtrar(int min, int max, const char *archivo) {
    FILE *f = fopen(archivo, "rb");
    if (!f) {
        perror("No se pudo abrir el archivo de forma correcta");
        return;
    }

    if (fread(&header, sizeof(struct Header), 1, f) != 1) {
        perror("Error al leer el encabezado del archivo");
        fclose(f);
        return;
    }

    // Verificar y convertir el encabezado a little endian si es necesario
    if (!is_little_endian()) {
        header.student_count = to_little_endian(header.student_count);
        header.course_count = to_little_endian(header.course_count);
        header.enrollment_count = to_little_endian(header.enrollment_count);
    }

    int32_t SIZE = header.student_count;
    struct Estudiantes *estudiante = (struct Estudiantes *)calloc(SIZE, sizeof(struct Estudiantes)); //construimos un vector de estructuras tipo estudiante

    if (!estudiante) {
        perror("No se creó el vector de estructuras de forma exitosa");
        fclose(f);
    }

    printf("%-23s %-5s %-10s\n", "Name", "Age", "Gender");

    for (int i = 0; i < SIZE; i++){ // llenamos el vector de las estructuras de estudiantes
        if (fread(&estudiante[i], sizeof(struct Estudiantes), 1, f) != 1) {
            perror("Error al leer datos de estudiante");
            fclose(f);
            break;
        }

        // Verificar y convertir los datos del estudiante a little endian si es necesario
        if (!is_little_endian()) {
            estudiante[i].std_id = to_little_endian(estudiante[i].std_id);
            estudiante[i].edad = to_little_endian(estudiante[i].edad);
        }

        int32_t EDAD = estudiante[i].edad;
        char genero[10]; // 10 es suficiente para "masculino" o "femenino"

        if (EDAD >= min && EDAD <= max) {
            if (estudiante[i].bandera & MASK1) {  // ponemos la máscara de 10000000
                strncpy(genero, "Female", sizeof(genero) - 1);
            } else {
                strncpy(genero, "Male", sizeof(genero) - 1);
            }
            genero[sizeof(genero) - 1] = '\0'; // Asegurar el carácter nulo al final

            printf("%-23s %-5i %-10s\n", estudiante[i].nombre, EDAD, genero);
        }
    }

    free(estudiante);
    fclose(f);
}

int is_little_endian() { //devuelve un 1 o un cero, si son little endian devuelve un 1. 
    uint16_t num = 1;
    return (*(uint8_t*)&num == 1);
}

uint32_t to_little_endian(uint32_t value) { //función convierte un número entero de 32 bits a 
    if (is_little_endian()) {
        return value;
    }
    return ((value >> 24) & 0x000000FF) |
           ((value >> 8) & 0x0000FF00) |
           ((value << 8) & 0x00FF0000) |
           ((value << 24) & 0xFF000000);
}
