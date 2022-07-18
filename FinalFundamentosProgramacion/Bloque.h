#pragma once
enum class TipoDeBloque { Vacio, L, J, S, Z, T, O, I };
enum class Rotacion { Grado0, Grado90,Grado180,Grado270 };

struct Bloque
{
	int x;
	int y;
	TipoDeBloque tipoDeBloque;
	Rotacion estado = Rotacion::Grado0;
	bool derecha;
	bool izquierda;
};