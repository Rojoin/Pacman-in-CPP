#pragma once
#include "Globales.h"

struct Fantasma
{
	int x;
	int y;
	EstadoFantasma estado = { EstadoFantasma::Normal };
	int timerFantasma;
	int timerFantasmaPowerUp;
	Colores colorActual;
	Colores colorDefault;
	const int xDefault =11;
	const int yDefault = 11;
	const int xCaja = 13;
	const int yCaja = 13;
	Direccion direccionActual;
	Direccion direccionAnterior;
	char cuerpo[2]{ fantasmaAlive,fantasmaDead};
	char cuerpoActual = { cuerpo[0] };
	void MovimientoFantasmal();
	void ResetearPosicion(int primero);
	void Normalizar();
	void Debilitar();
	void Encarcelar();

	bool SalirDeCasa(int tiempo);
};