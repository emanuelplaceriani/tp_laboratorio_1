#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
   int opcion;
   float numero1=0,numero2=0,rSuma,rResta,rMulti,rDivi;
   int rFactorial1,rFactorial2;
   char seguir='s';

   do{

      showMenu(&numero1,&numero2);// funcion que muestra el menu
      scanf("%d",&opcion);

      switch(opcion)
      {
        case 1:
            getNumber(&numero1);
            break;

        case 2:
            getNumber(&numero2);
            break;

        case 3:
            rSuma=suma(numero1,numero2);
            rResta=resta(numero1,numero2);
            rMulti=multiplicacion(numero1,numero2);
            rDivi=division(numero1,numero2);
            rFactorial1=factorial(numero1);
            rFactorial2=factorial(numero2);
            system("cls");
            printf("\nOperaciones calculadas\n\n");
            system("pause");
            break;

        case 4:

            system("cls");
            printf("\nResultados: ...\n");
            showResults(rSuma,rResta,rMulti,rDivi,rFactorial1,rFactorial2,&numero1,&numero2);
            system("pause");
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("Opcion no valida");
            seguir='n';
      }

      }while(seguir=='s'|| seguir == 'S');
    return 0;
}
