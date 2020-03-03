#include "ControllGame.h"
#include "ConsolGrapic.h"

ControllGame::ControllGame()
{
	menu = new Menu();
	sound = new Sound();
	stageNum = 0;

	setsizexy(120, 50);

	sound->MainMusic();
}
ControllGame::~ControllGame()
{
	delete sound;
}

void ControllGame::deleteMaze()
{
	delete maze;
	delete move;

	sound->MusicNULL();
}

void ControllGame::makeMaze()
{
	sound->MusicNULL();

	maze = new MazeView();
	move = new MazeMove();

	sound->MazeMusic();
}

void ControllGame::makeStory()
{
	story = new StorySetting();
}

void ControllGame::deleteStory()
{
	delete story;
	sound->MusicNULL();
}

void ControllGame::start()
{
	string textName="", textNameTemp="";
	int selection = 0, checkSuccess = 0, sumScore=0;

		selection = menu->MenuDraw();
		makeStory();

		switch (selection)
		{
		case 1:
			system("cls");

			story->story_name_set("Introduction.txt", "Introduction_temp.txt");
			story->read_story("Introduction_temp.txt");
		case 0:
			system("cls");

			story->getName();

			system("cls");
			story->story_name_set("backgroundStory.txt", "backgroundStory_temp.txt");
			story->read_story("backgroundStory_temp.txt");
			break;

		case 2:
			system("cls");

			xyputstr(25, 25, "Game End", WHITE, NULL);

			deleteStory();
			return;
		}

	delete menu;
	sound->MusicNULL();

	for (int stageNum = 0; stageNum < 4; stageNum++)
	{
		textName = "Story" + to_string(stageNum);
		textNameTemp = textName + "_temp" + ".txt";
		textName = textName + ".txt";

		sound->StoryStart();
		story->story_name_set(textName, textNameTemp);
		story->read_story(textNameTemp);

		makeMaze();

		maze->MakeALine(move);

		if (move->moveCharacter())
		{
			maze->ClearMaze(move);
			checkSuccess = move->getScore();

			sumScore += checkSuccess;
			deleteMaze();
		}

		if (stageNum == 0)
		{
			textName = "StoryEnd" + to_string(stageNum);
			sound->SuccessCase();
		}		

		else
		{
			if (checkSuccess >= 2000)
			{
				sound->SuccessCase();
				textName = "StorySuccess" + to_string(stageNum);
			}

			else
			{
				sound->FailCase();
				textName = "StoryFail" + to_string(stageNum);
			}			
		}

		textNameTemp = textName + "_temp" + ".txt";
		textName = textName + ".txt";

		story->story_name_set(textName, textNameTemp);
		story->read_story(textNameTemp);

		sound->MusicNULL();
	}

	if (sumScore >= 8000)
	{
		textName = "LastSuccess";
		sound->HappyEnding();
	}
	
	else
	{
		textName = "LastFail";
		sound->BadEnding();
	}
	
	textNameTemp = textName + "_temp" + ".txt";
	textName = textName + ".txt";

	story->story_name_set(textName, textNameTemp);
	story->read_story(textNameTemp);

	deleteStory();

	xyputstr(25, 25, "Game End", WHITE, NULL);
}
