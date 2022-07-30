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
		x = xCaja;
		y = yCaja;
		estado = EstadoFantasma::Encerrado;
	}
}
