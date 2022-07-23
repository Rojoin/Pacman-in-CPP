#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "Enum.h"

using namespace std;
const int columnas = 10;
const int filas = 22;


void CalcularCursor(int x, int y);
struct Grilla
{
    TipoDeBloque tablero[filas][columnas] = { TipoDeBloque::Vacio };

    bool LineaLlena(int fil);
    int CheckearLineas();
    void LimpiarLinea(int fil);
    void MoverLinea(int fil, int lineasAMover);
    void UpdatearGrilla(Grilla& grilla);
    void UpdatearGrilla();
    void RandomGrilla(Grilla& grilla);
};


