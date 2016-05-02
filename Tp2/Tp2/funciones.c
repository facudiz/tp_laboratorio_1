#include <stdio.h>
#include <stdlib.h>
#include "funciones2.h"
#define length 5

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;

}ePersona;

int initPersona(ePersona* pPersona, int largo)
{
    int i;
    int retorno=-1;

    if(pPersona != NULL && largo>0)
    {
        for(i=0;i<largo;i++)
        {
            pPersona[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
/**
 * Obtiene el primer indice libre del array.
 * @param el array se pasa como parametro.
 * @return el primer indice disponible
 */

int buscarLibre(ePersona* pPersona, int largo)
{
    int i;
    int retorno=-1;

    if(pPersona != NULL && largo>0)
    {
        for(i=0;i<largo;i++)
        {
            if(pPersona[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int agregarPersona(ePersona* pPersona, int largo, int indice)
{
    int retorno = -1;
    int i;
    int respuesta,respuesta2,respuesta3;


    if(pPersona!= NULL && largo> 0)
    {
        for(i=0;i<largo;i++)
        {
            if(pPersona[i].isEmpty==1)
            {

                respuesta=getString(pPersona[i].nombre,"Ingrese El nombre\n","Error Supero la cantidad de caracteres\n",2,20);
                    while(respuesta!=0)
                    {
                        respuesta=getString(pPersona[i].nombre,"Ingrese El nombre\n","Error Supero la cantidad de caracteres\n",2,20);
                    }

                respuesta2=getInt(pPersona[i].edad,"Ingrese la edad","Error, Reingresar la edad",1);
                    while(respuesta2!=0)
                    {
                        respuesta2=getInt(pPersona[i].edad,"Ingrese la edad\n","Error, Reingresar la edad\n",1);
                    }
                respuesta3=getInt(pPersona[i].dni,"Ingrese el Dni\n","Error, Reingresar la edad\n",0);
                    while(respuesta3!=0)
                    {
                        respuesta3=getInt(pPersona[i].dni,"Ingrese el Dni\n","Error, Reingresar la edad\n",0);
                    }

                pPersona[i].isEmpty = 0;
                retorno = 0;
                break;
            }


        }


    }

    return retorno;

}

ePersona* buscarPersXDni(ePersona* pPersona, int largo)
{

    ePersona* retorno = NULL;
    int i;
    int dni;

    if(pPersona != NULL && largo > 0)
    {
        printf("Ingrese el dni de la persona a buscar");
        scanf("%d",&dni);
        for(i=0;i<largo;i++)
        {
            if(pPersona[i].isEmpty == 0 && pPersona[i].dni==dni)
            {
                retorno =i;
                break;
            }
        }

    }

    return retorno;

}

int BorrarPersona(ePersona* pPersona, int largo)
{
    int retorno = -1;
    ePersona*  auxPersona= NULL ;
    auxPersona = buscarPersXDni(pPersona,length);

    if(auxPersona != NULL)
    {
        auxPersona->isEmpty = 1;
        retorno = 0;
    }

    return retorno;
}

void listar(ePersona pPersona[],int largo)
{
    int i, j;
    ePersona auxP;

    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(pPersona[j].isEmpty!=1)
            {
                if(strcmp(pPersona[i].nombre,pPersona[j].nombre)>0)
                {
                    auxP=pPersona[i];
                    pPersona[i]=pPersona[j];
                    pPersona[j]=auxP;
                }
            }

        }
    }

    for(i=0;i<largo; i++)
    {
        if(pPersona[i].isEmpty==0)
            printf("Nombre %s--Dni %d--Edad %d\n",pPersona[i].nombre, pPersona[i].dni,pPersona[i].edad);
    }
}



void grafico(ePersona* pPersona, int largo)
{


int i, hasta18, de19a35, mayorDe35, flag=0, mayor;

if( pPersona != NULL && largo >0 )
    {
        for( i=0 ; i<largo ; i++ )
        {
            if( pPersona[i].isEmpty == 0 )
            {

                if( pPersona[i].edad<= 18 )
                {
                    hasta18++;
                }
                if( pPersona[i].edad > 18 && pPersona[i].edad <= 35)
                {
                    de19a35++;
                }
                if( pPersona[i].edad > 35 )
                {
                    mayorDe35++;
                }
            }
        }
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
        }
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);

}
