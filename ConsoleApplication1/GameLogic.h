#pragma once
#include "PacMan.h"
#include "Ghost.h"
#include "Grid.h"
#include "Graphics.h"
#include "InputManager.h"



void ResetAfterDead(Ghost ghost[], Pacman& pacman,bool& pacmanPower);//Reset Secuence
void ResetGhost(Ghost ghost[]);//Reset Ghost 
void GetGhostOut(Ghost ghost[], int currentTime);//Get the ghost out of the jail 
void StartGhost(Ghost ghost[]);//Initialize Ghost
void StartGame(bool& doContinue, int& time, bool& midAnimation, bool& gameRunning, int& ghostTime, bool& gameover, bool& pacmanDead, int& gameTimePacman, int& gameTimeGhost, bool& pacmanPower,bool audio);//Parameters to StartGame
void Colisions(Ghost ghost[], Pacman& pacman, Grid& grid, int& ghostTime, bool& gameOver, bool& dead, bool& gameRunning, int& pacmanGameTime, bool& pacmanPower, bool audio);//Collision Between Pacman and Ghosts
void GameLogic(char rightKey, char leftKey, char upKey, char downKey, char selectKey, char acceptKey, char deniedKey, bool audio);//Main GameLogic

