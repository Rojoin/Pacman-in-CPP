#pragma once
#include "Globales.h"

struct Fantasma
{
	int x;
	int y;
	EstadoFantasma estado = { EstadoFantasma::Normal };
	int xDefault =11;
	int yDefault = 11;
	int xCaja = 13;
	int yCaja = 13;
	int objetivoX;
	int objetivoY;
	bool direccionesDisponibles[4];
	Direccion direccionActual;
	Direccion direccionAnterior;
	char cuerpo[3]{ 'M','m', 'Q'};
	char cuerpoActual = { cuerpo[0] };
	void MovimientoFantasmal();
	void ResetearPosicion(int primero);
};