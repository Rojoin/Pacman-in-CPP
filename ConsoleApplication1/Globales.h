#pragma once

#include <Windows.h>
const int filas = 28;
const int columnas = 28;
const int maximoFantasmas = 3;

enum class TipoDeBloque { Vacio, Cocos, Pildora, Fruta, Dibujo };
enum class EstadoFantasma { Normal, Debil, Muerto};
enum class EstadoPacMan { Normal, Debil, Muerto};
enum class Direccion { Derecha,Izquierda,Arriba,Abajo,Mid};


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
const char pacmanUp = 118;//v
const char pacmanDown = 94;//^
const char pacmanLeft = 62;//>
const char pacmanRight = 60;//<
const char pacmanMidDeadH = 196;//─
const char pacmanMidDeadV = 179;//─
const char pacmanDead = 158;//×

void MoverCursor(int x, int y);


