#pragma once
#include "Grilla.h"
#include "Globales.h"
#include "Fantasma.h"

struct Pacman
{
	char cuerpo[7]{ pacmanRight,pacmanLeft,pacmanUp,pacmanDown,pacmanMidDeadH,pacmanMidDeadV,pacmanDead };
	char cuerpoActual = cuerpo[0];
	const int xDefault = 13;
	const  int yDefault = 21;
	int x = xDefault;
	int y = yDefault;
	Colores colorBase = Colores::Amarillo;
	EstadoPacMan estado = EstadoPacMan::Normal;
	Direccion direccionActual = Direccion::Derecha;
	Direccion direccionAnterior= direccionActual;
	Direccion direccionBuffer= direccionActual;
	int vidasMax = 3;
	int vidas = vidasMax;
	int puntuacion = { 0 };
	int cocos = { 0 };
	TipoDeBloque CheckearTablero(Grilla& grilla);
	void MoverIzquierda(Grilla grilla,int& frames);
	void MoverDerecha(Grilla grilla, int& frames);
	void MoverArriba(Grilla grilla, int& frames);
	void MoverAbajo(Grilla grilla, int& frames);
	void Ganar(bool& GameOver);
	void SecuenciaMuerte(bool& GameOver);
	void AnimacionMuerte();
	void DibujarPacMan(bool& aux);
	void DibujarPacMan();
	void DesDibujar();
	void GuardarDireccionAnterior();
	void SettearDireccionAnterior();
	void SetBuffer();
	void GetBuffer();
	void ResetearPosicion();
	void PuntuacionActual();
};