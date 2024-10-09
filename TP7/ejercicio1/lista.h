/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#ifndef LISTA_H // Un detalle importante con las guardas
#define LISTA_H // Su nombre debe ser único a cada archivo

typedef struct nodo{
    struct nodo* siguiente;
    int valor;
}nodo_t;

typedef struct{
    nodo_t* inicio;
    int longitud;
}lista_t;

/**
 * Devuelve las caracteristicas, seteando la lista creada en la inicializacion
 * @return devuelve un "tipo lista" creado con 0 argomentos.
 * --------------------------------------------
 * 
 * 
 */
lista_t crear_lista();

/**
 * Elimina lista que se le pasa por parametro
 * @param lista se usa la DM para poder modificar la lista (eliminarla)
 * 
 * ---------------------------------
 * 
 * No se libera cada nodo, sino que se libera la coneccion de la lista con el primer nodo
 */
void eliminar_lista(lista_t *lista);

/**
 * Se le agrega los valores del arreglo a la lista, respetando el orden
 * @param lista se usa la DM de la lista la cual queremos modificar (agregar valores)
 * @param arreglo es el arreglo de numeros que queremos agregar a la lista
 * @param cantidad es el tamaño máximo del arreglo
 * 
 * --------------------------------------
 * 
 * Precaución: 
 *          La lista debe estar vacía, de otro modo se agregaran los valores del arreglo al pricipio de ésta
 */
void arreglo_a_lista(lista_t *lista, int arreglo[], int cantidad);

/**
 * Se asignan todos los valores de la lista al arreglo hasta la capacidad máxima
 * @param lista es la lista que copiaremos 
 * @param arreglo es el arreglo que queremos completar
 * @param capacidad_max es la capacidad máxima que puede almacenar el arreglo
 * 
 * --------------------------------
 * 
 * Precaución: 
 *          capacidad_max debe ser mayor que la cantidad de elementos de la lista, de otro modo esta sólo se copiará hasta la capacidad del arreglo
 */
void lista_a_arreglo(lista_t lista, int arreglo[], int capacidad_max);

/**
 * Agrega un elemento en la posición seleccionada
 * @param lista se usa la DM de la lista a la cuál le agregamos el valor
 * @param valor valor entero que le agregamos a la lista
 * @param posicion posición de la lista en donde agregaremos el valor (primero posicion -> 0 <-)
 */
void insertar_en_posicion(lista_t *lista, int valor, int posicion);

/**
 * Se devuelve el valor de la posición seleccionada
 * @param lista es la lista a la que le revisaremos
 * @param posicion es la posición que queremos devolver (primero posicion -> 0 <-)
 * @return se devuelve el valor de la posición encontrtada
 * 
 * -------------------------------------
 * 
 * Precondición:
 *          La posición debe estar dentro de la cantidad de elementos de la lista
 */
int recuperar_valor_de_posicion(lista_t lista, int posicion);

/**
 * Elimina el nodo/valor de la posición seleccionada
 * @param lista es la DM de la lista a la cual modificaremos
 * @param posicion es la posicion que vamos a eliminar
 * 
 * -------------------------------------
 * 
 * Precondición:
 *          La posición debe estar dentro de la cantidad de elementos de la lista
 */
void eliminar_posicion(lista_t *lista, int posicion);

/**
 * Devuelve la cantidad de elementos que tiene la lista
 * @param lista es la lista a la cuál revisaremos
 * @return devuelve la longitud de la lista
 * 
 * -----------------------------
 * 
 * Precondición:
 *          La lista tuvo que haber sido creada. No se revisa una lista que no existe
 */
int obntener_largo(lista_t lista);

/**
 * Imprime todos los valores de la lista
 * @param lista es la lista que imprimimos
 * 
 * ----------------------------------------
 * 
 * Estilo de muestra:    [4, 3, 7, 8, 19, ... , 21]
 */
void mostar_lista(lista_t lista);

/**
 * Inserta el valor seleccionado de manera ordenada
 * @param lista es la DM de la lista que modificaremos
 * @param valor es el valor que queremos agregar a la lista
 * 
 * --------------------------------------
 * 
 * Precondición: 
 *          El arreglo debe no tener valores o debe ya estar ordenado
 * 
 * Postcondición: 
 *          valor agregado debe ser mayor al de la posición anterior y menor a la posicion siguiente
 * 
 *  >>    [ posicion-1 < valor < posicion+1 ]
 */
void insertar_en_orden(lista_t *lista, int valor);

#endif
