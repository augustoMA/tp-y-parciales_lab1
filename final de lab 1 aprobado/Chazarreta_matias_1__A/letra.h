
typedef struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
}eLetra;

eLetra* new_letras();

int menu();

int menu2();

void mostrar(ArrayList*);

int letra_isVocal(ArrayList*);

ArrayList* letra_repe(char [], ArrayList*);

ArrayList* letra_noRepe(char [], ArrayList*);

int letra_compare(void*,void*);
