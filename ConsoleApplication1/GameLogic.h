#pragma once
#include "PacMan.h"
#include "Fantasma.h"
#include "Grilla.h"
#include "Graphics.h"
#include <conio.h>


Grilla grilla;
Pacman pacman;
Fantasma fantasma[3]{ {4,1},{2,1},{3,1} };
//Fantasma fantasma[1]{ {4,1} };

void FuenteDeConsola(int ancho, int alto)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = 24;
	cfi.dwFontSize.Y = 24;
	cfi.nFont = 4;
	cfi.FontFamily =
		cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void RemoveScrollbarAndResize()
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // Consigo una referencia al handle de salida
	CONSOLE_SCREEN_BUFFER_INFO info; // Creo una variable de informacion del buffer de la pantalla
	GetConsoleScreenBufferInfo(handle, &info); // Consigo el buffer actual de la pantalla de la consola

	COORD new_size // Creo una variable que indica que el buffer actual de la pantalla es exactamente igual al tamaño de la pantalla + 1 pixel
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};

	SetConsoleScreenBufferSize(handle, new_size); // Seteo mi nuevo tamaño de buffer con mi variable
	HWND consoleWindow = GetConsoleWindow(); // Consigo una referencia a la ventana de la consola
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX); // Seteo el tamaño de la pantalla como el tamaño total incluyendo los bordes, por lo tanto tapo los eventos de resize

}


void TamañoYScroller()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);

	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};

	SetConsoleScreenBufferSize(handle, new_size);
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}


void GameLogic()
{
	/*	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
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
		SetConsoleCursorInfo(hOut, &info);*/
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	FuenteDeConsola(5, 5);
	TamañoYScroller();
	bool midAnimation = false;

	int frame = 150;

	bool gameover = false;

	grilla.Iniciar(pacman.x, pacman.y, fantasma);

	do
	{
		do
		{
			if (clock() % frame == 0)
			{
				for (int fantas = 0; fantas < maximoFantasmas; fantas++)
				{

					grilla.MoverFantasma(fantasma[fantas]);
				grilla.DibujarFantasma(fantasma[fantas]);
				}
				MoverCursor(30, 0);
				cout << pacman.puntuacion;
				grilla.Dibujar(pacman.x, pacman.y, fantasma);
				grilla.Chekear();
				pacman.DesDibujar();

				switch (pacman.direccionActual)
				{
				case Direccion::Arriba:
					pacman.MoverArriba(grilla, frame);
					break;
				case Direccion::Abajo:
					pacman.MoverAbajo(grilla, frame);
					break;
				case Direccion::Derecha:
					pacman.MoverDerecha(grilla, frame);
					break;
				case Direccion::Izquierda:
					pacman.MoverIzquierda(grilla, frame);
					break;
				}

				pacman.Colision(grilla, fantasma, gameover);
				pacman.DibujarPacMan(midAnimation);
			}




		} while (!_kbhit());
		pacman.GuardarDireccionAnterior();
		switch (_getch())
		{
		case 'w':

			pacman.direccionActual = Direccion::Arriba;
			break;
		case 's':
			pacman.direccionActual = Direccion::Abajo;
			break;
		case 'd':
		{
			pacman.direccionActual = Direccion::Derecha;

		}
		break;
		case 'a':
		{
			pacman.direccionActual = Direccion::Izquierda;
		}
		break;
		default:
			break;
		}
		pacman.SetBuffer();

	} while (!gameover);
}
