/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#ifndef EJERCICIO_3_H // Un detalle importante con las guardas
#define EJERCICIO_3_H // Su nombre debe ser único a cada archivo

#define MAX_CADENA 265

void cadena_a_archivo(char* cadena, char* nombre_archivo);

char* archivo_a_cardena(char* nombre_archivo);

void arreglo_a_archivo(int* arreglo, int size ,char* nombre_archivo);

int archivo_a_arreglo(int arreglo[], char* nombre_archivo);

int* generador_lineal(int cantidad_elementos, int valor_inicial);

int* generador_aleatorio(int cantidad_elementos, int min, int max);

#endif
