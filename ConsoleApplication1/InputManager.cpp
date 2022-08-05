#include "InputManager.h"





int cursor;
void PauseMenu(bool& gameOver, bool& juegoCorriendo,char& acceptKey,char& deniedKey)
{
	MoveCursor(0, 31);
	SelectColor(Colors::Yellow);
	cout << "Menu de Pausa";
	MoveCursor(0, 32);
	cout << "Aprete ";
	SelectColor(Colors::LightGreen);
	cout << acceptKey;
	SelectColor(Colors::Yellow);
	cout << " seguir jugando o ";
	SelectColor(Colors::LightRed);
	if (deniedKey == deniedDefaultKey)
	{
		cout << "ESC";
	}
	else
	{
		cout << deniedKey;
	}
	SelectColor(Colors::Yellow);
	cout << " para salir.";
	char input = _getch();
	if (input == deniedKey)
	{
		SelectColor(Colors::White);
		MoveCursor(0, 31);
		cout << "                                                                         ";
		MoveCursor(0, 32);
		cout << "                                                                         ";
		MoveCursor(0, 31);
		SelectColor(Colors::Yellow);
		cout << "Gracias por Jugar :)";
		MoveCursor(0, 32);
		cout << "Aprete cualquier tecla para volver al menu";
		gameOver = false;
		juegoCorriendo = false;
		_getch();
		SelectColor(Colors::White);
	}
	else if (input == acceptKey)
	{
		SelectColor(Colors::White);
		MoveCursor(0, 31);
		cout << "                                                ";
		MoveCursor(0, 32);
		cout << "                                                         ";
		return;
	}
	else
	{
		PauseMenu(gameOver, juegoCorriendo,acceptKey,deniedKey);
	}

}
void InputManager(Pacman& pacman, bool& gameOver, bool& gameRunning, char rightKey, char leftKey, char upKey, char downKey, char selectKey, char acceptKey, char deniedKey)
{
	char input = _getch();
	if (input == upKey)
	{
		pacman.currentDirection = Direction::Up;
	} //Arriba  
	else if (input == downKey)
	{
		pacman.currentDirection = Direction::Down;
	} //Abajo
	else if (input == leftKey)
	{
		pacman.currentDirection = Direction::Left;
	} //Izquierda
	else if (input == rightKey)
	{
		pacman.currentDirection = Direction::Right;
	} //Derecha
	else if (input == selectKey)
	{
		//pacman.pellets = 228;
	} //Seleccion

	else if (input == acceptKey || input == deniedKey)
	{
		PauseMenu(gameOver, gameRunning,acceptKey,deniedKey);
	}
	
}
void InputManager(GameStates& gameStates, int& cursor, char upKey, char downKey, char selectKey)
{
	char input = _getch();
	if (cursor > (int)GameStates::Exit || cursor < (int)GameStates::Game)
	{
		cursor = (int)GameStates::Game;
	}
	if (input == upKey)
	{
		cursor--;
		if (cursor < (int)GameStates::Game)
		{
			cursor = (int)GameStates::Exit;
		}
	} //Arriba  
	else if (input == downKey)
	{
		cursor++;

		if (cursor > (int)GameStates::Exit)
		{
			cursor = (int)GameStates::Game;
		}
	} //Abajo
	else if (input == selectKey)
	{
		gameStates = (GameStates)cursor;
	} //Seleccion

}
bool InputManager(int& cursor,char& upKey,char& downKey,char& selectKey)
{
	char input = _getch();
	

	if (input == upKey)
	{
		cursor--;
		if (cursor < (int)Options::Up)
		{
			cursor = (int)Options::Menu;
		}
		return false;
	} //Arriba  
	else if (input == downKey)
	{
		cursor++;

		if (cursor > (int)Options::Menu)
		{
			cursor = (int)Options::Up;
		}
		return false;
	} //Abajo
	else if (input == selectKey)
	{
		return true;
	}
	return false;
}
