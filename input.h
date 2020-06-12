/** \brief Funcion que toma un entero entre el minimo y el maximo asignado en los parametros
 *
 * \param char[] mensaje para pedir el dato
 * \param char[] mensaje de error si el dato sobre pasa los limites
 * \param int minimo asignado para el dato
 * \param int maximo asignado para el dato
 * \return el dato si se ingreso correctamente || -1 si hubo algun error
 *
 */
int getInt(char mensaje[], char mError[], int min, int max);

/** \brief Funcion que toma un dato flotante
 *
 * \param char[] mensaje para pedir el dato
 * \return el dato ingresado || -1 si hubo algun error
 *
 */
float getFloat(char mensaje[]);

/** \brief Funcion que toma un caracter
 *
 * \param char[] mensaje para pedir el dato
 * \return retorna el dato ingresado
 *
 */
char getChar(char mensaje[]);

void getStr(char [], char []);

/***** Validaciones *****/

/** \brief Funcion que valida que los datos ingresados sean solo letras
 *
 * \param char[] string que vaya a ser validado
 * \return 0 si son todo letras || -1 si no son todas letras
 *
 */
int onlyLetters(char []);


int getStrLetters(char [], char []);

/** \brief Funcion que toma una cadena de datos y valida que sean numeros enteros y positivos
 *
 * \param char[] cadena de datos a ser validada
 * \return 0 si la cadena esta compuesta por numeros enteros y positivos || -1 si no solo son numeros
 *
 */
int onlyPNumbers(char []);
