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
			ElegirColor(Colores::Amarillo);
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
void Pacman::DibujarPacMan()
{
	if (estado == EstadoPacMan::Normal)
	{
		MoverCursor(x, y);
		ElegirColor(Colores::Amarillo);
		

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
		cout << cuerpoActual;

	}
}
void Pacman::DesDibujar()
{
	MoverCursor(x, y);
	ElegirColor(Colores::Blanco);
	cout << spa;
}
TipoDeBloque Pacman::CheckearTablero(Grilla& grilla)
{
	TipoDeBloque impactado;
	impactado = grilla.tablero[y][x];
	switch (impactado)
	{
	case TipoDeBloque::Vacio:
		
		break;
	case TipoDeBloque::Cocos:
		puntuacion++;
		cocos++;
		grilla.tablero[y][x] = TipoDeBloque::Vacio;
		break;
	case TipoDeBloque::Pildora:
		puntuacion += 10;
		cocos++;
		
		grilla.tablero[y][x] = TipoDeBloque::Vacio;
	
		break;
	case TipoDeBloque::Fruta:
		puntuacion += 10;
		grilla.tablero[y][x] = TipoDeBloque::Vacio;
		break;
	}
	return impactado;
}
void Pacman::SecuenciaMuerte(bool& GameOver)
{
	AnimacionMuerte();
	vidas--;
	if (vidas <= 0)
	{
		GameOver = true;
		MoverCursor(9, 15);
		ElegirColor(Colores::Rojo);
		std::cout << "GAME  OVER";
		MoverCursor(30, 30);
	}
	Sleep(500);
}
void Pacman::Ganar(bool& GameOver)
{
	if (cocos == puntosGanar)
	{
		GameOver = true;
		MoverCursor(9, 15);
		ElegirColor(Colores::Amarillo);
		std::cout << " YOU  WIN ";
		Sleep(500);
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
void Pacman::ResetearPosicion()
{
	x = xDefault;
	y = yDefault;
	direccionActual = Direccion::Derecha;
}
void Pacman::PuntuacionActual()
{
	MoverCursor(30, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << puntuacion;
}
void Pacman::AnimacionMuerte()
{
	MoverCursor(x, y);
	ElegirColor(Colores::Amarillo);
	std::cout << cuerpoActual;
	direccionActual = Direccion::Mid;
	MoverCursor(x, y);
	Sleep(500);
	if (direccionAnterior ==Direccion::Arriba || direccionAnterior == Direccion::Abajo)
	{
		std::cout << cuerpo[5];
	}
	else
	{
		std::cout << cuerpo[5];
	}
	Sleep(500);
	MoverCursor(x, y);
	std::cout << cuerpo[6];
	Sleep(500);
}

