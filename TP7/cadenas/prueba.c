/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#include "cadenas.h"
#include <assert.h>
#include <stdio.h>

void test_concatenacion(char* mensaje, char c1[], int size1, char c2[], int size2, char *esperado);
void test_deduplicador(char* mensaje, char cadena[], int size, char *esperado);
void test_fraccionador(char* mensaje, char cadena[], int size, char caracter, char *esperado);
void test_centrar(char* mensaje, char cadena[], int size, int ancho, char caracter, char *esperado);
void test_cortar(char* mensaje, char cadena[], int size, char caracter, char *esperado);
void test_quitar_espacios(char* mensaje, char cadena[], int size, char *esperado);
void test_numeros(char* mensaje, long num, int size, char *esperado);

int main()
{
    printf("Probando ...\n");
    int size = 0;
    char palabra1[15] = "Buenas tardes";
    char palabra2[15] = "Martin";
    test_concatenacion("Se convinan [Buenas tardes] y [Martin]", palabra1, 15, palabra2, 15, "Buenas tardes Martin");
    char *test = concatenacion(palabra1, 15, palabra2, 15, &size);
    

    test_deduplicador("Se sacan las letras duplicadas", test, size, "Buenas trdMi");
    

    char otra_frase[25] = "Hi how are you bro";
    test_fraccionador("Separando las palabras con '-'", otra_frase, 25, '-', "Hi-how-are-you-bro");
     

    char aux[15] = "ohaio";
    test_centrar("Centrar la frase ohaio", aux, 15, 15, '-', "-----ohaio-----");
    

    test_cortar("Cortando la cadena 'Buenas tardes Martin' desde 'r'", test, 15, 'r', "Buenas tar");
    

    char cadena_espaciada[20] = "     Hola mundo"; 
    test_quitar_espacios("Quitando los espacios de la cadena '     Hola mundo'", cadena_espaciada, 20, "Hola mundo");
    

    test_numeros("Pasando de numero a cadena el 645372", 645372, size, "645372");
    
    

    printf(">> FIN TEST\n");
    return 0;
}

bool iguales(char* c1, char* c2, int capacidad)
{
    int pos = 0;
    bool iguales = true;
    while(pos < capacidad && iguales && c1[pos] != '\0' && c2[pos] != '\0')
    {
        if(c1[pos] != c2[pos])
        {
            iguales = false;
        }
        if(c1[pos] == '\0' && c2[pos] == '\0')
        {
            iguales = true;
        }
        else
        {
            if(c1[pos] == '\0')
            {
                iguales = false;
            }
            if(c2[pos] == '\0')
            {
                iguales = false;
            }
        }
        pos++;
    }
    return iguales;
}

void test_concatenacion(char* mensaje, char c1[], int size1, char c2[], int size2, char *esperado)
{
    printf("%s:", mensaje);
    int size_f = 0;
    char* nueva_cadena = concatenacion(c1, size1, c2, size2, &size_f);
    if(iguales(nueva_cadena, esperado, size_f))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(size_f, nueva_cadena);
}

void test_deduplicador(char* mensaje, char cadena[], int size, char *esperado)
{
    printf("%s:", mensaje);
    int size_f = 0;
    char* nueva_cadena = deduplicador(cadena, size, &size_f);
    if(iguales(nueva_cadena, esperado, size_f))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(size_f, nueva_cadena);
}

void test_fraccionador(char* mensaje, char cadena[], int size, char caracter, char *esperado)
{
    printf("%s:", mensaje);
    char* nueva_cadena = fraccionador(cadena, size, caracter);
    if(iguales(nueva_cadena, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(size, nueva_cadena);
}

void test_centrar(char* mensaje, char cadena[], int size, int ancho, char caracter, char *esperado)
{
    printf("%s:", mensaje);
    char* nueva_cadena = centrar(cadena, size, ancho, caracter);
    if(iguales(nueva_cadena, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(size, nueva_cadena);
}

void test_cortar(char* mensaje, char cadena[], int size, char caracter, char *esperado)
{
    printf("%s:", mensaje);
    char* nueva_cadena = cortar(cadena, size, caracter);
    if(iguales(nueva_cadena, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(size, nueva_cadena);
}

void test_quitar_espacios(char* mensaje, char cadena[], int size, char *esperado)
{
    printf("%s:", mensaje);
    char* nueva_cadena = quitar_espacios(cadena, size);
    if(iguales(nueva_cadena, esperado, size))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(size, nueva_cadena);
}

void test_numeros(char* mensaje, long num, int size, char *esperado)
{
    printf("%s:", mensaje);
    int tamanio = size;
    char* nueva_cadena = numero_a_cadena(num, &tamanio);
    if(iguales(nueva_cadena, esperado, tamanio))
    {
        printf("OK\n\n");
    }
    else
    {
        printf("FAIL\n\n");
    }
    liberar_cadena(tamanio, nueva_cadena);
}