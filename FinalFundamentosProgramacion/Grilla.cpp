#include "Grilla.h"
#include <iostream>

Grilla grilla;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
const int Rojo = 4;
const int Azul = 9;
const int Violeta = 5;
const int Amarillo = 6;
const int Verde = 10;
const int Blanco = 7;
const int Crema = 14;
char cuadrado = 219;
void RandomGrilla() 
{
    for (int fil = 0; fil < filas; fil++)
    {

        for (int col = 0; col < columnas; col++)
        {
            int random = rand() % 8;
            grilla.tablero[fil][col] = (TipoDeBloque)random;

        }

    }
}
void CalcularCursor(int x, int y)
{
    COORD posicionCursorConsola{ (short)x, (short)y };
    SetConsoleCursorPosition(h, posicionCursorConsola);
}
void UpdatearGrilla()
{

    for (int fil = 0; fil < filas; fil++)
    {

        for (int col = 0; col < columnas; col++)
        {
            
            if (col == 0)
            {
            CalcularCursor(col, fil);

            }
            
            else
            {
                CalcularCursor(col+col, fil);
            }
            
            
            switch (grilla.tablero[fil][col])
            {
            case TipoDeBloque::Vacio:
                SetConsoleTextAttribute(h, 0);
                break;
            case TipoDeBloque::L:
                SetConsoleTextAttribute(h, Azul);

                break;
            case TipoDeBloque::J:
                SetConsoleTextAttribute(h, Crema);
                break;
            case TipoDeBloque::S:
                SetConsoleTextAttribute(h, Verde);
                break;
            case TipoDeBloque::Z:
                SetConsoleTextAttribute(h, Rojo);

                break;
            case TipoDeBloque::T:
                SetConsoleTextAttribute(h, Violeta);

                break;
            case TipoDeBloque::O:
                SetConsoleTextAttribute(h, Amarillo);

                break;
            case TipoDeBloque::I:
                SetConsoleTextAttribute(h, Blanco);

                break;
            }
            cout << cuadrado;
            cout<< cuadrado;
     
        }
        cout << endl;


    }
}
void GameLogic()
{
    UpdatearGrilla();
    grilla.CheckearLineas();
}
