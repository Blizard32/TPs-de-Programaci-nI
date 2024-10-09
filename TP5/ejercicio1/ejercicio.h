/*
 * Trabajo Practico 5
 * Ejercicio 1 - Valores Puntuales
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */

#ifndef EJERCICIO_H // Un detalle importante con las guardas
#define EJERCICIO_H // Su nombre debe ser único a cada archivo

/**
 * Reserva la memoria de un numero entero
 *
 * @param valor es el valor que va a reservar dentro de la alocaciópn de memoria
 * @returns Devuelve la DM de la alocación de memoria o NULL como error
 *  
 * ----------------------------------
 * 
 * Postcondiciones
 *       La alocación tuvo exito y no es NULL
 */
int* reserva_entero(int valor);

/**
 * Reemplazar por el comentario de documentación del prototipo que
 * esté a continuación.
 *
 * Recuerden que todas las funciones de los enunciados deben de tener
 * su comentario de documentación
 *
 * @param valor DM de la variable alocada anteriormente
 * 
 * ----------------------------
 * 
 * Precondiciones: El argumento pasado por parametro sea una alocación del Heap.
 */
int libera_entero(int* valor);
#endif
