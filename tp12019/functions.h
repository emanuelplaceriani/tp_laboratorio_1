#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

/** \brief Imprime el menu de opciones
 *
 * \param float* El puntero a el primer operando
 * \param float* El puntero a el segundo operando
 * \return void
 *
 */
void showMenu(float*,float*);

/** \brief Pide y obtiene un numero ingresado por el usuario
 *
 * \param Puntero a la variable donde gaurdo el numero
 * \return void
 *
 */
void getNumber(float*);

/** \brief Realiza una suma entre dos variables
 *
 * \param primer variable (operando 1)
 * \param segunda variable (operando 2)
 * \return El resultado de la suma
 *
 */
float suma(float,float);

/** \brief Realiza una resta entre dos variables
 *
 * \param primer variable (operando 1)
 * \param segunda variable (operando 2)
 * \return El resultado de la resta
 *
 */
float resta(float,float);

/** \brief Realiza una multiplicacion entre dos variables
 *
 * \param primer variable (operando 1)
 * \param segunda variable (operando 2)
 * \return El resultado de la multiplicación
 *
 */
float multiplicacion(float,float);

/** \brief Realiza una division entre dos variables
 *
 * \param primer variable (operando 1)
 * \param segunda variable (operando 2)
 * \return El resultado de la division
 *
 */
float division(float,float);

/** \brief Realiza el factorial de un numero
 *
 * \param numero para realizar la operacion
 * \return El resultado del factorial
 *
 */
int factorial(int);

/** \brief Imprime los resultados de las operaciones realizadas anteriormente
 *
 * \param variable con el resultado de la suma
 * \param variable con el resultado de la resta
 * \param variable con el resultado de la multiplicacion
 * \param variable con el resultado de la division
 * \param variable con el resultado del factorial del operando 1
 * \param variable con el resultado del factorial del operando 2
 * \param puntero a la variable del primer numero ingresado
 * \param puntero a la variable del segundo numero ingresado
 * \return void
 *
 */

void showResults(float suma,float resta,float multi,float divi,int f1,int f2,float* a, float* b);

#endif // _FUNCIONES_H
