#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define largo 20
#include <ctype.h>


int main()
{
    char seguir='s';
    int opcion=0;
    ePersona pPersona[largo];
    int init,indice,agregado,borrar;
    int flag=0;

    init=initPersona(pPersona,largo);

    if(init==0)
    {
        do
        {
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por  nombre\n");
            printf("4- Imprimir grafico de edades\n");
            printf("5- Salir\n");

            scanf("%d",&opcion);


            switch(opcion)
            {
                case 1: indice=buscarLibre(pPersona,largo);
                        if(indice !=-1)
                        {
                            agregado=agregarPersona(pPersona, largo, indice);
                            if(agregado==0)
                            {
                                printf("Se pudo Agregar a la persona\n");
                                flag=1;
                            }
                        }
                        else
                        {
                            printf("Hubo un error al agregar a la persona\n");
                        }
                        system("pause");
                        system("cls");

                    break;
                case 2:if(flag==1)
                        {
                            borrar=BorrarPersona(pPersona,largo);
                            if(borrar==0)
                            {
                                printf("Se borro a la persona\n");
                            }
                        }
                        else
                        {
                            printf("Error al borrar persona, Verifique que haya personas para borrar.\n");
                        }


                    break;
                case 3: if(flag==1)
                        {
                            listar(pPersona,largo);
                        }
                    break;
                case 4:if(flag==1)
                            {
                                 grafico(pPersona,largo);
                            }
                            else
                            {
                                printf("No hay personas Ingresadas\n");
                            }

                    break;
                case 5:
                    printf("Desea continuar?? S/N\n");
                    fflush(stdin);
                    scanf("%c",&seguir);
                    seguir=tolower(seguir);
                    break;
            }
        }while(seguir != 'n');
    }
    return 0;
}
