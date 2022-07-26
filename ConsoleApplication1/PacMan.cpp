#include "PacMan.h"
#include "Globales.h"
#include "Fantasma.h"


void Pacman::MoverAbajo(Grilla grilla, int& frames)
{
	if (grilla.tablero[y + 1][x] != TipoDeBloque::Dibujo)
	{

		y++;
		GuardarDireccionAnterior();
		if (direccionBuffer != direccionActual)
		{
			GetBuffer();
			frames = 125;
		}
		else
		{
			frames = 150;
		}
	}
	else
	{
		frames = 150;
			SettearDireccionAnterior();

		
	}

}
void Pacman::MoverArriba(Grilla grilla, int& frames)
{

	if (grilla.tablero[y - 1][x] != TipoDeBloque::Dibujo)
	{

		y--;
		GuardarDireccionAnterior();
		if (direccionBuffer != direccionActual)
		{
			GetBuffer();
			frames = 125;
		}
		else
		{
			frames = 150;
		}
	}
	else
	{
		frames = 150;
			SettearDireccionAnterior();

	}

}
void Pacman::MoverDerecha(Grilla grilla, int& frames)
{

	
    if (x >= columnas - 1)
	{
		x = 0;
	}
	else if (grilla.tablero[y][x + 1] != TipoDeBloque::Dibujo)
	{
		frames = 150;
		x++;
		GuardarDireccionAnterior();
		if (direccionBuffer != direccionActual)
		{
			GetBuffer();
			frames = 125;
		}
		else
		{
			frames = 150;
		}
	}
	else
	{
		SettearDireccionAnterior();
		frames = 150;
	}

}

void Pacman::MoverIzquierda(Grilla grilla, int& frames)
{

	
	if (x <= 0)
	{
		x = columnas - 1;

	}
	else if (grilla.tablero[y][x - 1] != TipoDeBloque::Dibujo)
	{
		x--;
		GuardarDireccionAnterior();
		
		if (direccionBuffer != direccionActual)
		{
			GetBuffer();
			frames = 125;
		}
		else
		{
			frames = 150;
		}
	}
	else
	{
			SettearDireccionAnterior();
			frames = 150;
	}
}
void Pacman::DibujarPacMan(bool& aux)
{
	if (estado == EstadoPacMan::Normal)
	{
			MoverCursor(x, y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		if (!aux)
		{

			switch (direccionAnterior)
			{
			case Direccion::Izquierda:
				cuerpoActual = cuerpo[(int)Direccion::Izquierda];
				break;
			case Direccion::Derecha:
				cuerpoActual = cuerpo[(int)Direccion::Derecha];
				break;
			case Direccion::Arriba:
				cuerpoActual = cuerpo[(int)Direccion::Arriba];
				break;
			case Direccion::Abajo:
				cuerpoActual = cuerpo[(int)Direccion::Abajo];
				break;
			}
			aux = true;
		}

		else if (aux)
		{
			switch (direccionAnterior)
			{
			case Direccion::Derecha:
			case Direccion::Izquierda:
			cuerpoActual = cuerpo[4];

				break;
			case Direccion::Arriba:
			case Direccion::Abajo:
				cuerpoActual = cuerpo[5];
				break;
			}
			aux = false;
		}
		cout << cuerpoActual;

	}
}
void Pacman::DesDibujar()
{
	MoverCursor(x, y);
	cout << spa;
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
		puntuacion += 10;
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
			else if (fantasma[i].estado == EstadoFantasma::Normal)
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
void Pacman::GuardarDireccionAnterior()
{
	direccionAnterior = direccionActual;
}
void Pacman::SettearDireccionAnterior()
{
	 direccionActual = direccionAnterior;
}
void Pacman::SetBuffer() 
{
	direccionBuffer = direccionActual;
}
void Pacman::GetBuffer()
{
	direccionActual=direccionBuffer;
}

