/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "fracciones.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR "ERROR AL ALOCAR MEMORIA"

fraccion crear_fraccion(int num, int denum)
{
    fraccion nueva_fraccion;
    nueva_fraccion.denominador = (int*) malloc(sizeof(int));
    if(nueva_fraccion.denominador != NULL)
    {
        *nueva_fraccion.denominador = denum;
    }
    nueva_fraccion.numerador = (int*) malloc(sizeof(int));
    if(nueva_fraccion.numerador != NULL)
    {
        *nueva_fraccion.numerador = num;
    }
    return nueva_fraccion;
}

void destruir_fraccion(fraccion *frac)
{
    free(frac->denominador);
    free(frac->numerador);
}

void mostrar_fraccion(fraccion frac)
{
    if(*frac.denominador != 1)
    {
        printf("%d/%d\n", *frac.numerador, *frac.denominador);
    }
    else
    {
        printf("%d\n", *frac.numerador);
    }
}

int buscar_MCD(int numerador, int denominador)
{
    int mcd = 1;
    int num_comun = 1;
    while(num_comun <= numerador && num_comun <= denominador)
    {
        if((numerador % num_comun) == 0)
        {
            if((denominador % num_comun) == 0)
            {
                mcd = num_comun;
            }
        }
        num_comun++;
    }
    return mcd;
}

void simplificar_fraccion(fraccion *frac)
{
    int mcd = buscar_MCD(*frac->numerador, *frac->denominador);
    if(mcd != 1)
    {
        *frac->denominador = *frac->denominador / mcd;
        *frac->numerador = *frac->numerador / mcd;
    }
}

fraccion suma_fracciones(fraccion f1, fraccion f2)
{
    fraccion suma;
    int numerador = (*f1.numerador * *f2.denominador) + (*f2.numerador * *f1.denominador);
    suma = crear_fraccion(numerador, *f1.denominador * *f2.denominador);
    return suma;
}

fraccion resta_fracciones(fraccion f1, fraccion f2)
{
    fraccion resta;
    int numerador = (*f1.numerador * *f2.denominador) - (*f2.numerador * *f1.denominador);
    resta = crear_fraccion(numerador, *f1.denominador * *f2.denominador);
    return resta;
}

fraccion multiplicacion_fracciones(fraccion f1, fraccion f2)
{
    fraccion mult;

    mult = crear_fraccion((*f1.numerador * *f2.numerador), (*f1.denominador * *f2.denominador));
    return mult;
}

fraccion division_fracciones(fraccion f1, fraccion f2)
{
    fraccion div;
    div = crear_fraccion((*f1.numerador * *f2.denominador), (*f1.denominador * *f2.numerador));
    return div;
}
