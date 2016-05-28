#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    char duracion[10];
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
    int isEmpty;
}eMovie;

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */


#endif // FUNCIONES_H_INCLUDED

int initArrayMovie(eMovie* pMovie, int largo);
int buscarLibre(eMovie* pMovie, int largo);
int agregarPelicula(eMovie* pMovie,int largo);
eMovie* buscarPeliculaXTitulo(eMovie* pMovie, int largo);
int borrarPelicula(eMovie* pMovie, int largo);
void modificarPelicula(eMovie* pMovie, int largo);
void guardarBinario(eMovie* pMovie, int largo);
void leerBinario(eMovie* pMovie, int largo);
void generarPagina(eMovie* pMovie, int largo);
