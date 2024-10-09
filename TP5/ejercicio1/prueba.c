/*
 * Trabajo Practico 5
 * Ejercicio 1 - Valores Puntuales
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */

#include "ejercicio.h"
#include "lentas.h"
#include <assert.h>
#include <stdio.h>

void test_suma_lenta(char* mensaje, int valor1, int valor2, int esperado)
{
    printf("%s: ", mensaje);
    int* num1 = reserva_entero(valor1);
    int* num2 = reserva_entero(valor2);
    if(suma_lenta(libera_entero(num1), libera_entero(num2)) == esperado)
    {
        printf("OK\n");
    }
    else
    {
        printf("FAIL\n");
    }
}

void test_potencia_lenta(char* mensaje, int valor1, int valor2, int esperado)
{
    printf("%s: ", mensaje);
    int* num1 = reserva_entero(valor1);
    int* num2 = reserva_entero(valor2);
    if(potencia_lenta(libera_entero(num1), libera_entero(num2)) == esperado)
    {
        printf("OK\n");
    }
    else
    {
        printf("FAIL\n");
    }
}

void test_dividir(char* mensaje, int valor1, int valor2, float esperado)
{
    printf("%s: ", mensaje);
    int* num1 = reserva_entero(valor1);
    int* num2 = reserva_entero(valor2);
    if(dividir(libera_entero(num1), libera_entero(num2)) == esperado)
    {
        printf("OK\n");
    }
    else
    {
        printf("FAIL\n");
    }
}

int main()
{
    printf("Probando ...\n");
    // int* algo = NULL;
    // printf("%p\n\n", algo);
    test_suma_lenta("Sumando 7 + 3", 7, 3, 10);
    test_potencia_lenta("Potencia: 3 a la 2", 3, 2, 9);
    test_dividir("Dividiendo 14 en 2", 14, 2, 7);


    return 0;
}
