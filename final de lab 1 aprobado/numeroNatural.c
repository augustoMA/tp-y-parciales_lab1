#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeroNatural.h"
#include "ArrayList.h"
eNumeroNatural* new_numeroNatural()
{
    eNumeroNatural* nuevoNumero;

    nuevoNumero = (eNumeroNatural*)malloc(sizeof(eNumeroNatural));

    return nuevoNumero;
}

int menu()
{
    int numero;
    printf("1-Altas\n2-Completar\n3-Listar\n4-Generar\n5-Salir\n");
    scanf("%d",&numero);

    return numero;
}
void mostrar(ArrayList* lista)
{
    eNumeroNatural* numero;
    int i;
    if(lista != NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            numero = (eNumeroNatural*) lista->get(lista,i);

            printf("%2d %2d %20s %2d %2d %2d \n", i,numero->numero, numero->nombre, numero->par, numero->impar,numero->primo);
        }

    }
}

int numero_esPar(ArrayList* lista)
{
    eNumeroNatural* numero;
    int i,okay;
    int auxReturn = -1;

    if(lista != NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            numero = (eNumeroNatural*)lista->get(lista,i);

            okay = numero->numero % 2;

            if(okay != 0)
            {
                numero->impar = 1;
            }
            else
            {
                numero->par = 1;
            }

            lista->set(lista,i,numero);
        }
        auxReturn = 0;
    }
    return auxReturn;
}

int numero_esPrimo(ArrayList* lista)
{
    eNumeroNatural* numero;
    int i;
    int okay = 0;
    int okay2 = 0;
    int okay3 = 0;
    int auxReturn = -1;

    if(lista != NULL)
    {
        for(i=0; i<lista->len(lista); i++)
        {
            numero = (eNumeroNatural*)lista->get(lista,i);

            okay = numero->numero % 2;
            okay2 = numero->numero % 3;
            okay3 = numero->numero % 5;

            if(okay != 0 && okay2 != 0 && okay3 != 0)
            {
                numero->primo = 1;
            }
            okay =0 ;
            okay2 = 0;
            okay3 = 0;
            lista->set(lista,i,numero);
        }
        auxReturn = 0;
    }
    return auxReturn;
}

ArrayList* numero_listaRepe(ArrayList* lista)
{
    ArrayList* auxRepe;

    ArrayList* clone = lista->clone(lista);
    auxRepe = al_newArrayList();

    eNumeroNatural* numero;
    eNumeroNatural* numero2;

    int i;

    for(i=0; i< clone->len(clone); i++)
    {
        numero = (eNumeroNatural*) clone->get(clone,i);
        numero2 = (eNumeroNatural*) clone->pop(clone,i);

        if(clone->contains(clone,numero) == 1)
        {
            clone
        }
    }
    return auxRepe;
}

