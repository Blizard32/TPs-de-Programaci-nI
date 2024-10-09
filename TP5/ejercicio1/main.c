/*
 * Trabajo Practico 5
 * Ejercicio 1 - Valores Puntuales
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */

#include "ejercicio.h"
#include "lentas.h"
#include <stdio.h>

int main()
{
    printf("Ejercicio 1\n");
    int num;
    printf("Ingresar numero: ");
    scanf("%d", &num);
    int* reserva1 = reserva_entero(num);
    printf("%d - %p\n", *reserva1, reserva1);
    libera_entero(reserva1);
    printf("%d - %p\n", *reserva1, reserva1);

    printf("Ingresar numero: ");
    scanf("%d", &num);
    int* reserva2 = reserva_entero(num);
    printf("%d - %p\n", *reserva2, reserva2);

    printf("Ingresar numero a sumar: ");
    scanf("%d", &num);
    reserva1 = reserva_entero(num);
    printf("%d - %p\n", *reserva1, reserva1);
    printf("suma: %d\n", *reserva1 + *reserva2);

    return 0;
}
