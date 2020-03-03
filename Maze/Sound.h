#pragma once
#include<windows.h>
#include <mmsystem.h>

class Sound
{
public:
	void MazeMusic()
	{
		PlaySound(TEXT("Breeze.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void StoryStart()
	{
		PlaySound(TEXT("LittleTwinkle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void FailCase()
	{
		PlaySound(TEXT("PormalHote.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void SuccessCase()
	{
		PlaySound(TEXT("LetterForMoon.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void HappyEnding()
	{
		PlaySound(TEXT("BlueSky.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void BadEnding()
	{
		PlaySound(TEXT("Darkness.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void MainMusic()
	{
		PlaySound(TEXT("Pastel-Summer.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	void MusicNULL()
	{
		PlaySound(NULL, NULL, NULL);
	}
};

