/*
 * Trabajo Practico 5
 * Ejercicio 1 - Valores Puntuales
 * Felipe Outeiral - Blizard32
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision II
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lentas.h"

int potencia_lenta(int numero, int potencia)
{
    int aumento = 0;
    int resultado = numero;
    for(int i=0; i<potencia; i++)
    {
        for(int j=1; j<numero; j++)
        {
            resultado = resultado + aumento;
        }
        aumento = resultado;
    }

    return resultado;
}

//Es una función privada (no se puede llamar con la libreria lentas.h)
int modulo_de_numero(int numero)
{
    if(numero < 0)
    {
        numero = numero * (-1);
    }
    return numero;
}

int suma_lenta(int sumando, int sumador)
{
    int contador = COMIENZO_CONTADOR;
    while(contador != modulo_de_numero(sumador))
    {
        if(sumador > 0) //check si se suma o resta
        {
            sumando ++;
        }
        else
        {
            sumando --;
        }
        contador ++;
    }
    return sumando; 
}

int cociente_lento(int dividendo, int divisor)
{
    int cociente = COMIENZO_CONTADOR;
    dividendo = dividendo - divisor;
    while(dividendo > 1)
    {
        dividendo = dividendo - divisor;
        cociente++;
    }
    return cociente;
}

int resto_lento(int dividendo, int divisor)
{
    int resto = dividendo - (divisor*cociente_lento(dividendo, divisor));
    return resto;
}

float dividir(int dividendo, int divisor)
{
    int resto = dividendo - (divisor*cociente_lento(dividendo, divisor));
    int decimales = 0;
    while(resto != 0)
    {
        if(resto<divisor)
        {
            resto = resto * 10;
            decimales = decimales * 10;
        }
        resto = resto - divisor;
        decimales++;
    }
    float resultado = decimales;
    while(resultado >= 1)
    {
        resultado = resultado * 0.1;
    }
    return resultado + cociente_lento(dividendo, divisor);
}