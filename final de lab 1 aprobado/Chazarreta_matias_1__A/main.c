#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "letra.h"
#include "parser.h"

int main()
{
    ArrayList* lista;
    ArrayList* descendente;
    ArrayList* ascendente;
    char cadena[51];
    int itsOkay;
    int flag = 0;
    char seguir = 's';
    char seguir2 = 's';

    lista = al_newArrayList();
    do
    {
        system("cls");

        switch(menu())
        {
        case 1:
            itsOkay = parserLetra("datos.csv",lista);
            if(itsOkay != 0)
            {
                printf("\nEl archivo o el array son null\n");
                system("pause");
            }
            else
            {
                mostrar(lista);
                printf("El archivo cargo correctamente\n");
                flag = 1;
                system("pause");
            }
            break;
        case 2:
            if(flag)
            {
                itsOkay = letra_isVocal(lista);
                if(itsOkay == 0)
                {
                    mostrar(lista);
                    printf("Se cargaro bien los datos\n");
                    system("pause");
                }
                else
                {
                    printf("No se pudo cargar los datos\n");
                    system("pause");
                }
            }
            break;
        case 3:
            if(flag)
            {
                printf("Ingrese cadena:");
                fflush(stdin);
                scanf("%s",cadena);
                do
                {
                    system("cls");
                    switch(menu2())
                    {
                    case 1:
                        descendente = letra_repe(cadena,lista);

                        if(descendente != NULL)
                        {
                            descendente->sort(descendente,letra_compare,0);
                            mostrar(descendente);
                            system("pause");
                        }
                        break;

                    case 2:
                        ascendente = letra_noRepe(cadena,lista);

                        if(ascendente != NULL)
                        {
                            ascendente->sort(ascendente,letra_compare,1);
                            mostrar(ascendente);
                            system("pause");
                        }
                        break;

                    case 3:
                        seguir2 = 'n';
                        break;
                    }
                }while(seguir2 == 's');
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
