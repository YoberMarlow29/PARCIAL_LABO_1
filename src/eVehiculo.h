
#ifndef EVEHICULO_H_
#define EVEHICULO_H_
#include "input.h"
typedef struct{

	int idVehiculo;
	char descripcion[TAM_DESVE];
	int modelo;
	char color[TAM_COLOR];
	int tipoId;
	int isEmpty;
}eVehiculo;
int VEHICULO_inicializadorEstructura(eVehiculo listaVehiculo[], int tamVehiculo);
int VEHICULO_buscarIndiceLibre(eVehiculo listaVehiculo[],int tamVehiculo);
void VEHICULO_mostrarUno(eVehiculo vehiculo);
int VEHICULO_mostrarTodos(eVehiculo listaVehiculo[],int tamVehiculo);

#endif /* EVEHICULO_H_ */
