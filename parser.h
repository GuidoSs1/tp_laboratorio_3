/** \brief Funcion que parsea los datos del archivo data.csv (texto)
 *
 * \param FILE* puntero al archivo
 * \param LinkedList* puntero a la lista enlazada con el listado de empleados
 * \return 0 si pudo parsear los datos del archivo || -1 si hubo un error
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Funcion que parsea los datos del archivo data.csv (binario)
 *
 * \param FILE* puntero al archivo
 * \param LinkedList* puntero a la lista enlazada con el listado de empleados
 * \return 0 si pudo parsear los datos del archivo || -1 si hubo un error
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
