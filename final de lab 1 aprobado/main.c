#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "parser.h"
#include "numeroNatural.h"

int main()
{
    ArrayList* lista;
    ArrayList* repetida;
    int itsOkay;
    int itsOkay2;
    char seguir = 's';

    lista = al_newArrayList();
    repetida = al_newArrayList();
    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                itsOkay = parserNumero("datos.csv" ,lista);
                if(itsOkay != 0)
                {
                    printf("\nEl archivo o el array son null");
                    system("pause");
                }
                else
                {
                    mostrar(lista);
                    printf("El archivo cargo correctamente");
                    system("pause");
                }
                break;
            case 2:
                itsOkay = numero_esPar(lista);
                itsOkay2 = numero_esPrimo(lista);

                if(itsOkay2 == 0 && itsOkay == 0)
                {
                    mostrar(lista);
                    printf("Se cargaro bien los datos");
                    system("pause");
                }
                else
                {
                    printf("No se pudo cargar los datos");
                    system("pause");
                }
                break;
            case 3:
                repetida = numero_listaRepe(lista);
                if(repetida != NULL)
                {
                    mostrar(repetida);
                    system("pause");
                }
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir == 's');

    return 0;
}
