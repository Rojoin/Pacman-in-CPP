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
