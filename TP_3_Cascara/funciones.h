#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[150];
} EMovie;

/** \brief Carga las peliculas y recibe la cantidad de peliculas guardadas.
 * \param EMovie* peliculas
 * \return retorna 0 si leyo o creo el archivo, o 1 si no pudo.
 */
int cargarPelicula(EMovie *peliculas,int*);

/** \brief recibe un string y el parametro para validarlo.
 * \param char stringToVal[].
 * \param int maximo length.
 * \return void.
 */
void valString(char stringAValid[], int);

/** \brief recibe un numero y dos parametros para validarlo.
 * \param int numero a validar.
 * \param int minimo.
 * \param int maximo.
 * \return retorna el numero validado.
 */
int valNumero(int,int,int );

/** \brief crea una pelicula, recibe un contador y dos punteros.
 * \param EMovie* peliculas.
 * \param int contador.
 * \param int* puntero a contador.
 * \return void.
 */
void addPelicula(EMovie *peliculas,int,int*);

/** \brief busca una pelicula por su titulo, pasa la duracion a cero si el usuario lo desea, recibe y un contador.
 * \param EMovie* peliculas.
 * \return void.
 */
void deletePelicula(EMovie *peliculas,int);

/** \brief crea un archivo html a partir de las peliculas cargadas.
 *  \param lista de peliculas para agregar al archivo.
 *  \param contador.
 *  \param el nombre del archivo.
 *  \return void.
 */
void newPagina(EMovie* peliculas, int, char nombreHtml[]);

/** \brief muestra las peliculas y permite modificar sus parametros, recibe un puntero y un contador.
 * \param EMovie* peliculas.
 * \param int contador.
 * \return void.
 */
void modificarPelicula(EMovie* peliculas,int);

/** \brief guarda los datos ingresados, recibe dos punteros y un contador.
 * \param EMovie* peliculas.
 * \param int contador.
 * \param int* puntero al contador.
 * \return int.
 */
int guardar(EMovie* peliculas,int,int*);

#endif // FUNCIONES_H_INCLUDED
