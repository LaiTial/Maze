#include "ConsolGrapic.h"
#include "MazeMove.h"

bool MazeMove::moveCharacter()
{
	int oldx, oldy;
	int key;
	int box1, box2, type=0;
	bool boxT=false;

	do{
		key = getKey();

		oldx = thisX;
		oldy = thisY;

		switch (key)
		{
		case UPKEY:
			if ((Maze[thisX][thisY-1] != 1)) thisY--; break;
		case DOWNKEY:
			if (Maze[thisX][thisY+1] != 1) thisY++; break;
		case LEFTKEY:
			if (Maze[thisX-1][thisY] != 1) thisX--; break;
		case RIGHTKEY:
			if (Maze[thisX+1][thisY] != 1) thisX++; break;
		case 'b': case 'B':
			if (bomb > 0)
			{
				WallBreak(key);
			}
			continue;
		}

		if (oldx != thisX || oldy != thisY)
		{
			switch (Maze[thisX][thisY])
			{
			case 0:
				DrawCharacter(oldx, oldy);
				break;
			case 2:
				DrawCharacter(oldx, oldy);
				type = 2;
				box1 = thisX; box2 = thisY;
				boxT = true;
				break;
			case 3:
				switch (key)
				{
				case UPKEY:
					MoveBall(thisX, thisY-1, thisX+1, thisY, thisX-1, thisY, oldx, oldy);
					break;
				case DOWNKEY:
					MoveBall(thisX, thisY+1, thisX+1, thisY, thisX-1, thisY, oldx, oldy);
					break;
				case LEFTKEY:
					MoveBall(thisX-1, thisY, thisX, thisY-1, thisX, thisY+1, oldx, oldy);
					break;
				case RIGHTKEY:
					MoveBall(thisX+1, thisY, thisX, thisY-1, thisX, thisY+1, oldx, oldy);
					break;
				}
				if (oldx != thisX || oldy != thisY)
				{
					DrawCharacter(oldx, oldy);
				}
				break;
			case 4:
				DrawCharacter(oldx, oldy);
				bomb+=3;
				xyputstr(getEndX() + 7, getStartY() + 7, to_string(getBomb()), BLACK, BROWN);
				break;
			case 6:
				DrawCharacter(oldx, oldy);
				type = 6;
				box1 = thisX; box2 = thisY;
				boxT = true;
				break;

			}

			if ((boxT == true) && ((thisX != box1) || (thisY != box2)))
			{
				Maze[box1][box2] = type;

				if(type==2)
					xyputstr(box1 * 2 + 10, box2+5, "¢Ì", BLACK, RED);

				else
					xyputstr(box1 * 2 + 10, box2 + 5, "¢Ì", BLACK, MAGENTA);
				boxT = false;
			}
		}

		if (CheckAllBoxClear())
			break;

	} while (key != ESCKEY);

	return true;
}

void MazeMove::DrawCharacter(int oldx, int oldy)
{
	Maze[oldx][oldy] = 0;
	Maze[thisX][thisY] = 5;

	xyputstr(oldx * 2 + 10, oldy + 5, " ", WHITE, WHITE);
	xyputstr(oldx * 2 + 11, oldy + 5, " ", WHITE, WHITE);
	xyputstr(thisX * 2 + 10, thisY + 5, "¡×", BLUE, WHITE);

	score -= 100;

	xyputstr(getEndX() + 8, getStartY() + 8, "            ", BLACK, BROWN);
	xyputstr(getEndX() + 8, getStartY() + 8, to_string(getScore()), BLACK, BROWN);
}

void MazeMove::MoveBall(int x, int y, int oX1, int oY1, int oX2, int oY2, int oldx, int oldy)
{
	switch (Maze[x][y])
	{
	case 0:
		Maze[x][y] = 3;
		xyputstr(x * 2 + 10, y + 5, "¢Ä", BLUE, WHITE);
		break;
	case 1:
		if (Maze[oX1][oY1] == 0)
		{
			Maze[oX1][oY1] = 3;
			xyputstr(oX1 * 2 + 10, oY1 + 5, "¢Ä", BLUE, WHITE);
		}

		else if (Maze[oX2][oY2] == 0)
		{
			Maze[oX2][oY2] = 3;
			xyputstr(oX2 * 2 + 10, oY2 + 5, "¢Ä", BLUE, WHITE);
		}

		else
		{
			thisX = oldx;
			thisY = oldy;
		}

		break;
	case 2:
		Maze[x][y] = 6;
		xyputstr(x * 2 + 10, y + 5, "¢Ì", BLACK, MAGENTA);
		score += 5000;
		xyputstr(getEndX() + 8, getStartY() + 8, "            ", BLACK, BROWN);
		xyputstr(getEndX() + 8, getStartY() + 8, to_string(getScore()), BLACK, BROWN);
		break;
	default:
		thisX = oldx;
		thisY = oldy;
		break;
	}
}

bool MazeMove::CheckAllBoxClear()
{
	int num=0;

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (Maze[i][j] == 6)
				num++;
		}
	}

	if (num == 4)
		return true;
	else
		return false;
}

void MazeMove::WallBreak(int &key)
{
	int x=0, y=0;
	key = getKey();

	switch (key)
	{
	case UPKEY:
		CheckThereHaveWall(x, y, thisX, thisY - 1);
		break;

	case DOWNKEY:
		CheckThereHaveWall(x, y, thisX, thisY + 1);
		break;

	case LEFTKEY:
		CheckThereHaveWall(x, y, thisX - 1, thisY);
		break;

	case RIGHTKEY:
		CheckThereHaveWall(x, y, thisX + 1, thisY);
		break;

	default:
		return;
	}

	fillbox(x, y, x+2, y+1, WHITE);
	bomb--;
	xyputstr(getEndX() + 7, getStartY() + 7, "         ", BLACK, BROWN);
	xyputstr(getEndX() + 7, getStartY() + 7, to_string(getBomb()), BLACK, BROWN);
}

void MazeMove::CheckThereHaveWall(int& x, int& y, int Lx, int Ly)
{
	if (Maze[Lx][Ly] == 1)
	{
		Maze[Lx][Ly] = 0;

		x = Lx * 2 + 10;
		y = Ly + 5;
	}
}