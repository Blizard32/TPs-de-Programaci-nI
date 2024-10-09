/*
 * Trabajo Practico 5
 * Ejercicio 3 - Cadenas Seguras III
 * <nombre> - <usuario github>
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision <comisión>
 */

#include "ejercicio.h"
#include <stdlib.h>
#include <stdio.h>

void liberar_cadena(int size, char* cadena)
{
    int pos = 0;
    while (pos < size)
    {
        cadena[pos] = ' ';
        pos++;
    }
    free(cadena);
    cadena = NULL;
}

char* concatenacion(char cadena1[], int size1, char cadena2[], int size2, int *size_fusion)
{
    int tamanio_fusion = size2 + size1 + 1;
    char* devolver = (char*) malloc(sizeof(char) * tamanio_fusion);
    if(devolver != NULL)
    {
        int pos = 0;
        while (pos < size1 && cadena1[pos] != '\0')
        {
            devolver[pos] = cadena1[pos];
            pos++;
        }
        int pos_aux = 0;
        devolver[pos] = ' ';
        pos++;
        while (pos_aux < size2 && cadena2[pos_aux] != '\0')
        {
            devolver[pos] = cadena2[pos_aux];
            pos++;
            pos_aux++;
        }
        devolver[pos] = '\0';
        *size_fusion = tamanio_fusion;
    }
    return devolver;
}

char* deduplicador(char cadena[], int size, int *size_final)
{
    char* devolver = (char*) malloc(sizeof(char) * size);
    if(devolver != NULL)
    {
        int repeticiones = 0;
        int pos = 0;
        int pos_aux = 0;
        bool repetido = false;
        while (pos < size && cadena[pos] != '\0')
        {
            while(pos_aux < pos && !repetido)
            {
                if(cadena[pos] == cadena[pos_aux])
                {
                    repetido = true;
                    repeticiones++;
                }
                pos_aux++;
            }
            if(!repetido)
            {
                devolver[pos - repeticiones] = cadena[pos];
            }
            repetido = false;
            pos_aux = 0;
            pos++;
        }
        *size_final = size - repeticiones;
        devolver[*size_final] = '\0';
        realloc(devolver, *size_final);
    }
    return devolver;
}

char* fraccionador(char cadena[], int size, char caracter)
{
    int pos = 0;
    char* devolver = (char*) malloc(sizeof(char) * size);
    if(devolver != NULL)
    {
        while(cadena[pos] != '\0' && pos < size)
        {
            if(cadena[pos] != ' ')
            {
                devolver[pos] = cadena[pos];
            }
            else
            {
                devolver[pos] = caracter;
            }
            pos++;
        }
        devolver[pos] = '\0';
    }
    return devolver;
}

char* centrar(char cadena[], int size, int ancho, char caracter_relleno)
{
    char* devolver = NULL;
    int tamanio = largo_seguro(size, cadena);
    if(tamanio <= ancho)
    {
        devolver = (char*) malloc(sizeof(char) * ancho);
        if(devolver != NULL)
        {
            int completar_caracteres = (ancho - tamanio) / 2;
            int pos = 0;
            while(pos < ancho)
            {
                if(pos < completar_caracteres)
                {
                    devolver[pos] = caracter_relleno;
                }
                else
                {
                    if((pos - completar_caracteres) < tamanio)
                    {
                        devolver[pos] = cadena[pos - completar_caracteres];
                    }
                    else
                    {
                        devolver[pos] = caracter_relleno;
                    }
                }
                pos++;
            }
            devolver[pos] = '\0';
        }
    }
    return devolver;
}

char* cortar(char cadena[], int size, char caracter_final)
{
    char* devolver = (char*) malloc(sizeof(char) * size);
    if(devolver != NULL)
    {
        int pos = 0;
        while(cadena[pos] != caracter_final && cadena[pos] != '\0' && pos < size)
        {
            devolver[pos] = cadena[pos];
            pos++;
        }
        if(cadena[pos] == caracter_final)
        {
            devolver[pos] = caracter_final;
            pos++;
        }
        devolver[pos] = '\0';
        realloc(devolver, pos + 1);
    }
    return devolver;
}

char* quitar_espacios(char cadena[], int size)
{
    char* devolver = (char*) malloc(sizeof(char) * size);
    if(devolver != NULL)
    {
        int pos = 0;
        int pos_aux = 0;
        bool comienzo = false;
        while(pos < size && cadena[pos] != '\0')
        {
            if(cadena[pos] == ' ' && !comienzo)
            {
                pos_aux++;
            }
            else
            {
                comienzo = true;
                devolver[pos - pos_aux] = cadena[pos];
            }
            pos++;
        }
        devolver[pos - pos_aux] = '\0';
        realloc(devolver, pos - pos_aux + 1);
    }
    return devolver;
}

int* separar_numeros(long numero, int *size)
{
    int* devolver = (int*) malloc(sizeof(int) * 5);
    if(devolver != NULL)
    {
        int cantidad = 0;
        while(numero >= 1)
        {
            devolver[cantidad] = numero%10;
            numero = numero/10;
            cantidad++;
            if(cantidad % 5 == 0)
            {
                realloc(devolver, sizeof(devolver) + 5);
            }
        }
        *size = cantidad;
    }
    return devolver;
}

char* numero_a_cadena(long numero, int *size_cadena)
{
    char* devolver = NULL;
    int cantidad = 0;
    int* numeros = separar_numeros(numero, &cantidad);
    if(numeros != NULL)
    {
        devolver = (char*) malloc(sizeof(char) * (cantidad));
        *size_cadena = cantidad;
        cantidad--;
        if(devolver != NULL)
        {
            int pos = 0;
            while(cantidad >= 0)
            {
                devolver[pos] = numeros[cantidad] + 48;
                cantidad--;
                pos++;
            }
            devolver[pos] = '\0';
        }
    }
    free(numeros);
    return devolver;
}