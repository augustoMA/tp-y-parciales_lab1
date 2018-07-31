#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayList.h"
#include "letra.h"
#include "parser.h"

eLetra* new_letras()
{
    eLetra* newLetra;

    newLetra = (eLetra*)malloc(sizeof(eLetra));

    return newLetra;
}

int menu()
{
    int numero;
    printf("1-Altas\n2-Completar\n3-Listar\n4-Generar\n5-Salir\n");
    scanf("%d",&numero);

    return numero;
}
int menu2()
{
    int numero;
    printf("1-Descendente\n2-Ascendente\n3-Salir\n");
    scanf("%d",&numero);

    return numero;
}

void mostrar(ArrayList* lista)
{
    eLetra* letra;
    int i;
    if(lista != NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            letra = (eLetra*) lista->get(lista,i);

            printf("%3d %2c %10s %2d %2d \n", i,letra->letra, letra->nombre, letra->vocal, letra->consonante);
        }

    }
}

int letra_isVocal(ArrayList* lista)
{
    eLetra* letra;
    int i,itsOkay,itsOkay2;
    int auxReturn = -1;

    if(lista != NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            letra = (eLetra*)lista->get(lista,i);

            if(!(itsOkay = isdigit(letra->letra)))
            {
                itsOkay2 = tolower(letra->letra);

                if(itsOkay2)
                {
                    if(letra->letra == 'a' || letra->letra == 'e' || letra->letra == 'i' || letra->letra == 'o' || letra->letra == 'u')
                    {
                        letra->vocal= 1;
                    }
                    else
                    {
                        letra->consonante = 1;
                    }

                    lista->set(lista,i,letra);
                }
            }
        }
        auxReturn = 0;
    }
    return auxReturn;
}

int letra_compare(void* letra1,void* letra2)
{
    int auxReturn = 0;
    eLetra* letraA;
    eLetra* letraB;

    letraA = (eLetra*) letra1;
    letraB = (eLetra*) letra2;

    if(letraA->letra > letraB->letra)
    {
        auxReturn = 1;
    }
    else
    {
        auxReturn = -1;
    }

    return auxReturn;
}

ArrayList* letra_noRepe(char cadena[], ArrayList* lista)
{
    ArrayList* new_array;
    new_array = al_newArrayList();
    int i,j,k;
    eLetra* letras;
    eLetra* letras2;
    cadena = strlwr(cadena);

    for(i=0 ; i< lista->len(lista); i++)
    {
        letras = (eLetra*) lista->get(lista,i);
        for(j=0; j<=strlen(cadena); j++)
        {

            if(!(isdigit(cadena[j])))
            {
                if(letras->letra != cadena[j])
                    {
                        if(new_array->contains(new_array,letras)!=0)
                        {
                            new_array->add(new_array,letras);
                        }
                    }

            }
        }
    }

    return new_array;
}
ArrayList* letra_repe(char cadena[], ArrayList* lista)
{
    ArrayList* new_array;
    new_array = al_newArrayList();
    int i,j;
    eLetra* letras;

    cadena = strlwr(cadena);
    for(i=0 ; i< lista->len(lista); i++)
    {
        letras = (eLetra*) lista->get(lista,i);
        for(j=0; j<strlen(cadena); j++)
        {

            if(!(isdigit(cadena[j])))
            {
                if(letras->letra == cadena[j])
                {
                    new_array->add(new_array,letras);
                }
            }
        }
    }

    return new_array;
}
