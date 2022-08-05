#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "SoundManager.h"
#pragma comment( lib, "winmm" )


void PlayTheme(bool audio)
{
	if (audio)
	{

	PlaySound(TEXT("Music/pacmanTheme.wav"), NULL, SND_LOOP | SND_ASYNC);
	}
}
void PlayStartSound(bool audio)
{
	if (audio)
	{
		PlaySound(TEXT("Music/pacmanStart.wav"), NULL, SND_ASYNC);
	}
}
void PlayDeathSound(bool audio)
{
	if (audio)
	{
		PlaySound(TEXT("Music/pacmanDeath.wav"), NULL, SND_ASYNC);
	}
}
void PlayWakaSound(bool audio)
{
	if (audio)
	{
		PlaySound(NULL, 0, 0);

		PlaySound(TEXT("Music/pacmanWakaV2.wav"), NULL, SND_ASYNC);
	}
}
void PlayWakaPillSound(bool audio)
{
	if (audio)
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Music/pacmanWakaPower.wav"), NULL, SND_ASYNC);
	}
}
void PlayWakaPill2Sound(bool audio)
{
	if (audio)
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Music/pacmanWakaPowerPart2.wav"), NULL, SND_ASYNC);
	}
}

void PlayEatsGhostSound(bool audio)
{
	if (audio)
	{
		PlaySound(TEXT("Music/pacmanEatsGhost.wav"), NULL, SND_ASYNC);
	}

}
void PlayNull()
{
	PlaySound(NULL, 0, 0);
}
void PlayPillSound(bool audio)
{
	if (audio)
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Music/pacmanPill.wav"), NULL, SND_ASYNC);
	}
}
void PlayFruitSound(bool audio)
{
	if (audio)
	{
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Music/pacmanFruit.wav"), NULL, SND_ASYNC);
	}
}