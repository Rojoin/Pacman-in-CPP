#pragma once
#include <iostream>
#include <windows.h>
#include "Fantasma.h"
#include "Globales.h"

using namespace std;


struct Grilla {

	TipoDeBloque tablero[filas][columnas];
	char tableroDibujado[filas][columnas + 1] =
	{
		{eSI, pH, pH, pH, pH, pH, pH, pH, pH, pH, pH, pH, pH, pT, pT, pH, pH, pH, pH, pH, pH, pH, pH, pH, pH, pH, pH, eSD},//linea 0
		{pV, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, pV, pV, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, pV },
		{pV, oM, eSI, pH, pH, eSD, oM, eSI, pH, pH, pH, eSD, oM, pV, pV, oM, eSI, pH, pH, pH, eSD, oM, eSI, pH, pH, eSD, oM, pV},
		{pV, pill, pV, space, space, pV, oM, pV, space, space, space, pV, oM, pV, pV, oM, pV, space, space, space, pV, oM, pV, space, space, pV, pill, pV},
		{pV, oM, eII, pH, pH, eID, oM, eII, pH, pH, pH, eID, oM, eII, eID, oM, eII, pH, pH, pH, eID, oM, eII, pH, pH, eID, oM, pV},
		{pV, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, pV},//linea 5
		{pV,oM,eSI,pH,pH,eSD,oM,eSI,eSD,oM,eSI,pH,pH,pH,pH,pH,pH,eSD,oM,eSI,eSD,oM,eSI,pH,pH,eSD,oM,pV},
		{pV,oM,eII,pH,pH,eID,oM,pV,pV,oM,eII,pH,pH,eSD,eSI,pH,pH,eID,oM,pV,pV,oM,eII,pH,pH,eID,oM,pV},
		{pV, oM, oM, oM, oM, oM, oM, pV,pV, oM, oM, oM, oM, pV, pV, oM, oM, oM, oM, pV,pV, oM, oM, oM, oM, oM, oM, pV },
		{eII, pH, pH, pH, pH, eSD, oM,pV,eII,pH, pH, eSD,space,pV,pV,space,eSI,pH,pH,eID,pV,oM,eSI,pH,pH,pH,pH,eID },
		{space, space, space, space, space, pV, oM,pV,eSI,pH, pH, eID,space,eII,eID,space,eII,pH,pH,eSD,pV,oM,pV, space, space, space, space },
		{space, space, space, space, space, pV, oM,pV,pV,space, space ,space,space,space,space,space,space,space,space,pV,pV,oM,pV, space, space, space, space },
		{pH, pH, pH, pH, pH, eID, oM,eII,eID,space, eSI, pH,pH,entrance,entrance,pH,pH,eSD,space,eII,eID,oM,eII,pH,pH,pH,pH,pH },
		{space, space, space, space, space,space,oM,space,space,space,pV,space,space,space,space,space,space,pV,space,space,space,oM,space, space, space, space, space,space},
		{pH, pH, pH, pH, pH, eSD, oM,eSI,eSD,space, eII, pH,pH,pH,pH,pH,pH,eID,space,eSI,eSD,oM,eSI,pH,pH,pH,pH,pH },
		{space, space, space, space, space, pV, oM,pV,pV,space, space, space,space,space,space,space,space,space,space,pV,pV,oM,pV, space, space, space, space },
		{eSI, pH, pH, pH, pH, eID, oM,eII,eID,space, eSI, pH,pH,pH,pH,pH,pH,eSD,space,eII,eID,oM,eII,pH,pH,pH,pH,eSD },
		{pV,oM,oM,oM,oM,oM,oM,oM,oM,oM,eII,pH,pH,eSD,eSI,pH,pH,eID,oM,oM,oM,oM,oM,oM,oM,oM,oM,pV},
		{pV,oM, eSI, pH, pH, pH, pH, pH,eSD, oM, oM, oM, oM, pV, pV, oM, oM, oM, oM, eSI, pH, pH, pH, pH, pH,eSD, oM, pV },
		{pV,oM, eII, pH, eSD, space, space, space,eII, pH, pH, eSD, oM, pV, pV, oM, eSI, pH, pH, eID, space, space, space, eSI, pH,eID, oM, pV },
		{pV, pill, oM, oM, eII, pH, pH, pH, pH, pH, pH, eID, oM, eII, eID,oM, eII, pH, pH, pH, pH, pH, pH, eID, oM, oM, pill, pV},
		{eII, pH,eSD, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, oM, eSI, pH, eID},
		{eSI, pH,eID, oM, eSI, pH, pH, pH, eSD, oM, eSI, pH, pH, pH, pH, pH, pH,eSD,  oM,  eSI, pH, pH, pH, eSD, oM, eII, pH, eSD},
		{pV, oM, oM, oM, pV, space, space, space,  pV,oM,eII,pH,pH,eSD,eSI,pH,pH,eID,  oM, pV, space, space, space, pV, oM, oM, oM, pV},
		{pV, oM, eSI, pH, eID, space, space, space, pV, oM, oM, oM, oM, pV, pV, oM, oM, oM, oM,  pV, space, space, space, eII, pH, eSD, oM, pV},
		{pV, oM, eII, pH, pH, pH, pH, pH, eID,  oM,eSI, eSD, oM, eII, eID, oM, eSI, eSD, oM, eII, pH, pH, pH, pH, pH, eID, oM, pV},
		{pV, oM, oM, oM, oM, oM, oM, oM, oM, oM, pV, pV, oM, oM, oM, oM, pV, pV, oM, oM, oM, oM, oM, oM, oM, oM, oM, pV},
		{eII, pH, pH, pH, pH, pH, pH, pH, pH, pH, pTIn, pTIn, pH, pH, pH, pH, pTIn, pTIn, pH, pH, pH, pH, pH, pH, pH, pH, pH, eID}
	};
	void GrillaReset()
	{

		for (int fil = 0; fil < filas; fil++)
		{
			for (int col = 0; col < columnas; col++)
			{
				switch (tableroDibujado[fil][col])
				{
				case pV:
				case pH:
				case eII:
				case eSI:
				case eID:
				case eSD:
				case pTIn:
				case pT:
				case pTI:
				case pTD:
				case pX:
					tablero[fil][col] = TipoDeBloque::Dibujo;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					break;
				case entrance:
					tablero[fil][col] = TipoDeBloque::Dibujo;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case oM:
					tablero[fil][col] = TipoDeBloque::Cocos;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case pill:
					tablero[fil][col] = TipoDeBloque::Pildora;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					break;
				case space:
					tablero[fil][col] = TipoDeBloque::Vacio;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

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
				for (int col = 0; col < columnas - 1; col++)
				{
					MoverCursor(col, fil);
					switch (tableroDibujado[fil][col])
					{
					case pV:
					case pH:
					case eII:
					case eSI:
					case eID:
					case eSD:
					case pTIn:
					case pT:
					case pTI:
					case pTD:
					case pX:
						tablero[fil][col] = TipoDeBloque::Dibujo;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
						break;
					case entrance:
						tablero[fil][col] = TipoDeBloque::Dibujo;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						break;
					case oM:
						tablero[fil][col] = TipoDeBloque::Cocos;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						break;
					case pill:
						tablero[fil][col] = TipoDeBloque::Pildora;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
						break;
					case space:
						tablero[fil][col] = TipoDeBloque::Vacio;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					default:
						break;
					}
					bool posicionOcupada = false;
					for (int i = 0; i < maximoFantasmas; i++)
					{
						if (fantasma[i].x == col && fantasma[i].y == fil)
						{
							std::cout << fantasma[i].cuerpoActual;
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
			for (int col = 0; col < columnas - 1; col++)
			{
				MoverCursor(col, fil);
				switch (tableroDibujado[fil][col])
				{
				case pV:
				case pH:
				case eII:
				case eSI:
				case eID:
				case eSD:
				case pTIn:
				case pT:
				case pTI:
				case pTD:
				case pX:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					break;
				case entrance:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case oM:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case pill:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					break;
				case space:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				default:
					break;
				}
				bool posicionOcupada = false;
				for (int i = 0; i < maximoFantasmas; i++)
				{
					if (fantasma[i].x == col && fantasma[i].y == fil)
					{
						std::cout << fantasma[i].cuerpoActual;
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
	void Chekear()
	{

		for (int fil = 0; fil < filas; fil++)
		{
			for (int col = 0; col < columnas - 1; col++)
			{
				if (tablero[fil][col] == TipoDeBloque::Vacio)
				{
					tableroDibujado[fil][col] = space;
				}
				
				
			}
		}
	};



};

