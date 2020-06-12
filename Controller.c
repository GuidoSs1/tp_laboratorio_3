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

    if(path != NULL)                                // verifica que el archivo pasado por parametros no sea nulo
    {
        pArchivo = fopen(path, "r");                // abre el archivo para leer en txt
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);              // llama al parseo de datos
        respuesta = 0;
        fclose(pArchivo);                               // cierra el archivo
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
    else                                                                    // avisa al usuario si pudo o no realizar el parseo
    {
        printf("\nHubo un error al cargar el archivo .txt.\n");
    }


    return respuesta;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int respuesta;

    FILE* pArchivo;

    if(path != NULL)                                            // verfica que el archivo no sea nulo
    {
        pArchivo = fopen(path, "rb");                           // abre el archivo para leer en binario
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);    // llama a la funcion para parsear los datos
        respuesta = 0;
        fclose(pArchivo);                                       // cierra el archivo
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
    else                                                                // Avisa al usuario si pudo o no hacerlo
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

    tam = ll_len(pArrayEmployee);                               // paso el tamaño del listado a una variable entera

    if(pArrayEmployee != NULL)                              // verifica que el puntero al listado no sea nulo
    {
        if(tam > 0)
        {
            for(i=0;i<tam;i++)                                  // recorre el listado
            {
                auxEmployee = ll_get(pArrayEmployee, i);
                employee_getId(auxEmployee, &idAux);            // toma el id del ultimo empleado en el listado
            }
            if(idAux > id)
            {
                id = idAux+1;                                      // lo incrementa en 1
            }

        }
    }

    return id;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    auxEmployee = employee_new();               // llama a la funcion para crear un nuevo empleado vacio

    int respuesta;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];

    if(pArrayListEmployee != NULL)                  // verifica que el puntero al listado no sea nulo
    {
        id = controller_ID(pArrayListEmployee);     // asigna el id al empleado

        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        fgets(nombre, 128, stdin);
        nombre[strlen(nombre)-1] = '\0';

        while(onlyLetters(nombre) == -1)                // Toma el nombre del empleado
        {
            printf("\nError. Vuelva a intentarlo: ");
            fflush(stdin);
            fgets(nombre, 128, stdin);
            nombre[strlen(nombre)-1] = '\0';
        }

        horasTrabajadas = getInt("\nIngrese la cantidad de horas trabajadas del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);     // toma las horas trabajadas por el empleado

        sueldo = getInt("\nIngrese el sueldo del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);            //toma el sueldo del empleado

        if(auxEmployee != NULL)                                             // verifica que el puntero planteado en la funcion no sea nulo
        {
            employee_setId(auxEmployee, id);
            employee_setNombre(auxEmployee, nombre);
            employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);          // asigna los valores a cada campo del empleado
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
    else                                                                            // avisa si lo pudo hacer o no
    {
        printf("\nHubo un error al cargar el empleado.\n");
    }



    return respuesta;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;                      // planteo un auxiliar de un empleado
    Employee* getEmployee;                         // planteo otro auxiliar para tomar el empleado

    int opcion;
    int i;
    int respuesta;
    int id;
    int getID;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
    int tam;

    tam = ll_len(pArrayListEmployee);           // paso el tamaño del listado a una variable entera

    if(pArrayListEmployee != NULL)                      // verifica que el puntero no sea nulo
    {
        id = getInt("\nIngrese el ID del empleado a modificar: ", "\nError. Vuelva a intentarlo: ", 1, 100000);             // toma el ID  del empleado a modificar

        for(i=0;i<tam;i++)                                  // recorre el listado
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &getID);            // toma los ID  de cada empleado en el listado uno por uno

            if(getID == id)                                 // verifica que el ID ingresado coincida con un empleado en el listado
            {
                getEmployee = ll_get(pArrayListEmployee, i);        // toma a ese empleado
                printf("\n1. Modificar nombre del empleado.");
                printf("\n2. Modificar horas trabajadas del empleado.");
                printf("\n3. Modificar sueldo del empleado.");              // da opciones de modificacion
                printf("\n4. Salir.");

                opcion = getInt("\nIngrese una opcion: ", "\nError. Vuelva a intentarlo: ", 1, 4);      // toma la opcion que elija el usuario

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese el nuevo nombre del empleado: ");
                    fflush(stdin);
                    fgets(nombre, 128, stdin);
                    nombre[strlen(nombre)-1] = '\0';

                    while(onlyLetters(nombre) == -1)                        // toma el nuevo nombre del empleado y lo asigna
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

                    employee_setHorasTrabajadas(getEmployee, horasTrabajadas);          // toma las horas trabajadas por el empleado y las asgina

                    respuesta = 0;
                    break;
                case 3:
                    sueldo = getInt("\nIngrese el sueldo del empleado: ", "\nError. Vuelva a intentarlo: ", 1, 1000000);

                    employee_setSueldo(getEmployee, sueldo);                        // toma el nuevo sueldo del empleado y lo asigna

                    respuesta = 0;
                    break;
                case 4:
                    printf("\nSaliendo de la operacion...");                        // sale del menu
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

    if(pArrayListEmployee != NULL)                          // verifica que el puntero pasado por parametro no sea nulo
    {
        id = getInt("\nIngrese el ID del empleado a dar de baja: ", "\nError. Vuelva a intentarlo: ", 1, 100000);       // toma el ID del empleado a dar de baja

        for(i=0; i<tam; i++)                            // recorre el listado de empleados
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &getID);            // toma el ID de cada empleado en el listado

            if(getID == id)                                     // verifica que el ID ingrasado sea igual al ID  de algun empleado en el listado
            {
                getEmployee = ll_get(pArrayListEmployee, i);

                printf("\nEsta seguro que quiere dar de baja el empleado?");
                printf("\n1. SI.");                                             // pregunta al usuario si esta seguro de dar de baja al empleado con el ID ingresado
                printf("\n2. NO.");

                opcion = getInt("\nIngrese una opcion: ", "\nError. Vuelva a intentarlo: ", 1, 2);      // toma la opcion del usuario

                switch(opcion)
                {
                case 1:
                    employee_removeEmployee(getEmployee);
                    ll_remove(pArrayListEmployee, i);                                       // da de baja a el empleado con el ID ingresado
                    respuesta = 0;
                    break;
                case 2:
                    printf("\nCancelando la operacion...");
                    respuesta = 0;                                                      // se cancela la operacion
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

    if(pArrayListEmployee != NULL)                          // verifica que el puntero al listado no sea nulo
    {
        printf("\nID \tNOMBRE \t\tHORAS TRABAJADAS \tSUELDO");
        respuesta = 0;

        for(i=0;i<tam;i++)                                  // recorre el listado
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &id);
            employee_getNombre(auxEmployee, nombre);
            employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);             // toma todos los campos de cada empleado en el listado
            employee_getSueldo(auxEmployee, &sueldo);
            printf("\n%d \t%10s %10d \t\t%10d\n", id, nombre, horasTrabajadas, sueldo);             // muestra todos los campos de los empleados en el listado
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

    if(pArrayListEmployee != NULL)                  // verifica que el puntero al listado no sea nulo
    {
        ll_sort(pArrayListEmployee, employee_CompareByName, 0);                         // llama a la funcion de ordenamiento
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

    if(pArrayListEmployee != NULL)                          // verifica que el puntero al listado no sea nulo
    {
        if(path != NULL)                                // verifica que el archivo no sea nulo
        {
            id = malloc(sizeof(int));
            nombre = malloc(sizeof(char)*128);
            sueldo = malloc(sizeof(int));                   // reserva espacio en memoria para cada campo
            horasTrabajadas = malloc(sizeof(int));

            pArchivo = fopen(path, "w");                            // abre el archivo .csv
            fprintf(pArchivo, "\nID,NOMBRE,HORAS TRABAJADAS,SUELDO");

            for(i=0; i<tam; i++)                                    // recorre el listado
            {
                auxEmployee = ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee, id);
                employee_getNombre(auxEmployee, nombre);                        // toma todos los datos de todos los empleados en el listado
                employee_getHorasTrabajadas(auxEmployee, horasTrabajadas);
                employee_getSueldo(auxEmployee, sueldo);
                fprintf(pArchivo, "\n%d,%s,%d,%d", *id, nombre, *horasTrabajadas, *sueldo);         // escribe todos los datos en el archivo
            }

            free(id);
            free(nombre);
            free(horasTrabajadas);                                          // libera el espacio en memoria reservado
            free(sueldo);

            respuesta = 0;

            fclose(pArchivo);                                               // cierra el archivo
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
    else                                                                    // avisa al usuario si pudo o no realizar el guardado de los datos
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

    if(pArrayListEmployee != NULL)                  // verifica que el puntero al listado no sea nulo
    {
        pArchivo = fopen(path, "wb");               // abre el archivo para escribir en binario

        for(i=0;i<tam;i++)                                  // recorre el listado
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);         // toma cada empleado en el listado
            fwrite(auxEmployee, sizeof(Employee), 1, pArchivo);                // lo escribe en el archivo en forma binaria
        }
        respuesta = 0;

        fclose(pArchivo);                                   // cierra el archivo
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
    else                                                            // avisa al usuario si pudo guardar los datos
    {
        printf("\nHubo un error al guardar el archivo .bin.\n");
    }

    return respuesta;
}
