#include "input.h"
#ifndef ESERVICIO_H_
#define ESERVICIO_H_
typedef struct{

	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct{

	int idHoja;
	int vehiculoId;
	char descripcion[TAM_SERVICIO];
	float precioServicio;
	eFecha fecha;
	int isEmpty;

}eServicio;
int SERVICIO_inicializadorEstructura(eServicio listaServicio[], int tamServicio);
int SERVICIO_buscarIndiceLibre(eServicio listaServicio[],int tamServicio);
void SERVICIO_mostrarUno(eServicio vaucher);
int SERVICIO_mostrarTodos(eServicio listaServicio[],int tamServicio);


#endif /* ESERVICIO_H_ */
