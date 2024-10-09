/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "arreglos.h"
#include "cadenas.h"
#include "ejercicio.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ejercicio 3\n");
    int* vec = generador_lineal(12, 32);
    arreglo_a_archivo(vec, 12, "numeros.txt");

    int arreglo[50];
    int size_arreglo = archivo_a_arreglo(arreglo, "numeros.txt");
    muestra_arreglo(size_arreglo, arreglo);

    char *leer = archivo_a_cardena("saludo.txt");
    printf("\n\n%s\n", leer);
    free(leer);

    return 0;
}
