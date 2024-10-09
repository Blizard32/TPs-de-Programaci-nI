/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#ifndef FRACCIONES_H // Un detalle importante con las guardas
#define FRACCIONES_H // Su nombre debe ser único a cada archivo

// * **Crear fracción**: Implementa una función que permita crear una fracción dinámica, inicializando sus valores.
// * **Destruir fracción**: Implementa una función para liberar la memoria reservada a una fracción.

typedef struct{
    int* numerador;
    int* denominador;
}fraccion;

fraccion crear_fraccion(int num, int denum);

void destruir_fraccion(fraccion *frac);

void mostrar_fraccion(fraccion frac);

void simplificar_fraccion(fraccion *frac);

fraccion suma_fracciones(fraccion f1, fraccion f2);

fraccion resta_fracciones(fraccion f1, fraccion f2);

fraccion multiplicacion_fracciones(fraccion f1, fraccion f2);

fraccion division_fracciones(fraccion f1, fraccion f2);

#endif
