/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arreglos.h"
#include "lista.h"

int main()
{
    srand(time(NULL));
    printf(" >> Iniciando Programa:\n");
    lista_t mi_lista = crear_lista();
    int* arreglo_random = crear_areglo_random(20, 15, 40);
    printf("LLegamos hasta aca\n");
    arreglo_a_lista(&mi_lista, arreglo_random, 20);
    mostar_lista(mi_lista);
    int arreglo_estatico[14];
    lista_a_arreglo(mi_lista, arreglo_estatico, 14);
    muestra_arreglo(14, arreglo_estatico);
    insertar_en_posicion(&mi_lista, 32, 15);
    mostar_lista(mi_lista);

    int posicion = 0;
    // printf("Ingrese posicion que desea ver el valor: ");
    // scanf("%d", &posicion);
    // printf(" >> %d\n", recuperar_valor_de_posicion(mi_lista, posicion));

    printf("Ingrese posicion que desea eliminar: ");
    scanf("%d", &posicion);
    eliminar_posicion(&mi_lista, posicion);
    mostar_lista(mi_lista);

    printf("Largo de la lista: %d\n", obntener_largo(mi_lista));
    liberar_arreglo(20, arreglo_random);
    eliminar_lista(&mi_lista);

    printf("\n\nPrueba de lista ordenada:\n\n");
    lista_t lista_ordenada = crear_lista();
    int num;
    for(int i=0; i<12; i++)
    {
        num = rand()%80 + 20;
        printf("Se agrega: %d\n", num);
        insertar_en_orden(&lista_ordenada, num);
    }
    mostar_lista(lista_ordenada);
    eliminar_lista(&lista_ordenada);
    return 0;
}
