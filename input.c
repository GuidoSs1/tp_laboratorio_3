#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

int getInt(char mensaje[], char mError[], int min, int max)
{
    int dato;

    printf("%s", mensaje);
    scanf("%d", &dato);

    while(dato < min || dato > max || dato < 0)
    {
        printf("%s", mError);
        scanf("%d", &dato);
    }

    return dato;
}

float getFloat(char mensaje[])
{
    float dato;

    printf("%s", mensaje);
    scanf("%f", &dato);

    return dato;
}

char getChar(char mensaje[])
{
    char dato;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &dato);

    return dato;
}

void getStr(char mensaje[], char dato[])
{
    printf(mensaje);
    scanf("%s", mensaje);
    gets(dato);
}



/***** Validaciones ******/

int onlyPNumbers(char dato[])
{
    int i = 0;
    int respuesta = 0;

    while(dato[i] != '\0')
    {
        i++;

        if(dato[i] < 0 || dato[i] > 9)
        {
            respuesta = -1;
            break;
        }
    }
    return respuesta;
}

int getStrLetters(char mensaje[], char dato[])
{
    char aux[256];

    getStr(mensaje, aux);

    if(onlyLetters(aux))
    {
        strcpy(dato, aux);
        return 1;
    }

    return 0;
}



int onlyLetters(char cadena[])
{
    int i=0;
    int respuesta = -1;

    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] <  'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            return respuesta;
            break;
        }
        i++;
    }
    return 0;
}

