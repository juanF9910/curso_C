#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Queremos determinar el promedio de edades de los estudiantes de cada curso */
#pragma pack(push, 1)
// Definimos una estructura para el encabezado del archivo

// Variables globales
struct Header {
    int16_t magic_string;  // Cadena mágica de 16 bits
    int32_t student_count;
    int32_t course_count;   // Cantidad de cursos (32 bits, little endian)
    int32_t enrollment_count; // Cantidad de matrículas (32 bits, little endian)
} header;

struct Estudiantes { 
   uint32_t std_id; // 32 bits enteros para la identificación del estudiante
   unsigned char banderas; // 8 bits para el género y el nivel educativo
   char nombre[23]; // Nombre con 23 bytes, 22 del nombre más 1 de caracter nulo. 
   uint32_t edad; // La edad como un entero de 32 bits en formato little endian.
}; 

struct Cursos{
    uint32_t crs_id; 
    char crs_name[32]; //32 bytes para el nombre del curso
    uint32_t hrs_cred; 
};

struct Matricula{
    uint32_t std_id; 
    uint32_t crs_id;
    uint32_t year; 
    uint32_t semester; 
}; 

#pragma pack(pop)

void promedio_curso(char *archivo); // Prototipo de la función
int is_little_endian(); // Función que determina si el sistema es little endian
uint32_t to_little_endian(uint32_t value); // Función para convertir un entero de 32 bits a little endian

int main(int argc, char *argv[]){

    if (argc != 2) {
        printf("Uso: %s <archivo>\n", argv[0]); // el a.out se cuenta como argumento también
        return 1;
    }
    
    char *archivo = argv[1];
    promedio_curso(archivo); 

    return 0; 
}

void promedio_curso(char *archivo){

    FILE *f = fopen(archivo, "rb"); // Abrimos el archivo

    if (!f) {
        perror("No se pudo abrir el archivo correctamente"); 
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

    int32_t size = header.student_count;  // Número de estudiantes
    int32_t SIZE = header.course_count; // Número de cursos
    int32_t SIZE2 = header.enrollment_count; // Número de matrículas

    struct Estudiantes *estudiante = (struct Estudiantes *)calloc(size, sizeof(struct Estudiantes));
    struct Cursos *curso = (struct Cursos *)calloc(SIZE, sizeof(struct Cursos));
    struct Matricula *matricula = (struct Matricula *)calloc(SIZE2, sizeof(struct Matricula));
    
    for (int i = 0; i < size; i++) { // Recorremos sobre todos los estudiantes
        if (fread(&estudiante[i], sizeof(struct Estudiantes), 1, f) != 1) { // Leemos las estructuras de los estudiantes y las guardamos en el vector
            perror("Error al leer estudiantes");
            fclose(f);
            return;
        }

        // Verificar y convertir los datos del estudiante a little endian si es necesario
        if (!is_little_endian()) {
            estudiante[i].std_id = to_little_endian(estudiante[i].std_id);
            estudiante[i].edad = to_little_endian(estudiante[i].edad);
        }
    }

    for (int i = 0; i < SIZE; i++) { // Recorremos sobre todos los cursos
        if (fread(&curso[i], sizeof(struct Cursos), 1, f) != 1) { // Leemos las estructuras de los cursos y las guardamos en el vector
            perror("Error al leer los cursos");
            fclose(f);
            return;
        }

        // Verificar y convertir los datos del curso a little endian si es necesario
        if (!is_little_endian()) {
            curso[i].crs_id = to_little_endian(curso[i].crs_id);
            curso[i].hrs_cred = to_little_endian(curso[i].hrs_cred);
        }
    }

    for (int j = 0; j < SIZE2; j++) { // Recorremos sobre todas las matrículas
        if (fread(&matricula[j], sizeof(struct Matricula), 1, f) != 1) {
            perror("Error al leer las matriculas");
            fclose(f);
            return;
        }

        // Verificar y convertir los datos de la matrícula a little endian si es necesario
        if (!is_little_endian()) {
            matricula[j].std_id = to_little_endian(matricula[j].std_id);
            matricula[j].crs_id = to_little_endian(matricula[j].crs_id);
            matricula[j].year = to_little_endian(matricula[j].year);
            matricula[j].semester = to_little_endian(matricula[j].semester);
        }
    }
    fclose(f);
    
    printf("%-32s %-32s\n", "Course Name", "Average Age");

    for(int i = 0; i < SIZE; i++) { // Recorremos cada curso
        int32_t suma_edades = 0; // Inicializamos la suma de edades en 0 para cada materia
        int32_t contador = 0;  // Inicializamos el contador en 0

        for (int j = 0; j < SIZE2; j++) {
            if (curso[i].crs_id == matricula[j].crs_id) { // Si el código del curso coincide con una matrícula entonces hay un estudiante matriculado
                for (int k = 0; k < size; k++) {
                    if (estudiante[k].std_id == matricula[j].std_id) {
                        suma_edades += estudiante[k].edad;
                        contador++; 
                    }
                }
            }
        }
        printf("%-32s %-32.2f \n", curso[i].crs_name, (float)suma_edades / contador);
    }

    free(estudiante);
    free(matricula);
    free(curso);
}

int is_little_endian() { // Función para determinar si el sistema es little endian
    uint16_t num = 1; // Creamos un número de 16 bits con el valor 1 
    return (*(uint8_t*)&num == 1); // Devolvemos 1 si el primer byte del número es 1 (little endian)
}

uint32_t to_little_endian(uint32_t value) { //función que convierte un número entero de 32 bits a little endian
    if (is_little_endian()) { // Si el sistema es little endian no hacemos nada
        return value; 
    }
    return ((value >> 24) & 0x000000FF) | // Si no es little endian, hacemos un shift de 24 bits y aplicamos una máscara de 0xFF
           ((value >> 8) & 0x0000FF00) | // Hacemos un shift de 8 bits y aplicamos una máscara de 0xFF00
           ((value << 8) & 0x00FF0000) | // Hacemos un shift de 8 bits y aplicamos una máscara de 0xFF0000
           ((value << 24) & 0xFF000000); // Hacemos un shift de 24 bits y aplicamos una máscara de 0xFF000000
}
