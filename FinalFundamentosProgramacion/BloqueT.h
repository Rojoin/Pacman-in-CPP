#pragma once
#include <iostream>
#include "Bloque.h"
#include "Grilla.h"



struct BloqueT : Bloque 
{
	int posicionX = { 5 };
	int posicionY = { 5 };
	TipoDeBloque tipoBloque = TipoDeBloque::T;
	Rotacion state = Rotacion::Grado0;
	bool derecha = { true };
	bool izquierda = { true };
	 

	BloqueT(int x, int y, TipoDeBloque tipoDeBloque, Rotacion estado, bool right, bool left) : Bloque(x, y, tipoDeBloque, estado, derecha, izquierda)
	{
		this->posicionX = x;
		this->posicionY = y;
		this->tipoBloque = tipoDeBloque;
		this->state = estado;
		this->derecha = right;
		this->izquierda = left;
		
	}
	void MoverDerecha();
	 void MoverIzquierda() override
	{
		cout << "Hi";
		cout << posicionX;
	}
};
