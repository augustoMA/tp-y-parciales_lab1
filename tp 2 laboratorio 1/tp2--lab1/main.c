#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define P 20

int main()
{
    ePersona persona[P];
    ePersona aux1[40];
    char opcion, auxNombre[40];
    char seguir = 's';
    int flag1 = 0, flag2 = 0, flag3;
    int respuesta, auxDni, cont18, cont19_35, cont35, edadMayor;

    setearA0(persona); //esta funcion inicializa estados a 0 para todas las personas.

    do
    {
        printf("Menu de opciones.\n");

        printf("\n1. Agregar una persona.\n");
        printf("2. Borrar una persona.\n");
        printf("3. Imprimir lista ordenada por nombre.\n");
        printf("4. Imprimir grafico de edades\n");

        printf("5. Salir.\n");
        printf("Elija una opcion: ");

        opcion = getch();

        switch(opcion)
        {
        case '1':
            flag1 = 0;
            for(int i = 0; i < 20; i++)
            {
                if(persona[i].estado == 0)
                {
                    printf("\n\nIngrese el nombre: ");
                    fflush(stdin);
                    gets(auxNombre);

                    validTam(auxNombre); //valida que el tamaño del nombre no sea demasiado largo.
                    nomSinNum(auxNombre); //valida que no haya numeros ingresados en el nombre.
                    toMayus(auxNombre); //convierte las iniciales a mayuscula.
                    strcpy(persona[i].nombre, auxNombre); //copia el auxiliar al array.

                    printf("\nIngrese la edad: ");
                    fflush(stdin);
                    scanf("%d", &persona[i].edad);

                    ordenar(persona,P);

                    printf("\nIngrese el D.N.I: ");
                    fflush(stdin);
                    scanf("%d", &persona[i].dni);

                    printf("\n\nCarga satisfactoria.\n\n");

                    persona[i].estado = 1;
                    flag1 = 1;

                    break;
                }
            }
            if(flag1 == 0)
            {
                printf("No hay espacio dispnible.!\n\n");
            }
            break;

        case '2':

            flag1 = 0;

            flag2 = verifBase(persona); //verifica si la BD tiene usuarios ingresados

            if(flag2 == 0) //si la funcion de arriba devuelve 0, significa que no hay usuarios ingresados
            {
                printf("\nNo hay datos ingresados.\n\n");
                break;
            }

            printf("\nIngrese el D.N.I de la persona que desea eliminar: ");
            fflush(stdin);
            scanf("%d", &auxDni);

            for(int i = 0; i < 20; i++)
            {
                if(persona[i].estado == 1  && auxDni == persona[i].dni)
                {
                    printf("\n%d--%s--%d\n", persona[i].dni, persona[i].nombre, persona[i].edad);

                    printf("\nEsta seguro de eliminar a la persona? s/n: \n");
                    respuesta = getch();

                    if(respuesta == 's')
                    {
                        persona[i].estado = 0;
                        printf("\nAccion completada con exito.!\n\n");
                    }
                    else
                    {
                        printf("\nAccion cancelada con exito.!\n\n");
                    }
                    flag1 = 1;
                    break;
                }
            }
            if(flag1 == 0)
            {
                printf("\nD.N.I inexistente\n\n");
            }
            break;

        case '3':

            flag2 = verifBase(persona); //verifica si la BD tiene usuarios ingresados

            if(flag2 == 0) //si la funcion de arriba devuelve 0, significa que no hay clientes ingresados
            {
                printf("\nNo hay datos ingresados previamente.\n\n");
                break;
            }

            ordenar(persona, P);
            for(int i = 0; i < 20; i++)
            {
                if(persona[i].estado == 1)
                {
                    printf("\nD.N.I--Nombre--Edad");
                    printf("\n%d--%s--%d\n\n", persona[i].dni, persona[i].nombre, persona[i].edad);
                }
            }
            break;

        case '4':

            flag2 = verifBase(persona); //verifica si la BD tiene usuarios ingresados

            if(flag2 == 0) //si la funcion de arriba devuelve 0, significa que no hay clientes ingresados
            {
                printf("\nNo hay datos ingresados previamente.\n\n");
                break;
            }
            cont18 = 0;
            cont35 = 0;
            cont19_35 = 0;

            for(int i = 0; i < 20; i++)
            {
                if(persona[i].edad < 19 && persona[i].estado == 1)
                {
                    cont18++;
                }
                else if(persona[i].edad > 35 && persona[i].estado == 1)
                {
                    cont35++;
                }
                else if(persona[i].edad > 18 && persona[i].edad < 36 && persona[i].estado == 1)
                {
                    cont19_35++;
                }
            }
            system("cls"); //limpìa pantalla para que el grafico se vea mejor

            if(cont18 >= cont19_35 && cont18 >= cont35)
            {
                edadMayor = cont18;
            }
            else
            {
                if(cont19_35 >= cont18 && cont19_35 >= cont35)
                {
                    edadMayor = cont19_35;
                }
                else
                {
                    edadMayor = cont35;
                }
            }
            for(int i = edadMayor; i > 0; i--)
            {
                if(i <= cont18)
                {
                    printf("[]");
                }
                if(i <= cont19_35)
                {
                    flag3 = 1;
                    printf("\t[]");
                }
                if(i <= cont35)
                {
                    if( flag3 == 0)
                    {
                        printf("\t\t[]");
                    }
                    if(flag3 == 1)
                    {
                        printf("\t[]");
                    }
                }
                printf("\n");
            }
            printf("<18\t19-35\t>35\n");
            printf("\n\nPresione una tecla para regresar al menu principal...\n");

            getch();
            system("cls");
            break;

        case '5':
            seguir = 'n';
            break;

        default:
            printf("\n\nOpcion invalida. Presione una tecla para reintentar\n");
            getch();
            system("cls");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
