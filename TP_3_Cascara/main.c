#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<limits.h>
#include "funciones.h"

int main()
{
    EMovie* peliculas;
    int contMovie=0;
    int* puntTOcont=&contMovie;
    char nameHtml[50]= {"listadoPeliculas"};
    char seguir='s';
    int opcion=0;
    int i;

    peliculas=(EMovie*)malloc(sizeof(EMovie)*100);

    if(peliculas==NULL)
    {
        printf("\n¡Uy!¡No hay espacio disponible!\n");
        exit(0);
    }

    for(i=0; i<contMovie; i++)
    {
        peliculas->duracion=0;
        peliculas->puntaje=0;
    }

    if(cargarPelicula(peliculas,puntTOcont))
    {
        printf("Uy!El fichero no puede abrirse!");
    }

    while(seguir=='s')
    {
        opcion=0;
        printf(":::MENU DE OPCIONES:::\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web y guardar archivo binario\n");
        printf("5- Salir\n");
        printf("-Seleccione la opcion deseada: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(contMovie%100==0)
                {
                    contMovie++;
                    EMovie* auxPeliculas;

                    auxPeliculas=(EMovie*)realloc(peliculas,100*sizeof(EMovie));

                    if(auxPeliculas==NULL)
                    {
                        exit(1);
                    }
                    else
                    {
                        peliculas=auxPeliculas;
                        addPelicula(peliculas,contMovie,puntTOcont);
                    }
                }
                else
                {
                    contMovie++;
                    addPelicula(peliculas,contMovie,puntTOcont);
                }
                break;
            case 2:
                deletePelicula(peliculas,contMovie);
                break;
            case 3:
                modificarPelicula(peliculas,contMovie);
                break;
            case 4:
                newPagina(peliculas,contMovie,nameHtml);
                printf("Se ha creado un archivo de tipo html llamado: %s",nameHtml);

                if(guardar(peliculas,contMovie,puntTOcont))
                {
                    printf("\nUy!El fichero no pudo abrirse\n");
                }
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida. Ingrese una opcion valida\n");
                break;
            }

            system("pause");
            system("cls");
        }
    return 0;
}
