#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<limits.h>
#include "funciones.h"

int cargarPelicula(EMovie *peliculas, int* puntTOcont)
{
    int flag = 0;
    FILE *f;

    f=fopen("moviesBin.dat", "rb");

    if(f==NULL)
    {
        f= fopen("moviesBin.dat", "wb");

        if(f==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag==0)
    {
        fread(puntTOcont,sizeof(int),1,f);

        while(!feof(f))
        {
            fread(peliculas,sizeof(EMovie),*puntTOcont,f);
        }
    }
    fclose(f);

    return 0;
}

void mostrar(EMovie *peliculas)
{
    printf("Titulo :%s\nGenero: %s\nDuracion: %d Minutos\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n", peliculas->titulo, peliculas->genero, peliculas->duracion, peliculas->descripcion, peliculas->puntaje, peliculas->linkImagen);
}

void valString(char stringToVal[], int max)
{
    int largo=strlen(stringToVal);

    while(largo>max)
    {
        printf("Se excedio del tamano reingrese: ");
        stringToVal=gets(stringToVal);
        largo=strlen(stringToVal);
    }
}

int valNumero(int num,int min,int max)
{
    int valNum=num;

    while(valNum<min || valNum>max)
    {
        printf("Por favor reingrese: ");
        fflush(stdin);
        scanf("%d", &valNum);
    }
    return valNum;
}

void addPelicula(EMovie *peliculas,int contMovie,int* puntTOcont)
{
    int lugar;
    int i;
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[100];
    char linkImagen[200];
    int duracion;
    int puntaje;
    int lTitulo;
    int existe=0;

    lugar=contMovie-1;

    printf("Informacion a ser ingresada\n");

    printf("Ingrese el titulo: ");
    fflush(stdin);
    scanf("%s", auxTitulo);

    valString(auxTitulo,20);
    lTitulo=strlen(auxTitulo);

    for(i=0; i<lTitulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }
    for(i=0; i<contMovie; i++)/*Se verifica que no haya un titulo igual ya ingresado */
    {
        if(strcmp(auxTitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
        {
            existe=1;
            break;
        }
    }
    if(!existe)//si existe==0 entonces entra
    {
        strcpy((peliculas+lugar)->titulo,auxTitulo);

        printf("Ingrese genero: ");
        fflush(stdin);
        gets(auxGenero);
        valString(auxGenero,20);
        strcpy((peliculas+lugar)->genero,auxGenero);

        printf("Ingrese duracion(en minutos): ");
        fflush(stdin);
        scanf("%d",&duracion);
        duracion=valNumero(duracion,0,200);
        (peliculas+lugar)->duracion=duracion;

        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);
        valString(auxDescripcion,50);
        strcpy((peliculas+lugar)->descripcion,auxDescripcion);

        printf("Ingrese puntaje: ");
        fflush(stdin);
        scanf("%d",&puntaje);
        puntaje=valNumero(puntaje,1,10);
        (peliculas+lugar)->puntaje=puntaje;

        printf("Ingrese el link de la imagen: ");
        fflush(stdin);
        gets(linkImagen);
        valString(linkImagen,150);
        strcpy((peliculas+lugar)->linkImagen,linkImagen);
    }
    else
    {
        printf("El titulo ingresado ya existe!\n");
        *puntTOcont-=1;
    }
}

void deletePelicula(EMovie *peliculas,int contMovie)
{
    int flag=0;
    int i;
    char titulo[50];
    char opcion;
    int lTitulo;

    printf("\nListado de peliculas\n\n");

    for(i=0; i<contMovie; i++)
    {
        if((peliculas+i)->duracion!=0)
        {
            printf("%s\n",(peliculas+i)->titulo);
        }
    }
    printf("Ingrese la pelicula que desea eliminar: ");
    fflush(stdin);
    scanf("%s", titulo);

    valString(titulo,20);
    lTitulo=strlen(titulo);

    for(i=0; i<lTitulo; i++)
    {
        titulo[i]=toupper(titulo[i]);
    }
    for(i=0; i<contMovie; i++)
    {
        if(strcmp(titulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
        {
            printf("Pelicula a eliminar:\n");

            mostrar((peliculas + i));

            printf("\nSeguro desea eliminar la pelcula s/n?: ");
            opcion=getche();
            if(opcion=='s')
            {
                (peliculas+i)->duracion=0;
                printf("\nPelicula eliminada!\n");
            }
            else
            {
                printf("\nAccion cancelada!\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Uy!Pelicula no cargada\n");
    }
}

void modificarPelicula(EMovie *peliculas,int contMovie)
{
    int flag=0;
    int opcion;
    int lugar;
    int i;
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[100];
    char linkImagen[100];
    int duracion;
    int puntaje;
    int lTitulo;
    int existe=0;

    printf("Listado de peliculas\n\n");

    for(i=0; i<contMovie; i++)
    {
        if((peliculas+i)->duracion!=0)
        {
            printf("%s\n",(peliculas+i)->titulo);
        }
    }
    printf("Ingrese la pelicula a modificar: ");
    fflush(stdin);
    scanf("%s", auxTitulo);

    valString(auxTitulo,20);
    lTitulo=strlen(auxTitulo);

    for(i=0; i<lTitulo; i++)
    {
        auxTitulo[i]=toupper(auxTitulo[i]);
    }
    for(i=0; i<contMovie; i++)
    {
        if(strcmp(auxTitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
        {
            printf("Pelicula a modificar:\n");

            mostrar((peliculas + i));
            lugar=i;
            printf("\nElija el parametro a modificar?\n");
            printf("1- Titulo\n");
            printf("2- Genero\n");
            printf("3- Duracion(en minutos)\n");
            printf("4- Descripcion\n");
            printf("5- Puntaje\n");
            printf("6- Link a imagen\n");
            fflush(stdin);
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("Informacion a ser ingresada\n");
                printf("Ingrese el titulo: ");
                fflush(stdin);
                scanf("%s", auxTitulo);

                valString(auxTitulo,20);
                lTitulo=strlen(auxTitulo);
                for(i=0; i<lTitulo; i++)
                {
                    auxTitulo[i]=toupper(auxTitulo[i]);
                }
                /*Se verifica que no haya un titulo igual ya ingresado*/
                for(i=0; i<contMovie; i++)
                {
                    if(strcmp(auxTitulo,(peliculas+i)->titulo)==0 && (peliculas+i)->duracion!=0)
                    {
                        existe=1;
                        break;
                    }
                }
                if(!existe)//si existe==0 entonces entra
                {
                    strcpy((peliculas+lugar)->titulo,auxTitulo);
                    printf("Titulo modificado exitosamente!\n");
                }
                else
                {
                    printf("Uy!Titulo ingresado existente!\n");
                }
                break;
            case 2:
                printf("Ingrese el genero: ");
                fflush(stdin);
                gets(auxGenero);

                valString(auxGenero,20);
                strcpy((peliculas+lugar)->genero,auxGenero);

                printf("\nGenero modificado exitosamente!\n");
                break;
            case 3:
                printf("Ingrese la duracion en minutos: ");
                fflush(stdin);
                scanf("%d",&duracion);

                duracion=valNumero(duracion,0,400);
                (peliculas+lugar)->duracion=duracion;

                printf("\nDuracion modificada exitosamente!\n");
                break;
            case 4:
                printf("Ingrese la descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);

                valString(auxDescripcion,50);
                strcpy((peliculas+lugar)->descripcion,auxDescripcion);

                printf("\nDescripcion modificada exitosamente!\n");
                break;
            case 5:
                printf("Ingrese el puntaje: ");
                fflush(stdin);
                scanf("%d",&puntaje);

                puntaje=valNumero(puntaje,1,10);
                (peliculas+lugar)->puntaje=puntaje;

                printf("\nPuntaje modificado exitosamente!\n");
                break;
            case 6:
                printf("Ingrese el link de la imagen: ");
                fflush(stdin);
                gets(linkImagen);

                valString(linkImagen,50);
                strcpy((peliculas+lugar)->linkImagen,linkImagen);

                printf("\nLink modificado exitosamente!\n");
                break;
            default:
                printf("Uy!Opcion invalida\n");
                break;
            }

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Uy!Pelicula no cargada\n");
    }
}

int guardar(EMovie* peliculas,int contMovie,int* puntTOcont)
{

    FILE *f;

    f=fopen("moviesBin.dat","wb");

    if(f == NULL)
    {
        return 1;
    }
    fwrite(puntTOcont,sizeof(int),1,f);

    fwrite(peliculas,sizeof(EMovie),contMovie,f);

    fclose(f);

    return 0;
}

void newPagina(EMovie* peliculas, int contMovie, char nameHtml[])
{
    FILE *f;
    int i;

    strcat(nameHtml,".html");
    f=fopen(nameHtml,"w");

    if(f == NULL)
    {
        printf("Uy!El archivo no se pudo crear");
        exit(1);
    }

    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

    for(i=0; i<contMovie; i++)
    {
        if((peliculas+i)->duracion!=0)
        {
            fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(peliculas+i)->linkImagen);
            fprintf(f,"<h3><a href='#'>%s</a></h3>\n",(peliculas+i)->titulo);
            fprintf(f,"<ul><li>Genero:%s</li>\n<li>Puntaje:%d</li>\n<li>Duracion:%d</li></ul>\n",(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion);
            fprintf(f,"<p>%s</p></article>",(peliculas+i)->descripcion);
        }
    }

    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    fclose(f);
}

