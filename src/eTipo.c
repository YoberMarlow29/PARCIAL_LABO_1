/*
 * eTipo.c
 *
 *  Created on: 20 oct. 2022
 *      Author: Yober
 */
#include "eTipo.h"
void TIPO_MostrarUnTipo(eTipo unTipo)
{
	printf("\n%d - %s", unTipo.idTipo, unTipo.descripcion);
}

void TIPO_MostrarListaTipo(eTipo listaTipos[], int tamTipos)
{
	for(int i=0; i<tamTipos; i++)
	{
		TIPO_MostrarUnTipo(listaTipos[i]);
	}
}

