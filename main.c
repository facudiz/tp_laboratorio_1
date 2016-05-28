#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define largo 3
#define CLEAR system("cls")
#define PAUSE system("pause")

int main()
{
    int opcion;
    eMovie pMovie[largo];
    int init,indice;
    int a,b;
    int flag=0;


    init=initArrayMovie(pMovie,largo);


    if(init==0)
    {


        do
        {
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar Pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Salir\n");
            PAUSE;
            scanf("%d",&opcion);
            CLEAR;


            switch(opcion)
            {
                case 1:indice=buscarLibre(pMovie,largo);
                        if(indice!=-1)
                        {
                            a=agregarPelicula(pMovie,largo);
                            if(a==0)
                            {
                                printf("Se agego la pelicula\n");
                                flag=1;
                            }
                            else
                            {
                                printf("Se produjo un error al intentar agregar la pelicula\n");
                            }

                        }
                        else
                        {
                            printf("No hay espacio para agregar peliculas");
                        }

                        PAUSE;
                        CLEAR;
                    break;
                case 2:if(flag==1)
                        {
                          b=borrarPelicula(pMovie,largo);
                          if(b==0)
                          {
                              printf("Se borro con exito la pelicula\n");
                          }
                          else
                          {
                              printf("Error no se pudo borrar la pelicula");
                          }
                        }
                        PAUSE;
                        CLEAR;
                    break;
                case 3:if(flag==1)
                        {
                            modificarPelicula(pMovie,largo);
                        }
                        else
                        {
                            printf("no hay peliculas cargadas para modificar");
                        }
                        PAUSE;
                        CLEAR;
                   break;
                case 4: generarPagina(pMovie,largo);
                        PAUSE;
                        CLEAR;
                    break;
                case 5:
                    break;
            }
        }while(opcion!=4);


    }
    return 0;
}
