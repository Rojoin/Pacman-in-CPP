#include "Grid.h"



void Grid::Reset()
{

	for (int fil = 0; fil < rows; fil++)
	{
		for (int col = 0; col < columns; col++)
		{
			switch (printedMap[fil][col])
			{
			case pVV:
			case pHH:
			case eII:
			case eSI:
			case eID:
			case eSD:
			case pTI:
			case pTT:

				map[fil][col] = BlockType::Draw;
				SelectColor(Colors::LightBlue);
				break;
			case ent:
				map[fil][col] = BlockType::Draw;
				SelectColor(Colors::White);

				break;
			case oMM:
				map[fil][col] = BlockType::Pellets;
				SelectColor(Colors::White);
				break;
			case pil:
				map[fil][col] = BlockType::Pill;
				SelectColor(Colors::Yellow);
				break;
			case spa:
				map[fil][col] = BlockType::Null;
				SelectColor(Colors::White);
			case fru:
				map[fil][col] = BlockType::Fruit;
				SelectColor(Colors::Red);
				break;
			default:
				break;
			}
			std::cout << printedMap[fil][col];

		}
		std::cout << std::endl;
	}
}
void Grid::Start(int pacmanX, int pacmanY, Ghost ghost[])
{

	for (int fil = 0; fil < rows; fil++)
	{
		for (int col = 0; col < columns; col++)
		{
			printedMap[fil][col] = defaultMap[fil][col];
		}

	}

	for (int fil = 0; fil < rows; fil++)
	{
		for (int col = 0; col < columns; col++)
		{
			MoveCursor(col, fil);
			switch (printedMap[fil][col])
			{
			case pVV:
			case pHH:
			case eII:
			case eSI:
			case eID:
			case eSD:
			case pTI:
			case pTT:
				map[fil][col] = BlockType::Draw;
				SelectColor(Colors::LightBlue);

				break;
			case ent:
				map[fil][col] = BlockType::Draw;
				SelectColor(Colors::White);
				break;
			case oMM:
				map[fil][col] = BlockType::Pellets;
				SelectColor(Colors::White);
				break;
			case pil:
				map[fil][col] = BlockType::Pill;
				SelectColor(Colors::Yellow);

				break;
			case spa:
				map[fil][col] = BlockType::Null;
				SelectColor(Colors::White);
				break;
			case fru:
				map[fil][col] = BlockType::Fruit;
				SelectColor(Colors::Red);
				break;
			}
			bool posicionOcupada = false;
			for (int i = 0; i < maximunGhost; i++)
			{
				if (ghost[i].x == col && ghost[i].y == fil)
				{
					posicionOcupada = true;
				}
			}
			 if (!posicionOcupada)
			{
				std::cout << printedMap[fil][col];
			}



		}
	}

}
void Grid::Draw(int pacmanX, int pacmanY)
{
	for (int veces = 0; veces < 6; veces++)
	{

		for (int fil = 0; fil < rows; fil++)
		{
			for (int col = 0; col < columns; col++)
			{
				MoveCursor(col, fil);
				switch (printedMap[fil][col])
				{
				case pVV:
				case pHH:
				case eII:
				case eSI:
				case eID:
				case eSD:
				case pTI:
				case pTT:
					if (veces % 2 == 0)
					{
						SelectColor(Colors::LightBlue);

					}
					else
					{
						SelectColor(Colors::White);
					}
					break;
				case ent:
				case oMM:
				case spa:
				case fru:
					break;
				default:
					break;
				}
				bool posicionOcupada = false;

				if (pacmanX == col && pacmanY == fil)
				{

					posicionOcupada = true;
				}

				if (!posicionOcupada)
				{
					std::cout << printedMap[fil][col];
				}
			}
		}
		Sleep(500);
	}
}
void Grid::Draw(int pacmanX, int pacmanY, Ghost ghost[])
{

	for (int fil = 0; fil < rows; fil++)
	{
		for (int col = 0; col < columns; col++)
		{
			MoveCursor(col, fil);
			switch (printedMap[fil][col])
			{
			case pVV:
			case pHH:
			case eII:
			case eSI:
			case eID:
			case eSD:
			case pTI:
			case pTT:
				SelectColor(Colors::LightBlue);
				break;
			case ent:
			case oMM:
			case spa:
				SelectColor(Colors::White);
				break;
			case pil:
				SelectColor(Colors::Yellow);
				break;
			case fru:
				SelectColor(Colors::Red);
				break;
			default:
				break;
			}
			bool posicionOcupada = false;
			for (int fantas = 0; fantas < maximunGhost; fantas++)
			{
				if (ghost[fantas].x == col && ghost[fantas].y == fil)
				{
					posicionOcupada = true;
				}
			}
			if (pacmanX == col && pacmanY == fil)
			{

				posicionOcupada = true;
			}

			if (!posicionOcupada)
			{
				std::cout << printedMap[fil][col];
			}
		}
	}
}
void Grid::DrawWin(int pacmanX, int pacmanY, Ghost ghost[])
{

	for (int fil = 0; fil < rows; fil++)
	{
		for (int col = 0; col < columns; col++)
		{
			MoveCursor(col, fil);
			switch (printedMap[fil][col])
			{
			case pVV:
			case pHH:
			case eII:
			case eSI:
			case eID:
			case eSD:
			case pTI:
			case pTT:
				SelectColor(Colors::LightBlue);
				break;
			case ent:
			case oMM:
			case spa:
				SelectColor(Colors::White);
				break;
			case pil:
				SelectColor(Colors::Yellow);
				break;
			default:
				break;
			}
			bool posicionOcupada = false;
			for (int fantas = 0; fantas < maximunGhost; fantas++)
			{
				if (ghost[fantas].x == col && ghost[fantas].y == fil)
				{
					posicionOcupada = true;
				}
			}
			if (pacmanX == col && pacmanY == fil)
			{

				posicionOcupada = true;
			}

			if (!posicionOcupada)
			{
				std::cout << printedMap[fil][col];
			}
		}
	}
}
void Grid::Check()
{

	for (int fil = 0; fil < rows; fil++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (map[fil][col] == BlockType::Null)
			{
				SelectColor(Colors::White);
				printedMap[fil][col] = spa;
			}


		}
	}
};
void Grid::DrawGhost(Ghost& ghost)
{
	MoveCursor(ghost.x, ghost.y);
	SelectColor(ghost.currentColor);
	std::cout << ghost.currentBody;
}
void Grid::EraseGhost(Ghost& ghost)
{
	MoveCursor(ghost.x, ghost.y);
	SelectColor(Colors::White);
	std::cout << spa;
}
void Grid::MoveGhost(Ghost& ghost)
{


	Direction random = (Direction)(rand() % 4);
	switch (random)
	{
	case Direction::Right:
		if (map[ghost.y][ghost.x + 1] != BlockType::Draw)
		{
			ghost.currentDirection = Direction::Right;
			if (ghost.previousDirection == Direction::Left)
			{
				ghost.currentDirection = ghost.previousDirection;
			}
		}


		break;
	case Direction::Left:
		if (map[ghost.y][ghost.x - 1] != BlockType::Draw)

		{
			ghost.currentDirection = Direction::Left;

			if (ghost.previousDirection == Direction::Right)
			{
				ghost.currentDirection = ghost.previousDirection;
			}
		}

		break;
	case Direction::Up:
		if (map[ghost.y - 1][ghost.x] != BlockType::Draw)

		{
			ghost.currentDirection = Direction::Up;
			if (ghost.previousDirection == Direction::Down)
			{
				ghost.currentDirection = ghost.previousDirection;
			}
		}

		break;
	case Direction::Down:
		if (map[ghost.y + 1][ghost.x] != BlockType::Draw)
		{
			ghost.currentDirection = Direction::Down;
			if (ghost.previousDirection == Direction::Up)
			{
				ghost.currentDirection = ghost.previousDirection;
			}
		}
		break;

	}
	if (CheckGhostPosition(ghost))
	{
		ghost.previousDirection = ghost.currentDirection;
		ghost.Movement();

	}
	else
	{
		MoveGhost(ghost);
	}

}
void Grid::MoveJailGhost(Ghost& ghost)
{
	switch (ghost.currentDirection)
	{
	case Direction::Right:

		if (ghost.x == 16)
		{
			ghost.currentDirection = Direction::Left;
		}
		break;
	case Direction::Left:
		if (ghost.x == 11)
		{
			ghost.currentDirection = Direction::Right;
		}
		break;
	case Direction::Up:
		ghost.currentDirection = Direction::Left;
		break;
	case Direction::Down:
		ghost.currentDirection = Direction::Right;
		break;
	}

	ghost.Movement();

}
bool Grid::CheckGhostPosition(Ghost& ghost)
{

	switch (ghost.currentDirection)
	{
	case Direction::Right:
		if (map[ghost.y][ghost.x + 1] != BlockType::Draw)
		{
			return true;
		}

		break;
	case Direction::Left:
		if (map[ghost.y][ghost.x - 1] != BlockType::Draw)

		{
			return true;
		}

		break;
	case Direction::Up:
		if (map[ghost.y - 1][ghost.x] != BlockType::Draw)
		{
			return true;
		}
		break;

	case Direction::Down:
		if (map[ghost.y + 1][ghost.x] != BlockType::Draw)
		{
			return true;
		}
		break;
	}
	return false;
}