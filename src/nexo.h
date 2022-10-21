#include "input.h"
#include "eVehiculo.h"
#include "eTipo.h"
#include "eServicio.h"
#ifndef NEXO_H_
#define NEXO_H_
int ObtenerIdViaje();
eVehiculo NEXO_pedirDatosVehiculo(eTipo listaTipos[],int tamTipos);
int NEXO_alta(eVehiculo listaVehiculo[],int tamVehiculo, eTipo listaTipos[],int tamTipos);
int NEXO_modificar(eVehiculo listaVehiculo[], int tamVehiculo);
int NEXO_baja(eVehiculo listaVehiculo[], int tamVehiculo);
eServicio SERVICIO_pedirDatosVaucher();
int VAUCHER_alta(eServicio listaServicio[],int tamServicio);
void pedirIdParaHacerAltaServicio(eVehiculo listaVehiculo[],int tamVehiculo,eServicio listaServicio[],int tamServicio);
void VehiculoTipoSeleccionado(eVehiculo listaVehiculo[],int tamVehiculo,eTipo listaTipos[],int tamTipos);
void mostrarServicioSegunFecha(eServicio listaServicio[],int tamServicio, eFecha fecha);

#endif /* NEXO_H_ */
