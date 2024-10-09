/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "ejercicio.h"
#include "cadenas.h"
#include "arreglos.h"
#include <stdio.h>
#include <stdlib.h>

void cadena_a_archivo(char* cadena, char* nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "w");
    if(archivo == NULL)
    {
        perror("Error al abrir el archivo");
    }
    else
    {
        fprintf(archivo, cadena);
        fprintf(stdout, " >> EXITO AL EDITAR TEXTO");
    }
    fclose(archivo);
}

char* archivo_a_cardena(char* nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    char* cadena = (char*) malloc(sizeof(char) * MAX_CADENA);
    if(archivo == NULL)
    {
        perror("Error al abrir el archivo");
    }
    else
    {
        fgets(cadena, MAX_CADENA, archivo);
    }
    fclose(archivo);
    return cadena;
}

void arreglo_a_archivo(int* arreglo, int size ,char* nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "w");
    if(archivo == NULL)
    {
        perror("Error al abrir el archivo");
    }
    else
    {
        int pos = 0;
        int size_devuelto;
        char* num = (char*) malloc(sizeof(char) * 20);
        //Se agrega primero la cantidad de elementos que contiene el arreglo
        fprintf(archivo, numero_a_cadena(size, &size_devuelto));
        fprintf(archivo, "\n");
        while(pos < size)
        {
            num = numero_a_cadena(arreglo[pos], &size_devuelto);
            fprintf(archivo, num);
            fprintf(archivo, "\n");
            pos++;
        }
        fprintf(stdout, " >> EXITO AL EDITAR TEXTO\n");
    }
    fclose(archivo);
}

int archivo_a_arreglo(int arreglo[], char* nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    int pos = -1; //Seteado en error
    if(archivo == NULL)
    {
        perror("Error al abrir el archivo");
    }
    else
    {
        pos = 0;
        char leer[MAX_CADENA];
        fgets(leer, MAX_CADENA, archivo);
        int size_archivo = atoi(leer);
        int num = 0;
        while(pos < size_archivo)
        {
            fgets(leer, MAX_CADENA, archivo);
            num = atoi(leer);
            arreglo[pos] = num;
            pos++;
        }
    }
    fclose(archivo);
    return pos;
}

int* generador_lineal(int cantidad_elementos, int valor_inicial)
{
    int* arreglo = crear_arreglo_inicializado_en_0(cantidad_elementos);
    if(arreglo != NULL)
    {
        int pos = 0;
        while(pos < cantidad_elementos)
        {
            arreglo[pos] = valor_inicial;
            valor_inicial++;
            pos++;
        }
    }
    return arreglo;
}

int* generador_aleatorio(int cantidad_elementos, int min, int max)
{
    int* arreglo = crear_arreglo_inicializado_en_0(cantidad_elementos);
    if(arreglo != NULL)
    {
        int pos = 0;
        while(pos < cantidad_elementos)
        {
            arreglo[pos] = rand()% (max-min)+min;
            pos++;
        }
    }
    return arreglo;
}