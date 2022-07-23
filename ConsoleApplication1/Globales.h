#pragma once

#include <Windows.h>
const int filas = 28;
const int columnas = 29;
const int maximoFantasmas = 3;

enum class TipoDeBloque { Vacio, Cocos, Pildora, Fruta, Dibujo };
enum class EstadoFantasma { Normal, Debil, Muerto};
enum class EstadoPacMan { Normal, Debil, Muerto};
enum class DireccionPacMan { Derecha,Izquierda,Arriba,Abajo};

const char pV = 186;		//║
const char pH = 205;		//═
const char eII = 200;		//╚
const char eSI = 201;		//╔
const char eID = 188;		//╝
const char eSD = 187;		//╗
const char pTIn = 202;		//╩
const char pT = 203;		//╦
const char pTI = 204;		//╠
const char pTD = 185;		//╣
const char pX = 206;		//╬
const char oM = 250;
const char pill = 157;
const char space = 32;
const char entrance = 196;
const char pacmanUp = 118;//v
const char pacmanDown = 94;//^
const char pacmanLeft = 62;//>
const char pacmanRight = 60;//<
const char pacmanMidDead = 196;//─
const char pacmanDead = 158;//×

void MoverCursor(int x, int y);


