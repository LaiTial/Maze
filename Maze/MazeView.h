#pragma once
#include "MazeMove.h"

class MazeView
{
public:
	MazeView(void);
	void MakeALine(MazeMove* m);
	void ClearMaze(MazeMove* m);
};

