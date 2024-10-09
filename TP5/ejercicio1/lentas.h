/*
 * Trabajo Practico 5
 * Ejercicio 1 - Valores Puntuales
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */

#ifndef LENTAS_H // Un detalle importante con las guardas
#define LENTAS_H // Su nombre debe ser único a cada archivo

#define COMIENZO_CONTADOR 1

/**
 * Realiza la operacion numero^potencia de manera lenta (con sumas)
 * @param numero mayor a 0 
 * @param potencia mayor a 0
 * @returns Devuelve la operacion realizada
 * (si algun Param es negativo o 0, se devuelve **numero**)
 * 
 * --------------------------------------------------
 * 
 * Precondiciones: numero debe ser positivo, potencia debe ser positivo.
 *                                                                
 * Postcondiciones: Si no se respeta la precondicion, se retorna numero.
 */
int potencia_lenta(int numero, int potencia);

/**
 * Operacion suma lenta
 * 
 * @param sumando numero de partida
 * @param sumador cantidad de veces sumadas
 * @return la suma entre ambos numeros
 */
int suma_lenta(int sumando, int sumador);

/**
 * Operacion cociente lento
 * 
 * @param dividendo numero al que queremos dividir 
 * @param divisor numero divisor ¡DIFERENTE a 0!
 * @return cociente (parte entera del resultado) de @param dividendo / @param divisor
 */
int cociente_lento(int dividendo, int divisor);

/**
 * Operacion resto lento
 * 
 * @param dividendo numero al que queremos dividir 
 * @param divisor numero divisor ¡DIFERENTE a 0!
 * @return resto (parte entera del resultado) de @param dividendo / @param divisor
 */
int resto_lento(int dividendo, int divisor);

/**
 * Operacion dividir
 * 
 * @param dividendo numero al que queremos dividir 
 * @param divisor numero divisor ¡DIFERENTE a 0!
 * @return resultado de la operación de @param dividendo / @param divisor como numero flotante
 */
float dividir(int dividendo, int divisor);


#endif
