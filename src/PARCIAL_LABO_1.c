#include "input.h"
#include "nexo.h"
#define MAX_TIPO 3
#define MAX_VEHICULO 300 //tamaño de los viajes, cambiarlos
#define MAX_SERVICIO 300 //tamaño de los vaucher, cambiarlos junto a VIAJE
eVehiculo listaVehiculo[MAX_VEHICULO];
eTipo listaTipos[MAX_TIPO]={{1000,"SEDAN3PTS"},{1001,"SEDAN5PTS"},{1002,"CAMIONETA"}};
eServicio listaServicio[MAX_SERVICIO];
int main(void)
{
	setbuf(stdout, NULL);
		int respuesta;
		int opcion;
		int flagAlta=0;
		int flagAltaServicio=0;
		int retorno;
		int respuestaInforme;
		int opcionInforme;
		eFecha aux;
		VEHICULO_inicializadorEstructura(listaVehiculo, MAX_VEHICULO);
		SERVICIO_inicializadorEstructura(listaServicio, MAX_SERVICIO);

		do{
						respuesta= utn_getNumero(&opcion,"\nSeleccione una opcion:(1-9) \n"
								"\n1-ALTA VEHICULO: "
								"\n2-MODIFICAR VEHICULO: "
								"\n3-BAJA VEHICULO: "
								"\n4-LISTAR VEHICULO: "
								"\n5-LISTAR TIPOS: "
								"\n6-ALTA SERVICIO: "
								"\n7-LISTAR SERVICIO: "
								"\n8-INFORMES: "
								"\n9-SALIR."
								, "ERROR.OPCION INCORRECTA", 1, 9, 10);

						if(!respuesta)
						{
							switch(opcion)
							{
							case 1:

								printf("\t\t***** ALTA VEHICULO *****\n");
								if((NEXO_alta(listaVehiculo, MAX_VEHICULO, listaTipos, MAX_TIPO))!=-1)
								{
									flagAlta=1;

								}
								else
								{
									printf("No se ha podido dar de alta");
								}
								break;

							case 2:
								printf("\t\t***** MODIFICAR VEHICULO *****\n");
								if(flagAlta==1)
								{
									retorno=NEXO_modificar(listaVehiculo, MAX_VEHICULO);
									switch(retorno)
									{
										case -1:
											printf("No se ha podido modificar el vehiculo");
										break;
										default:
											printf("Se ha modificado correctamente el vehiculo");
										break;
									}

								}
								else
								{
									printf("Ingrese a la opcion 1");
								}

								break;
							case 3:
								printf("\t\t***** BAJA VEHICULO *****\n");
								if(flagAlta==1)
								{
									retorno=NEXO_baja(listaVehiculo, MAX_VEHICULO);
									switch(retorno)
									{
										case -1:
											printf("No se ha podido dar de baja el vehiculo");
										break;
										default:
											printf("Se ha dado de baja correctamente el vehiculo");
										break;
									}

								}
								else
								{
									printf("Ingrese a la opcion 1");
								}
								break;
							case 4:
								printf("\t\t***** LISTAR VEHICULO *****\n");
								if(flagAlta==1)
								{
									VEHICULO_mostrarTodos(listaVehiculo, MAX_VEHICULO);
								}
								else
								{
									printf("Ingrese a la opcion 1");
								}

								break;
							case 5:
								printf("\t\t***** LISTAR TIPOS *****\n");
								if(flagAlta==1)
								{
									TIPO_MostrarListaTipo(listaTipos, MAX_TIPO);
								}
								else
								{
									printf("Ingrese a la opcion 1");
								}

								break;
							case 6:
								printf("\t\t***** ALTA SERVICIO *****\n");
								if(flagAlta==1)
								{
									pedirIdParaHacerAltaServicio(listaVehiculo, MAX_VEHICULO, listaServicio, MAX_SERVICIO);
									flagAltaServicio=1;
								}
								else
								{
									printf("Ingrese a la opcion 1");
								}

								break;
							case 7:
								printf("\t\t***** LISTAR SERVICIO *****\n");
								if(flagAltaServicio==1)
								{
									SERVICIO_mostrarTodos(listaServicio, MAX_SERVICIO);

								}
								else
								{
									printf("Ingrese al menos un servicio para mostrar la lista");

								}

								break;
							case 8:
								printf("\t\t***** INFORMES *****\n");
								do
								{
									respuestaInforme= utn_getNumero(&opcionInforme,"\nSeleccione una opcion:(1-5) \n"
																				"\n1-VEHICULOS DE UN TIPO SELECIONADO: "
																				"\n2-HOJAS DE SERVICIO EFECTUADOS EN UNA FECHA SELECCIONADA: "
																				"\n3-IMPORTE TOTAL DE LOS SERVICIOS REALIZADOS PARA UN VEHICULO SELECCIONADO: "
																				"\n4-IMPORTE TOTAL DE LOS SERVICIOS REALIZADOS DE UN TIPO EN UN FECHA SELECCIONADA: "
																				"\n5-SALIR"

																				, "ERROR.OPCION INCORRECTA", 1, 5, 10);
																			if(!respuestaInforme)
																			{
																				switch(opcionInforme)
																				{
																					case 1:
																						if(flagAlta==1)
																						{
																							printf("\t\t***** VEHICULOS DE UN TIPO SELECIONADO *****\n");
																							VehiculoTipoSeleccionado(listaVehiculo, MAX_SERVICIO, listaTipos, MAX_TIPO);
																						}
																						else
																						{
																							printf("No se ha cargado ningun vehiculo");
																						}
																						break;
																					case 2:
																						if(flagAltaServicio==1)
																						{
																							utn_getNumero(&aux.dia, "Ingrese el dia: ", "error", 1, 32, 3);
																							utn_getNumero(&aux.mes, "Ingrese el mes: ", "error", 1, 12, 3);
																							utn_getNumero(&aux.anio, "Ingrese el anio: ", "error", 1, 50000, 3);
																							mostrarServicioSegunFecha(listaServicio, MAX_SERVICIO, aux);
																						}
																						else
																						{
																							printf("No se ha cargado ningun s");
																						}
																						break;
																					case 3:
																						break;
																					case 4:
																						break;
																					case 5:
																						break;
																				}
																			}


																	break;

								}while(opcionInforme!=5);
								break;

							case 9:
								printf("\t\t***** SALIR *****\n");

								break;
							}
						}

					}while(opcion!=9);



	return 0;
}
