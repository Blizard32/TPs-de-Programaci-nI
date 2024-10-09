/*
 * Trabajo Practico 5
 * Ejercicio 2 - Arreglos III
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */
#include "arreglos.h"
#include <stdio.h>
#include <stdlib.h>

#define LOG 0

// Sirve para mandar un mensaje con log = 0
void debug(char* msj)
{
    if(LOG)
    {
        printf("\n[!DEBUG] >>  %s\n", msj);
    }
}

int* crear_arreglo_sin_inicializar(int size)
{
    int *vector = (int*) malloc(sizeof(int) * size);
    return vector;
}

int* crear_arreglo_inicializado_en_0(int size)
{
    int* vector = (int*) malloc(sizeof(int) * size);
    if(vector != NULL)
    {
        int pos = 0;
        while (pos < size)
        {
            vector[pos] = 0;
            pos++;
        }
    }
    return vector;
}

int* crear_arreglo_con_valor(int size, int valor_inicializacion)
{
    int* vector = (int*) malloc(sizeof(int) * size);
    if(vector != NULL)
    {
        int pos = 0;
        while (pos < size)
        {
            vector[pos] = valor_inicializacion;
            pos++;
        }
    }
    return vector;
}

int* crear_arreglo_con_vector(int size, int size_auxiliar, int vector_inicializacion[])
{
    int* vector = NULL;
    if(size > size_auxiliar)
    {
        vector = (int*) malloc(sizeof(int) * size);
        if(vector != NULL)
        {
            int pos = 0;
            while (pos < size)
            {
                if(pos < size_auxiliar)
                {
                    vector[pos] = vector_inicializacion[pos];
                }
                else
                {
                    vector[pos] = 0;
                }
                pos++;
            }
        }   
    }
    return vector;
}

void liberar_arreglo(int size, int* vector)
{
    debug("Liberando arreglo");
    int pos = 0;
    while (pos < size)
    {
        vector[pos] = -1;
        pos++;
    }
    free(vector);
    vector = NULL;
    debug("arreglo liberado");
}

int* duplicar(int size, int vector[])
{
    int* devolver = (int*) malloc(sizeof(int) * size);
    if(devolver != NULL)
    {
        int pos = 0;
        while (pos < size)
        {
            devolver[pos] = vector[pos];
            pos++;
        }
    }
    return devolver;
}

int* fusion(int size1, int vec1[], int size2, int vec2[])
{
    int tamanio_fusion = size2 + size1;
    int* devolver = (int*) malloc(sizeof(int) * tamanio_fusion);
    if(devolver != NULL)
    {
        int pos = 0;
        while (pos < size1)
        {
            devolver[pos] = vec1[pos];
            pos++;
        }
        int pos_aux = 0;
        while (pos_aux < size1)
        {
            devolver[pos] = vec2[pos_aux];
            pos++;
            pos_aux++;
        }
    }
    return devolver;
}

int* filtro(int *size, int vector[], int filtrar)
{
    int* devolver = (int*) malloc(sizeof(int) * (*size));
    if(devolver != NULL)
    {        
        int pos = 0;
        int salteo = 0;
        while (pos < *size)
        {
            if(vector[pos] != filtrar)
            {
                devolver[pos - salteo] = vector[pos];
            }
            else
            {
                salteo++;
            }
            pos++;
        }
        *size = (*size) - salteo;
    }
    realloc(devolver, *size);
    return devolver;
}

int* insercion(int* size, int vector[], int agregar, int posicion)
{
    int* devolver = (int*) malloc(sizeof(int) * (*size + 1));
    if(devolver != NULL)
    {
        int pos = 0;
        int sumado = 0;
        *size = *size + 1;
        while (pos < *size)
        {
            if(pos != posicion)
            {
                devolver[pos + sumado] = vector[pos];
            }
            else
            {
                devolver[pos] = agregar;
                sumado++;
            }
            pos++;
        }
    }
    return devolver;
}

int* remocion(int* size, int vector[], int posicion)
{
    int* devolver = (int*) malloc(sizeof(int) * (*size));
    if(devolver != NULL)
    {
        int pos = 0;
        int quitado = 0;
        while (pos < *size)
        {
            if(pos != posicion)
            {
                devolver[pos - quitado] = vector[pos];
            }
            else
            {
                quitado++;
            }
            pos++;
        }
        *size = *size - 1;
        realloc(devolver, *size);
    }
    return devolver;
}