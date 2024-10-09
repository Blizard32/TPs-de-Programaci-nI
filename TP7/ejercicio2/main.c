/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include <assert.h>
#include <stdio.h>

#include "cadenas.h"
#include "stack.h"

int main()
{
    printf("Iniciando Programa:\n\n");

    stack_t* mi_pila = crear_pila();
    char frase[20] = "(({&/{[]}}))";
    for(int i = 0; i < 12; i++)
    {
        push(mi_pila, frase[i]);
    }
    mostrar_pila(*mi_pila);
    printf("ver ulrimo caracter: %c\n", peek(*mi_pila));
    mostrar_pila(*mi_pila);
    printf("Quitar ultimo caracter: %c\n", pop(mi_pila));
    mostrar_pila(*mi_pila);

    char ecuacion[20] = "([4()2{(5)}]";
    if(esta_balanceado(ecuacion, 20))
    {
        printf("Esta balanceado\n");
    }
    else
    {
        printf("NO esta balanceado\n");
    }
    eliminar_stack(mi_pila);
    return 0;
}
