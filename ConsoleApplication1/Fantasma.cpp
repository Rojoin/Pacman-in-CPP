#include "Fantasma.h"




void Fantasma::MovimientoFantasmal()
{
	switch (direccionActual)
	{
	case Direccion::Derecha:
		x++;

		break;
	case Direccion::Izquierda:
		x--;

		break;
	case Direccion::Arriba:

		y--;
		break;
	case Direccion::Abajo:
		
		y++;
		break;
	}
}