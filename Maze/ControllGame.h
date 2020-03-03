#pragma once
#include "MazeView.h"
#include "MazeMove.h"
#include "StorySetting.h"
#include "Sound.h"
#include "Menu.h"

class ControllGame
{
	Menu* menu;
	MazeView* maze;
	MazeMove* move;
	StorySetting* story;
	Sound* sound;
	int stageNum;

public:
	ControllGame();
	~ControllGame();
	void start();
	void makeMaze();
	void deleteMaze();
	void makeStory();
	void deleteStory();
};

