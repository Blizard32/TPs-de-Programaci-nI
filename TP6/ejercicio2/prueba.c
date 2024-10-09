/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "ejercicio.h"
#include "arreglos.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void test_1(char* mensaje, int filas, int columnas, int **esperado);
void test_2(char* mensaje, int filas, int columnas, int valor, int **esperado);
void test_3(char* mensaje, int size_cuadrado, int **esperado);
void test_4(char* mensaje, int size_cuadrado, int **esperado);
void test_cambiar_random(char* mensaje, int filas, int columnas, int **esperado);
void test_suma(char* mensaje, int filas, int columnas, int** m1, int** m2, int **esperado);
void test_multiplicacion(char* mensaje, int** m1, int filas1, int columnas1, int** m2, int filas2, int columnas2, int **esperado);
void test_redim(char* mensaje, int** inicial, int filas, int columnas, int new_f, int new_c, int **esperado);
void test_cortar_columna(char* mensaje, int** inicial, int filas, int columnas, int num_cortar, int columna_esperada[] , int **esperado);


int main()
{
    printf("Ejercicio 2...\n");
    int** mat_esperada = NULL;
    int matriz_en_0[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    mat_esperada =  estatica_a_dinamica(4, 4, matriz_en_0);
    test_1("Crear matriz inicializada en 0", 4, 4, mat_esperada);
    liberar_matriz(mat_esperada, 4, 4);

    int matriz_en_3[4][4] = {{3, 3, 3, 3}, {3, 3, 3, 3}, {3, 3, 3, 3}, {3, 3, 3, 3}};
    mat_esperada = estatica_a_dinamica(4, 4, matriz_en_3);
    test_2("Crear matriz inicializada en 3", 4, 4, 3, mat_esperada);
    liberar_matriz(mat_esperada, 4, 4);

    int matriz_numerada[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    mat_esperada = estatica_a_dinamica(4, 4, matriz_numerada);
    test_3("Crear matriz numerada de 4x4", 4, mat_esperada);
    liberar_matriz(mat_esperada, 4, 4);

    int matriz_identidad[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    mat_esperada = estatica_a_dinamica(3, 3, matriz_identidad);
    test_4("Crear matriz identidad de 3x3", 3, mat_esperada);
    liberar_matriz(mat_esperada, 3, 3);

    int matriz_no_random[3][3] = {{1, 7, 2}, {32, 1, 4}, {0, 3, 12}};
    mat_esperada = estatica_a_dinamica(3, 3, matriz_no_random);
    test_cambiar_random("Crear matriz random de 3x3", 3, 3, mat_esperada);
    liberar_matriz(mat_esperada, 3, 3);

    int mat_suma_1[2][2] = {{3, 2}, {5, 2}};
    int mat_suma_2[2][2] = {{1, 1}, {3, 4}};
    int matriz_suma[2][2] = {{4, 3}, {8, 6}};
    mat_esperada = estatica_a_dinamica(2, 2, matriz_suma);
    test_suma("Suma 2 matrices", 2, 2, estatica_a_dinamica(2, 2, mat_suma_1), estatica_a_dinamica(2, 2, mat_suma_2), mat_esperada);
    liberar_matriz(mat_esperada, 2, 2);

    int mat_mul_1[2][4] = {{3, 2, 2, 1}, {5, 2, 4, 5}};
    int mat_mul_2[4][3] = {{1, 1, 1}, {3, 4, 1}, {4, 20, 2}, {5, 2, 8}};
    int** mat1 = estatica_a_dinamica(2, 4, mat_mul_1);
    int** mat2 =  estatica_a_dinamica(4, 3, mat_mul_2);
    int mat_multiplicacion[2][3] = {{22, 53, 17}, {52, 103, 55}};
    mat_esperada = estatica_a_dinamica(2, 3, mat_multiplicacion);
    test_multiplicacion("Multiplicacion de 2 matrices", mat1, 2, 4, mat2, 4, 3, mat_esperada);
    liberar_matriz(mat1, 2, 4);
    liberar_matriz(mat2, 4, 3);
    liberar_matriz(mat_esperada, 2, 2);

    int matriz[2][2] = {{12, 32}, {15, 5}};
    int** mat_inicial = estatica_a_dinamica(2, 2, matriz);
    int mat[3][4] = {{12, 32, 0, 0}, {15, 5, 0, 0}, {0, 0, 0, 0}};
    mat_esperada = estatica_a_dinamica(3, 4, mat);
    test_redim("Se redimenciona una matriz de 2x2 a 3x4", mat_inicial, 2, 2, 3, 4, mat_esperada);
    liberar_matriz(mat_inicial, 2, 2);
    liberar_matriz(mat_esperada, 3, 4);

    int matriz_a_cortar[3][5] = {{12, 32, 7, 3, 11}, {15, 5, 19, 0, 7}, {99, 3, 4, 5, 9}};
    mat_inicial = estatica_a_dinamica(3, 5, matriz_a_cortar);
    int mat_cortada[3][4] = {{12, 32, 3, 11}, {15, 5, 0, 7}, {99, 3, 5, 9}};
    mat_esperada = estatica_a_dinamica(3, 4, mat_cortada);
    int columna[3] = {7, 19, 4};
    test_cortar_columna("Se corta la columna y se verifica que se hay devuelto correctamente", mat_inicial, 3, 5, 2, columna, mat_esperada);
    liberar_matriz(mat_inicial, 2, 2);
    liberar_matriz(mat_esperada, 3, 4);

    printf(" >> FIN DEL TEST\n");

    return 0;
}

bool comparar(int** m1, int** m2, int filas, int columnas)
{
    bool iguales = true;
    int f = 0;
    int c = 0;
    while(f < filas && iguales)
    {
        while(c < columnas && iguales)
        {
            if(m1[f][c] != m2[f][c])
            {
                iguales = false;
            }
            c++;
        }
        c = 0;
        f++;
    }
    return iguales;
}

void test_1(char* mensaje, int filas, int columnas, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = crear_matriz_en_0(filas, columnas);
    if(comparar(matriz, esperado, filas, columnas))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, filas, columnas);
}

void test_2(char* mensaje, int filas, int columnas, int valor, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = crear_matriz_con_valor(filas, columnas, valor);
    if(comparar(matriz, esperado, filas, columnas))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, filas, columnas);
}

void test_3(char* mensaje, int size_cuadrado, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = crear_matriz_cuadrada_numerada(size_cuadrado);
    if(comparar(matriz, esperado, size_cuadrado, size_cuadrado))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, size_cuadrado, size_cuadrado);
}

void test_4(char* mensaje, int size_cuadrado, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = crear_matriz_identidad(size_cuadrado);
    if(comparar(matriz, esperado, size_cuadrado, size_cuadrado))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, size_cuadrado, size_cuadrado);
}

void test_cambiar_random(char* mensaje, int filas, int columnas, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = crear_matriz_en_0(filas, columnas);
    cambiar_matriz(matriz, filas, columnas);
    if(!comparar(matriz, esperado, filas, columnas))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, filas, columnas);
}

void test_suma(char* mensaje, int filas, int columnas, int** m1, int** m2, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = suma_matrices(m1, filas, columnas, m2, filas, columnas);
    if(comparar(matriz, esperado, filas, columnas))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, filas, columnas);
}

void test_multiplicacion(char* mensaje, int** m1, int filas1, int columnas1, int** m2, int filas2, int columnas2, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = multiplicacion_matrices(m1, filas1, columnas1, m2, filas2, columnas2);
    if(comparar(matriz, esperado, filas1, columnas2))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, filas1, columnas2);
}

void test_redim(char* mensaje, int** inicial, int filas, int columnas, int new_f, int new_c, int **esperado)
{
    printf("%s: ", mensaje);
    int** matriz = copiar_matriz_dinamica(filas, columnas, inicial);
    redimencionar_matriz(matriz, filas, columnas, new_f, new_c);
    if(!comparar(matriz, esperado, new_f, new_c))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_matriz(matriz, filas, columnas);
}

void test_cortar_columna(char* mensaje, int** inicial, int filas, int columnas, int num_cortar, int columna_esperada[] , int **esperado)
{
    printf("%s: ", mensaje);
    int* arreglo = separar_columna(inicial, filas, columnas, num_cortar);
    if(comparar(inicial, esperado, filas, columnas - 1))
    {
        bool iguales = true;
        int pos = 0;
        while(iguales && pos < filas)
        {
            if(columna_esperada[pos] != arreglo[pos])
            {
                iguales = false;
            }
            pos++;
        }
        if(iguales)
        {
            printf("OK\n\n");
        }
        else
        {
            printf("FAIL\n\n");
        }
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(filas, arreglo);
}