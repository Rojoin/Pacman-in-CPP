#pragma once
#include "Grilla.h"


static struct Bloque
{
	int posicionX = {0};
	int posicionY = {0};
	TipoDeBloque tipoBloque = {TipoDeBloque::Vacio};
	Rotacion state = { Rotacion::Grado0 };
	bool derecha = { true };
	bool izquierda = { true };
	Bloque(int x, int y, TipoDeBloque tipoDeBloque, Rotacion estado, bool right, bool left)
	{
		this->posicionX = x;
		this->posicionY = y;
		this->tipoBloque = tipoDeBloque;
		this->state = estado;
		this->derecha = right;
		this->izquierda = left;
	}
	
	 virtual void MoverIzquierda()
	{
		cout << "GoodBye";
		cout << posicionX;
	}
	
	 void MoverDerecha();
	
};