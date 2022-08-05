#include "PacMan.h"
#include "Globals.h"
#include "Ghost.h"


void Pacman::MoveDown(Grid grid)
{
	if (grid.map[y + 1][x] != BlockType::Draw)
	{

		y++;
		GetPreviousDirection();
		if (bufferDirection != currentDirection)
		{
			GetBuffer();

		}

	}
	else
	{

			SetPreviousDirection();

		
	}

}
void Pacman::MoveUp(Grid grid)
{

	if (grid.map[y - 1][x] != BlockType::Draw)
	{

		y--;
		GetPreviousDirection();
		if (bufferDirection != currentDirection)
		{
			GetBuffer();
		
		}
	
	}
	else
	{
			SetPreviousDirection();
	}

}
void Pacman::MoveRight(Grid grid)
{

	
    if (x >= columns - 1)
	{
		x = 0;
	}
	else if (grid.map[y][x + 1] != BlockType::Draw)
	{
		x++;
		GetPreviousDirection();
		if (bufferDirection != currentDirection)
		{
			GetBuffer();
		}
	}
	else
	{
		SetPreviousDirection();
	}

}
void Pacman::MoveLeft(Grid grid)
{
	if (x <= 0)
	{
		x = columns - 1;
	}
	else if (grid.map[y][x - 1] != BlockType::Draw)
	{
		x--;
		GetPreviousDirection();
		
		if (bufferDirection != currentDirection)
		{
			GetBuffer();
		}	
	}
	else
	{
			SetPreviousDirection();
	}
}
void Pacman::Start(bool continuar)
{
	currentBody = bodyPart[(int)Direction::Right];
	Direction direccionActual = Direction::Right;
	Direction direccionAnterior = direccionActual;
	Direction direccionBuffer = direccionActual;
	x = xDefault;
	y = yDefault;
	if (!continuar)
	{
	lifes = maxLifes;
	score =  0 ;
	}
	pellets =  0 ;
	DrawLifes();
	DrawScore();	
}
void Pacman::Draw(bool& aux)
{
	
		MoveCursor(x, y);
		SelectColor(Colors::Yellow);
		if (!aux)
		{
			switch (previousDirection)
			{
			case Direction::Left:
				currentBody = bodyPart[(int)Direction::Left];
				break;
			case Direction::Right:
				currentBody = bodyPart[(int)Direction::Right];
				break;
			case Direction::Up:
				currentBody = bodyPart[(int)Direction::Up];
				break;
			case Direction::Down:
				currentBody = bodyPart[(int)Direction::Down];
				break;
			}
			aux = true;
		}

		else if (aux)
		{
			switch (previousDirection)
			{
			case Direction::Right:
			case Direction::Left:
			currentBody = bodyPart[4];

				break;
			case Direction::Up:
			case Direction::Down:
				currentBody = bodyPart[5];
				break;
			}
			aux = false;
		}
		cout << currentBody;
	
}
void Pacman::Draw()
{
	
		MoveCursor(x, y);
		SelectColor(Colors::Yellow);
			switch (previousDirection)
			{
			case Direction::Left:
				currentBody = bodyPart[(int)Direction::Left];
				break;
			case Direction::Right:
				currentBody = bodyPart[(int)Direction::Right];
				break;
			case Direction::Up:
				currentBody = bodyPart[(int)Direction::Up];
				break;
			case Direction::Down:
				currentBody = bodyPart[(int)Direction::Down];
				break;
			}
		cout << currentBody;
	
}
void Pacman::Erase()
{
	MoveCursor(x, y);
	SelectColor(Colors::White);
	cout << spa;
}
BlockType Pacman::CheckBoard(Grid& grid)
{
	BlockType impactado;
	impactado = grid.map[y][x];
	switch (impactado)
	{
	case BlockType::Null:
		break;
	case BlockType::Pellets:
		score+= 10;
		pellets++;
		grid.map[y][x] = BlockType::Null;
		break;
	case BlockType::Pill:
		score += 100;
		pellets++;
		grid.map[y][x] = BlockType::Null;
		break;
	case BlockType::Fruit:
		score += 1000;
		grid.map[y][x] = BlockType::Null;
		break;
	}
	return impactado;
}
void Pacman::DeathSequence(bool& GameOver, bool& die, bool& juegoCorriendo)
{
	DeathAnimation();
	lifes--;
	die = true;
	if (lifes <= 0)
	{
		GameOver = true;
		juegoCorriendo = false;
		MoveCursor(9, 15);
		SelectColor(Colors::Red);
		std::cout << "GAME  OVER";
	}
	DrawLifes();
}
bool Pacman::Win(bool& GameOver,bool& continuar)
{
	if (pellets == pelletsToWin)
	{
		GameOver = true;
		continuar = true;
		return true;
	}
	return false;
}
void Pacman::GetPreviousDirection()
{
	previousDirection = currentDirection;
}
void Pacman::SetPreviousDirection()
{
	 currentDirection = previousDirection;
}
void Pacman::SetBuffer() 
{
	bufferDirection = currentDirection;
}
void Pacman::GetBuffer()
{
	currentDirection=bufferDirection;
}
void Pacman::ResetPosition()
{
	x = xDefault;
	y = yDefault;
	currentDirection = Direction::Right;
}
void Pacman::DrawScore()
{
	MoveCursor(0, 30);
	SelectColor(Colors::White);
	std::cout << "Puntuacion:";
	MoveCursor(12, 30);
	for (int i = 0; i < 30; i++)
	{
		std::cout << spa;
	}
	MoveCursor(12, 30);
	std::cout << score;
}
void Pacman::DeathAnimation()
{
	Draw();
	currentDirection = Direction::Mid;
	MoveCursor(x, y);
	Sleep(500);
	if (previousDirection ==Direction::Up || previousDirection == Direction::Down)
	{
		std::cout << bodyPart[5];
	}
	else
	{
		std::cout << bodyPart[4];
	}
	Sleep(500);
	MoveCursor(x, y);
	std::cout << bodyPart[6];
	Sleep(500);
	MoveCursor(x, y);
	std::cout << spa;
	Sleep(500);
}
void Pacman::DrawLifes()
{
	MoveCursor(0, 29);
	SelectColor(Colors::White);
	for (int i = 0; i < 30; i++)
	{
		std::cout << spa;
	}
	MoveCursor(0, 29);	
	SelectColor(Colors::White);
	std::cout << "Vidas:";
	SelectColor(Colors::Yellow);
	for (int i = 0; i < lifes; i++)
	{
		std::cout << bodyPart[(int)Direction::Right];
	}
}

