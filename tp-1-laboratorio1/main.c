#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    float numeroN1;
    float numeroN2;
    int flagN1 = 0;
    int flagN2 = 0;

    do
    {
        if(flagN1 == 0)
        {
        printf("1- Ingresar primer valor numerico para N1 \n");
        }
        else
        {
        printf("1- Ingresar primer valor numerico (N1=%.1f)\n",numeroN1);
        }
        if(flagN2 == 0)
        {
            printf("2- Ingresar segundo valor numerico para N2 \n");
        }
        else
        {
            printf("2- Ingresar segundo valor numerico (N2=%.1f)\n",numeroN2);
        }

        printf("3- Calcular la suma (N1+N2)\n");

        printf("4- Calcular la resta (N1-N2)\n");

        printf("5- Calcular la division (N1/N2)\n");

        printf("6- Calcular la multiplicacion (N1*N2)\n");

        printf("7- Calcular el factorial (N1!)\n");

        printf("8- Calcular todas las operaciones.\n");

        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                numeroN1 = pedirNumero('N1');
                flagN1 = 1;
                break;

            case 2:

                numeroN2 = pedirNumero('N2');
                flagN2 = 1;
                break;

            case 3:

                if(flagN1 == 0 || flagN2 == 0)
                {
                    printf("La suma no se puede realizar, debe cargar valores.");
                }
                else
                {
                   suma(numeroN1,numeroN2);
                }
                break;

            case 4:

                if(flagN1 == 0 || flagN2 == 0)
                {
                    printf("La resta no se puede realizar, debe cargar valores.");
                }
                else
                {
                    resta(numeroN1,numeroN2);
                }
                break;

            case 5:

                if(flagN1 == 0 || flagN2 == 0)
                {
                    printf("La division no se puede realizar, debe cargar valores.");
                }
                else
                {
                    dividir(numeroN1,numeroN2);
                }
                break;

            case 6:

                if(flagN1 == 0 || flagN2 == 0)
                {
                    printf("La multiplicacion no se puede realizar, debe cargar valores.");
                }
                else
                {
                    multiplicar(numeroN1,numeroN2);
                }
                break;

            case 7:

                if(flagN1 == 0)
                {
                    printf("El factorial no puede realizar, debe cargar un valor.");
                }
                else
                {
                    factorial(numeroN1);
                }
                break;

            case 8:

                if(flagN1==0 || flagN2==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                    mostrarTodo(numeroN1,numeroN2);
                }
                break;

            case 9:

                seguir = 'n';
                break;
            default:

                printf("Error, reingrese una opcion numerica valida (1-9)");
                break;
        }
        getch();
        system("cls");

    }while(seguir == 's');

 return 0;
}


