// FinalFundamentosProgramacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "Grilla.h";
#include "BloqueT.h";

using namespace std;


const int Rojo= 4;
const int Azul = 9;
const int Violeta = 5;
const int Amarillo = 6;
const int Verde = 10;
const int Blanco = 7;
const int Crema = 14;




CONSOLE_FONT_INFOEX f{};
#pragma region Controles
const char arribaDefault = 'w';
const char abajoDefault = 's';
const char izquierdaDefault = 'a';
const char derechaDefault = 'd';
const char seleccionarDefault = 'e';
const char ponerBanderaDefault = 'q';
const char xRayTeclaDefault = 'x';
const char resetTeclaDefault = 'r';
const char aceptarTeclaDefault = '1';
const char negarTeclaDefault = '2';
char aceptarTecla = aceptarTeclaDefault;
char negarTecla = negarTeclaDefault;
char arriba = arribaDefault;
char abajo = abajoDefault;
char izquierda = izquierdaDefault;
char derecha = derechaDefault;
char seleccionar = seleccionarDefault;
char ponerBandera = ponerBanderaDefault;
char xRayTecla = xRayTeclaDefault;
char resetTecla = resetTeclaDefault;
bool opcionesLoop = true;
struct Puntero//Puntero base
{
	int x;
	int y;
};
Puntero puntero//Puntero Ingame
{
	puntero.x = 1,
	puntero.y = 1
};

tm Tiempo;//Para mostrar el tiempo

COORD posicionCursorConsola{};//Cambiar el cursor
#pragma endregion

#pragma region Grilla // Para dibujar Grilla
char piezaPlanaVertical = 186;
char piezaPlanaHorizontal = 205;
char esquinaInferiorIzquierda = 200;
char esquinaSuperiorIzquierda = 201;
char esquinaInferiorDerecha = 188;
char esquinaSuperiorDerecha = 187;
char piezaTInvertida = 202;
char piezaT = 203;
char piezaTIzquierda = 204;
char piezaTDerecha = 185;
char piezaCruz = 206;
#pragma endregion
enum class MenuController { Menu, Juego, Reglas, Opciones, Creditos, Salir };//Menu States
enum class GameModes { Vacio = -1, Facil, Medio, Dificil, Custom, Historia, Vs };//GameStates
GameModes gamemodes;
MenuController menuController;

void Algo(Bloque& bloque);
    Bloque prueba(0, 0, TipoDeBloque::Vacio, Rotacion::Grado0, true, true);
    BloqueT prueba1(10, 10, TipoDeBloque::T, Rotacion::Grado180, false, true);
int main()
{


    prueba = prueba1;
 
    srand(time(NULL));
   
    RandomGrilla();
    system("pause");
    while (true)
    {

        do
        {
            if (clock() % 1000 == 0)
            {
                GameLogic();
                
            }
        } while (!_kbhit());
        if (_getch())
        {
            CalcularCursor(22, 2);
            Algo(prueba1);
        }
    }


    return 0;
}
//int main()
//{
//	GetCurrentConsoleFontEx(h, false, &f);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
//
//	SetCurrentConsoleFontEx(h, false, &f);
//	for (int fil = 0; fil < filas; fil++)
//	{
//		
//		for (int col = 0; col < columnas; col++)
//		{
//		
//			cout << "*";
//		}
//		cout << endl;
//	}
//}
void Algo(Bloque& bloque)
{
    bloque.MoverIzquierda();
}
//static CONSOLE_FONT_INFOEX  fontex;
//fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
//GetCurrentConsoleFontEx(h, 0, &fontex);
//fontex.FontWeight = 1000;
//fontex.dwFontSize.X = 28;
//fontex.dwFontSize.Y = 28;
//SetCurrentConsoleFontEx(h, NULL, &fontex);
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
