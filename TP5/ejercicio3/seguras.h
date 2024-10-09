/*
 * Trabajo Practico 5
 * Ejercicio 3 - Cadenas Seguras III
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */

//Uso el pragma once porque me causa fallo visual el #ifndef
#pragma once
// #ifndef EJERCICIO_H // Un detalle importante con las guardas
// #define EJERCICIO_H // Su nombre debe ser único a cada archivo

#include <stdbool.h>

#define CADENA_SIN_TERMINADOR -1

/**
 * La funcion edita cadena con un texto ingresado
 *  @param cadena es la secuencia de caracteres de la cual se completará.
 *  @param texto es la secuencia de caracteres que se copian.
 *  @param capacidad es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
void editar_cadena(int capacidad, char cadena[], char texto[]);

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la secuencia de caracteres de la cual se obtendrá el largo.
               La secuencia es valida y posee un tamaño físico que permite alojar el terminador. (PRE)
 *  @param capacidad es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres, y este valor es menor a la capacidad.
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea igual a la capacidad
               indicada por el argumento
 */
int largo_seguro(int capacidad, char cadena[]);

/**
 * La funcion copia la cadena en el destino y deja la deja sin datos
 *  @param cadena es la secuencia de caracteres que copiaremos.
 *  @param destino es la secuencia de caracteres la cual modificaremos.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @returns devuelve el largo de la cadena destino o el mensje de error:
            CADENA_SIN_TERMINADOR cuando la cadena original sea mayor a capacidad
 */
int copiar_cadena(int capacidad, char cadena[], char destino[]);

/**
 * La funcion inserta la cadena en destino en un lugar en específico.
 *  @param cadena es la secuencia de caracteres que insertaremos.
 *  @param destino es la secuencia de caracteres la cual modificaremos.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @param pos lugar donde se empesará la inserción de la cadena.
 *  @returns devuelve el largo de la cadena destino o el mensje de error:
            CADENA_SIN_TERMINADOR cuando la cadena original sea mayor a capacidad

 * --------------------------------------------------------------------------------
 * 
 * Precondición: Verifica si la cadena destino puede alojar la cantidad de caracteres de ambas cadenas.
 */
int insertar_cadena(int capacidad, char cadena[], char destino[], int pos);

/**
 * La funcion deja la cadena sin caracteres alfanumericos.
 *  @param cadena es la secuencia de caracteres que modificaremos.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @returns devuelve el largo de la cadena destino o el mensje de error:
            CADENA_SIN_TERMINADOR cuando la cadena original sea mayor a capacidad
 */
int limpieza_cadena(int capacidad, char cadena[]);

/**
 * Se fija si la cadena es completamente minuscula.
 *  @param cadena es la secuencia de caracteres que corrobora.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @returns devuelve true/false dependiendo del resultado
 * 
 * ---------------------------------------------------------------------------------------
 * 
 * Para fijarse si es mayuscula o minuscula se utiliza el numero que se obtiene en el codigo ASCII (min > 96, mayusc < 91)
 */
bool sin_mayusculas(char cadena[]);

/**
 * Se fija si el caracter es mayuscula.
 *  @param caracter es el caracter que se evalua.
 *  @returns devuelve true/false dependiendo del resultado
 * 
 * ---------------------------------------------------------------------------------------
 * 
 * Para fijarse si es mayuscula o minuscula se utiliza el numero que se obtiene en el codigo ASCII (64 < mayusc < 91)
 */
bool es_mayuscula(char caracter);


/**
 * La funcion indica el ordenamiento alfabético de dos cadenas (solo minúsculas)
 *  @param c1 es la secuencia de caracteres que insertaremos.
 *  @param c2 es la secuencia de caracteres la cual modificaremos.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @returns devuelve la comparacion de cadena
 * 
 * -Primera va antes (-1)    -Son iguales (0)   -Segunda va antes (1)

 * --------------------------------------------------------------------------------
 * 
 * Precondición: Verifica si la cadena destino puede alojar la cantidad de caracteres de ambas cadenas.
 */
int comparar(int capacidad, char c1[], char c2[]);

/**
 * La funcion cambia los caracteres de la cadena a minuscula.
 *  @param cadena es la secuencia de caracteres que modificaremos.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
void convertir_a_minuscula(int capacidad, char cadena[]);

/**
 * La funcion cambia los caracteres de la cadena a mayuscula.
 *  @param cadena es la secuencia de caracteres que modificaremos.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
void convertir_a_mayuscula(int capacidad, char cadena[]);

/**
 * La funcion se fija si la cadena es palindromo o no.
 *  @param cadena es la secuencia de caracteres a verificar.
 *  @param capacidad cantidad de caracteres que pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @return devuelve true/false dependiendo si es palindromo.
 *          Si tiene algun error, devuelve FALSE
 * 
 * -------------------------------------------------------------------------------------
 * 
 * Un palindromo es una palabra que se lee igual de ambos lados.
 */
bool es_palindromo(int capacidad, char cadena[]);

/**
 * Imprime todos los caracteres que contiene la cadena (imprime "_" en los espacios vacíos)
 *  @param cadena es la secuencia de caracteres de la cual se completará.
 *  @param capacidad es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
void ver_caracteres(int capacidad, char cadena[]);

/**
 * Cambia dos caracteres pasado por parametro
 *  @param origen Direccion de Memoria que queremos cambiar el dato
 *  @param destino DM en la que queremos alojar el dato
 * 
 * --------------------------------------
 * 
 * Intercambia los datos contenidos en cada DM
 */
void intercambia_caracter(char *origen, char *destino);

/**
 * Cambia dos caracteres de una cadena segura
 *  @param capacidad Límite seguro de la cadena
 *  @param cadena Cadena de caracteres a modificar
 *  @param origen Direccion de Memoria que queremos cambiar el dato
 *  @param destino DM en la que queremos alojar el dato
 * 
 * --------------------------------------
 * 
 * Precondición: El destino y origen deben estar dentro de los parametros de capacidad
 */
int intercambia(int capacidad, char cadena[], int origen, int destino);

/**
 * Devuelve el largo de la cadena, si no se encuentra el final de la cadena dentro de capacidad retorna CADENA_SIN_TERMINADOR
 *  @param cadena es la secuencia de caracteres de la cual verificara su seguridad.
 *  @param capacidad es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
int largo_seguro_II(int capacidad, char *cadena);

/**
 * Busca una cadena de caracteres dentro de otra y devuelve la longitud
 *  @param buscar es la secuencia de caracteres en la cual buscaremos la otra cadena
 *  @param capacidad_buscar es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 *  @param buscando es la secuencia de caracteres que buscaremos
 *  @param capacidad_buscado caracteres de la cadena a buscar (sirve para poner el limite al devolver un puntero)
 */
char* busqueda_segura(int capacidad_buscar, char buscar[], int capacidad_buscado, char buscado[]);

/**
 * Devuelve el largo de la cadena, si no se encuentra el final de la cadena dentro de capacidad retorna CADENA_SIN_TERMINADOR
 *  @param cadena es la secuencia de caracteres de la cual verificara su seguridad.
 *  @param capacidad es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
void invertir(int capacidad, char cadena[]);

/**
 * Muestra la cadena
 *  @param cadena es la secuencia de caracteres de la cual queremos mostrar.
 *  @param capacidad es cuantos caracteres pueden ser alojados en la cadena.
 *                   Este valor es mayor que cero y menor o igual al largo físico de la cadena. (PRE)
 */
void mostrar_cadena(int capacidad, char cadena[]);


// #endif
