#include "CharacterMove.h"
#include "ConsolGrapic.h"
#include <ctime>
#include <cstdlib>
#include <conio.h>

CharacterMove::CharacterMove()
{
	startx = 10;
	starty = 5;
	endx = 60;
	endy = 30;
}

int CharacterMove::getStartX()
{
	return startx;
}

int CharacterMove::getStartY()
{
	return starty;
}

int CharacterMove::getEndX()
{
	return endx;
}

int CharacterMove::getEndY()
{
	return endy;
}

bool CharacterMove::moveCharacter()
{
	int oldx, oldy;
	int key;

	do {
		key = getKey();

		oldx = thisX;
		oldy = thisY;

		switch (key)
		{
		case UPKEY:
			if ((Maze[thisX][thisY - 1] != 1)) thisY--; break;
		case DOWNKEY:
			if (Maze[thisX][thisY + 1] != 1) thisY++; break;
		case LEFTKEY:
			if (Maze[thisX - 1][thisY] != 1) thisX--; break;
		case RIGHTKEY:
			if (Maze[thisX + 1][thisY] != 1) thisX++; break;
		}

		if (oldx != thisX || oldy != thisY)
		{
			Maze[oldx][oldy] = 0;
			Maze[thisX][thisY] = 5;
			xyputstr(oldx * 2 + 10, oldy + 5, " ", WHITE, WHITE);
			xyputstr(oldx * 2 + 11, oldy + 5, " ", WHITE, WHITE);
			xyputstr(thisX * 2 + 10, thisY + 5, "¡×", BLUE, WHITE);
		}
		

	} while (key != ESCKEY);

	return true;
}

int CharacterMove::getKey()
{
	int key = _getch();

	return (key != 0xe0) ? key : (0xe000 | _getch());
}

