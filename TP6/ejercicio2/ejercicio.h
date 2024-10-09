/*
 * Trabajo Practico 6
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#ifndef EJERCICIO_2_H // Un detalle importante con las guardas
#define EJERCICIO_2_H // Su nombre debe ser único a cada archivo

//--------------------------- OPERACIONES BÁSICAS ---------------------------

/**
 * Funcion que devuelve una matriz dinámica con tamaño especificado e inicializada en 0
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * @return devuelve la DM de la matriz con el tamaño pasado por parametro
 * 
 * --------------------------------------------
 * 
 * Precondición: 
 *         Los valores de filas y columnas deben ser mayores a 0
 * 
 * Postcondición:
 *         La alocación de la matriz se realiza correctamente
 */
int** crear_matriz_en_0(int filas, int columnas);

/**
 * Funcion que devuelve una matriz dinámica con tamaño especificado e inicializada en un valor específico
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * @param valor numero en el que queremos setear la matriz
 * @return devuelve la DM de la matriz con el tamaño pasado por parametro
 * 
 * --------------------------------------------
 * 
 * Precondición: 
 *         Los valores de filas y columnas deben ser mayores a 0
 * 
 * Postcondición:
 *         La alocación de la matriz se realiza correctamente
 */
int** crear_matriz_con_valor(int filas, int columnas, int valor);

/**
 * Funcion que devuelve una matriz dinámica de identidad, con tamaño especificado
 * @param size es el tamaño (filas y columnas) que va a tener nuestra matriz
 * @return devuelve la DM de la matriz con el tamaño pasado por parametro
 * 
 * --------------------------------------------
 * 
 * Precondición: 
 *         El tamaño pasado debe ser mayor a 0
 * 
 * Postcondición:
 *         La alocación de la matriz se realiza correctamente
 */
int** crear_matriz_identidad(int size);

/**
 * Funcion que devuelve una matriz dinámica cuadrada enumerando cada lugar desde el 1
 * @param size es el tamaño (filas y columnas) que va a tener nuestra matriz
 * @return devuelve la DM de la matriz con el tamaño pasado por parametro
 * 
 * --------------------------------------------
 * 
 * Precondición: 
 *         El tamaño pasado debe ser mayor a 0
 * 
 * Postcondición:
 *         La alocación de la matriz se realiza correctamente
 */
int** crear_matriz_cuadrada_numerada(int size);

/**
 * Libera la matriz dinamica
 * @param matriz es la DM de la matriz quie queremos liberar
 * 
 * --------------------------------
 * 
 * Postcondición:
 *          Se deben liberar cada columna y fila de la matriz
 */
void liberar_matriz(int **matriz, int filas, int columnas);

/**
 * Se imprime cada lugar de la matriz
 * @param matriz es la DM de la matriz quie queremos imprimir
 * 
 */
void mostrtar_matriz(int **matriz, int filas, int columnas);

/**
 * Cambia los valores de la matriz por numeros al azar
 * @param matriz es la matriz que queremos editar
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * 
 * ----------------------------------------
 * 
 * 
 */
void cambiar_matriz(int **matriz, int filas, int columnas);

/**
 * Devuelve una matriz dinámica que contiene la suma de dos matrices pasadas por parametro
 * @param matriz1 una de las matrices para realizar la suma
 * @param filas_m1 son las filas que contiene la primer matriz
 * @param columnas_m1 son las columnas que contiene la primer matriz
 * @param matriz2 la otra matriz para realizar la suma
 * @param filas_m2 son las filas que contiene la segunda matriz
 * @param columnas_m2 son las columnas que contiene la segunda matriz
 * @return Devuelve una matriz la cual contiene la suma de las matrices pasadas por parametro
 *                  Ante cualquier error, se retorna un puntero NULL
 * 
 * --------------------------------
 * 
 * Precondición:
 * 
 *          -El contenido de las filas y columnas pasadas por parametro deben ser >= 0
 * 
 *          -Las dimensiones de las matrices pasadas por parametro deben coincidir
 */
int** suma_matrices(int **matriz1, int filas_m1, int columnas_m1,
                    int **matriz2, int filas_m2, int columnas_m2);

/**
 * Devuelve una matriz dinámica que contiene la multiplicación de dos matrices pasadas por parametro
 * @param matriz1 una de las matrices a multiplicar
 * @param filas_m1 son las filas que contiene la primer matriz
 * @param columnas_m1 son las columnas que contiene la primer matriz
 * @param matriz2 la otra matriz a multiplicar
 * @param filas_m2 son las filas que contiene la segunda matriz
 * @param columnas_m2 son las columnas que contiene la segunda matriz
 * @return Devuelve una matriz dinamica de dimencion fila1 x columa2
 * 
 * --------------------------------
 * 
 * Precondición:
 * 
 *          -El contenido de las filas y columnas pasadas por parametro deben ser >= 0. 
 * 
 *          -Las dimensiones de las matrices pasadas por parametro deben coincidir
 */
int** multiplicacion_matrices(int **matriz1, int filas_m1, int columnas_m1,
                                int **matriz2, int filas_m2, int columnas_m2);

/**
 * Devuelve la matriz pasada por parametro con nuevas dimensiones, si se agranda se la rellena con 0 y si se achica se borran los datos
 * @param matriz_base es la matriz a redimencionar
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * @param new_filas numero natural de filas al cual queremos redimencionar
 * @param new_columnas numero natural de columnas al cual queremos redimencionar
 * @return devuelve la DM de la matriz con el tamaño requerido
 * 
 * --------------------------------------------
 * 
 * Precondición: 
 *         Los valores de filas y columnas en ambos casos deben ser mayores a 0
 * 
 * Postcondición:
 *         La alocación de la matriz se realiza correctamente
 */
int** redimencionar_matriz(int **matriz_base, int filas, int columnas, int new_filas, int new_columnas);

/**
 * Corta la columna seleccionada de la matris (la elimina) y la devuelve cómo arreglo
 * @param matriz es la matriz que queremos editar
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * @param columna_a_cortar numero natural que indica la columa a retirar
 * @return Devuelve un arreglo con los valores de la columna suprimida
 * 
 * ----------------------------------------
 * 
 * Precondiciones: 
 *         Los valores de filas y columnas en ambos casos deben ser mayores a 0.
 *         La columna a cortar debe de estar dentro de los parametros (> 0 & < columnas)
 */
int* separar_columna(int **matriz, int filas, int columnas, int columna_a_cortar);

/**
 * En base a una matriz estática, retorna la misma matriz en memoria dinámica
 * @param matriz_estatica es la matriz que queremos copiar
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * @return Devuelve la matriz alocada correctamente
 * 
 * ----------------------------------------
 * 
 * 
 */
int** estatica_a_dinamica(int filas, int columnas, int matriz_estatica[filas][columnas]);

/**
 * En base a una matriz dinamica, retorna una copia de la matriz
 * @param matrix es la matriz que queremos copiar
 * @param filas numero natural que representa la cantidad de filas que contiene la matriz
 * @param columnas numero natural que representa la cantidad de columnas que contiene la matriz
 * @return Devuelve la matriz alocada correctamente
 * 
 * ----------------------------------------
 * 
 * 
 */
int** copiar_matriz_dinamica(int filas, int columnas, int** matrix);

#endif