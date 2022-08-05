#pragma once
#include <iostream>
#include <windows.h>
#include "Ghost.h"
#include "Globals.h"
#include <time.h>

using namespace std;


struct Grid {

	BlockType map[rows][columns];//What each block is
	const char defaultMap[rows][columns]= {
		{eSI, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pTT, pTT, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, eSD}, //linea0
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea1
		{pVV, oMM, eSI, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, eSD, oMM, pVV, pVV, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, eSD, oMM, pVV}, //linea2
		{pVV, pil, pVV, spa, spa, pVV, oMM, pVV, spa, spa, spa, pVV, oMM, pVV, pVV, oMM, pVV, spa, spa, spa, pVV, oMM, pVV, spa, spa, pVV, pil, pVV}, //linea3
		{pVV, oMM, eII, pHH, pHH, eID, oMM, eII, pHH, pHH, pHH, eID, oMM, eII, eID, oMM, eII, pHH, pHH, pHH, eID, oMM, eII, pHH, pHH, eID, oMM, pVV}, //linea4
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea5
		{pVV, oMM, eSI, pHH, pHH, eSD, oMM, eSI, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH, pHH, eSD, oMM, eSI, eSD, oMM, eSI, pHH, pHH, eSD, oMM, pVV}, //linea6
		{pVV, oMM, eII, pHH, pHH, eID, oMM, pVV, pVV, oMM, eII, pHH, pHH, eSD, eSI, pHH, pHH, eID, oMM, pVV, pVV, oMM, eII, pHH, pHH, eID, oMM, pVV}, //linea7
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea8
		{eII, pHH, pHH, pHH, pHH, eSD, oMM, pVV, eII, pHH, pHH, eSD, spa, pVV, pVV, spa, eSI, pHH, pHH, eID, pVV, oMM, eSI, pHH, pHH, pHH, pHH, eID}, //linea9
		{spa, spa, spa, spa, spa, pVV, oMM, pVV, eSI, pHH, pHH, eID, spa, eII, eID, spa, eII, pHH, pHH, eSD, pVV, oMM, pVV, spa, spa, spa, spa, spa}, //linea10
		{spa, spa, spa, spa, spa, pVV, oMM, pVV, pVV, spa, spa, spa, spa, spa, spa, spa, spa, spa, spa, pVV, pVV, oMM, pVV, spa, spa, spa, spa, spa}, //linea11
		{pHH, pHH, pHH, pHH, pHH, eID, oMM, eII, eID, spa, eSI, pHH, pHH, ent, ent, pHH, pHH, eSD, spa, eII, eID, oMM, eII, pHH, pHH, pHH, pHH, pHH}, //linea12
		{spa, spa, spa, spa, spa, spa, oMM, spa, spa, spa, pVV, spa, spa, spa, spa, spa, spa, pVV, spa, spa, spa, oMM, spa, spa, spa, spa, spa, spa}, //linea13
		{pHH, pHH, pHH, pHH, pHH, eSD, oMM, eSI, eSD, spa, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, spa, eSI, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH}, //linea14
		{spa, spa, spa, spa, spa, pVV, oMM, pVV, pVV, spa, spa, spa, spa, fru, spa, spa, spa, spa, spa, pVV, pVV, oMM, pVV, spa, spa, spa, spa, spa}, //linea15
		{eSI, pHH, pHH, pHH, pHH, eID, oMM, eII, eID, spa, eSI, pHH, pHH, pHH, pHH, pHH, pHH, eSD, spa, eII, eID, oMM, eII, pHH, pHH, pHH, pHH, eSD}, //linea16
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, eII, pHH, pHH, eSD, eSI, pHH, pHH, eID, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea17
		{pVV, oMM, eSI, pHH, pHH, pHH, pHH, pHH, eSD, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, eSI, pHH, pHH, pHH, pHH, pHH, eSD, oMM, pVV}, //linea18
		{pVV, oMM, eII, pHH, eSD, spa, spa, spa, eII, pHH, pHH, eSD, oMM, pVV, pVV, oMM, eSI, pHH, pHH, eID, spa, spa, spa, eSI, pHH, eID, oMM, pVV}, //linea19
		{pVV, pil, oMM, oMM, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, oMM, eII, eID, oMM, eII, pHH, pHH, pHH, pHH, pHH, pHH, eID, oMM, oMM, pil, pVV}, //linea20
		{eII, pHH, eSD, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, eSI, pHH, eID}, //linea21
		{eSI, pHH, eID, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, pHH, pHH, pHH, eSD, oMM, eSI, pHH, pHH, pHH, eSD, oMM, eII, pHH, eSD}, //linea22
		{pVV, oMM, oMM, oMM, pVV, spa, spa, spa, pVV, oMM, eII, pHH, pHH, eSD, eSI, pHH, pHH, eID, oMM, pVV, spa, spa, spa, pVV, oMM, oMM, oMM, pVV}, //linea23
		{pVV, oMM, eSI, pHH, eID, spa, spa, spa, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, spa, spa, spa, eII, pHH, eSD, oMM, pVV}, //linea24
		{pVV, oMM, eII, pHH, pHH, pHH, pHH, pHH, eID, oMM, eSI, eSD, oMM, eII, eID, oMM, eSI, eSD, oMM, eII, pHH, pHH, pHH, pHH, pHH, eID, oMM, pVV}, //linea25
		{pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, pVV, pVV, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, oMM, pVV}, //linea26
		{eII, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pTI, pTI, pHH, pHH, pHH, pHH, pTI, pTI, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, pHH, eID}  //linea27
	};//Draw Map
	char printedMap[rows][columns];//Map that is draw ingame
	void Reset();//Reset to default
	void Start(int pacmanX, int pacmanY, Ghost ghost[]);//Start
	void Draw(int pacmanX, int pacmanY);//Draw without ghost
	void Draw(int pacmanX, int pacmanY, Ghost ghost[]);//Draw with ghost
	void DrawWin(int pacmanX, int pacmanY, Ghost ghost[]);
	void Check();//Check block 
	void EraseGhost(Ghost& ghost);//Erase ghost from console
	void DrawGhost(Ghost& ghost);//Draw ghost in console
	void MoveGhost(Ghost& ghost);//Move Ghost
	void MoveJailGhost(Ghost& ghost);//Move Jail Ghost
	bool CheckGhostPosition(Ghost& ghost);//Check Ghost position
};