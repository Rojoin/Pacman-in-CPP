#pragma once
#include "Grilla.h"
#include "Globales.h"
#include "Fantasma.h"

struct Pacman
{
	char cuerpo[6]{ pacmanRight,pacmanLeft,pacmanUp,pacmanDown,pacmanMidDead,pacmanDead };
	char cuerpoActual = cuerpo[0];
	int x = 13;
	int y = 21;
	EstadoPacMan estado = EstadoPacMan::Normal;
	DireccionPacMan direccionActual = DireccionPacMan::Derecha;
	int vidasMax;
	int vidas = vidasMax;
	int puntuacion = { 0 };
	void Colision(Grilla& grilla, Fantasma fantasma[], bool& GameOver);
	void MoverIzquierda(Grilla grilla);
	void MoverDerecha(Grilla grilla);
	void MoverArriba(Grilla grilla);
	void MoverAbajo(Grilla grilla);
	void SecuenciaMuerte(bool& GameOver);
	void DibujarPacMan();
	void DesDibujar();
};