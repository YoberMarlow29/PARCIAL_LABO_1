#include "eServicio.h"
int SERVICIO_inicializadorEstructura(eServicio listaServicio[], int tamServicio)
{
	int retorno;
	retorno=-1;
	if(listaServicio != NULL && tamServicio>0){

		for(int i=0;i<tamServicio;i++){
			listaServicio[i].isEmpty = LIBRE;
		}
		retorno =0;
	}

	return retorno;
}

int SERVICIO_buscarIndiceLibre(eServicio listaServicio[],int tamServicio)
{
	 int retorno;
	 retorno=-1;

	 if(listaServicio != NULL && tamServicio>0){
	 		for(int i=0;i<tamServicio;i++){
	 			if(listaServicio[i].isEmpty == LIBRE){
	 				retorno=i;
	 				break;
	 			}
	 		}
	 	}
	 return retorno;
}
void SERVICIO_mostrarUno(eServicio servicio)
{

	printf("||%-14d||%-16s||%-13.2f||%d/ %d/ %d||\n",servicio.idHoja,servicio.descripcion,servicio.precioServicio,servicio.fecha.dia,servicio.fecha.mes,servicio.fecha.anio);
}
int SERVICIO_mostrarTodos(eServicio listaServicio[],int tamServicio)
{

	int retorno;

	retorno=-1;
	if(listaServicio !=NULL&&tamServicio>0){
		for(int i=0;i<tamServicio;i++){
			if(listaServicio[i].isEmpty==OCUPADO){
				SERVICIO_mostrarUno(listaServicio[i]);
			}

		}
		retorno=0;
	}

	return retorno;
}
