// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "GameLogic.h"
using namespace std;





TipoDeBloque tablero[filas][columnas];
char tableroDibujado[filas][columnas ] =
{
	{eSI, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pTT, pTT, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, eSD},//linea 0
	{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV },
	{pVV, oMM, eSI, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, eSD, oMM, pVV, pVV, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, eSD, oMM, pVV},
	{pVV, pil, pVV, spa, spa, pVV, oMM, pVV, spa, spa, spa, pVV, oMM, pVV, pVV, oMM, pVV, spa, spa, spa, pVV, oMM, pVV, spa, spa, pVV, pil, pVV},
	{pVV, oMM, eII, pHH, pHH, eID, oMM, eII, pHH, pHH, pHH, eID, oMM, eII, eID, oMM, eII, pHH, pHH, pHH, eID, oMM, eII, pHH, pHH, eID, oMM, pVV},
	{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV},//linea 5
	{pVV,oMM,eSI,pHH,pHH,eSD,oMM,eSI,eSD,oMM,eSI,pHH,pHH,pHH,pHH,pHH,pHH,eSD,oMM,eSI,eSD,oMM,eSI,pHH,pHH,eSD,oMM,pVV},
	{pVV,oMM,eII,pHH,pHH,eID,oMM,pVV,pVV,oMM,eII,pHH,pHH,eSD,eSI,pHH,pHH,eID,oMM,pVV,pVV,oMM,eII,pHH,pHH,eID,oMM,pVV},
	{pVV, oMM, oMM, oMM, oMM, oMM, oMM, pVV,pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV,pVV, oMM, oMM, oMM, oMM, oMM, oMM, pVV },
	{eII, pHH, pHH, pHH, pHH, eSD, oMM,pVV,eII,pHH, pHH, eSD,spa,pVV,pVV,spa,eSI,pHH,pHH,eID,pVV,oMM,eSI,pHH,pHH,pHH,pHH,eID },
	{spa, spa, spa, spa, spa, pVV, oMM,pVV,eSI,pHH, pHH, eID,spa,eII,eID,spa,eII,pHH,pHH,eSD,pVV,oMM,pVV, spa, spa, spa, spa },
	{spa, spa, spa, spa, spa, pVV, oMM,pVV,pVV,spa, spa ,spa,spa,spa,spa,spa,spa,spa,spa,pVV,pVV,oMM,pVV, spa, spa, spa, spa },
	{pHH, pHH, pHH, pHH, pHH, eID, oMM,eII,eID,spa, eSI, pHH,pHH,ent,ent,pHH,pHH,eSD,spa,eII,eID,oMM,eII,pHH,pHH,pHH,pHH,pHH },
	{spa, spa, spa, spa, spa,spa,oMM,spa,spa,spa,pVV,spa,spa,spa,spa,spa,spa,pVV,spa,spa,spa,oMM,spa, spa, spa, spa, spa,spa},
	{pHH, pHH, pHH, pHH, pHH, eSD, oMM,eSI,eSD,spa, eII, pHH,pHH,pHH,pHH,pHH,pHH,eID,spa,eSI,eSD,oMM,eSI,pHH,pHH,pHH,pHH,pHH },
	{spa, spa, spa, spa, spa, pVV, oMM,pVV,pVV,spa, spa, spa,spa,spa,spa,spa,spa,spa,spa,pVV,pVV,oMM,pVV, spa, spa, spa, spa },
	{eSI, pHH, pHH, pHH, pHH, eID, oMM,eII,eID,spa, eSI, pHH,pHH,pHH,pHH,pHH,pHH,eSD,spa,eII,eID,oMM,eII,pHH,pHH,pHH,pHH,eSD },
	{pVV,oMM,oMM,oMM,oMM,oMM,oMM,oMM,oMM,oMM,eII,pHH,pHH,eSD,eSI,pHH,pHH,eID,oMM,oMM,oMM,oMM,oMM,oMM,oMM,oMM,oMM,pVV},
	{pVV,oMM, eSI, pHH, pHH, pHH, pHH, pHH,eSD, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, eSI, pHH, pHH, pHH, pHH, pHH,eSD, oMM, pVV },
	{pVV,oMM, eII, pHH, eSD, spa, spa, spa,eII, pHH, pHH, eSD, oMM, pVV, pVV, oMM, eSI, pHH, pHH, eID, spa, spa, spa, eSI, pHH,eID, oMM, pVV },
	{pVV, pil, oMM, oMM, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, oMM, eII, eID,oMM, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, oMM, oMM, pil, pVV},
	{eII, pHH,eSD, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, eSI, pHH, eID},
	{eSI, pHH,eID, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH, pHH,eSD,  oMM,  eSI, pHH, pHH, pHH, eSD, oMM, eII, pHH, eSD},
	{pVV, oMM, oMM, oMM, pVV, spa, spa, spa,  pVV,oMM,eII,pHH,pHH,eSD,eSI,pHH,pHH,eID,  oMM, pVV, spa, spa, spa, pVV, oMM, oMM, oMM, pVV},
	{pVV, oMM, eSI, pHH, eID, spa, spa, spa, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM,  pVV, spa, spa, spa, eII, pHH, eSD, oMM, pVV},
	{pVV, oMM, eII, pHH, pHH, pHH, pHH, pHH, eID,  oMM,eSI, eSD, oMM, eII, eID, oMM, eSI, eSD, oMM, eII, pHH, pHH, pHH, pHH, pHH, eID, oMM, pVV},
	{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV},
	{eII, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pTI, pTI, pHH, pHH, pHH, pHH, pTI, pTI, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, eID}
};




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
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
