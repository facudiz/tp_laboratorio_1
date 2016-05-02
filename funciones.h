typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;

}ePersona;

int initPersona(ePersona* pPersona, int largo);
int buscarLibre(ePersona* pPersona, int largo);
int agregarPersona(ePersona* pPersona, int largo, int indice);
ePersona* buscarPersXDni(ePersona* pPersona, int largo);
int BorrarPersona(ePersona* pPpersona, int largo);
void listar(ePersona pPersona[],int largo);
void grafico(ePersona* pPersona, int largo);
