#include "Ghost.h"




void Ghost::Movement()
{
	switch (currentDirection)
	{
	case Direction::Right:
		x++;
		if (x >= columns - 1)
		{
			x = 0;
		}
		break;
	case Direction::Left:
		x--;
		if (x <= 0)
		{
			x = columns - 1;

		}
		break;
	case Direction::Up:

		y--;
		break;
	case Direction::Down:
		
		y++;
		break;
	}
}
void Ghost::ResetPosition(int first)
{
	if (first == 0)
	{
		x = xDefault;
		y = yDefault;
		state = GhostState::Normal;
	}
	else if (first>0)
	
	{
		x = xJail+first;
		y = yJail;
		state = GhostState::Jail;
	}
	currentColor = DefaultColor;

}
void Ghost::Weak()
{
	
	if (state == GhostState::Normal)
	{
		state = GhostState::Weak;
		currentColor = Colors::White;
		currentBody = bodyPart[1];
	}
}
void Ghost::Normalize()
{
	if (state == GhostState::Weak)
	{
		state = GhostState::Normal;
		currentBody = bodyPart[0];
		currentColor = DefaultColor;
	}
}
bool Ghost::OutOfJail(int currentTime)
{
	if (state == GhostState::Jail && ((currentTime-jailTimer)/1000) ==10)
	{
		x = xDefault;
		y = yDefault;
		state = GhostState::Normal;
		currentBody = bodyPart[0];
		currentColor = DefaultColor;
		return true;
	}
	else
	{
		return false;
	}
}
void Ghost::Jail()
{
	state = GhostState::Jail;
	currentBody = bodyPart[0];
	currentColor = DefaultColor;
	x = xJail;
	y = yJail;
}
