#pragma once
#include "Globals.h"
#include <conio.h>
#include "PacMan.h"

const char upDefaultKey = 'w';		   //Default Keys
const char downDefaultKey = 's';	   //Default Keys
const char leftDeaultKey = 'a';		   //Default Keys
const char rightDefaultKey = 'd';	   //Default Keys
const char selectDefaultKey = 'e';	   //Default Keys
const char resetTeclaDefault = 'r';	   //Default Keys
const char acceptDefaultKey = '1';	   //Default Keys
const char deniedDefaultKey = 27;	   //Default Keys
void PauseMenu(bool& gameOver, bool& juegoCorriendo, char& acceptKey, char& deniedKey);//Pause Menu
void InputManager(GameStates& gameStates, int& cursor, char upKey, char downKey, char selectKey);//Input for Menu
void InputManager(Pacman& pacman, bool& gameOver, bool& gameRunning, char rightKey, char leftKey, char upKey, char downKey, char selectKey, char acceptKey, char deniedKey);//Input for Game
bool InputManager(int& cursor, char& upKey, char& downKey, char& selectKey);//Input for Options