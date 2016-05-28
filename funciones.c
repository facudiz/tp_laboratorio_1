#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

typedef struct{
    char titulo[20];
    char genero[20];
    char duracion[10];
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int isEmpty;
}eMovie;

/** \brief Inicializa el Array
 *
 * \param  pPersona recibe el array
 * \param largo el largo del array
 * \return retorna [0] si se inicializo o [-1] en caso de algun error
 *
 */

int initArrayMovie(eMovie* pMovie, int largo)
{
    int i;
    int retorno=-1;

    if(pMovie != NULL && largo>0)
    {
        for(i=0;i<largo;i++)
        {
            pMovie[i].isEmpty=1;//vacio
            retorno=0;
        }
    }
    return retorno;
}


/**
 * Obtiene el primer indice libre del array.
 * @param el array se pasa como parametro.
 * @return el primer indice disponible en caso de no haber disponible devuelve [-1]
 */

int buscarLibre(eMovie* pMovie, int largo)
{
    int i;
    int retorno=-1;

    if(pMovie != NULL && largo>0)
    {
        for(i=0;i<largo;i++)
        {
            if(pMovie[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie* pMovie,int largo)
{
    int retorno = -1;
    int i,puntaje;
    int respuesta,respuesta2,respuesta3,respuesta4,respuesta5,respuesta6;
    char titulo[50];
    char genero[50];
    char descripcion [100];
    char linkImagen[1000];
    char duracion[10];


    if(pMovie!= NULL && largo> 0)
    {
        for(i=0;i<largo;i++)
        {
            if(pMovie[i].isEmpty==1)
            {

                respuesta=getString(titulo,"Ingrese El Titulod de la pelicula\n","Error Supero la cantidad de caracteres\n",1,20);
                    while(respuesta!=0)
                    {
                        respuesta=getString(titulo,"Ingrese El Titulo de la pelicula\n","Error Supero la cantidad de caracteres\n",1,20);
                    }

                respuesta2=getString(genero,"Ingrese El genero de la pelicula\n","Error, Reingresar el genero",1,20);
                    while(respuesta2!=0)
                    {
                        respuesta2=getString(genero,"Ingrese El genero de la pelicula\n","Error, Reingresar el genero",1,20);
                    }
                respuesta3=getString(duracion,"Ingrese la duraciond e la pelicula\n","Error, Reingresar la duracion\n",1,99);
                    while(respuesta3!=0)
                    {
                        respuesta3=getString(duracion,"Ingrese la duraciond e la pelicula\n","Error, Reingresar la duracion\n",0,99);
                    }
                respuesta4=getString(descripcion,"Ingrese la descripcion  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,50);
                    while(respuesta4!=0)
                    {
                        respuesta4=getString(descripcion,"Ingrese la descripcion  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,50);
                    }
                respuesta5=getString(linkImagen,"Ingrese el link de la imagen  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,1000);
                while(respuesta5!=0)
                    {
                        respuesta5=getString(linkImagen,"Ingrese el link de la imagen  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,150);
                    }
                puntaje=getInt("Ingrese el puntaje para la  pelicula\n");
                    while(puntaje<0 && puntaje>10)
                    {
                        puntaje=getInt("Ingrese el puntaje para la  pelicula\n");
                    }

                    strcpy(pMovie[i].titulo,titulo);
                    strcpy(pMovie[i].genero,genero);
                    strcpy(pMovie[i].descripcion,descripcion);
                    strcpy(pMovie[i].linkImagen,linkImagen);
                    strcpy(pMovie[i].duracion,duracion);
                    pMovie[i].puntaje=puntaje;

                pMovie[i].isEmpty = 0;
                retorno = 0;
                break;
            }


        }


    }

    return retorno;

}

/** \brief Busca a una persona por dni
 *
 * \param pPersona recibe el array
 * \param Largo recibe el largo del array
 * \return retorna [0] si se inicializo o [-1] en caso de algun error
 *
 */

eMovie* buscarPeliculaXTitulo(eMovie* pMovie, int largo)
{

    eMovie* retorno = NULL;
    int i;
    char titulo[50];

    if(pMovie != NULL && largo > 0)
    {
        printf("Ingrese el titulo de la pelicula a buscar");
        scanf("%s",titulo);
        for(i=0;i<largo;i++)
        {
            if(pMovie[i].isEmpty == 0 && pMovie[i].titulo==titulo)
            {
                retorno =i;
                break;
            }
        }

    }

    return retorno;

}

/** \brief Borra a una persona del array
 *
 * \param pPersona recibe el array
 * \param Largo recibe el largo del array
 * \return retorna [0] si se inicializo o [-1] en caso de algun error
 *
 */


int borrarPelicula(eMovie* pMovie, int largo)
{
    int retorno = -1;
    eMovie*  auxMovie= NULL ;
    auxMovie = buscarPeliculaXTitulo(pMovie,largo);

    if(auxMovie != NULL)
    {
        auxMovie->isEmpty = 1;
        retorno = 0;
    }

    return retorno;
}

void modificarPelicula(eMovie* pMovie, int largo)
{
    int opcion,duracion,puntaje;
    int indice=NULL;
    char genero[50];
    char descripcion [100];
    char linkImagen[150];
    int respuesta,respuesta2,respuesta3,respuesta4,respuesta5;

    indice=buscarPeliculaXTitulo(pMovie,largo);

    if(indice!=NULL)
    {
        do
        {
        printf("Que desea modificar?\n");
        printf("1- Genero\n2-Duracion\n3-Descripcion\n4-Puntaje\n5-Link De la Imagen\n6-Salir");
        scanf("%d",&opcion);

            switch(opcion)
            {
                case 1: respuesta=getString(genero,"Ingrese El genero de la pelicula\n","Error, Reingresar el genero",1,20);
                    while(respuesta!=0)
                    {
                        respuesta=getString(genero,"Ingrese El genero de la pelicula\n","Error, Reingresar el genero",1,20);
                    }
                    strcpy(pMovie[indice].genero,genero);
                    break;
                case 2:respuesta2=getString(duracion,"Ingrese la duraciond e la pelicula\n","Error, Reingresar la duracion\n",0,99);
                    while(respuesta2!=0)
                    {
                        respuesta2=getString(duracion,"Ingrese la duraciond e la pelicula\n","Error, Reingresar la duracion\n",0,99);
                    }
                    strcpy(pMovie[indice].duracion,duracion);
                    break;
                case 3:respuesta3=getString(descripcion,"Ingrese la descripcion  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,50);
                    while(respuesta3!=0)
                    {
                        respuesta3=getString(descripcion,"Ingrese la descripcion  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,50);
                    }
                    strcpy(pMovie[indice].descripcion,descripcion);
                    break;
                case 4: respuesta4=getString(linkImagen,"Ingrese el link de la imagen  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,150);
                while(respuesta4!=0)
                    {
                        respuesta4=getString(linkImagen,"Ingrese el link de la imagen  de la pelicula\n","Error Supero la cantidad de caracteres\n",1,150);
                    }
                    strcpy(pMovie[indice].linkImagen,linkImagen);
                    break;
                case 5: puntaje=getInt("Ingrese el puntaje para la  pelicula\n");
                    while(puntaje<0 && puntaje>10)
                    {
                        puntaje=getInt("ReIngrese el puntaje para la  pelicula\n");
                    }
                    pMovie[indice].puntaje=puntaje;
                    break;
            }
        }while(opcion!=6);

    }


}

/** \brief guarda el binario
 *
 * \param pMovie array
 * \param largo del array
 * \return void
 *
 */
void guardarBinario(eMovie* pMovie, int largo)
{
    FILE *f;
    f = fopen("bin.dat", "wb");
    if(f == NULL)
    {
        printf("Error no se pudo Abrir el fichero");
        exit(1);
    }

    fwrite(pMovie, sizeof(eMovie), largo, f);

    printf("\nFichero guardado con exito\n");

    fclose(f);
}
/** \brief
 *
 * \param peliculas EMovie*
 * \param cantidad int
 * \return void
 *
 */
void leerBinario(eMovie* pMovie, int largo)
{
    FILE *f;
    f = fopen("bin.dat", "rb");
    if(f == NULL)
    {
        f = fopen("bin.dat", "wb");

    }
    if(f == NULL)
    {
        printf("Error al abrirel fichero");
        exit(1);
    }
    fread(pMovie, sizeof(eMovie), largo, f);

    printf("Se cargo con exito el fichero\n");

    system("pause");

    fclose(f);
}
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */

void generarPagina(eMovie* pMovie, int largo)
{
    int i;

     FILE *f;

    f=fopen("pagina.html", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>eMovie Peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

  for(i=0;i<largo;i++)
    {
        if(pMovie[i].isEmpty==0)
        {
         fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", pMovie[i].linkImagen);
         fprintf(f,"</a><h3><a href='#'>%s</a></h3><ul>",pMovie[i].titulo);
         fprintf(f,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", pMovie[i].genero, pMovie[i].puntaje,pMovie[i].duracion);
         fprintf(f,"<p>%s</p></article>",pMovie[i].descripcion);
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
    printf("\n\n archivo escrito con exito\n\n");

}
