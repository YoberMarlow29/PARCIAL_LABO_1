#include "eVehiculo.h"
int VEHICULO_inicializadorEstructura(eVehiculo listaVehiculo[], int tamVehiculo)
{
	int retorno;
	retorno=-1;
	if(listaVehiculo != NULL && tamVehiculo>0){

		for(int i=0;i<tamVehiculo;i++){
			listaVehiculo[i].isEmpty = LIBRE;
		}
		retorno =0;
	}

	return retorno;
}

int VEHICULO_buscarIndiceLibre(eVehiculo listaVehiculo[],int tamVehiculo)
{
	 int retorno;
	 retorno=-1;

	 if(listaVehiculo != NULL && tamVehiculo>0){
	 		for(int i=0;i<tamVehiculo;i++){
	 			if(listaVehiculo[i].isEmpty == LIBRE){
	 				retorno=i;
	 				break;
	 			}
	 		}
	 	}
	 return retorno;
}
void VEHICULO_mostrarUno(eVehiculo vehiculo)
{

		printf("||%-12d||%-14s||%-23d||%-12s||\n\n",vehiculo.idVehiculo,vehiculo.descripcion,vehiculo.modelo,vehiculo.color);

}
int VEHICULO_mostrarTodos(eVehiculo listaVehiculo[],int tamVehiculo)
{

	int retorno;
	printf("================================================================\n"
			"||ID VEHICULO    ||DESCRIPCION       ||MODELO     ||COLOR       \n"
			"===============================================================\n");
	retorno=-1;
	if(listaVehiculo !=NULL&&tamVehiculo>0){
		for(int i=0;i<tamVehiculo;i++){
			if(listaVehiculo[i].isEmpty==OCUPADO){
				VEHICULO_mostrarUno(listaVehiculo[i]);
			}

		}
		retorno=0;
	}
	printf("================================================================\n");
	return retorno;
}

