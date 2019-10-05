
/** \brief pide un dato y valida si lo ingresado es de solo letras
 *
 * \param mensaje a mostrar
 * \param mensaje de error
 * \param string a cargar lo ingresado por el usuario
 * \param cantidad de intentos para ingresar bien el dato
 * \return 0 si se ingreso bien el dato / -1 si no
 *
 */
int getString(char* msje,char* msjeError,char* string,int intentos);

/** \brief pide un dato y valida si lo ingresado es float
 *
 * \param mensaje a mostrar
 * \param mensaje de error
 * \param variable a cargar lo ingresado por el usuario
 * \param numero maximo permitido
 * \param numero minimo permitido
 * \param cantidad de intentos para ingresar bien el dato
 * \return 0 si se ingreso bien el dato / -1 si no
 *
 */
int getFloat(char* msje,char* msjeError,float* n,float max,float min,int intentos);

/** \brief valida si un string es float
 *
 * \param string a validar
 * \return 0 si es / -1 si no es
 *
 */
int es_float (char* n);

/** \brief pide un dato y valida si lo ingresado es int
 *
 * \param mensaje a mostrar
 * \param mensaje de error
 * \param variable a cargar lo ingresado por el usuario
 * \param numero maximo permitido
 * \param numero minimo permitido
 * \param cantidad de intentos para ingresar bien el dato
 * \return 0 si se ingreso bien el dato / -1 si no
 *
 */
int getInt(char* msje,char* msjeError,int* n,int max,int min,int intentos);

/** \brief valida si un string es solo letras
 *
 * \param string a validar
 * \return 0 si es / -1 si no es
 *
 */
int es_letras(char* s);

/** \brief muestra un menu de opciones, toma el numero elegido y devuelve
 *
 * \return el numero cargado por el usuario
 *
 */

int menu(void);
