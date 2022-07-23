#pragma once
#include "Globales.h"

struct Fantasma
{
	int x;
	int y;
	EstadoFantasma estado = { EstadoFantasma::Normal };
	char cuerpo[3]{ 'M','m', 'Q'};
	char cuerpoActual = { cuerpo[0] };
};