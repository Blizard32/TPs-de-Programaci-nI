/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "lista.h"
#include "arreglos.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void test_arreglo_a_lista(char* mensaje, int arreglo[], int size, int esperado[]);
void test_lista_a_arreglo(char* mensaje, lista_t lista, int esperado[]);


int main()
{
    printf("Iniciando Test:\n\n");
    int arreglo[7] = {5, 8, 32, 4, 1, 0, 8};
    test_arreglo_a_lista("Pasando arreglo a lista y comprobando igualdad", arreglo, 7, arreglo);

    lista_t lista_ejemplo = crear_lista();
    for(int i = 0; i < 7; i++)
    {
        insertar_en_posicion(&lista_ejemplo, arreglo[i], i);
    }
    test_lista_a_arreglo("Liasta a arreglo", lista_ejemplo, arreglo);

    eliminar_lista(&lista_ejemplo);
    printf("\n\n >> TEST FINALIZADO");
    return 0;
}

bool comparar_lista_arreglo(int arr[], lista_t l, int size_arr)
{
    bool iguales = true;
    int pos = 0;
    while(pos < size_arr && iguales)
    {
        if(recuperar_valor_de_posicion(l, pos) != arr[pos])
        {
            iguales = false;
        }
        pos++;
    }
    return iguales;
}

bool comparar_arreglos(int a1[], int a2[], int size_max)
{
    bool iguales = true;
    int pos = 0;
    while (pos < size_max && iguales)
    {
        if(a1[pos] != a2[pos])
        {
            iguales = false;
        }
        pos++;
    }

    return iguales;
}

void test_arreglo_a_lista(char* mensaje, int arreglo[], int size, int esperado[])
{
    printf("%s: ", mensaje);
    lista_t lista = crear_lista();
    arreglo_a_lista(&lista, arreglo, size);
    if(comparar_lista_arreglo(arreglo, lista, size))
    {
        printf("OK!\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    eliminar_lista(&lista);
}

void test_lista_a_arreglo(char* mensaje, lista_t lista, int esperado[])
{
    printf("%s: ", mensaje);
    int arreglo[50];
    lista_a_arreglo(lista, arreglo, 50);
    if(comparar_arreglos(arreglo, esperado, obntener_largo(lista)))
    {
        printf("OK!\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
}