#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "numeroNatural.h"

int parserNumero(char* fileName, ArrayList* pArray)
{
    char auxInt[10];
    char auxNombre[51];
    char auxPar[10];
    char auxImpar[10];
    char auxPrimo[10];
    FILE* pArch;
    int cant;
    int auxReturn = -1;

    pArch = fopen(fileName,"r");
    eNumeroNatural* nuevoNumero;

    if(pArch != NULL && pArray != NULL)
    {
        cant = fscanf(pArch, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxInt, auxNombre, auxPar, auxImpar, auxPrimo);

        while(!feof(pArch))
        {
            nuevoNumero = new_numeroNatural();
            if(nuevoNumero != NULL)
            {
                cant = fscanf(pArch, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxInt, auxNombre, auxPar, auxImpar, auxPrimo);

                if(cant != 5)
                {
                    if(feof(pArch))
                    {
                        break;
                    }
                }


                nuevoNumero->numero = atoi(auxInt);
                strcpy(nuevoNumero->nombre, auxNombre);
                nuevoNumero->par = atoi(auxPar);
                nuevoNumero->impar = atoi(auxImpar);
                nuevoNumero->primo = atoi(auxPrimo);

                pArray->add(pArray, nuevoNumero);

            }

        }
        auxReturn = 0;
    }

    fclose(pArch);
    return auxReturn;
}
