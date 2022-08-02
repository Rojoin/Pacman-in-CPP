// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "GameLogic.h"
using namespace std;





TipoDeBloque tablero[filas][columnas];




int main()
{

	/*for (int fil = 0; fil < filas; fil++)
	{
		for (int col = 0; col < columnas - 1; col++)
		{
			switch (tableroDibujado[fil][col])
			{
			case pV:
			case pH:
			case eII:
			case eSI:
			case eID:
			case eSD:
			case pTIn:
			case pT:
			case pTI:
			case pTD:
			case pX:
				tablero[fil][col] = TipoDeBloque::Dibujo;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				break;
			case oM:
				tablero[fil][col] = TipoDeBloque::Cocos;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				break;
			case pill:
				tablero[fil][col] = TipoDeBloque::Pildora;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				break;
			case space:
				tablero[fil][col] = TipoDeBloque::Vacio;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			default:
				break;
			}
			std::cout << tableroDibujado[fil][col];

		}
		std::cout << std::endl;
	}*/
	srand(time(0));
	GameLogic();
	MoverCursor(30, 30);
	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
