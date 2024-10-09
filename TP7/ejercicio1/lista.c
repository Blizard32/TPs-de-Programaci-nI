/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "lista.h"
#include "arreglos.h"
#include <stdio.h>
#include <stdlib.h>



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
nodo_t* crear_nodo(int x)
{
    nodo_t* nuevo = (nodo_t*) malloc(sizeof(nodo_t));
    nuevo->siguiente = NULL;
    nuevo->valor = x;
    return nuevo;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

lista_t crear_lista()
{
    lista_t nueva_lista;
    nueva_lista.inicio = NULL;
    nueva_lista.longitud = 0;

    return nueva_lista;
}

void eliminar_lista(lista_t *lista)
{
    lista->longitud = 0;
    // se podría hacer un while para liberar cada valor, pero fiaca
    free(lista->inicio);
}

void insertar_primero(lista_t *lista, int valor)
{
    nodo_t* nuevo = crear_nodo(valor);
    nuevo->siguiente = lista->inicio;
    lista->inicio = nuevo;
    lista->longitud++;
}

void arreglo_a_lista(lista_t *lista, int arreglo[], int cantidad)
{
    int pos = cantidad - 1;
    while(pos >= 0)
    {
        insertar_primero(lista, arreglo[pos]);
        pos--;
    }
}

void lista_a_arreglo(lista_t lista, int arreglo[], int capacidad_max)
{
    int pos = 0;
    nodo_t* act = lista.inicio;
    while(pos < capacidad_max && act != NULL)
    {
        arreglo[pos] = act->valor;
        pos++;
        act = act->siguiente;
    }
}

void insertar_en_posicion(lista_t *lista, int valor, int posicion)
{
    if(posicion <= obntener_largo(*lista))
    {
        int pos = 1;
        nodo_t* lugar = lista->inicio;
        if(posicion == 0)
        {
            insertar_primero(lista, valor);
        }
        else
        {
            while (pos != posicion) //
            {
                lugar = lugar->siguiente;
                pos++;
            }
            nodo_t* nuevo = crear_nodo(valor);
            nuevo->siguiente = lugar->siguiente;
            lugar->siguiente = nuevo;
            lista->longitud++; //lo hago adentro del if porque en insertar_primero ya hay un long++;
        }
    }
}

#define ERROR -1

int recuperar_valor_de_posicion(lista_t lista, int posicion)
{
    int dato = ERROR;
    if(posicion < obntener_largo(lista))
    {
        int pos = 0;
        nodo_t* lugar = lista.inicio;
        while (pos != posicion) //
        {
            lugar = lugar->siguiente;
            pos++;
        }
        dato = lugar->valor;
    }
    return dato;
}

void eliminar_posicion(lista_t *lista, int posicion)
{
    if(posicion < obntener_largo(*lista))
    {
        int pos = 0;
        nodo_t* anterior = NULL;
        nodo_t* actual = lista->inicio;
        if(posicion == 0)
        {
            lista->inicio = actual->siguiente;
        }
        else
        {
            while (pos != posicion) //
            {
                anterior = actual;
                actual = actual->siguiente;
                pos++;
            }
            anterior->siguiente = actual->siguiente;
        }
        lista->longitud--;
        free(actual);
    }
}

int obntener_largo(lista_t lista)
{
    return lista.longitud;
}

void mostar_lista(lista_t lista)
{
    nodo_t* act = lista.inicio;
    printf("[");
    while(act != NULL)
    {   
        printf(" %d", act->valor);
        act = act->siguiente;
        if(act != NULL)
        {
            printf(",");
        }
    }
    printf(" ]\n\n");
}

void insertar_en_orden(lista_t *lista, int valor)
{
    if(obntener_largo(*lista) == 0)
    {
        insertar_primero(lista, valor);
    }
    else
    {
        nodo_t* actual = lista->inicio;
        int pos = 0;
        while(actual != NULL && valor >= actual->valor)
        {
            actual = actual->siguiente;
            pos++;
        }
        insertar_en_posicion(lista, valor, pos);
    }
}



