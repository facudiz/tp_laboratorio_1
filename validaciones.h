#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(char message[]);
int getString(char* input,char message[], char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[], char eMessage[], float lowLimit, float hiLimit);
int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit);
int esNumericoFlotante(char str[]);
int esNumerico(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

