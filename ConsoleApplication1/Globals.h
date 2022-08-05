#pragma once
#include "Graphics.h"


enum class BlockType { Null, Pellets, Pill, Fruit, Draw }; //Block Type of the grid
enum class GhostState { Normal, Weak,Jail}; //State of Ghost
enum class Direction { Right,Left,Up,Down,Mid};//Direction of Pacman and Ghost
enum class GameStates { Menu, Game, How, Options, Credits, Exit };//State of Game
enum class Options {Up = 1,Down,Left,Right,Select,Acept,Denied,Audio,Default,Menu};//Options from the menu
enum class Colors //Colors
{
	Blue = 1,
	Green =2,
	BlueSecondType = 3,
	Red = 4,
	Violet = 5,
	Yellow = 6,
	White = 7,
	Gray = 8,
	LightBlue =9,
	LightGreen = 10,
	LightBlueSecondType = 11,
	LightRed =12,
	Purple =13,
	Cream = 14
};


const int rows = 28;				 //Default values
const int columns = 28;				 //Default values
const int maximunGhost =4;			 //Default values
const int gameTimeDefault = 4;		 //Default values
const int gametimePowerUp = 1;		 //Default values
const int pelletsToWin = 228;		 //Default values
const char enie = 164;		//ñ
const char pVV = 186;		//║
const char pHH = 205;		//═
const char eII = 200;		//╚
const char eSI = 201;		//╔
const char eID = 188;		//╝
const char eSD = 187;		//╗
const char pTI = 202;		//╩
const char pTT = 203;		//╦
const char oMM = 250;		//·
const char pil = 157;		//Ø
const char spa = 32;		// 
const char ent = 196;		//─
const char fru = 208;		//ð
const char pacmanUp = 118;//v
const char pacmanDown = 94;//^
const char pacmanLeft = 62;//>
const char pacmanRight = 60;//<
const char pacmanMidDeadH = 196;//─
const char pacmanMidDeadV = 179;//─
const char pacmanDead = 158;//×
const char ghostAlive = 77;//M
const char ghostDead = 109;//m

void MoveCursor(int x, int y);//Move cursor across the console
void SelectColor(Colors color);//Select a color to draw

