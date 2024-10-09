/*
 * Trabajo Practico 5
 * Ejercicio 1 - Valores Puntuales
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */
#include <stdlib.h>

int* reserva_entero(int valor)
{
    int* reserva = (int*) malloc(sizeof(int));
    if(reserva != NULL)
    {
        *reserva = valor;
    }
    return reserva;
}

int libera_entero(int* valor)
{
    int devolver = *valor;
    free(valor);
    valor = NULL;
    return devolver;
}
