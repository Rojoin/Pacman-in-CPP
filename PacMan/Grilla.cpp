#include "Grilla.h"
#include "Posicion.h"
#include <iostream>


HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
const int Rojo = 4;
const int Azul = 9;
const int Violeta = 5;
const int Amarillo = 6;
const int Verde = 10;
const int Blanco = 7;
const int Crema = 14;
char cuadrado = 219;
Posicion inicial = {5,0};
void CalcularCursor(int x, int y)
{
    COORD posicionCursorConsola{ (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicionCursorConsola);
}

bool Grilla::LineaLlena(int fil)
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
int Grilla::CheckearLineas()// Returnear para score?
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
        else if (lineasCompletas > 0)
        {
            MoverLinea(fil, lineasCompletas);
            UpdatearGrilla();
            Sleep(100);
        }
    }
    return lineasCompletas;
}
void Grilla::LimpiarLinea(int fil)
{
    for (int col = 0; col < columnas; col++)
    {
        tablero[fil][col] = TipoDeBloque::Vacio;;
    }
}
void Grilla::MoverLinea(int fil, int lineasAMover)
{
    for (int col = 0; col < columnas; col++)
    {
        tablero[fil + lineasAMover][col] = tablero[fil][col];
        tablero[fil][col] = TipoDeBloque::Vacio;
    }
}
void Grilla::RandomGrilla(Grilla& grilla) 
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
void Grilla::UpdatearGrilla(Grilla& grilla)
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
                SetConsoleTextAttribute(h, Rojo);

                break;
            }
            cout << "[";
            cout<< "]";
     
        }
        cout << endl;


    }
}
void Grilla::UpdatearGrilla()

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
                CalcularCursor(col + col, fil);
            }


            switch (tablero[fil][col])
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
                SetConsoleTextAttribute(h, Rojo);

                break;
            }
            cout << "[";
            cout << "]";

        }
        cout << endl;


    }
}






