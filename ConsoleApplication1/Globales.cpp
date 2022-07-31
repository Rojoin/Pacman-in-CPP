#include "Globales.h"

void MoverCursor(int x, int y)
{
	COORD posicionCursor{ (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicionCursor);
}
void ElegirColor(Colores color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(int)color);
}