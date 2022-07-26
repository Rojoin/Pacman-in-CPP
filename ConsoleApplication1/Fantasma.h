#pragma once
#include "Globales.h"

struct Fantasma
{
	int x;
	int y;
	int objetivoX;
	int objetivoY;
	EstadoFantasma estado = { EstadoFantasma::Normal };
	Direccion direccionActual;
	Direccion direccionAnterior;
	char cuerpo[3]{ 'M','m', 'Q'};
	char cuerpoActual = { cuerpo[0] };
	void MovimientoFantasmal();
};