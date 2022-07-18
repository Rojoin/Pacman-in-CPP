#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>


using namespace std;

enum class TipoDeBloque { Vacio, L, J, S, Z, T,O,I};
const int columnas = 10;
const int filas = 22;
void CalcularCursor(int x, int y);
void UpdatearGrilla();
struct Grilla
{
    TipoDeBloque tablero[filas][columnas] = { TipoDeBloque::Vacio };

    bool LineaLlena(int fil)
    {
       
         for (int col = 0; col < columnas; col++)
            {
                if (tablero[fil][col] == TipoDeBloque::Vacio)
                {
                    return false;
                }
            }
         return true;
        
    }
    int CheckearLineas()// Returnear para score?
    {
        int lineasCompletas = 0;
        for (int fil = filas; fil >= 0; fil--)
        {
            if (LineaLlena(fil))
            {
                LimpiarLinea(fil);
                lineasCompletas++;
                UpdatearGrilla();
                Sleep(100);
            }
            else if (lineasCompletas >0)
            {
                MoverLinea(fil, lineasCompletas);
                UpdatearGrilla();
                Sleep(100);
            }
        }
        return lineasCompletas;
    }
    void LimpiarLinea(int fil)
    {
        for (int col = 0; col < columnas; col++)
        {
            tablero[fil][col] = TipoDeBloque::Vacio;;
        }
    }
    void MoverLinea(int fil,int lineasAMover)
    {
            for (int col = 0; col < columnas; col++)
            {
                tablero[fil + lineasAMover][col] = tablero[fil][col];
                tablero[fil][col] = TipoDeBloque::Vacio;
            }
    }
  
    

};

void RandomGrilla();
void GameLogic();
