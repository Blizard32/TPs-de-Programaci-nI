/*
 * Trabajo Practico 5
 * Ejercicio 3 - Cadenas Seguras III
 * <nombre> - <usuario github>
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision <comisión>
 */

#include "seguras.h"

#ifndef EJERCICIO_H // Un detalle importante con las guardas
#define EJERCICIO_H // Su nombre debe ser único a cada archivo


/**
 * Libera la alocación de la cadena en la memoria dinámica
 * @param size es el tamaño seguro de la cadena
 * @param cadena es la cadena dinamica que queremos liberar
 */
void liberar_cadena(int size, char* cadena);

/**
 * Devuelve una cadena alocada con memoria dinámica, la cual es la combinación de otras dos cadenas
 *
 * @param cadena1 es la primer cadena que vamos a incluir en la concatenación
 * @param size1 tamaño seguro de la primer cadena
 * @param cadena1 es la segunda cadena que vamos a incluir en la concatenación
 * @param size1 tamaño seguro de la segunda cadena
 * @param size_fusion DM del tamaño final de la cadena fusionada
 * @returns devuelve la DM de la combinación de ambas cadenas alocadas en el heap
 * 
 * -----------------------------------------------------
 *  
 */
char* concatenacion(char cadena1[], int size1, char cadena2[], int size2, int *size_fusion);

/**
 * Devuelve una cadena alocada con memoria dinámica, salteando los caracteres repetidos
 *
 * @param cadena es la cadena de caracteres que vamos a modificar
 * @param size tamaño seguro de la cadena
 * @param size_final DM del tamaño de la cadena retornada
 * @returns devuelve la DM de la cadena sin caracteres repetidos
 * 
 * -----------------------------------------------------
 *  
 * Postcondición:
 *      La cadena retornada debe ser menor/igual a la cadena recivida, esta debe ser alocada en el heap
 */
char* deduplicador(char cadena[], int size, int *size_final);

/**
 * Devuelve un arreglo de cadenas las cuales son las palabras separadas de la cadena pasada por parametro
 *
 * @param cadena es la cadena de caracteres que vamos a fraccionar
 * @param size tamaño seguro de la cadena
 * @param cantidad_palabras DM de la cantidad de palabras encontradas
 * @param size_max_palabras DM del tamaño máximo que pueden tener las palabras
 * @returns devuelve la DM dentro del heap, la cual es un doble puntero el cual contiene las palabras de la cadena
 * 
 * -----------------------------------------------------
 *  USAR COMO CORTE CON CARACTER FINAL --> ' ' <--, así se puede separar por nuevas cadenas
 */
/**
 * Devuelve una cadena alocada con memoria dinámica, separando las palabras con el caracter elegido
 *
 * @param cadena es la cadena de caracteres que vamos a modificar
 * @param size tamaño seguro de la cadena
 * @param caracter caracter que elegimos para separar las palabras
 * @returns devuelve la DM de la cadena sin caracteres repetidos
 * 
 * -----------------------------------------------------
 *  
 * Postcondición:
 *      La cadena retornada debe ser menor/igual a la cadena recivida, esta debe ser alocada en el heap
 */
char* fraccionador(char cadena[], int size, char caracter);

/**
 * Devuelve un arreglo de la cadena centrada en un ancho, rellenando los caracteres vacíos con un caracter en específico
 *
 * @param cadena es la cadena de caracteres que vamos a modificar
 * @param size tamaño seguro de la cadena
 * @param ancho es el tamaño final de la cadena que devolveremos
 * @param caracter_relleno caracter específico con el cuál queremos rellenar
 * @returns devuelve la DM dentro del heap, la cual contiene el comienzo de nuestra nueva cadena centrada
 * 
 * -----------------------------------------------------
 *  
 */
char* centrar(char cadena[], int size, int ancho, char caracter_relleno);

/**
 * Devuelve un arreglo de cadenas el cual se corta luego de encontrar el primer caracter de fin
 *
 * @param cadena es la cadena de caracteres que vamos cortar
 * @param size tamaño seguro de la cadena
 * @param caracter_final es el caracter donde queremos cortar nuestra cadena
 * @returns devuelve la DM dentro del heap, con la cadena cortada
 * 
 * -----------------------------------------------------
 *  
 */
char* cortar(char cadena[], int size, char caracter_final);

/**
 * Devuelve un arreglo de cadenas sin espacios del comienzo
 *
 * @param cadena es la cadena de caracteres que vamos a editar
 * @param size tamaño seguro de la cadena
 * @returns devuelve la DM dentro del heap, sin espacios en el comienzo
 * 
 * -----------------------------------------------------
 *  
 */
char* quitar_espacios(char cadena[], int size);

/**
 * Devuelve un arreglo de cadenas de numeros
 *
 * @param cadena es la cadena de caracteres que vamos fraccionar
 * @param size tamaño seguro de la cadena
 * @param cantidad_palabras DM de la cantidad de palabras encontradas
 * @param size_max_palabras DM del tamaño máximo que pueden tener las palabras
 * @returns devuelve la DM dentro del heap, la cual es un doble puntero el cual contiene las palabras de la cadena
 * 
 * -----------------------------------------------------
 *  
 */
char* numero_a_cadena(long numero, int *size_cadena);

#endif
