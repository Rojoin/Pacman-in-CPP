#include "Globals.h"

void MoveCursor(int x, int y)
{
	COORD posicionCursor{ (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicionCursor);
}
void SelectColor(Colors color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(int)color);
}