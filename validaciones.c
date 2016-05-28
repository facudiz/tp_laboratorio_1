#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/** \brief Solicita un numero flotante al usuario
 *
 * \param input array donde se cargara el numero flotante
 * \param message recibe un mensaje para mostrar
 * \param eMessage recibe un mensaje de error para mostrar
 * \param lowLimit limite mas bajo para el numero
 * \param hilimit limite mas alto para el numero
 * \return retorna [0] en caso de que se ingrese bien o [-1] en caso de que se ingrese mal
 *
 */
int getFloat(float input[],char message[], char eMessage[], float lowLimit, float hiLimit)

{
    int respuesta=-1;
    float aux;
    int scanfOk;
    puts(message);
    scanfOk=scanf("%f",&aux);

    if(scanfOk)
    {
        if(aux<lowLimit||aux>hiLimit)
        {
        puts(eMessage);
        }
        else
        {
        *input=aux;
        respuesta=0;

        }
    }
    return respuesta;

}
/** \brief Solicita un char al usuario
 *
 * \param input array donde se cargara el char
 * \param message recibe un mensaje para mostrar
 * \param eMessage recibe un mensaje de error para mostrar
 * \param lowLimit limite mas bajo para el char
 * \param hilimit limite mas alto para el char
 * \return retorna [0] en caso de que se ingrese bien o [-1] en caso de que se ingrese mal
 *
 */
int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit)
{
    int respuesta=-1;
    char aux;
    int scanfOk;
    puts(message);
    scanfOk=scanf("%c",&aux);
    aux=tolower(aux);

    if(scanfOk)
    {
        if(aux<lowLimit||aux>hiLimit)
        {
        puts(eMessage);
        }
        else
        {
        aux=toupper(aux);
        *input=aux;
        respuesta=0;

        }
    }
    return respuesta;

}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */

int getString(char* input,char message[], char eMessage[], int lowLimit, int hiLimit)
{
    char aux[50];
    int respuesta=-1;
    int x;


    printf(message);
    fflush(stdin);
    scanf("%s",aux);
    x=strlen(aux);

        if(x<lowLimit || x>hiLimit)
        {
            printf(eMessage);
        }
        else
        {
            strcpy(input,aux);
            respuesta=0;
        }

    return respuesta;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(aux,mensaje,mensaje,1,256);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(aux,mensaje,mensaje,1,256);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(aux,mensaje,mensaje,1,256);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

