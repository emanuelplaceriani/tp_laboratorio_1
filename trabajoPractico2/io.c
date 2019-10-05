#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include "arrayEmployee.h"
#include "io.h"
#define TAM 3
#define TRUE 1
#define FALSE 0

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Empleados *******\n\n");
    printf("1-Alta Empleado\n");
    printf("2-Modificar Empleado\n");
    printf("3-Baja Empleado\n");
    printf("4-Informar\n");
    printf("5-Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int getString(char* msje,char* msjeError,char* string,int intentos)
{
    int retorno=-1;

    while(intentos>0)
     {
        char auxString[80];
        printf("%s",msje);
        fflush(stdin);
        gets(auxString);
        if(string!=NULL && es_letras(auxString)==0)
        {
            strcpy(string,auxString);
            retorno=0;
            break;
        }
        else
        {
            printf("%s",msjeError);
        }
        intentos--;
     }


    return retorno;
}


int getFloat(char* msje,char* msjeError,float* n,float max,float min,int intentos)
{
    int retorno=-1;
    char auxString[80];
    float auxFloat;

    printf("%s",msje);
    fflush(stdin);
    gets(auxString);

    if(es_float(auxString)==0)
    {
        auxFloat=(float)atof(auxString);
        if(auxFloat<=max && auxFloat>=min)
        {
            *n=auxFloat;
            retorno=0;
        }
        else
        {
            while(intentos>0)
            {
                intentos--;
                printf("\n%s",msjeError);
                printf("%s",msje);
                fflush(stdin);
                gets(auxString);
                auxFloat=(float)atof(auxString);
                if(auxFloat<=max && auxFloat>=min)
                {
                    *n=auxFloat;
                    retorno=0;
                    break;
                }
            }
            if(intentos==0)
                retorno=-1;
        }
    }
    else
    {
        while(intentos>0)
        {
            intentos--;
            printf("\n%s",msjeError);
            printf("%s",msje);
            fflush(stdin);
            gets(auxString);
            auxFloat=(float)atof(auxString);
            if(auxFloat<=max && auxFloat>=min)
            {
                *n=auxFloat;
                retorno=0;
                break;
            }
        }
        if(intentos==0)
         {
            retorno = -1;
         }
    }

    return retorno;
}

int es_float (char* n)
{
    int retorno=-1;
    int contPunto=0;
    int i=0;

    while(n[i]!='\0')
    {

     if(isdigit(n[i])&&contPunto==1)
     {
        retorno=0;
     }
     else if(n[i]==46)
     {
            contPunto++;
     }
     else
        retorno=-1;

       i++;
    }

    return retorno;
}


int getInt(char* msje,char* msjeError,int* n,int max,int min,int intentos)
{
    int retorno=-1;
    int i=0;
    char auxString[80];
    int auxInt;
    printf("%s",msje);
    fflush(stdin);
    gets(auxString);

    while(auxString[i]!= '\0')
    {
        while(auxString[i]<47 || auxString[i]>58)
        {
            intentos--;
            printf("\n%s",msjeError);
            printf("\n%s",msje);
            fflush(stdin);
            gets(auxString);

            if(intentos==0)
            {
                retorno=-1;
                break;
            }
        }
        if(auxString[i]>47 && auxString[i]<58)
        {
            auxInt=atoi(auxString);
            if(auxInt>=min && auxInt<=max)
            {
                *n = auxInt;
                retorno=0;
            }
            else
            {
                while(intentos>0)
                {
                    intentos--;
                    printf("%s",msjeError);
                    printf("\n%s",msje);
                    fflush(stdin);
                    gets(auxString);
                }
                 if(intentos==0)
                 {
                    retorno=-1;
                    break;
                 }
            }
        }
        i++;
    }

    return retorno;
}

int es_letras(char* s)
{
    int r=0;
    int i;
    int len=strlen(s);

    for(i=0;i<len;i++)
    {
        if(isalpha(s[i])!=0)
            i++;
        else
            r=-1;
    }

    return r;
}
