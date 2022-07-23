// FinalFundamentosProgramacion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "GameLogic.h"


using namespace std;



CONSOLE_FONT_INFOEX f{};


Grilla grilla;


int main()
{
    
    system("pause");
    while (true)
    {

        GameLogic(grilla);
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
