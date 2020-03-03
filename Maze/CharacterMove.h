#pragma once

#define UPKEY  0xe048
#define LEFTKEY 0xe04b
#define RIGHTKEY 0xe04d
#define DOWNKEY 0xe050
#define ESCKEY 0x1b

class CharacterMove
{
protected:
	int startx, starty, endx, endy;
	int thisX, thisY;

public:
	int Maze[25][25];

	CharacterMove();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	virtual bool moveCharacter();
	int getKey();
};

