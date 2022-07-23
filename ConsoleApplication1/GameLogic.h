#pragma once
#include "PacMan.h"
#include "Fantasma.h"
#include "Grilla.h"
#include "Graphics.h"
#include <conio.h>


Grilla grilla;
Pacman pacman;
Fantasma fantasma[3]{ {4,1},{2,1},{3,1} };



void GameLogic()
{
		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 80;
	fontex.dwFontSize.X = 40;
	fontex.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(hOut, &info);

		bool gameover= false;

		grilla.Iniciar(pacman.x, pacman.y, fantasma);

	do
	{
		do
		{
			if (clock() % 150 == 0)
			{
				MoverCursor(30, 0);
				cout << pacman.puntuacion;
				grilla.Dibujar(pacman.x, pacman.y, fantasma);
				grilla.Chekear();
				pacman.DesDibujar();
				switch (pacman.direccionActual)
				{
				case DireccionPacMan::Arriba:
					pacman.MoverArriba(grilla);
					break;
				case DireccionPacMan::Abajo:
					pacman.MoverAbajo(grilla);
					break;
				case DireccionPacMan::Derecha:
					pacman.MoverDerecha(grilla);
					break;
				case DireccionPacMan::Izquierda:
					pacman.MoverIzquierda(grilla);
					break;
				}
				pacman.Colision(grilla,fantasma,gameover);
				pacman.DibujarPacMan();

			}




		} while (!_kbhit());
		switch (_getch())
		{
		case 'w':

			pacman.direccionActual = DireccionPacMan::Arriba;
			break;
		case 's':
			pacman.direccionActual = DireccionPacMan::Abajo;
			break;
		case 'd':
		{
			pacman.direccionActual = DireccionPacMan::Derecha;

		}
		break;
		case 'a':
		{
			pacman.direccionActual = DireccionPacMan::Izquierda;
	
		}
		break;
		default:
			break;
		}

	} while (!gameover);
}
