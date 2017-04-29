#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void setearA0(ePersona persona[20])
{
    for (int i = 0; i < 20; i++)
    {
        persona[i].estado = 0;
    }
}
void ordenar(ePersona persona[], ePersona aux1[])
{
    int i;
    int j;
     for(int i = 0; i < 19; i++) //ordena base de datos alfabeticamente.
                    {
                        for(int j = i + 1; j < 19; j++)
                        {

                            if(strcmp(persona[i].nombre, persona[j].nombre) == 1 && persona[i].estado == 1 && persona[j].estado == 1)
                            {
                                strcpy(&aux1[i], persona[i].nombre); //intercambia los nombres
                                strcpy(persona[i].nombre, persona[j].nombre);
                                strcpy(persona[j].nombre, &aux1[i]);

                                strcpy(&aux1[i], &persona[i].edad); //intercambia las edades
                                strcpy(&persona[i].edad, &persona[j].edad);
                                strcpy(&persona[j].edad, &aux1[i]);

                                strcpy(&aux1[i], &persona[i].dni); //intercambia los DNI
                                strcpy(&persona[i].dni, &persona[j].dni);
                                strcpy(&persona[j].dni, &aux1[i]);

                                strcpy(&aux1[i], &persona[i].estado); //intercambia los estados
                                strcpy(&persona[i].estado, &persona[j].estado);
                                strcpy(&persona[j].estado, &aux1[i]);
                            }
                        }
                    }
}
void validTam (char auxNombre[40])
{
    while(strlen(auxNombre) > 50)
    {
        system("cls");
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);
    }
}
void nomSinNum (char auxNombre[40])
{
    int flag = 0;
    while(flag == 0)
    {
        for(int i = 0; i < 20; i++)
        {
            if(isdigit(auxNombre[i]) == 0)
            {
                flag = 1;
            }
            else
            {
                printf("Error. Ingrese unicamente letras. Reingrese el nombre: ");
                fflush(stdin);
                gets(auxNombre);
                flag = 0;
                break;
            }
        }
    }
    flag = 0;
}
void toMayus (char auxNombre[40])
{
    strlwr(auxNombre);
    auxNombre[0] = toupper(auxNombre[0]);

    for (int i = 0; i < strlen(auxNombre); i++)
    {
        if(auxNombre[i] == ' ')
        {
            auxNombre[i + 1] = toupper(auxNombre[i + 1]);
        }
    }
}
int verifBase (ePersona aux[])
{
    int flag;

    for(int i = 0; i < 20; i++)
    {
        if(aux[i].estado == 0)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
