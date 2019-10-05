#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployee.h"
#include "io.h"
#define TAM 1000
#define TRUE 1
#define FALSE 0

int main()
{
    int ultId=0;
    int contAlta=0;
    char salir='n';
    Employee empleados[TAM];
    initEmployees(empleados,TAM);//INICIALIZA EMPLEADO

    do
    {
        switch( menu())
        {
        case 1:
            if(addEmployee(empleados, TAM, ultId)==0)
              {
                ultId++;
                contAlta++;
              }
            break;

        case 2:
            if(contAlta)
            modifyEmployee(empleados,TAM);
            else
                printf("\nNo hay empleados dados de alta\n");
            break;

        case 3:
            if(contAlta)
                deleteEmployee(empleados,TAM);
            else
                printf("\nNo hay empleados dados de alta\n");

            break;

        case 4:
            if(contAlta)
                listEmployee(empleados,TAM);
            else
                printf("\nNo hay empleados dados de alta\n");

            break;

        case 5:
            salir='s';
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
            break;
        }
        system("pause");
    }
    while(salir == 'n');


    return 0;
}

