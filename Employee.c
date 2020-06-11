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
        auxEmployee->id = 0;
        strcpy(auxEmployee->nombre, " ");
        auxEmployee->horasTrabajadas = 0;
        auxEmployee->sueldo = 0;
    }

    return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmployee;
    auxEmployee = employee_new();

    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    strcpy(nombre, nombreStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if(auxEmployee != NULL)
    {
        employee_setId(auxEmployee, id);
        employee_setNombre(auxEmployee, nombre);
        employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
        employee_setSueldo(auxEmployee, sueldo);
    }
    return auxEmployee;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int respuesta;

    if(this != NULL)
    {
        if(onlyLetters(nombre) == 0)
        {
            strcpy(this->nombre, nombre);
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

    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
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

    if(this != NULL)
    {
        if(sueldo != NULL && sueldo > 0)
        {
            this->sueldo = sueldo;
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

    if(this != NULL)
    {
        if(sueldo != NULL && sueldo > 0)
        {
            *sueldo = this->sueldo;
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

    if(this != NULL)
    {
        if(id != NULL && id >= 0)
        {
            this->id = id;
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

    if(this != NULL)
    {
        if(id != NULL && id >= 0)
        {
            *id = this->id;
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

    if(this != NULL)
    {
        if(horasTrabajadas != NULL && horasTrabajadas > 0)
        {
            this->horasTrabajadas = horasTrabajadas;
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

    if(this != NULL)
    {
        if(horasTrabajdas != NULL && horasTrabajdas > 0)
        {
            *horasTrabajdas = this->horasTrabajadas;
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
    char nombreUno[128];
    char nombreDos[128];

    employee_getNombre(e1, nombreUno);
    employee_getNombre(e2, nombreDos);

    if(strcmp(nombreUno, nombreDos) < 0)
    {
        respuesta = 1;
    }
    else
    {
        if(strcmp(nombreUno, nombreDos) > 0)
        {
            respuesta = -1;
        }
        else
        {
            if(strcmp(nombreUno, nombreDos) == 0)
            {
                employee_CompareById(e1, e2);
            }
        }
    }

    return respuesta;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int respuesta;
    int idUno;
    int idDos;

    employee_getId(e1, &idUno);
    employee_getId(e2, &idDos);

    if(idUno > idDos)
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

    if(this != NULL)
    {
        free(this);
        respuesta = 0;
    }
    else
    {
        respuesta = -1;
    }
    return respuesta;
}

