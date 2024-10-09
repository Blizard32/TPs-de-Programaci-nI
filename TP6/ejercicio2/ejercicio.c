/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "ejercicio.h"
#include "arreglos.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int** crear_matriz_en_0(int filas, int columnas)
{
    int ** matriz = (int**) malloc(sizeof(int*) * filas);
    for(int i = 0; i < filas; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * columnas);
    }
    if(matriz != NULL)
    {
        for(int i= 0; i < filas; i++)
        {
            for(int j = 0; j < columnas; j++)
            {
                matriz[i][j] = 0;
            }
        }
    }
    return matriz;
}

int** crear_matriz_con_valor(int filas, int columnas, int valor)
{
    int ** matriz = (int**) malloc(sizeof(int*) * filas);
    for(int i = 0; i < filas; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * columnas);
    }
    if(matriz != NULL)
    {
        for(int i= 0; i < filas; i++)
        {
            for(int j = 0; j < columnas; j++)
            {
                matriz[i][j] = valor;
            }
        }
    }
    return matriz;
}

int** crear_matriz_identidad(int size)
{
    int ** matriz = (int**) malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * size);
    }
    if(matriz != NULL)
    {
        for(int i= 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(j == i)
                {
                    matriz[i][j] = 1;
                }
                else
                {
                    matriz[i][j] = 0;
                }
            }
        }
    }
    return matriz;
}

int** crear_matriz_cuadrada_numerada(int size)
{
    int ** matriz = (int**) malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * size);
    }
    if(matriz != NULL)
    {
        int cont = 1;
        for(int i= 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                matriz[i][j] = cont;
                cont++;
            }
        }
    }
    return matriz;
}

void liberar_matriz(int **matriz, int filas, int columnas)
{
    for(int i= 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }
    for(int i = 0; i < columnas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void mostrtar_matriz(int **matriz, int filas, int columnas)
{
    for(int i= 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            printf("\t%d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

}

void cambiar_matriz(int **matriz, int filas, int columnas)
{
    for(int i= 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = rand()%10;
        }
    }
}

int** suma_matrices(int **matriz1, int filas_m1, int columnas_m1, int **matriz2, int filas_m2, int columnas_m2)
{
    int** suma = NULL;
    if(filas_m1 == filas_m2 && columnas_m1 == columnas_m2)
    {
        suma = crear_matriz_en_0(filas_m1, columnas_m1);
        if(suma != NULL)
        {
            for(int i= 0; i < filas_m1; i++)
            {
                for(int j = 0; j < columnas_m1; j++)
                {
                    suma[i][j] = matriz1[i][j] + matriz2[i][j];
                }
            }
        }
    }
    return suma;
}

int** multiplicacion_matrices(int **matriz1, int filas_m1, int columnas_m1, int **matriz2, int filas_m2, int columnas_m2)
{
    int** multiplicacion = NULL;
    if(columnas_m1 == filas_m2)
    {
        multiplicacion = crear_matriz_en_0(filas_m1, columnas_m2);
        if(multiplicacion != NULL)
        {
            for(int i= 0; i < filas_m1; i++)
            {
                for(int j = 0; j < columnas_m2; j++)
                {
                    for(int k = 0; k < columnas_m1; k++)
                    {
                        multiplicacion[i][j] = multiplicacion[i][j] + (matriz1[i][k] * matriz2[k][j]);
                    }
                }
            }
        }
    }
    return multiplicacion;
}

void set_matrices(int** m_base, int** m_llegada, int filas, int columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            m_llegada[i][j] = m_base[i][j];
        }
    }
}

int** redimencionar_matriz(int **matriz_base, int filas, int columnas, int new_filas, int new_columnas)
{
    int** copia_matriz = crear_matriz_en_0(new_filas, new_columnas);
    if(copia_matriz != NULL)
    {
        if(filas >= new_filas)
        {
            if(columnas >= new_columnas)
            {
                set_matrices(matriz_base, copia_matriz, new_filas, new_columnas);
            }
            else
            {
                set_matrices(matriz_base, copia_matriz, new_filas, columnas);
            }
        }
        else
        {
            if(columnas >= new_columnas)
            {
                set_matrices(matriz_base, copia_matriz, filas, new_columnas);
            }
            else
            {
                set_matrices(matriz_base, copia_matriz, filas, columnas);
            }
        }
    }
    return copia_matriz;
}

int* separar_columna(int **matriz, int filas, int columnas, int columna_a_cortar)
{
    int* arreglo = NULL;
    if(columna_a_cortar < columnas && columna_a_cortar >= 0)
    {
        arreglo = (int*) crear_arreglo_inicializado_en_0(filas);
        if(arreglo != NULL)
        {
            for(int i = 0; i < filas; i++)
            {
                arreglo[i] = matriz[i][columna_a_cortar];
            }
            for(int i = 0; i < filas; i++)
            {
                for(int j = columna_a_cortar; j < columnas - 1; j++)
                {
                    matriz[i][j] = matriz[i][j +1];
                }
            }
            for(int i = 0; i < filas; i++)
            {
                realloc(matriz[i], (columnas -1) * sizeof(int));
            }
            
        }
    }
    return arreglo;
}


int** estatica_a_dinamica(int filas, int columnas, int matriz_estatica[filas][columnas])
{
    int** matriz = NULL;
	if(filas > 0 && columnas >0)
	{
        matriz = crear_matriz_en_0(filas, columnas);
        if(matriz != NULL)
        {
            for(int i = 0; i < filas; i++)
            {
                for(int j = 0; j < columnas; j++)
                {
                    matriz[i][j] = matriz_estatica[i][j];
                }
            }
        }
	}
	return matriz;
}

int** copiar_matriz_dinamica(int filas, int columnas, int** matrix)
{
    int** matriz = NULL;
	if(filas > 0 && columnas >0)
	{
        matriz = crear_matriz_en_0(filas, columnas);
        if(matriz != NULL)
        {
            for(int i = 0; i < filas; i++)
            {
                for(int j = 0; j < columnas; j++)
                {
                    matriz[i][j] = matrix[i][j];
                }
            }
        }
	}
    return matriz;
}