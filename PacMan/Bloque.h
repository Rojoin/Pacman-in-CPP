#pragma once

#include <iostream>
#include "Posicion.h"

 struct Bloque
{
	TipoDeBloque tipoBloque = {TipoDeBloque::Vacio};
	Rotacion state = { Rotacion::Grado0 };
	bool derecha = { true };
	bool izquierda = { true };

	Posicion tetromino[4][4] = { 0,0 };
	Posicion inicial = { 0,0 };
	Posicion relativo = { 0,0 };
	Bloque(TipoDeBloque tipoDeBloque, Rotacion estado, bool right, bool left,Posicion initial)
	{
		this->tipoBloque = tipoDeBloque;
		this->state = estado;
		this->derecha = right;
		this->izquierda = left;
		this->relativo.columna = initial.columna;
		this->relativo.fila = initial.fila;
		
	}
	
	bool Colision()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{

			}
		}
	}
	virtual void MoverIzquierda(Grilla& grilla)
	{
		switch (tipoBloque)
		{

		case TipoDeBloque::L:

			break;
		case TipoDeBloque::J:
			break;
		case TipoDeBloque::S:
			break;
		case TipoDeBloque::Z:
			break;
		case TipoDeBloque::T:
			break;
		case TipoDeBloque::O:
			break;
		case TipoDeBloque::I:
			break;
	
		}
	}
	virtual void BajarPieza(Grilla& grilla)abstract;
	
	virtual void Dibujar(Grilla& grilla)
	{
		

	}
	virtual void DesDibujar(Grilla& grilla)
	{


	}
	
};