/*
 * Trabajo Practico 5
 * Ejercicio 3 - Cadenas Seguras III
 * <nombre> - <usuario github>
 * Programación 1 - Ingenieria en Computación - UNRN Andina
 * Cohorte 2024 - comision <comisión>
 */

#include "seguras.h"
#include <stdlib.h>
#include <stdio.h>


void editar_cadena(int capacidad, char cadena[], char texto[])
{
    if(largo_seguro(capacidad, texto))
    {
        int lugar = 0;
        while(texto[lugar] != '\0')
        {
            cadena[lugar] = texto[lugar];
            lugar++;
        }
        cadena[lugar] = '\0';
    }
}

int largo_seguro(int capacidad, char cadena[])
{
    int longitud = 0;
    if(capacidad > 0)
    {
        while(longitud < capacidad && cadena[longitud] != '\0')
        {
            longitud++;
        }
        if(longitud == capacidad)
        {
            longitud = CADENA_SIN_TERMINADOR;
        }
    }
    return longitud;
}

int copiar_cadena(int capacidad, char cadena[], char destino[])
{
    int largo_destino = CADENA_SIN_TERMINADOR;
    int dim_cadena = largo_seguro(capacidad, cadena);
    if(dim_cadena > 0 && dim_cadena < capacidad)
    {
        int lugar = 0;
        while(cadena[lugar] != '\0') //Se tiene en cuenta que la longitud de la cadena es menor a la capacidad
        {
            destino[lugar] = cadena[lugar];
            lugar++;
        }
        destino[lugar] = '\0';
        largo_destino = largo_seguro(capacidad, destino);
    }
    return largo_destino;
}

int insertar_cadena(int capacidad, char cadena[], char destino[], int pos)
{
    int long_1 = largo_seguro(capacidad, cadena);
    int long_2 = largo_seguro(capacidad, destino);
    int long_final = long_1 + long_2;
    int devolucion = CADENA_SIN_TERMINADOR; //si se ejecuta el codigo, no queda con error
    if(long_final < capacidad)
    {
        int lugar_cadena = 0;
        int pos_destino = 0;
        char cadena_auxiliar[capacidad];
        while(cadena[lugar_cadena] != '\0')
        {
            if(pos_destino >= pos)
            {

                cadena_auxiliar[lugar_cadena] = destino[pos_destino];
                destino[pos_destino] = cadena[lugar_cadena];
                lugar_cadena++;
            }
            pos_destino++;
        }
        if(long_2 > long_1 + pos) 
        {
            int posicion_auxiliar = pos_destino;
            while(destino[posicion_auxiliar] != '\0')
            {
                cadena_auxiliar[lugar_cadena] = destino[posicion_auxiliar];
                lugar_cadena++;
                posicion_auxiliar++;
            }
        }
        cadena_auxiliar[lugar_cadena] = '\0';
        lugar_cadena = 0;
        while(cadena_auxiliar[lugar_cadena] != '\0')
        {
            destino[pos_destino] = cadena_auxiliar[lugar_cadena];
            lugar_cadena++;
            pos_destino++;
        }
        destino[pos_destino] = '\0';
        devolucion = largo_seguro(capacidad, destino);
    }

    return devolucion;
}

int limpieza_cadena(int capacidad, char cadena[])
{
    int devolucion = CADENA_SIN_TERMINADOR;
    if(largo_seguro(capacidad, cadena) != -1)
    {
        char cadena_auxiliar[capacidad];
        int lugar = 0;
        int lugar_copia = 0;
        while(cadena[lugar] != '\0')
        {
            if((cadena[lugar] >= 48 && cadena[lugar] <= 57) || (cadena[lugar] >= 65 && cadena[lugar] <= 90) || (cadena[lugar] >= 97 && cadena[lugar] <= 122)) //caracter numerico
            {
                cadena_auxiliar[lugar_copia] = cadena[lugar];
                lugar_copia++;
            }
            lugar++;
        }
        cadena_auxiliar[lugar_copia] = '\0';
        devolucion = largo_seguro(capacidad, cadena_auxiliar);
        // printf("Aux: %s\n", cadena_auxiliar);    //Corroboración de que la funcion efectivamente funca :)
    }

    return devolucion;
}

bool sin_mayusculas(char cadena[])
{
    int lugar = 0;
    bool devolucion = true;
    while(cadena[lugar] != '\0')
    {
        if(64 < cadena[lugar] && cadena[lugar] < 91)
        {
            devolucion = false;
        }
        lugar++;
    }

    return devolucion;
}

bool es_mayuscula(char caracter)
{
    bool devolucion = false;
    if(64 < caracter && caracter < 91)
    {
        devolucion = true;
    }
    return devolucion;
}

/*
Implementar una función que indique el ordenamiento alfabético de dos cadenas (solo minúsculas)

* -1 la primera cadena va antes de que las segunda
* 0 ambas cadenas son iguales
* 1 la primera cadena va después que la segunda.
*/
#define IGUALES 0
#define PRIMERA_ANTES -1
#define SEGUNDA_ANTES 1

int comparar(int capacidad, char c1[], char c2[])
{
    int devolver = IGUALES;
    if(sin_mayusculas(c1) && sin_mayusculas(c2))
    {
        bool diferentes = false;
        int lugar = 0;
        while(!diferentes && lugar < capacidad)
        {
            if(c1[lugar] == '\0')
            {
                diferentes = true;
                devolver = PRIMERA_ANTES;   //La que va antes es la primera
            }
            if(c2[lugar] == '\0')
            {
                diferentes = true;
                if(devolver == IGUALES)
                {
                    devolver = PRIMERA_ANTES;   //La que va antes es la segunda, ya que la anterior no termino
                }
                else
                {
                    devolver = IGUALES;     //Son iguales ya que ambas terminaron
                }
            }
            if(c1[lugar] > c2[lugar])
            {
                diferentes = true;
                devolver = SEGUNDA_ANTES;
            }
            if(c1[lugar] < c2[lugar])
            {
                diferentes = true;
                devolver = PRIMERA_ANTES;
            }
            lugar++;
        }
    }
    else
    {
        devolver = CADENA_SIN_TERMINADOR;
    }

    return devolver;
}

void convertir_a_minuscula(int capacidad, char cadena[])
{
    if(largo_seguro(capacidad, cadena))
    {
        int lugar = 0;
        while(cadena[lugar] != '\0')
        {
            if(64 < cadena[lugar] && cadena[lugar] < 91)
            {
                cadena[lugar] = cadena[lugar] + 32;
            }
            lugar++;
        }
    }
}

void convertir_a_mayuscula(int capacidad, char cadena[])
{
    if(largo_seguro(capacidad, cadena))
    {
        int lugar = 0;
        while(cadena[lugar] != '\0')
        {
            if(96 < cadena[lugar] && cadena[lugar] < 123)
            {
                cadena[lugar] = cadena[lugar] - 32;
            }
            lugar++;
        }
    }
}

bool es_palindromo(int capacidad, char cadena[])
{
    bool devolucion = true;
    int lugar = 0;
    int lugar_opuesto = largo_seguro(capacidad, cadena) - 1;
    while((devolucion == true) && (cadena[lugar] != '\0'))
    {
        //Se fija que el numero del caracter sea igual (o el mismo caracter pero en mayusculas)
        if((cadena[lugar] - cadena[lugar_opuesto]) != 0 && (cadena[lugar] - cadena[lugar_opuesto]) != 32 && (cadena[lugar] - cadena[lugar_opuesto]) != -32) 
        {
            devolucion = false;
        }
        lugar_opuesto--;
        lugar++;
    }

    return devolucion;
}


void ver_caracteres(int capacidad, char cadena[])
{
    int lugar = 0;
    while(lugar < capacidad)
    {
        if(cadena[lugar] != ' ' && cadena[lugar] != '\0')
        {
            printf("   %c", cadena[lugar]);
        }
        else
        {
            printf("   _");
        }
        lugar++;
    }
    lugar = 0;
    printf("\n");
    while(lugar < capacidad)
    {
        if(lugar < 10)
        {
            printf("   %d", lugar);
        }
        else
        {
            printf("  %d", lugar);
        }
        lugar++;
    }
    printf("\n");
}

void intercambia_caracter(char *origen, char *destino)
{
    char auxiliar = *destino;
    *destino = *origen;
    *origen = auxiliar;
}

int intercambia(int capacidad, char cadena[], int origen, int destino)
{
    int devolver = CADENA_SIN_TERMINADOR;
    if(origen >= 0 && origen < capacidad && destino >= 0 && destino < capacidad )
    {
        char* ptr1 = &cadena[origen];
        char* ptr2 = &cadena[destino];
        intercambia_caracter(ptr1, ptr2);
        devolver = 1; //intercambio exitoso
    }
    return devolver;
}


int largo_seguro_II(int capacidad, char *cadena)
{
    int longitud = 0;
    while(longitud < capacidad && *cadena != '\0')
    {
        cadena++;
        longitud++;
    }
    if(longitud == capacidad)
    {
        longitud = CADENA_SIN_TERMINADOR;
    }
    return longitud;
}

char* busqueda_segura(int capacidad_buscar, char buscar[], int capacidad_buscado, char buscado[])
{
    int lugar = 0;
    int pos_buscado = 0;
    bool encontrado = false;
    int lugar_aux = 0;
    char *posicion = NULL;
    while(lugar < capacidad_buscar && encontrado == false)
    {

        if(buscar[lugar] == buscado[pos_buscado])
        {
            posicion = &buscar[lugar];
            encontrado = true;
            lugar_aux = lugar;
            while(encontrado == true && buscado[pos_buscado] != '\0' && lugar_aux < capacidad_buscar)
            {
                if(buscado[pos_buscado] != buscar[lugar_aux])
                {
                    encontrado = false;
                }
                lugar_aux++;
                pos_buscado++;
            }
            if(encontrado != true || buscado[pos_buscado] != '\0')
            {
                posicion = NULL;
                pos_buscado = 0;
                encontrado = false;
            }
        }
        lugar++;
    }
    *(posicion + capacidad_buscado) = '\0'; 
    return posicion;
}


void invertir(int capacidad, char cadena[])
{
    int inicio = 0;
    int final = largo_seguro_II(capacidad, cadena) - 1;
    if(final > 0)
    {
        while(inicio <= final)
        {
            intercambia_caracter(&cadena[inicio], &cadena[final]);
            inicio++;
            final--;
        }
        cadena[largo_seguro_II(capacidad, cadena)] = '\0';
    }
}

void mostrar_cadena(int capacidad, char cadena[])
{
    int pos = 0;
    while(pos < capacidad && cadena[pos] != '\0')
    {
        printf("%c", cadena[pos]);
        pos++;
    }
    printf("\n");
}