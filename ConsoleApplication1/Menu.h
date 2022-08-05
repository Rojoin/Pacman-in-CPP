#pragma once
#include "GameLogic.h"

void GameMenu();//Main
void OptionsMenu(int& cursor, char& rightKey, char& leftKey, char& upKey, char& downKey, char& selectKey, char& acceptKey, char& deniedKey, bool& audio);//OptionsMenu
void ResetKeys(char& rightKey, char& leftKey, char& upKey, char& downKey, char& selectKey, char& acceptKey, char& deniedKey);
void ChooseOptions(int cursor, bool& opcionesLoop, char& rightKey, char& leftKey, char& upKey, char& downKey, char& selectKey, char& acceptKey, char& deniedKey, bool& audio);

