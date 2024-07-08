#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*Queremos imprimir los semestres asociados a cada año y el número de estudiantes matriculados en cada semestre en pregrado, posgrado 
y de acuerdo a su género*/

#define MASK1 1<<7 // Máscara para el género, si coincide (1) es femenino, sino (0) es masculino
#define MASK2 1<<6 // Máscara para el nivel de estudios, si coincide (1) es posgrado, si no coincide (0) es pregrado

#pragma pack(push, 1)

// Definimos una estructura para el encabezado del archivo
struct Header {
    int16_t magic_string;  // Cadena mágica de 16 bits
    int32_t student_count;
    int32_t course_count;   // Cantidad de cursos (32 bits, little endian)
    int32_t enrollment_count; // Cantidad de matrículas (32 bits, little endian)
} header;

// Variables globales
struct Estudiantes { 
   uint32_t std_id; // 32 bits enteros para la identificación del estudiante
   unsigned char banderas; // 8 bits para el género y para el nivel educativo 
   char nombre[23]; // Nombre con 23 bytes, 22 del nombre más 1 de caracter nulo. 
   uint32_t edad; // La edad como un entero de 32 bits en formato little endian.
};

struct Cursos {
    uint32_t crs_id; 
    char crs_name[32]; // 32 bytes para el nombre del curso
    uint32_t hrs_cred; 
};

struct Matricula {
    uint32_t std_id; 
    uint32_t crs_id;
    uint32_t year; // Desde 2020 hasta 2029
    uint32_t semester; // 1, 2, 3, 4
};

//Vamos a definir una estructura que va a tener el formato de cada fila de la tabla que queremos imprimir
struct Datos {
    uint32_t year;
    uint32_t semester;
    unsigned int num_H_pre; 
    unsigned int num_M_pre;
    unsigned int num_H_pos; 
    unsigned int num_M_pos;
};

#pragma pack(pop)

void estadisticas(char *archivo); // Prototipo de la función
int is_little_endian(); // Función que determina si el sistema es little endian
uint32_t convert_to_little_endian(uint32_t value); // Función para convertir un entero de 32 bits a little endian

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Uso: %s <archivo>\n", argv[0]); // El a.out se cuenta como argumento también
        return 1;
    }

    char *archivo = argv[1];

    estadisticas(archivo);
    return 0; 
}

void estadisticas(char *archivo){
    
    FILE *f = fopen(archivo, "rb"); 

    if (!f) {
        perror("Error al abrir el archivo"); 
        return; 
    }

    if (fread(&header, sizeof(struct Header), 1, f) != 1) {
        perror("Error al leer el encabezado del archivo");
        fclose(f);
        return;
    }

    int32_t size = header.student_count;  // Número de estudiantes
    int32_t SIZE = header.course_count; // Número de cursos 
    int32_t SIZE2 = header.enrollment_count; // Número de matrículas

    struct Estudiantes *estudiante = malloc(size * sizeof(struct Estudiantes)); // Vector 
    struct Cursos *curso = malloc(SIZE * sizeof(struct Cursos));
    struct Matricula *matricula = malloc(SIZE2 * sizeof(struct Matricula));
 
    if (!estudiante || !curso || !matricula) {
        perror("Error al asignar memoria");
        fclose(f);
        return;
    }

    for(int i = 0; i < size; i++) { // Recorremos sobre todos los estudiantes
        if(fread(&estudiante[i], sizeof(struct Estudiantes), 1, f) != 1) { // Leemos las estructuras de los estudiantes y las guardamos en el vector
            perror("Error al leer estudiantes");
            fclose(f);
            return;
        }

        if (!is_little_endian) {
            estudiante[i].std_id = convert_to_little_endian(estudiante[i].std_id);
            estudiante[i].edad = convert_to_little_endian(estudiante[i].edad);
            // Asegúrate de que otros campos que necesiten conversión se conviertan aquí
        }
    }

    for(int i = 0; i < SIZE; i++) { // Recorremos sobre todos los cursos
        if(fread(&curso[i], sizeof(struct Cursos), 1, f) != 1) { // Leemos las estructuras de los cursos y las guardamos en el vector
            perror("Error al leer los cursos");
            fclose(f);
            return;
        }

        if (!is_little_endian) {
            curso[i].crs_id = convert_to_little_endian(curso[i].crs_id);
            curso[i].hrs_cred = convert_to_little_endian(curso[i].hrs_cred);
            // Otros campos de cursos
        }
    }

    for(int j = 0; j < SIZE2; j++) { // Recorremos sobre las matrículas
        if(fread(&matricula[j], sizeof(struct Matricula), 1, f) != 1) {
            perror("Error al leer las matrículas");
            fclose(f);
            return;
        }

        if (!is_little_endian) {
            matricula[j].std_id = convert_to_little_endian(matricula[j].std_id);
            matricula[j].crs_id = convert_to_little_endian(matricula[j].crs_id);
            matricula[j].year = convert_to_little_endian(matricula[j].year);
            matricula[j].semester = convert_to_little_endian(matricula[j].semester);
        }
    }

    fclose(f); // Ya no necesitamos el archivo



    // Inicializamos el vector de estructuras del tipo datos, cada estructura es una fila de la tabla que queremos imprimir
    struct Datos datos[40] = {0}; // Tenemos 10 años (2020-2029)con 4 trimestres cada uno

    for (int i = 0; i < 40; i++) {
        datos[i].year = 2020 + i / 4; // i/4 entrega un valor entero por el tipo de variable que es datos[i].year
        datos[i].semester = (i % 4) + 1; // % da el reciduo de la división
    }

    // Creamos un arreglo para llevar el control de las matrículas ya contadas
    int *matriculas_contadas = calloc(size * 40, sizeof(int)); // size * 40 porque tenemos size estudiantes y 40 semestres, 
    //cada estudiante pudo haberse matriculado en 40 ocasiones. 
    //cada componente de este vector puede ser a lo máximo 1, y significa que el estudiante ya se matriculo en ese semestre.
    //caso contrario será cero. 

    for (int i = 0; i < SIZE2; i++) { // Recorremos todas las matrículas
        uint32_t currentYear = matricula[i].year; // Año de la matrícula i-ésima
        uint32_t currentSemester = matricula[i].semester; // Semestre de la matrícula i-ésima
        uint32_t studentId = matricula[i].std_id; // ID del estudiante que se matriculó

        struct Estudiantes *estud = NULL; // Creamos un puntero a una estructura de tipo estudiante

        for (int j = 0; j < size; j++) { // Recorremos sobre todos los estudiantes
            if (estudiante[j].std_id == studentId) {
                estud = &estudiante[j]; // Apuntamos hacia la estructura del estudiante j-ésimo
                break;
            }
        }

        if (estud){// ya sabemos que el estudiante se matriculó en un curso en cierto semestre y año, falta determinar si 
        //ya tenía alguna materia matriculada el mismo semestre. 

            int idx = (currentYear - 2020) * 4 + (currentSemester - 1); //fila de la tabla que vamos a imprimir

            if (!matriculas_contadas[studentId * 40 + idx]) { // Verificamos si el estudiante no ha tenido una matricula ese
                //semestre. se hace de esta manera pues el id de los estudiantes va desde 0 hasta 999, coincide con el número del estudiante. 
                matriculas_contadas[studentId * 40 + idx] = 1; // Marcamos como contado si no había tenido matrícula. 

                if (estud->banderas & MASK2) { // Posgrado
                    if (estud->banderas & MASK1) {
                        datos[idx].num_M_pos++; // Es femenino, sumamos uno
                    } else {
                        datos[idx].num_H_pos++; // Es masculino, sumamos uno
                    }
                } else { // Pregrado
                    if (estud->banderas & MASK1) {
                        datos[idx].num_M_pre++; // Mujer, sumamos uno
                    } else {
                        datos[idx].num_H_pre++; // Hombre, sumamos uno
                    }
                }
            }
        }
    }
    
    printf("%s %-10s %-12s %-12s %-12s %-12s\n", "AÑO", "TRISEMESTRE", "H-pre", "M-pre", "H-pos", "M-pos");

    // Imprimimos la lista definitiva
    for (int i = 0; i < 40; i++) {
        printf("%-8d %-8d %-12u %-12u %-12u %-12u\n",
               datos[i].year, datos[i].semester, datos[i].num_H_pre, datos[i].num_M_pre, datos[i].num_H_pos, datos[i].num_M_pos);
    }

    free(estudiante);
    free(curso);
    free(matricula);
    free(matriculas_contadas);
}


int is_little_endian() {
    uint16_t num = 0x0001;
    return (*((uint8_t*)&num)) == 0x01;
}

// Función para convertir un entero de 32 bits a little endian
uint32_t convert_to_little_endian(uint32_t value) {
    if (!is_little_endian) {
        return ((value & 0xFF) << 24) | ((value & 0xFF00) << 8) |
               ((value & 0xFF0000) >> 8) | ((value >> 24) & 0xFF);
    }
    return value;
}