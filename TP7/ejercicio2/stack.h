/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#ifndef STACK_H // Un detalle importante con las guardas
#define STACK_H // Su nombre debe ser único a cada archivo

#include <stdbool.h>

#define MAXIMO 10

typedef struct
{
	char datos[MAXIMO];
	int tope;
	int capacidad;
}stack_t;

stack_t* crear_pila();

void push(stack_t *pila, char simbolo);

char pop(stack_t *pila);

char peek(stack_t pila);

bool esta_vacio(stack_t pila);

bool esta_lleno(stack_t pila);

void eliminar_stack(stack_t *pila);

void mostrar_pila(stack_t pila);

bool esta_balanceado(char* ecuacion, int capacidad);



#endif
