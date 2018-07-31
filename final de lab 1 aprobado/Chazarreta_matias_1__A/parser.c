#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "letra.h"
#include "parser.h"

int parserLetra(char* fileName, ArrayList* pArray)
{
    char auxLetra[2];
    char auxNombre[21];
    char auxVocal[10];
    char auxConsonante[10];
    FILE* pArch;
    int cant;
    int auxReturn = -1;

    pArch = fopen(fileName,"r");
    eLetra* letra;

    if(pArch != NULL && pArray != NULL)
    {
        cant = fscanf(pArch, "%[^,],%[^,],%[^,],%[^\n]\n", auxLetra, auxNombre, auxVocal, auxConsonante);

        while(!feof(pArch))
        {
            letra = new_letras();
            if(letra != NULL)
            {
                cant = fscanf(pArch, "%[^,],%[^,],%[^,],%[^\n]\n", auxLetra, auxNombre, auxVocal, auxConsonante);

                if(cant != 5)
                {
                    if(feof(pArch))
                    {
                        break;
                    }
                }


                letra->letra = auxLetra[0];
                strcpy(letra->nombre, auxNombre);
                letra->vocal = atoi(auxVocal);
                letra->consonante = atoi(auxConsonante);

                pArray->add(pArray, letra);

            }

        }
        auxReturn = 0;
    }

    fclose(pArch);
    return auxReturn;
}
