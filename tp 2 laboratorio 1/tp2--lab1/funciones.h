#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[40];
    int edad;
    int dni;
    int estado;

} ePersona;

void inicializar0 (ePersona[]);
/** \brief La funcion inicializa todos los estados de los usuario en 0.
 *  \param persona[20] anida el estado del usuario, siendo 1 para su alta o 0 para su baja.
 */


void validarTam (char[]);
/** \brief L fauncion valida que el tamaño del string ingresado no supere al del auxiliar.
 *  \param auxNombre[40] es el auxiliar donde se copia el string que se ingresa.
 */

void ordenar(ePersona[], ePersona[]);
/** \brief La funcion permite ordenar la base de datos alfabeticamente.
*   \param aux1[40] es el auxiliar donde se copia el string que se ingresa para ordenarlo.
*/


void nombreSinNum (char[]);
/** \brief La funcion valida que el string ingresado no contenga numeros.
 *  \param auxNombre[40] es el auxiliar donde se copia el string que se ingresa.
 */


void pasarMayus (char[]);
/** \brief La funcion pasa a mayuscula las iniciales del string.
 * \param auxNombre[40] es el auxiliar donde se el string que se ingresa.
 */


int verifBase (ePersona[]);
/** \brief La funcion verifica si la base de datos tiene usuarios ingresados previamente o no.
 *  \param aux[40] es el auxiliar que recibe a persona[20], para verificar si estan de alta o de baja.
 */
#endif // FUNCIONES_H_INCLUDED
