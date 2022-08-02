#include "Fantasma.h"




void Fantasma::MovimientoFantasmal()
{
	switch (direccionActual)
	{
	case Direccion::Derecha:
		x++;
		if (x >= columnas - 1)
		{
			x = 0;
		}
		break;
	case Direccion::Izquierda:
		x--;
		if (x <= 0)
		{
			x = columnas - 1;

		}
		break;
	case Direccion::Arriba:

		y--;
		break;
	case Direccion::Abajo:
		
		y++;
		break;
	}
}
void Fantasma::ResetearPosicion(int primero)
{
	if (primero == 0)
	{
		x = xDefault;
		y = yDefault;
		estado = EstadoFantasma::Normal;
	}
	else if (primero>0)
	
	{
		x = xCaja+primero;
		y = yCaja;
		estado = EstadoFantasma::Encerrado;
	}
	colorActual = colorDefault;

}
void Fantasma::Debilitar()
{
	
	if (estado == EstadoFantasma::Normal)
	{
		estado = EstadoFantasma::Debil;
		colorActual = Colores::Blanco;
		cuerpoActual = cuerpo[1];
	}
}
void Fantasma::Normalizar()
{
	if (estado == EstadoFantasma::Debil)
	{
		estado = EstadoFantasma::Normal;
		cuerpoActual = cuerpo[0];
		colorActual = colorDefault;
	}
}
bool Fantasma::SalirDeCasa(int tiempo)
{
	if (estado == EstadoFantasma::Encerrado && ((tiempo-timerFantasma)/1000) ==10)
	{
		x = xDefault;
		y = yDefault;
		estado = EstadoFantasma::Normal;
		cuerpoActual = cuerpo[0];
		colorActual = colorDefault;
		return true;
	}
	else
	{
		return false;
	}
}
void Fantasma::Encarcelar()
{
	estado = EstadoFantasma::Encerrado;
	cuerpoActual = cuerpo[0];
	colorActual = colorDefault;
	x = xCaja;
	y = yCaja;
}
