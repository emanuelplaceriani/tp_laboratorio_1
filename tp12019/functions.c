#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void showMenu(float* a,float* b)
{
     system("cls");
     printf("\n1- Ingresar el 1er operando (A = %.2f)\n",*a);
     printf("2- Ingresar el 2do operando (B = %.2f)\n",*b);
     printf("3- Calcular todas las operaciones\n");
        printf("   a) Calcular la suma (%.2f+%.2f)\n",*a,*b);
        printf("   b) Calcular la resta (%.2f-%.2f)\n",*a,*b);
        printf("   c) Calcular la division (%.2f/%.2f)\n",*a,*b);
        printf("   d) Calcular la multiplicacion (%.2f*%.2f)\n",*a,*b);
        printf("   e) Calcular el factorial (%.2f!) y (%.2f!)\n\n",*a,*b);
     printf("4- Informar resultados\n");
     printf("5- Salir");
}


void getNumber(float* n)
{
    float aux;
    printf("Ingrese el Numero");
    scanf("%f",&aux);
    *n=aux;
}

float suma(float a, float b)
{
    float resultado = a+b;

    return resultado;
}

float resta(float a, float b)
{
    float resultado = a-b;

    return resultado;
}

float multiplicacion(float a, float b)
{
    float resultado = a*b;

    return resultado;
}

float division(float a, float b)
{
    float resultado = a/b;

    return resultado;
}

int factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}

void showResults(float suma,float resta,float multi,float divi,int f1,int f2,float* a, float* b)
{
        printf("   a) El resultado de %.2f+%.2f es: %.2f\n",*a,*b,suma); // agregar mascara y variable de resultado a c/u
        printf("   b) El resultado de %.2f-%.2f es: %.2f\n",*a,*b,resta);
        printf("   c) El resultado de %.2f*%.2f es: %.2f\n",*a,*b,multi);
        if(*b==0)
        printf("   d) \n***ERROR*** no se puede dividir por 0\n");
        else
        printf("   d) El resultado de %.2f/%.2f es: %.2f\n",*a,*b,divi);

        printf("   e) El factorial de (%.2f) es: %.2f y El factorial de (%.2f) es: %.2f\n\n",*a,*b,(float)f1,(float)f2);
}
