#pragma once
#include "CharacterMove.h"

class MazeMove : public CharacterMove
{
private:
	int bomb, score;
public:
	MazeMove();
	void initMaze();
	int getScore();
	int randomMaze();
	void MoveBall(int x, int y, int CX1, int CY1, int CX2, int CY2, int oldx, int oldy);
	void WallBreak(int& key);
	bool CheckAllBoxClear();
	bool moveCharacter();
	void DrawCharacter(int oldx, int oldy);
	void CheckThereHaveWall(int& x, int& y, int Lx, int Ly);
	int getBomb();
};

