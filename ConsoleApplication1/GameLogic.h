#pragma once
#include "PacMan.h"
#include "Fantasma.h"
#include "Grilla.h"
#include "Graphics.h"
#include <conio.h>


Grilla grilla;
Pacman pacman;
//Fantasma fantasma[4]{ {4,1,EstadoFantasma::Normal},{2,1,EstadoFantasma::Normal},{3,1,EstadoFantasma::Normal},{13,13,EstadoFantasma::Encerrado} };
Fantasma fantasma[4]{ };
//Fantasma fantasma[1]{ {4,1} };

void FuenteDeConsola(int ancho, int alto)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = 24;
	cfi.dwFontSize.Y = 24;
	cfi.nFont = 4;
		cfi.FontFamily = FF_DONTCARE;

		wcscpy_s(cfi.FaceName, L"Terminal"); // Choose your font
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void RemoveScrollbarAndResize()
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // Consigo una referencia al handle de salida
	CONSOLE_SCREEN_BUFFER_INFO info; // Creo una variable de informacion del buffer de la pantalla
	GetConsoleScreenBufferInfo(handle, &info); // Consigo el buffer actual de la pantalla de la GetStdHandle(STD_OUTPUT_HANDLE)

	COORD new_size // Creo una variable que indica que el buffer actual de la pantalla es exactamente igual al tamaño de la pantalla + 1 pixel
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};

	SetConsoleScreenBufferSize(handle, new_size); // Seteo mi nuevo tamaño de buffer con mi variable
	HWND consoleWindow = GetConsoleWindow(); // Consigo una referencia a la ventana de la GetStdHandle(STD_OUTPUT_HANDLE)
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
void ResetAfterDead(Fantasma fantasma[], Pacman& pacman)
{
	pacman.ResetearPosicion();
	for (int fantas = 0; fantas < maximoFantasmas; fantas++)
	{
		fantasma[fantas].ResetearPosicion(fantas);
	}
}
void ResetFantasmas(Fantasma fantasma[], int& timerCasa)
{
	for (int fantas = 0; fantas < maximoFantasmas; fantas++)
	{
		fantasma[fantas].Normalizar();
	}
	timerCasa = clock();
}
void SacarFantasmasDeLaCasa(Fantasma fantasma[],int& timerCasa)
{
	bool aux = false;
	for (int fantas = 0; fantas < maximoFantasmas; fantas++)
	{
		if (fantasma[fantas].SalirDeCasa())
		{
			timerCasa = clock();
		
			break;	
		}
	}

		timerCasa = clock();
	

}
void IniciarFantasmas(Fantasma fantasma[])
{
	for (int fantas = 0; fantas < maximoFantasmas; fantas++)
	{
		fantasma[fantas].ResetearPosicion(fantas);
		switch (fantas)
		{
		case 0:
			fantasma[fantas].colorDefault = Colores::Rojo;
			fantasma[fantas].colorActual = fantasma[fantas].colorDefault;
			break;
		case 1:
			fantasma[fantas].colorDefault = Colores::Verde;
			fantasma[fantas].colorActual = fantasma[fantas].colorDefault;
			break;
		case 2:
			fantasma[fantas].colorDefault = Colores::VioletaClaro;
			fantasma[fantas].colorActual = fantasma[fantas].colorDefault;
			break;
		case 3:
			fantasma[fantas].colorDefault = Colores::Celeste;
			fantasma[fantas].colorActual = fantasma[fantas].colorDefault;
			break;
		}
	}
	
}
void Colisiones(Fantasma fantasma[],Pacman& pacman,Grilla& grilla,int& timerFantasma,bool& GameOver)
{
	if (pacman.CheckearTablero(grilla) == TipoDeBloque::Pildora)
	{
		 timerFantasma = clock();
		for (int i = 0; i < maximoFantasmas; i++)
		{
			fantasma[i].Debilitar();
		}
	}
	for (int i = 0; i < maximoFantasmas; i++)
	{
		if (pacman.x == fantasma[i].x && pacman.y == fantasma[i].y)
		{
			if (fantasma[i].estado == EstadoFantasma::Debil)
			{
				
				pacman.DibujarPacMan();
				fantasma[i].estado = EstadoFantasma::Encerrado;
				fantasma[i].x = fantasma[i].xCaja;
				fantasma[i].y = fantasma[i].yCaja;
				Sleep(500);
				pacman.puntuacion += 100;
			}
			else if (fantasma[i].estado == EstadoFantasma::Normal)
			{
				pacman.SecuenciaMuerte(GameOver);
				ResetAfterDead(fantasma, pacman);
			}
		}
	}
}
void GameLogic()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	/*	static CONSOLE_FONT_INFOEX  fontex;
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
	int timerFantasma;
	int timerCasa = clock();
	bool gameover = false;

	grilla.Iniciar(pacman.x, pacman.y, fantasma);
	IniciarFantasmas(fantasma);
	int tiempo = 0;

	while (!gameover)
	{
		
		do
		{

		Colisiones(fantasma, pacman,grilla,timerFantasma,gameover);
		int tiempoActual = clock();
			

			
			if (tiempo % 2000 == 0)
			{
				
				
				pacman.PuntuacionActual();
				grilla.Dibujar(pacman.x, pacman.y, fantasma);
				grilla.Chekear();
				pacman.DesDibujar();
				Colisiones(fantasma, pacman, grilla, timerFantasma, gameover);
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
				Colisiones(fantasma, pacman, grilla, timerFantasma, gameover);
				pacman.DesDibujar();
				pacman.DibujarPacMan(midAnimation);

			}
			if (tiempo%3000 == 0)
			{
				for (int fantas = 0; fantas < maximoFantasmas; fantas++)
				{
					if (fantasma[fantas].estado == EstadoFantasma::Encerrado)
					{
						grilla.MoverFantasmaEncerrado(fantasma[fantas]);
					}
					else
					{
						grilla.MoverFantasma(fantasma[fantas]);
					}
					grilla.DibujarFantasma(fantasma[fantas]);
				}
				Colisiones(fantasma, pacman, grilla, timerFantasma, gameover);
				grilla.Dibujar(pacman.x, pacman.y, fantasma);
			}

			tiempo++;
			if (tiempo == 400000)
			{
				tiempo = 0;
			}
			if ((tiempoActual- timerFantasma)/1000 == 5)
			{
				

				
				ResetFantasmas(fantasma,timerCasa);
				timerFantasma = 0;
			}
			if ((tiempoActual - timerCasa)/1000 == 5)
			{
				SacarFantasmasDeLaCasa(fantasma,timerCasa);
			}
			pacman.Ganar(gameover);
		} while (!_kbhit()&&!gameover);
		if (!gameover)
		{

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
		Colisiones(fantasma, pacman, grilla, timerFantasma, gameover);
		}
		
	};

}
