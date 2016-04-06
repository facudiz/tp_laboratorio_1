#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <windows.h>

int main()
{

    int opcion=0;
    int numero1=0;
    int numero2=0;
    int flag=0, flag2=0;


    do //Comienzo del do while
        {
        printf("1- Ingresar 1er operando (A=%d)\n",numero1);
        printf("2- Ingresar 2do operando (B=%d)\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion) //Comienzo del switch
        {
            case 1:numero1= pedirNumero();//llamada a la funcion pedirNumero
                flag=1;
                system("cls");
                break;
            case 2:numero2= pedirNumero();//llamada a la funcion pedirNumero
                flag2=1;
                system("cls");
                break;
            case 3:
                if(flag==1&&flag2==1)
                {
                    suma(numero1,numero2);//llamada a la funcion suma
                }
                else
                {
                    printf("Falto el ingreso de uno o dos operando\n\n");
                }
                system("pause");
                system("cls");
                 break;
            case 4:
                if(flag==1 && flag2==1)
                {
                    resta(numero1,numero2);//llamada a la funcion resta
                }
                else
                {
                    printf("Falto el ingreso de uno o dos operando\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                if(flag==1 && flag2==1)
                {
                    division(numero1,numero2);//llamada a la funcion division
                }
                else
                {
                    printf("Falto el ingreso de uno o dos operando\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 6:
                if(flag==1 && flag2==1)
                {
                multiplicacion(numero1,numero2);//llamada a la funcion multiplicacion
                }
                else
                {
                    printf("Falto el ingreso de uno o dos operando\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 7:
                if(flag==1 && flag2==1)
                {
                factorial(numero1,numero2);//llamada a la funcion factorial
                }
                else
                {
                    printf("Falto el ingreso de uno o dos operando\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 8:
                if(flag==1 && flag2==1)
                {
                    suma(numero1,numero2); //llamada a todas las funciones
                    resta(numero1,numero2);
                    division(numero1,numero2);
                    multiplicacion(numero1,numero2);
                    factorial(numero1,numero2);
                }
                else
                {
                    printf("Falto el ingreso de uno o dos operando\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 9:
                break;
        }//fin del switch

        }while(opcion!=9);//fin del do while

    system("pause");
    return 0;


}
