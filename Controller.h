/** \brief Funcion que permite cargar los datos del archivo en forma texto
 *
 * \param char* puntero al archivo(.csv)
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si cargo los datos correctamente || -1 si hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Funcion que permite cargar los datos del archivo en forma binaria
 *
 * \param char* puntero al archivo (.bin)
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si cargo los datos correctamente || -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Funcion que carga empleados en la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si cargo el empleado correctamente || -1 si hubo un error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Funcion que permite modificar los campos de un elemento en la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si pudo modificar los datos del elemento correctamente || -1 si hubo un error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Funcion que permite eliminar un elemento de la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si pudo eliminar el elemento de la lista correctamente || -1 si hubo un error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Funcion que permite listar los elementos de la lista y mostrarlos por pantalla
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si pudo mostrar los elementos de la lista correctamente || -1 si hubo un error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Funcion que permite ordenar los elementos de la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si pudo ordenar los elementos de la lista correctamente || -1 si hubo un error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Funcion que guarda los datos modificados de la lista en el archivo en forma texto
 *
 * \param char* puntero al archivo(.csv)
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si guardo los datos modificados correctamente || -1 si hubo un error
 * \return
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Funcion que guarda los datos modificados de la lista en el archivo en forma binaria
 *
 * \param char* puntero al archivo(.bin)
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si guardo los datos modificados correctamente || -1 si hubo un error
 * \return
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Funcion que asigna un ID autoincremental y unico a cada empleado cargado con exito
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return ID del empleado si funciono correctamente || -1 si hubo algun error o el puntero es nulo
 *
 */
int controller_ID(LinkedList* pArrayListEmployee);


