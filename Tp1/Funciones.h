#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief da la opcion al usuario de ingresar un numero.
 *
 * \param variable donde se asignara el numero.
 * \return el numero que ingreso el usuario.
 *
 */

int tomarNumero();

/** \brief suma dos numeros
 *
 * \param a primer numero a sumar
 * \param b segundo numero a sumar
 * \return a y b sumados
 *
 */
int sumar (int a,int b);

/** \brief resta dos numeros
 *
 * \param a Numero a restar
 * \param b Numero que resta
 * \return a restado por b
 *
 */
int restar (int a,int b);

/** \brief divide dos numeros
 *
 * \param a dividendo
 * \param b divisor que no es 0
 * \return a dividido por b
 *
 */
float dividir (int a,int b);

/** \brief multiplica dos numeros
 *
 * \param a primer numero a multiplicar
 * \param b segundo numero a multiplicar
 * \return a y b multiplicados
 *
 */
int multiplicar (int a,int b);

/** \brief calcula el factorial de un numero
 *
 * \param a Numero a factoriar
 * \return factorial de a
 *
 */
long double factorial (int a);

#endif // FUNCIONES_H_INCLUDED
