#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployee.h"
#include "io.h"
#include <strings.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

int initEmployees(Employee* list, int len)
{
    int retorno=-1;
    int i;

    if(list != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;
        }
        retorno=0;
    }

    return retorno;
}

int findFreeSpace(Employee* list,int len)
{
    int retorno = -1;

    if(list != NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int addEmployee(Employee* list, int len, int id)
{
    int retorno=-1;
    int freeSpace=findFreeSpace(list,len);

    if(freeSpace!=-1)
    {
        system("cls");
        printf("**** ALTA de Empleado ****\n\n");
        if(getString("Ingrese nombre del empleado\n","ERROR - Dato invalido\n",list[freeSpace].name,2)==0)
        {
            system("cls");
            printf("\nNombre guardado correctamente\n\n\n");

            if(getString("Ingrese apellido del empleado\n","ERROR - Dato invalido\n",list[freeSpace].lastName,2)==0)
            {
                system("cls");
                printf("\nApellido guardado correctamente\n\n\n");

                if(getFloat("\nIngrese salario (con decimal) ","\nError - salario invalido\n",&list[freeSpace].salary,1000000,0,3)!=-1)
                {
                    system("cls");
                    printf("\nSalario guardado correctamente\n\n\n");

                    if(getInt("Ingrese sector\n","Error - Sector invalido\n",&list[freeSpace].sector,10,1,3)!=1)
                    {
                        list[freeSpace].id=id;
                        list[freeSpace].isEmpty=0;
                        system("cls");
                        printf("\n\nAlta exitosa\n");
                        retorno=0;
                    }
                    else
                    {
                        system("cls");
                        printf("\nAlta cancelada\n");
                        system("pause");
                        retorno=-1;
                    }
                }
                else
                {
                    system("cls");
                    printf("\nAlta cancelada\n");
                    system("pause");
                    retorno=-1;
                }

            }
            else
            {
               printf("Apellido no ingresado, ALTA cancelada");
               retorno=-1;
            }
        }
        else
        {
            printf("Nombre no ingresado, ALTA cancelada");
        }

    }

    return retorno;
}

void showEmployee(Employee x)
{
    printf(" ID:\t %d\nNOMBRE:\t    %s\nAPELLIDO: \t%s\nSALARIO\t    %.2f\nSECTOR\t     %d  \n\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}

int showEmployees(Employee* e,int len)
{
    int retorno=-1;
    int i;

    if(len>0)
    {
        for(i=0;i<len;i++)
        {
            if(e[i].isEmpty==0)
            {
                showEmployee(e[i]);
            }
        }
    }
    return retorno;
}

int modifyEmployee(Employee* e,int len)
{
    int retorno;
    int id;
    int indice;
    int opcion;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
    int seguir='s';

    system("cls");
    showEmployees(e,len);

    printf("Ingrese el ID del empleado a modificar");
    fflush(stdin);
    if(scanf("%d",&id)!=0)
    {
        indice=searchEmployeeById(id,e,len);

        if(indice!=-1)
        {
           do{
                system("cls");
                showEmployee(e[indice]);


                printf("Que dato desea modificar?\n");
                printf("1- nombre\n");
                printf("2- apellido\n");
                printf("3- Sector\n");
                printf("4- Salario\n");
                printf("5- Salir");
                scanf("%d",&opcion);

                switch(opcion)
                {
                    case 1:
                            if(getString("\nIngrese nuevo nombre\n","\n\nError, nombre invalido\n",auxNombre,2)==0)
                            {
                                strcpy(e[indice].name,auxNombre);

                                printf("\n\nModificacion exitosa");
                                retorno=0;
                                break;
                            }
                        else
                            retorno=-1;
                        break;
                    case 2:
                            if(getString("\nIngrese nuevo apellido\n","\n\nError, apellido invalido\n",auxApellido,2)==0)
                            {
                                strcpy(e[indice].lastName,auxApellido);
                                printf("\n\nModificacion exitosa");

                                retorno=0;
                                break;
                            }
                        else
                            retorno=-1;
                        break;
                    case 3:
                            if(getInt("\nIngrese nuevo Sector\n","\n\nError, sector invalido\n",&auxSector,1000,0,2)==0)
                            {
                                e[indice].salary=auxSalario;
                                printf("\n\nModificacion exitosa");

                                retorno=0;
                                break;
                            }
                            else
                                retorno=-1;
                            break;
                    case 4:
                            if(getFloat("\nIngrese nuevo Salario\n","\n\nError, salario invalido\n",&auxSalario,10000000,0,1)==0)
                            {
                                e[indice].sector=auxSector;
                                printf("\n\nModificacion exitosa");

                                retorno=0;
                                break;
                            }
                            else
                                retorno=-1;
                            break;
                    case 5:
                            seguir='n';
                            break;
                    default:
                        printf("Opcion invalida");
                        seguir='n';
                }
            system("pause");
           }while(seguir=='s');
        }
        else
        {
            printf("\nERROR - ID INEXISTENTE");
            system("pause");
            retorno=-1;
        }
    }


    if(retorno==-1)
    {
        system("cls");
        printf("NO SE REALIZO LA MODIFICACION");
    }
    return retorno;

}

int searchEmployeeById(int id, Employee* e,int len)
{
    int retorno = -1;
    int i;
    for( i=0; i < len; i++)
    {
        if( e[i].id == id && e[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
// ***********************************************************
int deleteEmployee(Employee* e,int len)
{
    int r;
    int indice;
    int id;
    int opcion;

    showEmployees(e,len);

    printf("\nIngrese el ID del empleado a Eliminar\n");
    fflush(stdin);
    if(scanf("%d",&id)!=0)
    {
        indice=searchEmployeeById(id,e,len);

        if(indice==-1)
        {
            printf("No se encontro empleado con ese ID");
            r=-1;
        }
        else
        {
            system("cls");
            showEmployee(e[indice]);
            printf("Confirma la eliminacion del empleado ?\n\n");
            printf("1- confirmar\n");
            printf("2- cancelar\n");
            scanf("%d",&opcion);
            if(opcion==1)
            {
                e[indice].isEmpty=1;
                r=0;
                system("cls");
                printf("BAJA REALIZADA");
                system("pause");

            }
            else
            {
                printf("\nSe ha cancelado la baja");
                r=-1;
            }
        }
     }
    return r;
}

int listEmployee(Employee* e,int tam)
{
    int r;
    int opcion;
    int seguir='s';

    do
    {
        //1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
        //2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
        system("cls");
        printf("••• MENU DE INFORMES •••\n\n");
        printf("1- Mostrar Listado de ordenados de Menor a mayor\n");
        printf("2- Mostrar Listado de ordenados de Mayor a menor\n");
        printf("3- Mostrar total y promedio de los salarios\n");
        printf("4- Mostrar empleado con salario mas alto\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            sortEmployee(e,tam,1);
            system("cls");
            showEmployees(e,tam);
            system("pause");
            break;
        case 2:
            sortEmployee(e,tam,2);
            system("cls");
            showEmployees(e,tam);
            system("pause");
            break;
        case 3:
            system("cls");
            showSalaries(e,tam);
            system("pause");
            break;
        case 4:
                break;
        case 5:
                seguir='n';
                break;
        default:
                printf("OPCION INVALIDA");
                r=-1;
                break;
        }
    }while(seguir=='s');

    return r;
}

int sortEmployee(Employee* e, int tam,int orden)
{
    int r=0;
    Employee aux;

    if(e!=NULL && tam>0)
    {
         if(orden == 1)
             {
                for(int i= 0; i < tam-1 ; i++)
                {
                    for(int j= i+1; j <tam; j++)
                    {
                        if( strcmp(e[i].lastName,e[j].lastName)>0)
                        {
                            aux = e[i];
                            e[i] = e[j];
                            e[j] = aux;
                        }
                        else if(strcmp(e[i].lastName,e[j].lastName)==0)
                        {
                            if(e[i].salary>e[j].salary)
                            {
                                aux = e[i];
                                e[i] = e[j];
                                e[j] = aux;
                            }//mayor a menos
                        }
                    }
                }
             }
             else if(orden == 2)
             {
                for(int i= 0; i < tam-1 ; i++)
                {
                    for(int j= i+1; j <tam; j++)
                    {
                        if( strcmp(e[i].lastName,e[j].lastName)<0)//mayor a menos
                        {
                            aux = e[i];
                            e[i] = e[j];
                            e[j] = aux;
                        }
                        else if(strcmp(e[i].lastName,e[j].lastName)==0)
                        {
                            if(e[i].salary<e[j].salary)
                            {
                                aux = e[i];
                                e[i] = e[j];
                                e[j] = aux;
                            }//mayor a menos
                        }
                    }
                }
             }
    }
    else
        r=-1;

    return r;

}

void showSalaries(Employee* e,int len)
{
    float totalSalarios=0;
    float promedioSalarios;
    int cantSalarios=0;
    int contSalarioAlto=0;

    for(int i=0;i<len;i++)
    {
        if(e[i].isEmpty == 0)
        {
            totalSalarios+=e[i].salary;
            cantSalarios++;
        }
    }

    promedioSalarios=totalSalarios/cantSalarios;

    for(int i=0;i<len;i++)
    {
        if(e[i].isEmpty == 0 && e[i].salary>promedioSalarios)
        {
            contSalarioAlto++;
        }
    }

    printf("\nEl promedio de salarios es %.2f",promedioSalarios);
    printf("\nEl total de salarios es %.2f",totalSalarios);
    printf("\nY %d empleados perciben un salario mayor al promedio",contSalarioAlto);
}

