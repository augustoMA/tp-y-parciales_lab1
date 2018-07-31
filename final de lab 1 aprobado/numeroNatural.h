#include "ArrayList.h"
typedef struct
{
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;

}eNumeroNatural;

eNumeroNatural* new_numeroNatural();

int menu();

void mostrar(ArrayList* );

int numero_esPar(ArrayList* );

int numero_esPrimo(ArrayList*);

int numero_ordenar(ArrayList*);

ArrayList* numero_listaRepe(ArrayList*);
