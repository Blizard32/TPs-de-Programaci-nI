/*
 * Trabajo Practico 7
 * Alumno
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024
 */

#ifndef ARREGLOS_H // Un detalle importante con las guardas
#define ARREGLOS_H // Su nombre debe ser único a cada archivo


/**
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @return Deja el arreglo con los datos ingresados
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 */
int cargar_arreglo(int capacidad, int arreglo[]);

/**
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param execute Realiza stdout en cada posicion del arreglo
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 */
void muestra_arreglo(int capacidad, int arreglo[]);

/**
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param return Devuelve la suma de todos los valores del arreglo
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 */
int suma_arreglo(int capacidad, int arreglo[]);

/**
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param return Devuelve el promedio de los valores del arreglo
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 */
float promedio_arreglo(int capacidad, int arreglo[]);

/**
 * Retorna el valor minimo del arreglo
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param return Devuelve el valor del menor dato dentro del arreglo
 * 
 * --------------------------------------------------
 * 
 * Precondición: La capacidad debe ser mayor a 0 y menor al limite del arreglo
 * 
 * Postcondición: El dato debe estar dentrto del arreglo
 */
int valor_minimo(int capacidad, int arreglo[]);

/**
 * Retorna el valor maximo del arreglo
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param return Devuelve el valor del menor dato dentro del arreglo
 * 
 * --------------------------------------------------
 * 
 * Precondición: La capacidad debe ser mayor a 0 y menor al limite del arreglo
 * 
 * Postcondición: El dato debe estar dentrto del arreglo
 */
int valor_maximo(int capacidad, int arreglo[]);

/**
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param return Devuelve la posicion del valor más alto (de 0 a n-1)
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 * 
 * Postcondición: La posicion debe ser >0 y <cantidad.
 *            Si no cumple la precondicion, se retorna -1
 */
int posicion_maximo(int capacidad, int arreglo[]);

/**
 * Se obtiene el mínimo, máximo, suma y promedio del arreglo y se guarda en las DM (direccion de memoria) correspondiente
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * @param maximo Variable donde agendar el máximo
 * @param minimo Variable donde agendar el mínimo
 * @param promedio Variable donde agendar el promedio
 * @param suma Variable donde agendar la suma del vector
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 * Realiza los cambios en cada parametrto mediante pruntero
 */
void estadistica(int capacidad, int arreglo[], int *maximo, int *minimo, float *promedio, int *suma);

/**
 * Ordena el arreglo utilizando una funcion auxiliar de <intercambiar valor>
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 */
void ordenar(int capacidad, int arreglo[]);

/**
 * Intercambia los valores de dos direcciones de memoria (DM)
 * 
 * @param izquierda DM del valor que esta a la derecha
 * @param derecha DM del otro valor a intercambiar
 */
void intercambiar_numeros(int* izquierda, int* derecha);

/**
 * Devuelve la direccion de memoria del valor máximo del arreglo
 * 
 * @param capacidad Es el limite a utilizar (mayor a 0)
 * @param arreglo Arreglo a modificar
 * 
 * --------------------------------------------------
 * 
 * Precondición: la capacidad debe ser mayor a 0 y menor al limite del arreglo
 */
int* posicion_maximo_ptr(int capacidad, int arreglo[]);






//-------------------------------------------------------------------------------
//---------------------------------     TP5     ---------------------------------
//-------------------------------------------------------------------------------





/**
 * Reserva la memoria de un numero entero
 *
 * @param valor es el valor que va a reservar dentro de la alocaciópn de memoria
 * @returns Devuelve la DM de la alocación de memoria o NULL como error
 *  
 * ----------------------------------
 * 
 * Postcondiciones
 *       La alocación tuvo exito y no es NULL
 */
int* reserva_entero(int valor);

/**
 * Reemplazar por el comentario de documentación del prototipo que
 * esté a continuación.
 *
 * Recuerden que todas las funciones de los enunciados deben de tener
 * su comentario de documentación
 *
 * @param valor DM de la variable alocada anteriormente
 * 
 * ----------------------------
 * 
 * Precondiciones: El argumento pasado por parametro sea una alocación del Heap.
 */
int libera_entero(int* valor);

/**
 * Crea un arreglo sin inicializar con un tamaño dado.
 *
 * @param size tamaño que le asignaremos al vector
 * @return devuelve el arreglo
 * 
 * -----------------------------------------
 * 
 * Postcondiciones:
 * El puntero obtiene una direccion en el heder con el tamaño definido
 */
int* crear_arreglo_sin_inicializar(int size);

/**
 * Crea un arreglo inicializado en 0 con un tamaño dado.
 *
 * @param size tamaño que le asignaremos al vector
 * @return devuelve el arreglo
 * 
 * -----------------------------------------
 * 
 * Postcondiciones:
 * El puntero obtiene una direccion en el heder con el tamaño definido
 */
int* crear_arreglo_inicializado_en_0(int size);

/**
 * Crea un arreglo inicializado con un valor específico con un tamaño dado.
 *
 * @param valor_inicializacion numero en el cuál queremos inicializar el vector
 * @param size tamaño que le asignaremos al vector
 * @return devuelve el arreglo
 * 
 * -----------------------------------------
 * 
 * Postcondiciones:
 * El puntero obtiene una direccion en el heder con el tamaño definido
 */
int* crear_arreglo_con_valor(int size, int valor_inicializacion);

/**
 * Crea un arreglo inicializado con un vector menor con un tamaño dado.
 *
 * @param vector_inicializacion numero en el cuál queremos inicializar el vector
 * @param size tamaño que le asignaremos al vector
 * @return devuelve el arreglo
 * 
 * -----------------------------------------
 * 
 * Precondiciones:
 * El vector pasado debe tener dimension menor al size
 * 
 * Postcondiciones:
 * El puntero obtiene una direccion en el heder con el tamaño definido
 */
int* crear_arreglo_con_vector(int size, int size_auxiliar, int vector_inicializacion[]);

/**
 * Crea un arreglo sin inicializar con un tamaño dado.
 *
 * @param size tamaño que le asignaremos al vector
 * 
 * -----------------------------------------
 * 
 * Precondición:
 * El vector debe haberse inicializado/creado con malloc
 */
void liberar_arreglo(int size, int* vector);

/**
 * Duplica un arreglo y lo aloca en la memoria dinamica
 *
 * @param vector es el arreglo al cuál queremos copiar
 * @param size tamaño del arreglo pasado por parametro
 * @return devuelve el arreglo duplicado
 * 
 * -----------------------------------------
 * 
 * Precondición:
 *  el tamaño debe estar dentro de los parametros del arreglo
 */
int* duplicar(int size, int vector[]);

/**
 * Fusiona ambos arreglos y devuelve un arreglo dinámico con ambos
 *
 * @param vec1 uno de los arreglos a fusionar
 * @param size1 tamaño del arreglo pasado por parametro
 * @param vec2 el otro arreglo a fusionar
 * @param size2 tamaño del arreglo pasado por parametro
 * @return devuelve ambos arreglos
 * 
 * -----------------------------------------
 * 
 * Precondición:
 *  los tamaños deben estar dentro de los parametros del los arreglos
 * 
 * Postcondición:
 *  el tamaño del arreglo fusionado debe ser la suma de ambos tamaños
 */
int* fusion(int size1, int vec1[], int size2, int vec2[]);

/**
 * Duplica un arreglo filtrando un numero y lo devuelve alocado en el heap 
 *
 * @param vector es el arreglo al cuál queremos copiar
 * @param size tamaño del arreglo pasado por parametro
 * @param filtar numero al cuál queremos quitar
 * @return devuelve el arreglo sin el numero filtrado
 * 
 * -----------------------------------------
 * 
 * Precondición:
 *  el tamaño debe estar dentro de los parametros del arreglo
 */
int* filtro(int* size, int vector[], int filtrar);

/**
 * Duplica un arreglo filtrando un numero y lo devuelve alocado en el heap 
 *
 * @param vector es el arreglo al cuál queremos copiar
 * @param size tamaño del arreglo pasado por parametro
 * @param agregar numero que queremos agregar
 * @param posicion posicion que queremos agregar el numero
 * @return devuelve el arreglo con el numero agregado y el tamaño aumentado
 * 
 * -----------------------------------------
 * 
 * Precondición:
 *  el tamaño debe estar dentro de los parametros del arreglo
 */
int* insercion(int* size, int vector[], int agregar, int posicion);

/**
 * Duplica un arreglo filtrando un numero y lo devuelve alocado en el heap 
 *
 * @param vector es el arreglo al cuál queremos copiar
 * @param size tamaño del arreglo pasado por parametro
 * @param posicion posicion que queremos quitar
 * @return devuelve el arreglo sin la posicion que quitamos
 * 
 * -----------------------------------------
 * 
 * Precondición:
 *  el tamaño debe estar dentro de los parametros del arreglo
 */
int* remocion(int* size, int vector[], int posicion);

/**
 * Devuelve un arreglo dinamico inicializado con valores random
 * @param size es el tamaño del vector
 * @return devuelve un arreglo con valores entre min y max
 */
int* crear_areglo_random(int size, int min, int max);




#endif
