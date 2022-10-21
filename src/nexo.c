#include "nexo.h"
int ObtenerIdViaje()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}
int ObtenerIdServicio()
{
	static int idAutoIncremental = 20000;
	return idAutoIncremental++;
}
eVehiculo NEXO_pedirDatosVehiculo(eTipo listaTipos[],int tamTipos)
{

	eVehiculo aux;
	aux.idVehiculo=ObtenerIdViaje();
	utn_getDescripcion(aux.descripcion, TAM_DESVE, "\nIngrese una descripcion: ", "\nERROR.Ingrese nuevamente la descripcion: ", 3);
	utn_getNumero(&aux.modelo, "\nIngrese el modelo: ", "\nERROR. Ingrese nuevamente el modelo: ", 1, 50000, 3);
	utn_getNombre(aux.color, TAM_COLOR, "\nIngrese el color: ", "\nERROR. Ingrese nuevamente el color: ", 3);
	TIPO_MostrarListaTipo(listaTipos, tamTipos);
	utn_getNumero(&aux.tipoId, "\nIngrese el id de Tipo: ", "\nERROR. Ingrese nuevamente el id de Tipo: ", 1000, 1002, 3);
	aux.isEmpty=OCUPADO;

	return aux;
}
int NEXO_alta(eVehiculo listaVehiculo[],int tamVehiculo, eTipo listaTipos[],int tamTipos)
{

	int retorno;
	int posicionLibre;

	eVehiculo vehiculoUno;

	retorno=-1;

	if(listaVehiculo !=NULL&&tamVehiculo > 0){

		posicionLibre= VEHICULO_buscarIndiceLibre(listaVehiculo, tamVehiculo);

		vehiculoUno =NEXO_pedirDatosVehiculo(listaTipos, tamTipos);

		if(posicionLibre!=-1){

			listaVehiculo[posicionLibre] = vehiculoUno;
			retorno=0;
		}
	}

	return retorno;
}
int NEXO_modificar(eVehiculo listaVehiculo[], int tamVehiculo)
{
	int index = -1;
	int idIngresado;

	VEHICULO_mostrarTodos(listaVehiculo, tamVehiculo);
 	idIngresado = UTN_pedirEnteroRango("\nSeleccion un id a modificar: ", -1, 5000);

	for(int i=0; i<tamVehiculo; i++)
	{
		if(idIngresado == listaVehiculo[i].idVehiculo && listaVehiculo[i].isEmpty == OCUPADO)
		{
			int opcion;
			opcion=UTN_pedirEnteroRango("\nSeleccion una opcion: "
										"\n1-DESCRIPCIOn:"
										"\n2-PRECIO SERVICIO: "
										"\n3-CANCELAR", -1, 5000);

			switch(opcion)
			{
				case 1:
					utn_getDescripcion(listaVehiculo[i].descripcion, TAM_DESVE, "\nIngrese una descripcion: ", "\nERROR.Ingrese nuevamente la descripcion: ", 3);

					printf("Se modifico la descripcion con exito");
					index = 1;
					break;
				break;
				case 2:

					index = 1;
					break;
				break;
				case 3:
					printf("Si desea modificar, ingrese a la opcion MODIFICAR nuevamente, Gracias");
				break;

			}
		}
	}

	return index;
}
int NEXO_baja(eVehiculo listaVehiculo[], int tamVehiculo)
{
	int index = -1;
	int idIngresado;

	VEHICULO_mostrarTodos(listaVehiculo, tamVehiculo);

 	idIngresado = UTN_pedirEnteroRango("\nSeleccion un id a bajar: ", -1, 5000);


	for(int i=0; i<tamVehiculo; i++)
	{
		if(idIngresado == listaVehiculo[i].idVehiculo && listaVehiculo[i].isEmpty == OCUPADO)
		{
			listaVehiculo[i].isEmpty = LIBRE;
			listaVehiculo[i].idVehiculo = -1;
			index = 1;
			break;
		}
	}

	return index;
}
eServicio SERVICIO_pedirDatosVaucher()
{
	eServicio aux;
	aux.idHoja=ObtenerIdServicio();
	utn_getDescripcion(aux.descripcion,TAM_SERVICIO, "Ingrese una descripcion: ", "ERROR.Ingrese nuevamente una descripcion: ", 3);
	utn_getNumeroFlotante(&aux.precioServicio, "Ingrese el precio del viaje: ", "ERROR.Ingrese nuevamente el precio del viaje:", 1, 999999, 3);
	utn_getNumero(&aux.fecha.dia, "Ingrese el dia: ", "ERROR.Ingrese nuevamente el dia: ", 1, 32, 3);
	utn_getNumero(&aux.fecha.mes, "Ingrese el mes: ", "ERROR.Ingrese nuevamente  el mes: ", 1, 12, 3);
	utn_getNumero(&aux.fecha.anio, "Ingrese  el anio: ", "ERROR.Ingrese nuevamente el anio: ", 1, 999999, 3);
	aux.isEmpty=OCUPADO;

	return aux;
}
int VAUCHER_alta(eServicio listaServicio[],int tamServicio)
{

	int retorno;
	int posicionLibre;

	eServicio servicioUno;

	retorno=-1;

	if(listaServicio !=NULL&&tamServicio > 0){

		posicionLibre= SERVICIO_buscarIndiceLibre(listaServicio, tamServicio);

		servicioUno =SERVICIO_pedirDatosVaucher();

		if(posicionLibre!=-1){

			listaServicio[posicionLibre] = servicioUno;
			retorno=0;
		}
	}

	return retorno;
}
void pedirIdParaHacerAltaServicio(eVehiculo listaVehiculo[],int tamVehiculo,eServicio listaServicio[],int tamServicio)
{
	int idIngresado;
	VEHICULO_mostrarTodos(listaVehiculo, tamVehiculo);
 	idIngresado = UTN_pedirEnteroRango("\nSeleccion el id del VEHICULO, para dar de alta un servicio", 1, 999999);

	for(int i=0; i<tamVehiculo; i++)
	{

			if(idIngresado==listaVehiculo[i].idVehiculo)
			{
				VAUCHER_alta(listaServicio, tamServicio);

			}
	}
}
void VehiculoTipoSeleccionado(eVehiculo listaVehiculo[],int tamVehiculo,eTipo listaTipos[],int tamTipos)
{
	int idIngresado;
	TIPO_MostrarListaTipo(listaTipos, tamTipos);

 	idIngresado = UTN_pedirEnteroRango("\nSeleccion el id de Tipo, para que sus vehiculos sea mostrados: ", 1000, 1003);

	for(int i=0; i<tamTipos; i++)
	{
		for(int j=0; j<tamVehiculo; j++)
		{
			if(idIngresado==listaVehiculo[j].tipoId&&idIngresado == listaTipos[i].idTipo)
			{
				VEHICULO_mostrarUno(listaVehiculo[j]);

			}
		}

	}

}
void mostrarServicioSegunFecha(eServicio listaServicio[],int tamServicio, eFecha fecha)
{
	if(listaServicio !=NULL&&tamServicio>0){
			for(int i=0;i<tamServicio;i++){
				if(listaServicio[i].isEmpty==OCUPADO){
					if(listaServicio[i].fecha.dia==fecha.dia&&listaServicio[i].fecha.mes==fecha.mes&&listaServicio[i].fecha.anio==fecha.anio)
					{
						SERVICIO_mostrarUno(listaServicio[i]);

					}
				}
			}
		}


}
