#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];                   // estructura de empleados
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Funcion que crea un nuevo empleado
 *
 * \return puntero a la estructura si funciono || NULL si hubo algun error
 *
 */
Employee* employee_new();

/** \brief Funcion que crea un nuevo empleado y carga los campos del elemento con datos
 *
 * \param char* puntero al dato ID
 * \param char* puntero al dato Nombre
 * \param char* puntero al dato Horas Trabajadas
 * \param char* puntero al dato Sueldo
 * \return puntero a la estructura si funciono || NULL si hubo algun error
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Funcion que permite eliminar un empleado de la lista de empleados
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \return 0 si el empleado fue eliminado correctamente || -1 si hubo un error o el puntero es nulo
 *
 */
int employee_removeEmployee(Employee* this);

/** \brief Funcion que asigna un ID a un empleado en el listado
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \param int ID del empleado
 * \return 0 si asigno el ID correctamente || -1 si hubo un error al asignar el ID o el puntero es nulo
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Funcion que permite tomar el ID de un empleado en el listado
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \param int* puntero del ID del empleado
 * \return 0 si tomo el ID del empleado correctamente || -1 si hubo un error al tomar el ID o el puntero es nulo
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Funcion que asigna un nombre a un empleado en el listado
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \param char* puntero del nombre del empleado
 * \return 0 si se le asigno el nombre correctamente al empleado || -1 si hubo un error al asginar el nombre o el puntero es nulo
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Funcion que permite tomar el nombre de un empleado en el listado
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \param char* puntero al nombre del empleado
 * \return 0 si el tomo el nombre del empleado correctamente || -1 si hubo un error o el puntero es nulo
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Funcion que permite asignar las horas trabajadas de un empleado en el listado
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \param int horas trabajadas del empleado a asignar
 * \return 0 si asgino las horas trabajadas correctamente || -1 si hubo un error o el puntero es nulo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Funcion que permite tomar las horas trabajadas de un empleado en el listado
 *
 * \param Employee* puntero a la estructura de empleados en una posicion
 * \param int* puntero a las horas trabajadas por el empleado
 * \return 0 si se tomo correctamente || -1 si hubo un error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Funcion que permite asignar el sueldo a un empleado en el listado
 *
 * \param Employee* puntero a la estructura en una posicion
 * \param int sueldo del empleado a asignar
 * \return 0 si se asigno correctamente el sueldo del empleado || -1 si hubo un error
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Funcion que permite tomar el sueldo de un empleado en el listado
 *
 * \param Employee* puntero a la estructura en una posicion
 * \param int* sueldo del empleado a tomar
 * \return 0 si tomo el sueldo del empleado correctamente || -1 si hubo algun error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Funcion que compara los empleados por nombre para ordenarlos de forma ascendente o descendente
 *
 * \param Employee* e1 puntero a estructura de empleados (empleado 1)
 * \param Employee* e2 puntero a estructura de empleados (empleado 2)
 * \return 1 si los ordeno de forma ascendente || 0 si los ordeno de forma descendente
 *
 */
int employee_CompareByName(Employee* e1, Employee* e2);

/** \brief Funcion que compara los empleados por ID por igualdad de nombres(en forma alfabetica) de forma descendente
 *
 * \param Employee* e1 puntero a estructura de empleados (empleado 1)
 * \param Employee* e2 puntero a estructura de empleados (empleado 2)
 * \return 1 si los ordeno de forma ascendente || 0 si los ordeno de forma descendente
 *
 */
int employee_CompareById(Employee* e1, Employee* e2);

#endif
