#pragma once

#include <Windows.h>

const int filas = 28;
const int columnas = 28;
const int maximoFantasmas =4;


enum class TipoDeBloque { Vacio, Cocos, Pildora, Fruta, Dibujo };
enum class EstadoFantasma { Normal, Debil, Muerto,Encerrado};
enum class EstadoPacMan { Normal, Debil, Muerto};
enum class Direccion { Derecha,Izquierda,Arriba,Abajo,Mid};
enum class Colores 
{
	Azul = 1,
	Verde =2,
	CelesteOscuro = 3,
	Rojo = 4,
	Violeta = 5,
	Amarillo = 6,
	Blanco = 7,
	Gris = 8,
	AzulClaro =9,
	VerdeClaro = 10,
	Celeste = 11,
	RojoClaro =12,
	VioletaClaro =13,
	Crema = 14
};
enum class GamesStates{Menu,Game,How,Options,Credits,Exit};


const int puntosGanar = 228;
const char pVV = 186;		//║
const char pHH = 205;		//═
const char eII = 200;		//╚
const char eSI = 201;		//╔
const char eID = 188;		//╝
const char eSD = 187;		//╗
const char pTI = 202;		//╩
const char pTT = 203;		//╦
const char oMM = 250;
const char pil = 157;
const char spa = 32;
const char ent = 196;
const char fru = 208;

const char pacmanUp = 118;//v
const char pacmanDown = 94;//^
const char pacmanLeft = 62;//>
const char pacmanRight = 60;//<
const char pacmanMidDeadH = 196;//─
const char pacmanMidDeadV = 179;//─
const char pacmanDead = 158;//×
const char fantasmaAlive = 77;//M
const char fantasmaDead = 109;//m
const int GameTimeDefault = 3000;
const int GametimePowerUp = 500;

void MoverCursor(int x, int y);
void ElegirColor(Colores color);

