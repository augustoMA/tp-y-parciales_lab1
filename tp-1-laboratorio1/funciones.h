#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Solicita un numero, lo asigna a la letra por defecto y lo devuelve.
 *  \param Solicita la letra en la que se va a utilizar.
 *  \return Devuelve el numero ingresado por el scanf.
 */
float pedirNumero(char);


/** \brief Suma los valores ingresados y muestra el resultado.
 *  \param  Solicita un valor flotante que se deposita en N1.
 *  \param  Solicita un valor flotante que se deposita en N2.
 */
void suma(float,float);


/** \brief Resta los 2 valores cargados y muestra el resultado.
 *  \param  Solicita un valor flotante que se deposita en N1.
 *  \param  Solicita un valor flotante que se deposita en N2.
 */
void resta(float,float);


/** \brief Divide los 2 valores cargados, valida si el segundo valor es 0 y muestra el resultado.
 *  \param  Solicita un valor flotante que se deposita en N1.
 *  \param  Solicita un valor flotante que se deposita en N2.
 */
void dividir(float,float);


/** \brief Multiplica los 2 valores cargados y muestra el resultado.
 *  \param  Solicita un valor flotante que se deposita en N1.
 *  \param  Solicita un valor flotante que se deposita en N2.
 */
void multiplicar(float,float);


/** \brief Hace el factorial del valor N1 y lo muestra.
 *  \param  Solicita un valor flotante que se caega en N1.
 */
void factorial(float);


/** \brief Muestra los resultados de todas las operaciones realizadas.
 */
void mostrarTodo(float,float);


#endif // FUNCIONES_H_INCLUDED

