/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include <assert.h>
#include <stdio.h>

#include "arreglos.h"
#include "cadenas.h"
#include "ejercicio.h"

int main()
{
    int filas = 3;
    int columnas = 7;
    int** matriz = crear_matriz_en_0(filas, columnas);
    mostrtar_matriz(matriz, filas, columnas); 
    liberar_matriz(matriz, filas, columnas);

    matriz = crear_matriz_con_valor(filas, columnas, 5);
    mostrtar_matriz(matriz, filas, columnas);
    liberar_matriz(matriz, filas, columnas);

    matriz = crear_matriz_identidad(4);
    mostrtar_matriz(matriz, 4, 4);
    liberar_matriz(matriz, 4, 4);

    matriz = crear_matriz_cuadrada_numerada(3);
    mostrtar_matriz(matriz, 3, 3);
    liberar_matriz(matriz, 3, 3);

    int** m_suma1 = crear_matriz_cuadrada_numerada(3);
    int** m_suma2 = crear_matriz_con_valor(3, 3, 4);
    matriz = suma_matrices(m_suma1, 3, 3, m_suma2, 3, 3);
    mostrtar_matriz(matriz, 3, 3);
    liberar_matriz(matriz, 3, 3);

    printf("-------- PREPARANDING ---------\n");
    int** m_op1 = crear_matriz_en_0(4, 2);
    int** m_op2 = crear_matriz_en_0(2, 5);
    cambiar_matriz(m_op1, 4, 2);
    cambiar_matriz(m_op2, 2, 5);
    mostrtar_matriz(m_op1, 4, 2);
    mostrtar_matriz(m_op2, 2, 5);

    printf("-------- MULTIPLICACION ---------\n");
    matriz = multiplicacion_matrices(m_op1, 4, 2, m_op2, 2, 5);
    mostrtar_matriz(matriz, 4, 5);

    printf("-------- REALOCACION ---------\n");
    int new_filas = 4;
    int new_columnas = 6;
    matriz = redimencionar_matriz(matriz, 4, 5, new_filas, new_columnas);
    mostrtar_matriz(matriz, 4, 6);

    printf("-------- CORTAR COLUMNA ---------\n");
    int* arreglo = crear_arreglo_inicializado_en_0(4);
    arreglo = separar_columna(matriz, 4, 6, 2);
    mostrtar_matriz(matriz, 4, 5);
    printf("Arrelgo: ");
    muestra_arreglo(4, arreglo);
    liberar_matriz(matriz, 4, 5);
    liberar_arreglo(4, arreglo);
    return 0;
}
