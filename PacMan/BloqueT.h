#pragma once
#include <iostream>
#include "Bloque.h"
#include "Grilla.h"
#include "Posicion.h"



struct BloqueT : Bloque
{
	int posicionX = { 5 };
	int posicionY = { 5 };
	TipoDeBloque tipoBloque = TipoDeBloque::T;
	Rotacion state = Rotacion::Grado0;
	bool derecha = { true };
	bool izquierda = { true };
	Posicion tetromino[4][4] = { 0,0 };

	Posicion inicial = { 0,0 };
	Posicion relativo = { 0,0 };

	BloqueT(TipoDeBloque tipoDeBloque, Rotacion estado, bool right, bool left, Posicion initial) : Bloque( tipoDeBloque, estado, derecha, izquierda, initial)
	{
		
		this->tipoBloque = tipoDeBloque;
		this->state = estado;
		this->derecha = right;
		this->izquierda = left;
		this->relativo.columna = initial.columna;
		this->relativo.fila = initial.fila;

	}
	void MoverDerecha();
	 void MoverIzquierda(Grilla& grilla) 
	{
		 cout << "tu vieja";
		 relativo.columna--;
		 if (izquierda)
		 {
			 switch (state)
			 {
			 case Rotacion::Grado0:
				 if (grilla.tablero[posicionX-1][posicionY] != TipoDeBloque::Vacio && grilla.tablero[posicionX][posicionY+1] != TipoDeBloque::Vacio)
				 {
					 izquierda = false;
				 }
				 else
				 {

				 }
				 break;
			 case Rotacion::Grado90:
				 break;
			 case Rotacion::Grado180:
				 break;
			 case Rotacion::Grado270:
				 break;
			 default:
				 break;
			 }
		 }
	}
};
