#include "MazeMove.h"
#include <ctime>
#include <cstdlib>

MazeMove::MazeMove()
{
	srand(unsigned int(time(NULL)));

	score = 5000;
	bomb = 10;

	initMaze();
}

void MazeMove::initMaze()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if ((i > 0 && i < 24) && (j > 0 && j < 24))
				Maze[i][j] = 0;
			else
				Maze[i][j] = 1;
		}
	}

	for (int i = 2; i < 23; i += 2)
	{
		for (int j = 2; j < 23; j += 2)
		{
			Maze[i][j] = 1;
		}
	}

	for (int i = 0; i < 25 * 7; i++)
	{
		int x = randomMaze();
		int y = randomMaze();

		Maze[x][y] = 1;
	}

	for (int i = 2; i < 5; i++)
	{
		int num = 0;

		while (num <= 3)
		{
			int x = randomMaze();
			int y = randomMaze();

			if (Maze[x][y] == 0)
			{
				Maze[x][y] = i;
				num++;
			}
		}
	}

	while (true)
	{
		int x = randomMaze();
		int y = randomMaze();

		if (Maze[x][y] == 0)
		{
			thisX = x;
			thisY = y;

			Maze[x][y] = 5;
			break;
		}
	}
}

int MazeMove::randomMaze()
{
	int num;

	num = rand() % 25;

	return num;
}

int MazeMove::getScore()
{
	return score;
}

int MazeMove::getBomb()
{
	return bomb;
}