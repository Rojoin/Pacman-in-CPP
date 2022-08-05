#include "GameLogic.h"
#include <chrono> 
#include <thread>
#include <conio.h>
#include "SoundManager.h"
using namespace std::literals;

Grid grid;
Pacman pacman;
Ghost ghost[4]{ };



void StartGame(bool& doContinue, int& time, bool& midAnimation, bool& gameRunning, int& ghostTime, bool& gameover, bool& pacmanDead, int& gameTimePacman, int& gameTimeGhost, bool& pacmanPower,bool audio)
{
	pacmanPower = false;
	midAnimation = false;
	gameRunning = true;
	ghostTime = 0;
	gameover = false;
	pacmanDead = true;
	gameTimeGhost = gameTimeDefault;
	gameTimePacman = gameTimeDefault;
	StartGhost(ghost);
	pacman.Start(doContinue);
	if (doContinue)
	{
		pacman.Draw();
		grid.Draw(pacman.x, pacman.y);
	}
	PlayStartSound(audio);
	doContinue = false;
	grid.Start(pacman.x, pacman.y, ghost);
	time = 0;
	Sleep(2800);
}
void StartGhost(Ghost ghost[])
{
	for (int number = 0; number < maximunGhost; number++)
	{
		ghost[number].ResetPosition(number);
		switch (number)
		{
		case 0:
			ghost[number].DefaultColor = Colors::Red;
			ghost[number].currentColor = ghost[number].DefaultColor;
			break;
		case 1:
			ghost[number].DefaultColor = Colors::Green;
			ghost[number].currentColor = ghost[number].DefaultColor;
			break;
		case 2:
			ghost[number].DefaultColor = Colors::Purple;
			ghost[number].currentColor = ghost[number].DefaultColor;
			break;
		case 3:
			ghost[number].DefaultColor = Colors::LightBlueSecondType;
			ghost[number].currentColor = ghost[number].DefaultColor;
			break;
		}
		ghost[number].currentBody = ghost[number].bodyPart[0];
		ghost[number].jailTimer = clock() + (number * 5000);
	}
}
void ResetGhost(Ghost ghost[])
{
	for (int fantas = 0; fantas < maximunGhost; fantas++)
	{
		ghost[fantas].Normalize();
	}
}
void ResetAfterDead(Ghost ghost[], Pacman& pacman, bool& pacmanPower)
{
	pacman.ResetPosition();
	pacmanPower = false;
	for (int fantas = 0; fantas < maximunGhost; fantas++)
	{
		ghost[fantas].ResetPosition(fantas);
		ghost[fantas].jailTimer = clock() + (fantas * 5000);
	}
}
void Colisions(Ghost ghost[], Pacman& pacman, Grid& grid, int& ghostTime, bool& gameOver, bool& dead, bool& gameRunning, int& pacmanGameTime, bool& pacmanPower,bool audio)
{
	switch (pacman.CheckBoard(grid))
	{
	case BlockType::Pill:
		PlayPillSound(audio);
		ghostTime = clock();
		for (int i = 0; i < maximunGhost; i++)
		{
			ghost[i].Weak();
		}
		pacmanGameTime = gameTimeDefault - (gametimePowerUp * 2);
		pacmanPower = true;
		break;
	case BlockType::Fruit:
		PlayFruitSound(audio);
		break;
	}
	for (int i = 0; i < maximunGhost; i++)
	{
		if (pacman.x == ghost[i].x && pacman.y == ghost[i].y)
		{
			if (ghost[i].state == GhostState::Weak)
			{
				pacman.Draw();
				PlayEatsGhostSound(audio);
				ghost[i].Jail();
				ghost[i].jailTimer = clock() + 5000;
				Sleep(500);
				pacman.score += 200;
			}
			else if (ghost[i].state == GhostState::Normal)
			{
				PlayDeathSound(audio);
				pacman.DeathSequence(gameOver, dead, gameRunning);
				ResetAfterDead(ghost, pacman, pacmanPower);
				Sleep(500);
			}
		}
	}
}
void GetGhostOut(Ghost ghost[], int currentTime)
{

	for (int fantas = 0; fantas < maximunGhost; fantas++)
	{
		ghost[fantas].OutOfJail(currentTime);
	}

}
void GameLogic(char rightKey, char leftKey, char upKey, char downKey, char selectKey, char acceptKey, char deniedKey,bool audio)
{
	bool doContinue = false;
	bool midAnimation = false;
	bool gameRunning = true;
	int ghostTimer;
	int gameTime;
	int soundTime = 12;
	int ghostGameTime = gameTimeDefault;
	int pacmanGameTime = gameTimeDefault;
	bool gameOver = false;
	bool pacmanDied = true;
	bool pacmanPower = false;
	StartGame(doContinue, gameTime, midAnimation, gameRunning, ghostTimer, gameOver, pacmanDied, pacmanGameTime, ghostGameTime, pacmanPower,audio);
	while (gameRunning)
	{
		do
		{
			if (pacmanDied)
			{
				pacmanDied = false;
				pacman.Draw(midAnimation);
				Sleep(1500);
			};
			Colisions(ghost, pacman, grid, ghostTimer, gameOver, pacmanDied, gameRunning, pacmanGameTime, pacmanPower, audio);
			int currentTime = clock();

			std::this_thread::sleep_for(1us);

			if (gameTime % pacmanGameTime == 0)
			{

				pacman.DrawScore();
				grid.Draw(pacman.x, pacman.y, ghost);

				grid.Check();
				pacman.Erase();
				Colisions(ghost, pacman, grid, ghostTimer, gameOver, pacmanDied, gameRunning, pacmanGameTime, pacmanPower,audio);
				switch (pacman.currentDirection)
				{
				case Direction::Up:
					pacman.MoveUp(grid);
					break;
				case Direction::Down:
					pacman.MoveDown(grid);
					break;
				case Direction::Right:
					pacman.MoveRight(grid);
					break;
				case Direction::Left:
					pacman.MoveLeft(grid);
					break;
				}
				Colisions(ghost, pacman, grid, ghostTimer, gameOver, pacmanDied, gameRunning, pacmanGameTime, pacmanPower, audio);
				pacman.Erase();
				pacman.Draw(midAnimation);

			}
			if (gameTime % soundTime == 0)
			{
				if (!pacmanPower)
				{
					PlayWakaSound(audio);
				}
				else
				{
					if (midAnimation)
					{
						PlayWakaPillSound(audio);
					}
					else
					{
						PlayWakaPill2Sound(audio);
					}
				}
			}
			if (gameTime % ghostGameTime == 0)
			{
				for (int fantas = 0; fantas < maximunGhost; fantas++)
				{
					if (ghost[fantas].state == GhostState::Jail)
					{
						grid.MoveJailGhost(ghost[fantas]);
					}
					else
					{
						grid.MoveGhost(ghost[fantas]);
					}
					grid.DrawGhost(ghost[fantas]);
				}
				Colisions(ghost, pacman, grid, ghostTimer, gameOver, pacmanDied, gameRunning, pacmanGameTime, pacmanPower, audio);
				if (gameRunning && !gameOver)
				{
					grid.Draw(pacman.x, pacman.y, ghost);
				}
			}
			gameTime++;
			if (gameTime == 400000)
			{
				gameTime = 0;
			}
			if ((currentTime - ghostTimer) / 1000 == 10)
			{
				ResetGhost(ghost);
				ghostTimer = 0;
				ghostGameTime = gameTimeDefault;
				pacmanGameTime = gameTimeDefault;
				pacmanPower = false;
			}
			GetGhostOut(ghost, currentTime);
			if (pacman.Win(gameOver, doContinue))
			{
				grid.Check();
				grid.Draw(pacman.x, pacman.y, ghost);
				StartGame(doContinue, gameTime, midAnimation, gameRunning, ghostTimer, gameOver, pacmanDied, pacmanGameTime, ghostGameTime, pacmanPower,audio);
			}
		} while (!_kbhit() && !gameOver && gameRunning);
		if (!gameOver)
		{
			pacman.GetPreviousDirection();
			InputManager(pacman, gameOver, gameRunning, rightKey, leftKey, upKey, downKey, selectKey, acceptKey, deniedKey);
			pacman.SetBuffer();
			Colisions(ghost, pacman, grid, ghostTimer, gameOver, pacmanDied, gameRunning, pacmanGameTime, pacmanPower, audio);
		}
		else
		{
			Sleep(500);
		}

	};

}
