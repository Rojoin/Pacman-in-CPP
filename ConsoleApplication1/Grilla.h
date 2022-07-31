#pragma once
#include <iostream>
#include <windows.h>
#include "Fantasma.h"
#include "Globales.h"
#include <time.h>

using namespace std;


struct Grilla {

	TipoDeBloque tablero[filas][columnas];
	char tableroDibujado[filas][columnas] =
	{
		{eSI, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pTT, pTT, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, eSD}, //linea0
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea1
		{pVV, oMM, eSI, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, eSD, oMM, pVV, pVV, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, eSD, oMM, pVV}, //linea2
		{pVV, pil, pVV, spa, spa, pVV, oMM, pVV, spa, spa, spa, pVV, oMM, pVV, pVV, oMM, pVV, spa, spa, spa, pVV, oMM, pVV, spa, spa, pVV, pil, pVV}, //linea3
		{pVV, oMM, eII, pHH, pHH, eID, oMM, eII, pHH, pHH, pHH, eID, oMM, eII, eID, oMM, eII, pHH, pHH, pHH, eID, oMM, eII, pHH, pHH, eID, oMM, pVV}, //linea4
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea5
		{pVV, oMM, eSI, pHH, pHH, eSD, oMM, eSI, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH, pHH, eSD, oMM, eSI, eSD, oMM, eSI, pHH, pHH, eSD, oMM, pVV}, //linea6
		{pVV, oMM, eII, pHH, pHH, eID, oMM, pVV, pVV, oMM, eII, pHH, pHH, eSD, eSI, pHH, pHH, eID, oMM, pVV, pVV, oMM, eII, pHH, pHH, eID, oMM, pVV}, //linea7
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea8
		{eII, pHH, pHH, pHH, pHH, eSD, oMM, pVV, eII, pHH, pHH, eSD, spa, pVV, pVV, spa, eSI, pHH, pHH, eID, pVV, oMM, eSI, pHH, pHH, pHH, pHH, eID}, //linea9
		{spa, spa, spa, spa, spa, pVV, oMM, pVV, eSI, pHH, pHH, eID, spa, eII, eID, spa, eII, pHH, pHH, eSD, pVV, oMM, pVV, spa, spa, spa, spa, spa}, //linea10
		{spa, spa, spa, spa, spa, pVV, oMM, pVV, pVV, spa, spa, spa, spa, spa, spa, spa, spa, spa, spa, pVV, pVV, oMM, pVV, spa, spa, spa, spa, spa}, //linea11
		{pHH, pHH, pHH, pHH, pHH, eID, oMM, eII, eID, spa, eSI, pHH, pHH, ent, ent, pHH, pHH, eSD, spa, eII, eID, oMM, eII, pHH, pHH, pHH, pHH, pHH}, //linea12
		{spa, spa, spa, spa, spa, spa, oMM, spa, spa, spa, pVV, spa, spa, spa, spa, spa, spa, pVV, spa, spa, spa, oMM, spa, spa, spa, spa, spa, spa}, //linea13
		{pHH, pHH, pHH, pHH, pHH, eSD, oMM, eSI, eSD, spa, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, spa, eSI, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH}, //linea14
		{spa, spa, spa, spa, spa, pVV, oMM, pVV, pVV, spa, spa, spa, spa, spa, spa, spa, spa, spa, spa, pVV, pVV, oMM, pVV, spa, spa, spa, spa, spa}, //linea15
		{eSI, pHH, pHH, pHH, pHH, eID, oMM, eII, eID, spa, eSI, pHH, pHH, pHH, pHH, pHH, pHH, eSD, spa, eII, eID, oMM, eII, pHH, pHH, pHH, pHH, eSD}, //linea16
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, eII, pHH, pHH, eSD, eSI, pHH, pHH, eID, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea17
		{pVV, oMM, eSI, pHH, pHH, pHH, pHH, pHH, eSD, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, eSI, pHH, pHH, pHH, pHH, pHH, eSD, oMM, pVV}, //linea18
		{pVV, oMM, eII, pHH, eSD, spa, spa, spa, eII, pHH, pHH, eSD, oMM, pVV, pVV, oMM, eSI, pHH, pHH, eID, spa, spa, spa, eSI, pHH, eID, oMM, pVV}, //linea19
		{pVV, pil, oMM, oMM, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, oMM, eII, eID, oMM, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, oMM, oMM, pil, pVV}, //linea20
		{eII, pHH, eSD, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, eSI, pHH, eID}, //linea21
		{eSI, pHH, eID, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eII, pHH, eSD}, //linea22
		{pVV, oMM, oMM, oMM, pVV, spa, spa, spa, pVV, oMM, eII, pHH, pHH, eSD, eSI, pHH, pHH, eID, oMM, pVV, spa, spa, spa, pVV, oMM, oMM, oMM, pVV}, //linea23
		{pVV, oMM, eSI, pHH, eID, spa, spa, spa, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, spa, spa, spa, eII, pHH, eSD, oMM, pVV}, //linea24
		{pVV, oMM, eII, pHH, pHH, pHH, pHH, pHH, eID, oMM, eSI, eSD, oMM, eII, eID, oMM, eSI, eSD, oMM, eII, pHH, pHH, pHH, pHH, pHH, eID, oMM, pVV}, //linea25
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea26
		{eII, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pTI, pTI, pHH, pHH, pHH, pHH, pTI, pTI, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, eID}  //linea27
	};
	void GrillaReset()
	{

		for (int fil = 0; fil < filas; fil++)
		{
			for (int col = 0; col < columnas; col++)
			{
				switch (tableroDibujado[fil][col])
				{
				case pVV:
				case pHH:
				case eII:
				case eSI:
				case eID:
				case eSD:
				case pTI:
				case pTT:

					tablero[fil][col] = TipoDeBloque::Dibujo;
					ElegirColor(Colores::AzulClaro);
					break;
				case ent:
					tablero[fil][col] = TipoDeBloque::Dibujo;
					ElegirColor(Colores::Blanco);
					
					break;
				case oMM:
					tablero[fil][col] = TipoDeBloque::Cocos;
					ElegirColor(Colores::Blanco);
					break;
				case pil:
					tablero[fil][col] = TipoDeBloque::Pildora;
					ElegirColor(Colores::Amarillo);
					break;
				case spa:
					tablero[fil][col] = TipoDeBloque::Vacio;
					ElegirColor(Colores::Blanco);

				default:
					break;
				}
				std::cout << tableroDibujado[fil][col];

			}
			std::cout << std::endl;
		}
	}
	void Iniciar(int pacmanX, int pacmanY, Fantasma fantasma[])
	{

		{

			for (int fil = 0; fil < filas; fil++)
			{
				for (int col = 0; col < columnas; col++)
				{
					MoverCursor(col, fil);
					switch (tableroDibujado[fil][col])
					{
					case pVV:
					case pHH:
					case eII:
					case eSI:
					case eID:
					case eSD:
					case pTI:
					case pTT:
						tablero[fil][col] = TipoDeBloque::Dibujo;
						ElegirColor(Colores::AzulClaro);

						break;
					case ent:
						tablero[fil][col] = TipoDeBloque::Dibujo;
						ElegirColor(Colores::Blanco);
						break;
					case oMM:
						tablero[fil][col] = TipoDeBloque::Cocos;
						ElegirColor(Colores::Blanco);
						break;
					case pil:
						tablero[fil][col] = TipoDeBloque::Pildora;
						ElegirColor(Colores::Amarillo);

						break;
					case spa:
						tablero[fil][col] = TipoDeBloque::Vacio;
						ElegirColor(Colores::Blanco);
						break;
					}
					bool posicionOcupada = false;
					for (int i = 0; i < maximoFantasmas; i++)
					{
						if (fantasma[i].x == col && fantasma[i].y == fil)
						{
							posicionOcupada = true;
						}
					}
					if (pacmanX == col && pacmanY == fil)
					{

						posicionOcupada = true;
					}
					else if (!posicionOcupada)
					{
						std::cout << tableroDibujado[fil][col];
					}



				}
			}
		}
	}
	void Dibujar(int pacmanX, int pacmanY, Fantasma fantasma[])
	{

		for (int fil = 0; fil < filas; fil++)
		{
			for (int col = 0; col < columnas; col++)
			{
				MoverCursor(col, fil);
				switch (tableroDibujado[fil][col])
				{
				case pVV:
				case pHH:
				case eII:
				case eSI:
				case eID:
				case eSD:
				case pTI:
				case pTT:
					ElegirColor(Colores::AzulClaro);
					break;
				case ent:
				case oMM:
				case spa:
					ElegirColor(Colores::Blanco);
					break;
				case pil:
					ElegirColor(Colores::Amarillo);
					break;
				default:
					break;
				}
				bool posicionOcupada = false;
				for (int fantas = 0; fantas < maximoFantasmas; fantas++)
				{
					if (fantasma[fantas].x == col && fantasma[fantas].y == fil)
					{
						posicionOcupada = true;
					}
				}
				if (pacmanX == col && pacmanY == fil)
				{

					posicionOcupada = true;
				}

				if (!posicionOcupada)
				{
					std::cout << tableroDibujado[fil][col];
				}
			}
		}
	}
	void Chekear()
	{

		for (int fil = 0; fil < filas; fil++)
		{
			for (int col = 0; col < columnas; col++)
			{
				if (tablero[fil][col] == TipoDeBloque::Vacio)
				{
					ElegirColor(Colores::Blanco);
					tableroDibujado[fil][col] = spa;
				}


			}
		}
	};
	void DesDibujarFantasma(Fantasma& fantasma)
	{
		MoverCursor(fantasma.x, fantasma.y);
		ElegirColor(Colores::Blanco);
		std::cout << spa;
	}
	void DibujarFantasma(Fantasma& fantasma)
	{
		MoverCursor(fantasma.x, fantasma.y);
		ElegirColor(fantasma.colorActual);
		std::cout << fantasma.cuerpoActual;
	}
	void MoverFantasma(Fantasma& fantasma)
	{


		Direccion random = (Direccion)(rand() % 4);
		switch (random)
		{
		case Direccion::Derecha:
			if (tablero[fantasma.y][fantasma.x + 1] != TipoDeBloque::Dibujo)
			{
				fantasma.direccionActual = Direccion::Derecha;
				if (fantasma.direccionAnterior == Direccion::Izquierda)
				{
					fantasma.direccionActual = fantasma.direccionAnterior;
				}
			}


			break;
		case Direccion::Izquierda:
			if (tablero[fantasma.y][fantasma.x - 1] != TipoDeBloque::Dibujo)

			{
				fantasma.direccionActual = Direccion::Izquierda;

				if (fantasma.direccionAnterior == Direccion::Derecha)
				{
					fantasma.direccionActual = fantasma.direccionAnterior;
				}
			}

			break;
		case Direccion::Arriba:
			if (tablero[fantasma.y - 1][fantasma.x] != TipoDeBloque::Dibujo)

			{
				fantasma.direccionActual = Direccion::Arriba;
				if (fantasma.direccionAnterior == Direccion::Abajo)
				{
					fantasma.direccionActual = fantasma.direccionAnterior;
				}
			}

			break;
		case Direccion::Abajo:
			if (tablero[fantasma.y + 1][fantasma.x] != TipoDeBloque::Dibujo)
			{
				fantasma.direccionActual = Direccion::Abajo;
				if (fantasma.direccionAnterior == Direccion::Arriba)
				{
					fantasma.direccionActual = fantasma.direccionAnterior;
				}
			}
			break;

		}
		if (ChekearPosicionFantasma(fantasma))
		{
			fantasma.direccionAnterior = fantasma.direccionActual;
			fantasma.MovimientoFantasmal();

		}
		else
		{
			MoverFantasma(fantasma);
		}

	}
	void MoverFantasmaEncerrado(Fantasma& fantasma)
	{
		switch (fantasma.direccionActual)
		{
		case Direccion::Derecha:

			if (fantasma.x == 16)
			{
				fantasma.direccionActual = Direccion::Izquierda;
			}
			break;
		case Direccion::Izquierda:
			if (fantasma.x == 11)
			{
				fantasma.direccionActual = Direccion::Derecha;
			}
			break;
		case Direccion::Arriba:
			fantasma.direccionActual = Direccion::Izquierda;
			break;
		case Direccion::Abajo:
			fantasma.direccionActual = Direccion::Derecha;
			break;
		}

		fantasma.MovimientoFantasmal();

	}
	bool ChekearPosicionFantasma(Fantasma& fantasma)
	{

		switch (fantasma.direccionActual)
		{
		case Direccion::Derecha:
			if (tablero[fantasma.y][fantasma.x + 1] != TipoDeBloque::Dibujo)
			{
				return true;
			}

			break;
		case Direccion::Izquierda:
			if (tablero[fantasma.y][fantasma.x - 1] != TipoDeBloque::Dibujo)

			{
				return true;
			}

			break;
		case Direccion::Arriba:
			if (tablero[fantasma.y - 1][fantasma.x] != TipoDeBloque::Dibujo)
			{
				return true;
			}
			break;

		case Direccion::Abajo:
			if (tablero[fantasma.y + 1][fantasma.x] != TipoDeBloque::Dibujo)
			{
				return true;
			}
			break;
		}
		return false;
	}
};