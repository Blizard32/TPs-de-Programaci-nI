/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "fracciones.h"

#include <stdio.h>

int main()
{
    printf("Ejercicio 3\n");
    fraccion Q = crear_fraccion(4, 3);
    mostrar_fraccion(Q);
    simplificar_fraccion(&Q);
    mostrar_fraccion(Q);

    fraccion Q_aux = crear_fraccion(1, 4);
    printf("Operaciones: \n\n");
    printf("Suma: ");
    fraccion sumando = suma_fracciones(Q, Q_aux);
    mostrar_fraccion(sumando);
    printf("Resta: ");
    fraccion restando = resta_fracciones(Q, Q_aux);
    mostrar_fraccion(restando);
    printf("Multiplicacion: ");
    fraccion multiplicando = multiplicacion_fracciones(Q, Q_aux);
    mostrar_fraccion(multiplicando);
    printf("Division: ");
    fraccion dividiendo = division_fracciones(Q, Q_aux);
    mostrar_fraccion(dividiendo);

    printf("\nOperaciones simplificadas: \n\n");
    simplificar_fraccion(&sumando);
    simplificar_fraccion(&restando);
    simplificar_fraccion(&multiplicando);
    simplificar_fraccion(&dividiendo);
    printf("Suma: ");
    mostrar_fraccion(sumando);
    printf("Resta: ");
    mostrar_fraccion(restando);
    printf("Multiplicacion: ");
    mostrar_fraccion(multiplicando);
    printf("Division: ");
    mostrar_fraccion(dividiendo);

    destruir_fraccion(&Q);
    destruir_fraccion(&Q_aux);
    return 0;
}
