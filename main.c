#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* miLista = ll_newLinkedList();                                               // Inicializo la LinkedList

    int opcion;

    int validarModificacion;
    int validarBaja;
    int validarOrdenamiento;


    do
    {
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado.\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");                                                               // Menu de opciones
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleados.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir.\n");

        opcion = getInt("Ingrese una opcion: ", "Error. Vuelva a intentarlo: ", 1, 10);                 // Toma la opcion que elige el usuario

        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv", miLista);
            break;
        case 2:
            controller_ListEmployee(miLista);
            controller_loadFromBinary("data.bin", miLista);
            break;
        case 3:
            controller_ListEmployee(miLista);

            controller_addEmployee(miLista);
            break;
        case 4:
            controller_ListEmployee(miLista);

            validarModificacion = controller_editEmployee(miLista);
            if(validarModificacion == 0)
            {
                printf("\nEl empleado ha sido modificado con exito.\n");
            }
            else                                                                    // Valida si la modificacion fue realizada o no y avisa al usuario
            {
                printf("\nHubo un error al modificar al empleado.\n");
            }
            break;
        case 5:
            validarBaja = controller_removeEmployee(miLista);
            if(validarBaja == 0)
            {
                printf("\nEl empleado ha sido dado de baja con exito.\n");
            }
            else                                                                    // Valida si la baja fue realizada o no y avisa al usuario
            {
                printf("\nHubo un error al dar de baja al empleado.\n");
            }
            break;
        case 6:
            controller_ListEmployee(miLista);
            break;
        case 7:
            validarOrdenamiento = controller_sortEmployee(miLista);
            if(validarOrdenamiento == 0)
            {
                printf("\nEl listado de empleados fue ordenado con exito.\n");
            }
            else                                                                     // Valida si el ordenamiento fue realizado o no y avisa al usuario
            {
                printf("\nHubo un error al ordenar el listado de los empleados.\n");
            }
            break;
        case 8:
            controller_saveAsText("data.csv", miLista);
            break;
        case 9:
            controller_saveAsBinary("data.bin", miLista);
            break;
        case 10:
            printf("Saliendo...\n");
            break;
        }

        system("\npause\n");                // Pausa la consola
        system("cls");                      // Limpia la consola

    }while(opcion != 10);                   // sale del loop si el usuario elige la opcion 10 ("Salir")

    return 0;
}
