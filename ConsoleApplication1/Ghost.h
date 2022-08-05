#pragma once
#include "Globals.h"

struct Ghost
{
	int x;
	int y;
	GhostState state = { GhostState::Normal };
	int jailTimer;//Time in Jail
	Colors currentColor;	 //Color 
	Colors DefaultColor;	 //Color 
	const int xDefault =11;		 //DefaultPosition for spawn
	const int yDefault = 11;	 //DefaultPosition for spawn
	const int xJail = 13;	 //JailPosition
	const int yJail = 13;	 //JailPosition
	Direction currentDirection;
	Direction previousDirection;
	char bodyPart[2]{ ghostAlive,ghostDead};   //Body
	char currentBody = { bodyPart[0] };		   //Body
	void Movement();//Moves Ghost
	void ResetPosition(int first);//Reset Ghost
	void Normalize();//Turn Ghost Normal
	void Weak();//Turn Ghost Weak
	void Jail();//Put the Ghost in Jail
	bool OutOfJail(int currentTime);//Put the Ghost out of  Jail
};