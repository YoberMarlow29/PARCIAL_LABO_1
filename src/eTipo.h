/*
 * eTipo.h
 *
 *  Created on: 20 oct. 2022
 *      Author: Yober
 */

#ifndef ETIPO_H_
#define ETIPO_H_
#include "input.h"
typedef struct{

	int idTipo;
	char descripcion[TAM_TIPO];
}eTipo;
void TIPO_MostrarUnTipo(eTipo unTipo);
void TIPO_MostrarListaTipo(eTipo listaTipos[], int tamTipos);



#endif /* ETIPO_H_ */
