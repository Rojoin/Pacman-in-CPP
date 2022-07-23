#include "PacMan.h"
#include "Globales.h"
#include "Fantasma.h"


void Pacman::MoverAbajo(Grilla grilla)
{
	
	if (grilla.tablero[y + 1][x] != TipoDeBloque::Dibujo)
	{
		y++;
	}

}
void Pacman::MoverArriba(Grilla grilla)
{
	if (grilla.tablero[y -1][x] != TipoDeBloque::Dibujo)
	{
		y--;
	}
	
}
void Pacman::MoverDerecha(Grilla grilla)
{

	if (x >= columnas-2)
	{
		x = 0;
	}
	else if (grilla.tablero[y][x+ 1] != TipoDeBloque::Dibujo)
	{
		x++;
	}
	
}

void Pacman::MoverIzquierda(Grilla grilla)
{

	if (x <= 0)
	{
		x = columnas-2;

	}
	else if (grilla.tablero[y][x -1] != TipoDeBloque::Dibujo)
	{
		x--;
	}
}
void Pacman::DibujarPacMan()
{
	if (estado == EstadoPacMan::Normal)
	{
		MoverCursor(x, y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		switch (direccionActual)
		{
		case DireccionPacMan::Izquierda:
			cuerpoActual = cuerpo[(int)DireccionPacMan::Izquierda];
			break;
		case DireccionPacMan::Derecha:
			cuerpoActual = cuerpo[(int)DireccionPacMan::Derecha];
			break;
		case DireccionPacMan::Arriba:
			cuerpoActual = cuerpo[(int)DireccionPacMan::Arriba];
			break;
		case DireccionPacMan::Abajo:
			cuerpoActual = cuerpo[(int)DireccionPacMan::Abajo];
			break;
		}
		cout << cuerpoActual;
	}
}
void Pacman::DesDibujar()
{
	MoverCursor(x, y);
	cout << space;
}
void Pacman::Colision(Grilla& grilla, Fantasma fantasma[], bool& GameOver)
{
	switch (grilla.tablero[y][x])
	{
	case TipoDeBloque::Vacio:
		break;
	case TipoDeBloque::Cocos:
		puntuacion++;
		grilla.tablero[y][x] = TipoDeBloque::Vacio;
		break;
	case TipoDeBloque::Pildora:
		puntuacion+= 10;
		for (int i = 0; i < maximoFantasmas; i++)
		{
			fantasma->estado = EstadoFantasma::Debil;
		}
		grilla.tablero[y][x] = TipoDeBloque::Vacio;
		break;
	case TipoDeBloque::Fruta:
		puntuacion += 10;
		grilla.tablero[y][x] = TipoDeBloque::Vacio;
		break;
	}
	for (int i = 0; i < maximoFantasmas; i++)
	{
		if (x == fantasma[i].x && y == fantasma[i].y)
		{
			if (fantasma[i].estado == EstadoFantasma::Debil)
			{
				fantasma[i].estado = EstadoFantasma::Muerto;
				fantasma[i].x = 1;
				fantasma[i].y = 1;
				puntuacion += 100;
			}
			else if(fantasma[i].estado == EstadoFantasma::Normal )
			{
				SecuenciaMuerte(GameOver);
			}
		}
	}
}
void Pacman::SecuenciaMuerte(bool& GameOver)
{
	vidas--;
	if (vidas <= 0)
	{
		GameOver = true;
	}
}
