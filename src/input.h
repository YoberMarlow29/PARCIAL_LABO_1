#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0
#define TAM_DESVE 30
#define TAM_COLOR 10
#define TAM_TIPO 30
#define TAM_SERVICIO 30


#ifndef INPUT_H_
#define INPUT_H_


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int UTN_pedirEnteroRango(char* mensaje, int min, int max);





#endif /* INPUT_H_ */
