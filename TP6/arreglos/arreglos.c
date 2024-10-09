/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "arreglos.h"
#include <stdio.h>
#include <stdlib.h>


//-------------------------------------------------------------------------------
//---------------------------------     TP4     ---------------------------------
//-------------------------------------------------------------------------------


int cargar_arreglo(int capacidad, int arreglo[])
{
    if(capacidad > 0)
    {
        int valor = 0;
        for(int i=0; i<capacidad; i++)
        {
            printf("Ingresar posicion %d del arreglo: ", i+1);
            scanf("%d", &valor);
            arreglo[i] = valor;
            system("cls");
        }
    }
    return 1;
}

void muestra_arreglo(int capacidad, int arreglo[])
{
    for(int i=0; i<capacidad; i++)
    {
        printf("%d\t", arreglo[i]);
    }
    printf("\n");
}

int suma_arreglo(int capacidad, int arreglo[])
{
    int suma = 0;
    for(int i=0; i<capacidad; i++)
    {
        suma = suma + arreglo[i];
    }
    return suma;
}

float promedio_arreglo(int capacidad, int arreglo[])
{
    double promedio = 0;
    if(capacidad > 0)
    {
        int suma = suma_arreglo(capacidad, arreglo);
        promedio = (double)suma/capacidad;
    }
    return promedio;  
}

int valor_minimo(int capacidad, int arreglo[])
{
    int minimo = 99999;
    if(capacidad > 0)
    {
        for(int i=0; i<capacidad; i++)
        {
            if(arreglo[i] < minimo)
                minimo = arreglo[i];
        }
    }
    else
    {
        minimo = 0;
    }
    return minimo;
}

int valor_maximo(int capacidad, int arreglo[])
{
    int maximo = 0;
    if(capacidad > 0)
    {
        for(int i=0; i<capacidad; i++)
        {
            if(arreglo[i] > maximo)
                maximo = arreglo[i];
        }
    }
    else
    {
        maximo = 0;
    }
    return maximo;
}


int posicion_maximo(int capacidad, int arreglo[])
{
    int posicion = -1;
    int maximo = 0;
    for(int i=0; i<capacidad; i++)
    {
        if(arreglo[i] > maximo)
        {
            maximo = arreglo[i];
            posicion = i;
        }
    }
    return posicion;
}

void estadistica(int capacidad, int arreglo[], int *maximo, int *minimo, float *promedio, int *suma)
{
    *maximo = valor_maximo(capacidad, arreglo);
    *minimo = valor_minimo(capacidad, arreglo);
    *promedio = promedio_arreglo(capacidad, arreglo);
    *suma = suma_arreglo(capacidad, arreglo);
}

void intercambiar_numeros(int* izquierda, int* derecha)
{
    int auxiliar = *izquierda;
    *izquierda = *derecha;
    *derecha = auxiliar;
}

void ordenar(int capacidad, int arreglo[])
{
    int lugar = 0;
    int posicion_cambio = 1;
    while(lugar < capacidad)
    {
        while(posicion_cambio < capacidad)
        {
            if(arreglo[posicion_cambio] < arreglo[lugar])
            {
                int pos_aux = posicion_cambio;
                while(pos_aux > lugar)
                {
                    intercambiar_numeros(&arreglo[pos_aux - 1], &arreglo[pos_aux]);
                    pos_aux--;
                }
            }
            posicion_cambio++;
        }
        lugar++;
        posicion_cambio = lugar+1;
    }
}

int* posicion_maximo_ptr(int capacidad, int arreglo[])
{
    int *pos = NULL;
    int maximo = 0;
    for(int i=0; i<capacidad; i++)
    {
        if(arreglo[i] > maximo)
        {
            maximo = arreglo[i];
            pos = &arreglo[i];
        }
    }
    return pos;
}



//-------------------------------------------------------------------------------
//---------------------------------     TP5     ---------------------------------
//-------------------------------------------------------------------------------

#ifndef LOG
#define LOG 0
#endif

// Sirve para mandar un mensaje con log = 0
void debug(char* msj)
{
    if(LOG)
    {
        printf("\n[!DEBUG] >>  %s\n", msj);
    }
}

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
                if(pos < size)
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
    fflush(NULL);
    int* devolver = (int*) malloc(sizeof(int) * (*size));
    if(devolver != NULL)
    {        
        int pos = 0;
        int salteo = 0;
        debug("Empezando a crear arreglo filtrado");
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
        printf("size: %d", *size);
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