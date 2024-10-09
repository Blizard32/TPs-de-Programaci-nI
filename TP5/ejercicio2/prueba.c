/*
 * Trabajo Practico 5
 * Ejercicio 2 - Arreglos III
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */
#include "ejercicio.h"
#include "arreglos.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void test_crear_arreglo_1(char* mensaje, int size);
void test_crear_arreglo_2(char* mensaje, int size, int esperado[]);
void test_crear_arreglo_3(char* mensaje, int size, int valor, int esperado[]);
void test_crear_arreglo_4(char* mensaje, int size, int vector[], int v_size, int esperado[]);
void test_duplicar(char* mensaje, int size, int vector[], int esperado[]);
void test_fusionar(char* mensaje, int size1, int vector1[], int size2, int vector2[], int esperado[]);
void test_filtro(char* mensaje, int size, int vector[], int filtrar, int esperado[]);
void test_insercion(char* mensaje, int size, int vector[], int num, int posicion, int esperado[]);
void test_remocion(char* mensaje, int size, int vector[], int filtrar, int esperado[]);

int main()
{
    printf("Probando ...\n");
    int size = 15;
    test_crear_arreglo_1("Se aloca 15 lugares de memoria", size);

    int vector_en_0[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    test_crear_arreglo_2("Se aloca 15 lugares seteados en 0", size, vector_en_0);

    int vector_en_4[15] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    test_crear_arreglo_3("Se aloca 15 lugares seteados en 4", size, 4, vector_en_4);

    int vec_aux[9] = {5, 7, 3, 12, 35, 12, 0, 14, 32};
    int vector_final[15] = {5, 7, 3, 12, 35, 12, 0, 14, 32, 0, 0, 0, 0, 0, 0};
    test_crear_arreglo_4("Se aloca 15 lugares en base al arreglo [5, 7, 3, 12, 35, 12, 0, 14, 32]", size, vec_aux, 9, vector_final);

    test_duplicar("Duplicando arreglo auxiliar", 9, vec_aux, vec_aux);

    int vec_fusion[6] = {2, 18, 20, 16, 11, 8};
    int vector_fucionado[15] = {5, 7, 3, 12, 35, 12, 0, 14, 32, 2, 18, 20, 16, 11, 8};
    test_fusionar("Fucionando [5, 7, 3, 12, 35, 12, 0, 14, 32] y [2, 18, 20, 16, 11, 8]", 9, vec_aux, 6, vec_fusion, vector_fucionado);

    // int vector_filtrado[7] = {5, 7, 3, 35, 0, 14, 32};
    // test_filtro("Filtrando 12 en [5, 7, 3, 12, 35, 12, 0, 14, 32]", 9, vec_aux, 12, vector_filtrado);

    

    printf("\t>> FIN TEST");

    return 0;
}

bool comparar(int v1[], int v2[], int size)
{
    int pos = 0;
    bool iguales = true;
    while(pos < size && iguales)
    {
        if(v1[pos] != v2[pos])
        {
            iguales = false;
        }
        pos++;
    }
    return iguales;
}

void test_crear_arreglo_1(char* mensaje, int size)
{
    printf("%s:", mensaje);
    int* puntero = crear_arreglo_sin_inicializar(size);
    if(puntero != NULL)
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(size, puntero);
}

void test_crear_arreglo_2(char* mensaje, int size, int esperado[])
{
    printf("%s:", mensaje);
    int* puntero = crear_arreglo_inicializado_en_0(size);
    if(comparar(puntero, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(size, puntero);
}

void test_crear_arreglo_3(char* mensaje, int size, int valor, int esperado[])
{
    printf("%s:", mensaje);
    int* puntero = crear_arreglo_con_valor(size, valor);
    if(comparar(puntero, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(size, puntero);
}

void test_crear_arreglo_4(char* mensaje, int size, int vector[], int v_size, int esperado[])
{
    printf("%s:", mensaje);
    int* puntero = crear_arreglo_con_vector(size, v_size, vector);
    if(comparar(puntero, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(size, puntero);
}

void test_duplicar(char* mensaje, int size, int vector[], int esperado[])
{
    printf("%s:", mensaje);
    int* puntero = duplicar(size, vector);
    if(comparar(puntero, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(size, puntero);
}

void test_fusionar(char* mensaje, int size1, int vector1[], int size2, int vector2[], int esperado[])
{
    printf("%s:", mensaje);
    int* tamanio = reserva_entero(size1 + size2);
    int* puntero = fusion(size1, vector1, size2, vector2);
    if(comparar(puntero, esperado, *tamanio))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(*tamanio, puntero);
    libera_entero(tamanio);
}

void test_filtro(char* mensaje, int size, int vector[], int filtrar, int esperado[])
{
    printf("%s:", mensaje);
    int* tamanio = reserva_entero(size);
    int* puntero = filtro(tamanio, vector, filtrar);
    if(comparar(puntero, esperado, *tamanio))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(*tamanio, puntero);
    libera_entero(tamanio);
}

void test_insercion(char* mensaje, int size, int vector[], int num, int posicion, int esperado[])
{
    printf("%s:", mensaje);
    int* tamanio = reserva_entero(size);
    int* puntero = insercion(tamanio, vector, num, posicion);
    if(comparar(puntero, esperado, *tamanio))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(*tamanio, puntero);
    libera_entero(tamanio);
}

void test_remocion(char* mensaje, int size, int vector[], int filtrar, int esperado[])
{
    printf("%s:", mensaje);
    int* tamanio = reserva_entero(size);
    int* puntero = filtro(tamanio, vector, filtrar);
    if(comparar(puntero, esperado, *tamanio))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_arreglo(*tamanio, puntero);
    libera_entero(tamanio);
}