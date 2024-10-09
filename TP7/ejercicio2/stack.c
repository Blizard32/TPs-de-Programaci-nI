/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "stack.h"
#include "cadenas.h"
#include <stdio.h>
#include <stdlib.h>

stack_t* crear_pila()
{
    stack_t* nueva_pila = (stack_t*) malloc(sizeof(stack_t));
    nueva_pila->capacidad = MAXIMO;
    nueva_pila->tope = 0;
    
    return nueva_pila;
}

void push(stack_t *pila, char simbolo)
{
    if(!esta_lleno(*pila))
    {
        pila->datos[pila->tope] = simbolo;
        pila->tope++;
    }
}

char pop(stack_t *pila)
{
    char caracter = ' ';
    if(!esta_vacio(*pila))
    {
        pila->tope--;
        caracter = pila->datos[pila->tope];
    }
    return caracter;
}

char peek(stack_t pila)
{
    return pila.datos[pila.tope-1];
}

bool esta_vacio(stack_t pila)
{
    bool vacio = false;
    if(pila.tope == 0)
    {
        vacio = true;
    }
    return vacio;
}

bool esta_lleno(stack_t pila)
{
    bool lleno = false;
    if(pila.tope == pila.capacidad)
    {
        lleno = true;
    }
    return lleno;
}

void eliminar_stack(stack_t *pila)
{
    free(pila);
}

void mostrar_pila(stack_t pila)
{
    for(int i = 0; i < pila.tope; i++)
    {
        printf("%c ", pila.datos[i]);
    }
    printf("\n");
}

bool esta_balanceado(char* ecuacion, int capacidad)
{
    int largo = largo_seguro_II(capacidad, ecuacion);
    bool balanceado = true;
    if(largo_seguro(capacidad, ecuacion) > 0)
    {
        stack_t* pila = crear_pila();
        int pos = 0;
        while(pos < largo && balanceado)
        {
            switch(ecuacion[pos])
            {
                case '(':
                    push(pila, ecuacion[pos]);
                    break;
                case '{':
                    push(pila, ecuacion[pos]);
                    break;
                case '[':
                    push(pila, ecuacion[pos]);
                    break;
                case ')':
                    if(pop(pila) != '(')
                    {
                        balanceado = false;
                    }
                    break;
                case '}':
                    if(pop(pila) != '{')
                    {
                        balanceado = false;
                    }
                    break;
                case ']':
                    if(pop(pila) != '[')
                    {
                        balanceado = false;
                    }
                    break;
                default:
                    break;
            }
            pos++;
        }
        if(balanceado && !esta_vacio(*pila))
        {
            balanceado = false;
        }
    }
    return balanceado;
}