#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(int input,char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int respuesta=-1;
    int aux;
    int scanfOk;
    puts(message);
    scanfOk= scanf("%d",&aux);
    if(scanfOk)
    {
        if(aux<lowLimit)
        {
            puts(eMessage);
        }
        else
        {
        input=aux;
        respuesta=0;

        }
    }
    return respuesta;

}


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

int getString(char* input,char message[], char eMessage[], int lowLimit, int hiLimit)
{
    char aux[50];
    int respuesta=-1;
    int x;


    printf(message);
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


