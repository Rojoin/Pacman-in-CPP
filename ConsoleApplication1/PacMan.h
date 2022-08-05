#pragma once
#include "Grid.h"
#include "Globals.h"
#include "Ghost.h"

struct Pacman
{
	char bodyPart[7]{ pacmanRight,pacmanLeft,pacmanUp,pacmanDown,pacmanMidDeadH,pacmanMidDeadV,pacmanDead };  //BodyPart
	char currentBody = bodyPart[0];																			  //BodyPart
	const int xDefault = 13;//Default Position
	const int yDefault = 21;//Default Position
	int x = xDefault;		
	int y = yDefault;		
	Colors colorBase = Colors::Yellow;
	Direction currentDirection = Direction::Right;	//Direction Values
	Direction previousDirection= currentDirection;	//Direction Values
	Direction bufferDirection= currentDirection;	//Direction Values
	int maxLifes = 3;
	int lifes = maxLifes;
	int score = { 0 };
	int pellets = { 0 };
	BlockType CheckBoard(Grid& grid);				//CheckPacmanPosition
	void MoveLeft(Grid grid);						//MovePacman
	void MoveRight(Grid grid);						//MovePacman
	void MoveUp(Grid grid);							//MovePacman
	void MoveDown(Grid grid);						//MovePacman
	bool Win(bool& GameOver, bool& continuar);
	void DeathSequence(bool& GameOver, bool& die,bool& juegoCorriendo);
	void DeathAnimation();
	void Start(bool continuar);
	void Draw(bool& aux);//Draw Pacman
	void Draw();		 //Draw Pacman
	void Erase();		//ErasePacman
	void GetPreviousDirection();
	void SetPreviousDirection();
	void SetBuffer();
	void GetBuffer();
	void ResetPosition();
	void DrawScore();
	void DrawLifes();
};