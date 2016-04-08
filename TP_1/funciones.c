#include <stdio.h>
#include <stdlib.h>

/** \brief función que pide un numero y lo devuelve
 *
 * \return retorna el numero
 *
 */

int pedirNumero()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    return numero;
}
/** \brief  se suma dos numeros
 *
 * \param "a" es el primer numero a sumar
 * \param "b" es el segundo numero a sumar
 *
 */

void suma(int a, int b)
{
   int suma;
    suma= a+b;
    printf("el resultado de la suma es: %d\n\n",suma);
}

/** \brief Se restan dos numeros
 *
 * \param "a" primer numero para la resta
 * \param "b" segundo numero para la resta
 *
 */

void resta(int a, int b)
{
   int resta;
    resta= a-b;
    printf("el resultado de la resta es: %d\n\n",resta);
}

/** \brief Se multiplican dos numeros
 *
 * \param "a" primer numero para la multiplicacion
 * \param "b" segundo numero para la multiplicacion
 *
 */

void multiplicacion(int a, int b)
{
   int multiplicacion;
    multiplicacion= a*b;
    printf("el resultado de la multiplicacion es: %d\n\n",multiplicacion);

}
/** \brief Se dividen dos numeros
 *
 * \param "a" primer numero para la division
 * \param "b" segundo numero para la division
 *
 */

void division(float a, float b)
{
   float division;
   if(a==0||b==0)
   {
    printf("No es posible realizar la division entre 0 \n\n");
   }
   else
   {
    division= a/b;
    printf("el resultado de la division es: %f\n\n",division);
    }


}
/** \brief Saca el factorial de dos numeros
 *
 * \param "a" el primer numero a sacar el factorial
 * \param "b" el segundo numero a sacar el factorial
 *
 */

void factorial(int a, int b)
{
int i;
int fact=1;
int fact2=1;

    for(i=1;i<=a;i++)
        {
        fact= fact*i;
        }

printf("el resultado del Factorial del numero 1 es: %d\n\n",fact);

    for(i=1;i<=b;i++)
        {
        fact2= fact2 * i;
        }
        printf("el resultado del Factorial del numero 2 es: %d\n\n",fact2);


}
