#pragma once
#include "PacMan.h"
#include "Fantasma.h"
#include "Grilla.h"
#include "Graphics.h"
#include <conio.h>
#include "InputManager.h"



//Fantasma fantasma[4]{ {4,1,EstadoFantasma::Normal},{2,1,EstadoFantasma::Normal},{3,1,EstadoFantasma::Normal},{13,13,EstadoFantasma::Encerrado} };

//Fantasma fantasma[1]{ {4,1} };

void FuenteDeConsola(int ancho, int alto);
void RemoveScrollbarAndResize();


void TamañoYScroller();
void ResetAfterDead(Fantasma fantasma[], Pacman& pacman);
void ResetFantasmas(Fantasma fantasma[]);
void SacarFantasmasDeLaCasa(Fantasma fantasma[], int tiempoActual);
void IniciarFantasmas(Fantasma fantasma[]);
void IniciarJuego(bool& continuar, int& tiempo, bool& midAnimation, bool& juegoCorriendo, int& timerFantasma, int& timerCasa, bool& gameover, bool& murio);
void Colisiones(Fantasma fantasma[], Pacman& pacman, Grilla& grilla, int& timerFantasma, bool& GameOver, bool& dead, bool& juegoCorriendo, int& GameTimeFantasma, int& GameTimePacman);
void GameLogic();

