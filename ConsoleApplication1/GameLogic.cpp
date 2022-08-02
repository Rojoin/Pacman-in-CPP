#include "GameLogic.h"

Grilla grilla;
Pacman pacman;
Fantasma fantasma[4]{ };
int tiempo = 0;
bool midAnimation = false;
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
		fantasma[fantas].timerFantasma = clock() + (fantas * 5000);
	}
}
void ResetFantasmas(Fantasma fantasma[])
{
	for (int fantas = 0; fantas < maximoFantasmas; fantas++)
	{
		fantasma[fantas].Normalizar();
	}

}
void SacarFantasmasDeLaCasa(Fantasma fantasma[], int tiempoActual)
{
	
	for (int fantas = 0; fantas < maximoFantasmas; fantas++)
	{
		if (fantasma[fantas].SalirDeCasa(tiempoActual))
		{


			
		}
	}

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
		fantasma[fantas].cuerpoActual = fantasma[fantas].cuerpo[0] ;
		fantasma[fantas].timerFantasma = clock()+(fantas*5000);
	}

}

void IniciarJuego(bool& continuar,int& tiempo, bool& midAnimation,bool& juegoCorriendo,int& timerFantasmal, int& timerCasa, bool& gameover, bool& murio)
{
    midAnimation = false;
	juegoCorriendo = true;
	timerFantasmal =0;
	timerCasa = clock();
	gameover = false;
	murio = true;
	pacman.IniciarPacman(continuar);
	if (continuar)
	{
		pacman.DibujarPacMan();
		grilla.Dibujar(pacman.x, pacman.y);
	}
	continuar = false;
	grilla.Iniciar(pacman.x, pacman.y, fantasma);
	IniciarFantasmas(fantasma);
	tiempo = 0;
	Sleep(500);
}
void Colisiones(Fantasma fantasma[], Pacman& pacman, Grilla& grilla, int& timerFantasma, bool& GameOver, bool& dead, bool& juegoCorriendo,int& GameTimeFantasma, int& GameTimePacman)
{
	if (pacman.CheckearTablero(grilla) == TipoDeBloque::Pildora)
	{
		timerFantasma = clock();
		for (int i = 0; i < maximoFantasmas; i++)
		{
			fantasma[i].Debilitar();

		}
		GameTimeFantasma = GameTimeDefault - GametimePowerUp;
		GameTimePacman = GameTimeDefault +(GametimePowerUp*2);
	}
	int multiplicador =1;
	for (int i = 0; i < maximoFantasmas; i++)
	{

		if (pacman.x == fantasma[i].x && pacman.y == fantasma[i].y)
		{
			if (fantasma[i].estado == EstadoFantasma::Debil)
			{
				multiplicador++;
				pacman.DibujarPacMan();

				fantasma[i].Encarcelar();
				fantasma[i].timerFantasma = clock()+5000;
				Sleep(500);
				pacman.puntuacion += 200*multiplicador;
			}
			else if (fantasma[i].estado == EstadoFantasma::Normal)
			{
				pacman.SecuenciaMuerte(GameOver, dead, juegoCorriendo);
				ResetAfterDead(fantasma, pacman);


				Sleep(500);

			}
		}
	}
}

void GameLogic()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	FuenteDeConsola(5, 5);
	TamañoYScroller();
	bool continuar = false;
	bool midAnimation = false;
	bool juegoCorriendo = true;
	int frame = 150;
	int timerFantasma;
	int timerCasa = clock();
	bool gameover = false;
	bool murio = true;
	int tiempo;
	
	int GameTimeFantasma = GameTimeDefault;
	int GameTimePacman = GameTimeDefault;
	IniciarJuego(continuar, tiempo, midAnimation, juegoCorriendo, timerFantasma, timerCasa, gameover, murio);
	

	while (juegoCorriendo)
	{

		do
		{
			if (murio)
			{
				murio = false;
				pacman.DibujarPacMan(midAnimation);
				Sleep(1500);
			};
			Colisiones(fantasma, pacman, grilla, timerFantasma, gameover, murio, juegoCorriendo, GameTimeFantasma, GameTimePacman);
			int tiempoActual = clock();



			if (tiempo % GameTimeFantasma == 0)
			{

				pacman.DibujarPuntuacion();
				grilla.Dibujar(pacman.x, pacman.y, fantasma);

				grilla.Chekear();
				pacman.DesDibujar();
				Colisiones(fantasma, pacman, grilla, timerFantasma, gameover, murio, juegoCorriendo, GameTimeFantasma, GameTimePacman);
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
				Colisiones(fantasma, pacman, grilla, timerFantasma, gameover, murio, juegoCorriendo, GameTimeFantasma, GameTimePacman);
				pacman.DesDibujar();
				pacman.DibujarPacMan(midAnimation);

			}
			if (tiempo % GameTimePacman == 0)
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

				Colisiones(fantasma, pacman, grilla, timerFantasma, gameover, murio, juegoCorriendo, GameTimeFantasma, GameTimePacman);
				grilla.Dibujar(pacman.x, pacman.y, fantasma);
			}

			tiempo++;
			if (tiempo == 400000)
			{
				tiempo = 0;
			}
			if ((tiempoActual - timerFantasma) / 1000 == 10)
			{

				ResetFantasmas(fantasma);
				timerFantasma = 0;
				GameTimeFantasma = GameTimeDefault;
				GameTimePacman = GameTimeDefault;
				
			}
			SacarFantasmasDeLaCasa(fantasma, tiempoActual);
			if (pacman.Ganar(gameover,continuar))
			{
				grilla.Chekear();
				grilla.Dibujar(pacman.x, pacman.y, fantasma);

				IniciarJuego(continuar, tiempo, midAnimation, juegoCorriendo, timerFantasma, timerCasa, gameover, murio);
			}
		} while (!_kbhit() && !gameover);
		if (!gameover)
		{

			pacman.GuardarDireccionAnterior();
			InputManager(pacman, gameover, juegoCorriendo);
			pacman.SetBuffer();
			Colisiones(fantasma, pacman, grilla, timerFantasma, gameover, murio, juegoCorriendo, GameTimeFantasma, GameTimePacman);
		}

	};

}
