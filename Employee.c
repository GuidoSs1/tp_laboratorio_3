#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "input.h"

Employee* employee_new()
{
    Employee* auxEmployee;
    auxEmployee = (Employee*)malloc(sizeof(Employee));

    if(auxEmployee != NULL)
    {
        auxEmployee->id = 0;                                // Crea un nuevo empleado sin datos
        strcpy(auxEmployee->nombre, " ");
        auxEmployee->horasTrabajadas = 0;
        auxEmployee->sueldo = 0;
    }

    return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmployee;
    auxEmployee = employee_new();                           // Crea un nuevo empleado sin datos

    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    strcpy(nombre, nombreStr);                              // copio los datos de char a su tipo de variable original
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if(auxEmployee != NULL)
    {
        employee_setId(auxEmployee, id);
        employee_setNombre(auxEmployee, nombre);                    // Asigno los datos al empleado en la posicion del listado
        employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
        employee_setSueldo(auxEmployee, sueldo);
    }
    return auxEmployee;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int respuesta;

    if(this != NULL)                        // verifica que el empleado no sea nulo
    {
        if(onlyLetters(nombre) == 0)
        {
            strcpy(this->nombre, nombre);           // Copia el dato nombre pasado por parametro a el empleado del listado pasado por parametro
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int respuesta;

    if(this != NULL)                            // verifica que el empleado no sea nulo
    {
        strcpy(nombre, this->nombre);                       // copia el dato nombre del empleado en el listado pasado por parametro y lo devuelve como puntero
        respuesta = 0;
    }
    else
    {
        respuesta = -1;
    }

    return respuesta;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int respuesta;

    if(this != NULL)                    // verifica que el empleado no sea nulo
    {
        if(sueldo > 0)                      // verifica que el sueldo no sea negativo
        {
            this->sueldo = sueldo;                         // Copia el sueldo pasado por parametro en el empleado del listado pasado por parametro
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int respuesta;

    if(this != NULL)                        // Verifica que el empleado pasado por parametro no sea nulo
    {
        if(sueldo != NULL && sueldo > 0)    // Verifica que el sueldo pasado por parametro no sea nulo o negativo
        {
            *sueldo = this->sueldo;            // copia el sueldo pasado por parametro a el empleado del listado pasado por parametro
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_setId(Employee* this,int id)
{
    int respuesta;

    if(this != NULL)                        // Verifica que el empleado no sea nulo
    {
        if(id >= 0)                         // Verifica que le ID sea positivo
        {
            this->id = id;                  // Copia el id ingresado por parametro a el empleado del listado pasado por parametro
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_getId(Employee* this, int* id)
{
    int respuesta;

    if(this != NULL)                        // Verifica que el empleado no sea nulo
    {
        if(id >= 0)                         // verifica que el ID sea positivo
        {
            *id = this->id;                 // Copia el ID del empleado y lo pasa por parametro
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int respuesta;

    if(this != NULL)                            // Verifica que el empleado no sea nulo
    {
        if(horasTrabajadas > 0)                 // verifica que las horas pasadas por parametro sean positivas
        {
            this->horasTrabajadas = horasTrabajadas;        // Copia las horas en el empleado del listado
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int respuesta;

    if(this != NULL)                                        // verifica que el empleado no sea nulo
    {
        if(horasTrabajdas != NULL && horasTrabajdas > 0)       // verifica que las horas no sean nulas y negativas
        {
            *horasTrabajdas = this->horasTrabajadas;           // copia las horas del empleado en el listado y las pasa por parametro
            respuesta = 0;
        }
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    int respuesta;
    char nombreUno[128];                            // planteo variables para aclarar el codigo
    char nombreDos[128];

    employee_getNombre(e1, nombreUno);                 // tomo los nombres de los empleados pasados por parametro y los copio a las varibles
    employee_getNombre(e2, nombreDos);

    if(strcmp(nombreUno, nombreDos) < 0)                   // comparo los nombres
    {
        respuesta = 1;
    }
    else
    {
        if(strcmp(nombreUno, nombreDos) > 0)
        {
            respuesta = 0;
        }
        else
        {
            if(strcmp(nombreUno, nombreDos) == 0)           // si los nombres empiezan con la misma letra y no pueden ordenarse
            {
                employee_CompareById(e1, e2);               // llamo a la comparacion por ID
            }
        }
    }

    return respuesta;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int respuesta;
    int idUno;                                      // planteo variables para aclarar el codigo
    int idDos;

    employee_getId(e1, &idUno);                        // copio los id de los empleados pasados por parametro a las varibles
    employee_getId(e2, &idDos);

    if(idUno > idDos)                   // comparo los ID
    {
        respuesta = 0;
    }
    else
    {
        if(idUno < idDos)
        {
            respuesta = -1;
        }
    }
    return respuesta;
}

int employee_removeEmployee(Employee* this)
{
    int respuesta;

    if(this != NULL)                // verifica que el empleado pasado por parametro no sea nulo
    {
        free(this);                 // libera el espacio que ocupa el empleado en el listado
        respuesta = 0;
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

