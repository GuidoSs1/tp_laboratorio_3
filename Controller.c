#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int respuesta;

    if(path != NULL)
    {
        pArchivo = fopen(path, "r");
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        respuesta = 0;
        fclose(pArchivo);
    }
    else
    {
        respuesta = -1;
    }

    /***** Aviso *****/

    if(respuesta == 0)
    {
        printf("\nEl archivo en .txt ha sido cargado con exito.\n");
    }
    else
    {
        printf("\nHubo un error al cargar el archivo .txt.\n");
    }


    return respuesta;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int respuesta;

    FILE* pArchivo;

    if(path != NULL)
    {
        pArchivo = fopen(path, "rb");
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        respuesta = 0;
        fclose(pArchivo);
    }
    else
    {
        respuesta = -1;
    }

    /***** Aviso *****/

    if(respuesta == 0)
    {
        printf("\nEl archivo en .bin ha sido cargado con exito.\n");
    }
    else
    {
        printf("\nHubo un error al cargar el archivo .bin.\n");
    }


    return respuesta;
}

int controller_ID(LinkedList* pArrayEmployee)
{
    Employee* auxEmployee;

    int i;
    int idAux;
    int id = 0;
    int tam;

    tam = ll_len(pArrayEmployee);

    if(pArrayEmployee != NULL)
    {
        if(tam > 0)
        {
            for(i=0;i<tam;i++)
            {
                auxEmployee = ll_get(pArrayEmployee, i);
                employee_getId(auxEmployee, &idAux);
            }
            if(idAux > id)
            {
                id = idAux+1;
            }

        }
    }

    return id;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    auxEmployee = employee_new();

    int respuesta;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];

    if(pArrayListEmployee != NULL)
    {
        id = controller_ID(pArrayListEmployee);

        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        fgets(nombre, 128, stdin);
        nombre[strlen(nombre)-1] = '\0';

        while(onlyLetters(nombre) == -1)
        {
            printf("\nError. Vuelva a intentarlo: ");
            fflush(stdin);
            fgets(nombre, 128, stdin);
            nombre[strlen(nombre)-1] = '\0';
        }

        horasTrabajadas = getInt("\nIngrese la cantidad de horas trabajadas del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);

        sueldo = getInt("\nIngrese el sueldo del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);

        if(auxEmployee != NULL)
        {
            employee_setId(auxEmployee, id);
            employee_setNombre(auxEmployee, nombre);
            employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
            employee_setSueldo(auxEmployee, sueldo);
            ll_add(pArrayListEmployee, auxEmployee);
            respuesta = 0;
        }

    }
    else
    {
        respuesta = -1;
    }

    /***** Aviso *****/

    if(respuesta == 0)
    {
        printf("\nEl empleado ha sido cargado con exito. ID: %d\n", id);
    }
    else
    {
        printf("\nHubo un error al cargar el empleado.\n");
    }



    return respuesta;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    Employee* getEmployee;

    int opcion;
    int i;
    int respuesta;
    int id;
    int getID;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
    int tam;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        id = getInt("\nIngrese el ID del empleado a modificar: ", "\nError. Vuelva a intentarlo: ", 1, 100000);

        for(i=0;i<tam;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &getID);

            if(getID == id)
            {
                getEmployee = ll_get(pArrayListEmployee, i);
                printf("\n1. Modificar nombre del empleado.");
                printf("\n2. Modificar horas trabajadas del empleado.");
                printf("\n3. Modificar sueldo del empleado.");
                printf("\n4. Salir.");

                opcion = getInt("\nIngrese una opcion: ", "\nError. Vuelva a intentarlo: ", 1, 4);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese el nuevo nombre del empleado: ");
                    fflush(stdin);
                    fgets(nombre, 128, stdin);
                    nombre[strlen(nombre)-1] = '\0';

                    while(onlyLetters(nombre) == -1)
                    {
                        printf("\nError. Vuelva a intentarlo: ");
                        fflush(stdin);
                        fgets(nombre, 128, stdin);
                        nombre[strlen(nombre)-1] = '\0';
                    }
                    employee_setNombre(getEmployee, nombre);
                    respuesta = 0;
                    break;
                case 2:
                    horasTrabajadas = getInt("\nIngrese la cantidad de horas trabajadas del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);

                    employee_setHorasTrabajadas(getEmployee, horasTrabajadas);

                    respuesta = 0;
                    break;
                case 3:
                    sueldo = getInt("\nIngrese el sueldo del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);

                    employee_setSueldo(getEmployee, sueldo);

                    respuesta = 0;
                    break;
                case 4:
                    printf("\nSaliendo de la operacion...");
                    break;
                }
            }
        }
    }
    else
    {
        respuesta = -1;
    }


    return respuesta;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    Employee* getEmployee;

    int respuesta;
    int i;
    int id;
    int getID;
    int opcion;
    int tam;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        id = getInt("\nIngrese el ID del empleado a dar de baja: ", "\nError. Vuelva a intentarlo: ", 1, 100000);

        for(i=0; i<tam; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &getID);

            if(getID == id)
            {
                getEmployee = ll_get(pArrayListEmployee, i);

                printf("\nEsta seguro que quiere dar de baja el empleado?");
                printf("\n1. SI.");
                printf("\n2. NO.");

                opcion = getInt("\nIngrese una opcion: ", "\nError. Vuelva a intentarlo: ", 1, 2);

                switch(opcion)
                {
                case 1:
                    employee_removeEmployee(getEmployee);
                    ll_remove(pArrayListEmployee, i);
                    respuesta = 0;
                    break;
                case 2:
                    printf("\nCancelando la operacion...");
                    respuesta = 0;
                    break;
                }
            }

        }
    }
    else
    {
        respuesta = -1;
    }

    return respuesta;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    int respuesta;
    int tam;
    int i;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[128];

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("\nID \tNOMBRE \t\tHORAS TRABAJADAS \tSUELDO");
        respuesta = 0;

        for(i=0;i<tam;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &id);
            employee_getNombre(auxEmployee, nombre);
            employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
            employee_getSueldo(auxEmployee, &sueldo);
            printf("\n%d \t%10s %10d \t\t%10d\n", id, nombre, horasTrabajadas, sueldo);
        }
    }
    else
    {
        respuesta = -1;
    }

    return respuesta;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_CompareByName, 0);
        respuesta = 0;
    }
    else
    {
        respuesta = -1;
    }


    return respuesta;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxEmployee;

    int respuesta;
    int i;
    int* id;
    char* nombre;
    int* sueldo;
    int* horasTrabajadas;
    int tam;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        if(path != NULL)
        {
            id = malloc(sizeof(int));
            nombre = malloc(sizeof(char)*128);
            sueldo = malloc(sizeof(int));
            horasTrabajadas = malloc(sizeof(int));

            pArchivo = fopen(path, "w");
            fprintf(pArchivo, "\nID,NOMBRE,HORAS TRABAJADAS,SUELDO");

            for(i=0; i<tam; i++)
            {
                auxEmployee = ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee, id);
                employee_getNombre(auxEmployee, nombre);
                employee_getHorasTrabajadas(auxEmployee, horasTrabajadas);
                employee_getSueldo(auxEmployee, sueldo);
                fprintf(pArchivo, "\n%d,%s,%d,%d", *id, nombre, *horasTrabajadas, *sueldo);
            }

            free(id);
            free(nombre);
            free(horasTrabajadas);
            free(sueldo);

            respuesta = 0;

            fclose(pArchivo);
        }
    }
    else
    {
        respuesta = -1;
    }

    /***** Aviso *****/

    if(respuesta == 0)
    {
        printf("\nEl archivo ha sido guardado con exito en .txt.\n");
    }
    else
    {
        printf("\nHubo un error al cuardar el archivo en .txt.\n");
    }


    return respuesta;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxEmployee;

    int respuesta;
    int i;
    int tam;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path, "wb");

        for(i=0;i<tam;i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee, sizeof(Employee), 1, pArchivo);
        }
        respuesta = 0;

        fclose(pArchivo);
    }
    else
    {
        respuesta = -1;
    }

    /***** Aviso *****/

    if(respuesta == 0)
    {
        printf("\nEl archivo ha sido guardado con exito en .bin.\n");
    }
    else
    {
        printf("\nHubo un error al guardar el archivo .bin.\n");
    }

    return respuesta;
}
