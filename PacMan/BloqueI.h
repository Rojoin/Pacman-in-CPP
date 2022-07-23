#pragma once
#include <iostream>
#include "Bloque.h"
#include "Grilla.h"



struct BloqueI : Bloque
{
	TipoDeBloque tipoBloque = TipoDeBloque::I;
	Rotacion state = Rotacion::Grado0;
	bool derecha = { true };
	bool izquierda = { true };

	const Posicion tetromino[4][4] = { {{1,0},{1,1},{1,2},{1,3}},
									   {{0,2},{1,2},{2,2},{3,2}},
									   {{2,0},{2,1},{2,2},{2,3}},
									   {{0,1},{1,1},{2,1},{3,1}} };
	Posicion inicial = { 0,0 };
	Posicion relativo = { 0,0 };

	BloqueI( TipoDeBloque tipoDeBloque, Rotacion estado, bool right, bool left,Posicion initial) : Bloque( tipoDeBloque, estado, derecha, izquierda,initial)
	{
		
		this->tipoBloque = tipoDeBloque;
		this->state = estado;
		this->derecha = right;
		this->izquierda = left;
		this->relativo.columna = initial.columna;
		this->relativo.fila = initial.fila;

	}
	virtual void MoverIzquierda(Grilla& grilla) 
	{
		cout << "Hola";
		if (izquierda)
		{
			relativo.columna--;
			switch (state)
			{
			case Rotacion::Grado0:
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

	void BajarPieza(Grilla& grilla) override
	{


		if (grilla.tablero[relativo.fila+1][relativo.columna]==TipoDeBloque::Vacio)
		{
			DesDibujar(grilla);
			relativo.fila++;
			Dibujar(grilla);
		}
		else
		{
			Dibujar(grilla);
			return;
		}
	}
	void Dibujar(Grilla& grilla) override
	{
		grilla.tablero[relativo.fila + tetromino[0][0].fila][relativo.columna + tetromino[0][0].columna] = tipoBloque;
		grilla.tablero[relativo.fila + tetromino[0][1].fila][relativo.columna + tetromino[0][1].columna] = tipoBloque;
		grilla.tablero[relativo.fila + tetromino[0][2].fila][relativo.columna + tetromino[0][2].columna] = tipoBloque;
		grilla.tablero[relativo.fila + tetromino[0][3].fila][relativo.columna + tetromino[0][3].columna] = tipoBloque;
	}
	void DesDibujar(Grilla& grilla) override
	{
		grilla.tablero[relativo.fila + tetromino[0][0].fila][relativo.columna + tetromino[0][0].columna] = TipoDeBloque::Vacio;
		grilla.tablero[relativo.fila + tetromino[0][1].fila][relativo.columna + tetromino[0][1].columna] = TipoDeBloque::Vacio;
		grilla.tablero[relativo.fila + tetromino[0][2].fila][relativo.columna + tetromino[0][2].columna] = TipoDeBloque::Vacio;
		grilla.tablero[relativo.fila + tetromino[0][3].fila][relativo.columna + tetromino[0][3].columna] = TipoDeBloque::Vacio;
	}
	void MoverDerecha() {
		{

		};
	}
};

