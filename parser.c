#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    int respuesta;
    char idChar[100];
    char nombre[128];
    char horasTrabajadasChar[100];
    char sueldoChar[100];
    int flag = 0;

    if(pFile != NULL)
    {
        while(!feof(pFile)){                    // recorre el archivo hasta la linea final
            if(flag == 0)
            {
                fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]", idChar, nombre, horasTrabajadasChar, sueldoChar);
                printf("\n%s \t%10s \t%10s \t%5s\n", idChar, nombre, horasTrabajadasChar, sueldoChar);              // lee la primera linea del archivo y la mustra de otra forma
                flag = 1;
            }
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]", idChar, nombre, horasTrabajadasChar, sueldoChar);
            printf("\n%10s \t%10s \t%10s \t%10s\n", idChar, nombre, horasTrabajadasChar, sueldoChar);                  // lee todas las lineas del archivo y las muestra
            auxEmployee = employee_newParametros(idChar, nombre, horasTrabajadasChar, sueldoChar);
            if(auxEmployee != NULL)                         // verifica si el puntero es nulo
            {
                ll_add(pArrayListEmployee, auxEmployee);            // agrega el puntero al listado
                respuesta = 0;
            }

        }

    }
    else
    {
        respuesta = -1;
    }

    return respuesta;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int respuesta;

    if(pFile != NULL)                       // verifica que el archivo no sea nulo
    {
        while(!feof(pFile))                         // recorre el archivo hasta el final
        {
            auxEmployee = employee_new();
            fread(auxEmployee, sizeof(Employee), 1, pFile);             // lee los datos del archivo y agrega el puntero
            ll_add(pArrayListEmployee, auxEmployee);
        }
        respuesta = 0;
    }
    else
    {
        respuesta = -1;
    }

    return respuesta;
}
