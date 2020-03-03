#include "MazeView.h"
#include "ConsolGrapic.h"
#include <iostream>
using namespace std;

MazeView::MazeView(void)
{
	_setcursortype(_NOCURSOR);
}

void MazeView::MakeALine(MazeMove* m)
{
	int s1, s2, width;
	
	s1 = m->getEndX();
	s2 = m->getStartY();
	width = m->getEndY()- m->getStartY();

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int x = i * 2 + 10;
			int y = j + 5;

			switch (m->Maze[i][j])
			{
			case 0:
				fillbox(x, y, x + 2, y + 1, WHITE);
				break;

			case 1:
				fillbox(x, y, x + 2, y + 1, CYAN);
				break;

			case 2:
				xyputstr(x, y, "▩", BLACK, RED);
				break;

			case 3:
				xyputstr(x, y, "◐", BLUE, WHITE);
				break;

			case 4:
				xyputstr(x, y, "¤", MAGENTA, WHITE); 
				break;

			case 5:
				xyputstr(x, y, "§", BLUE, WHITE);
					break;

			}
		}
	}

	fillbox(s1, s2, s1 + 20, s2 + width, BROWN);
	xyputstr(s1+7, s2+5, "MAZE", BLUE, BROWN);

	xyputstr(s1 + 1, s2 + 7, "bomb: ", BLACK, BROWN);
	xyputstr(s1 + 7, s2 + 7, to_string(m->getBomb()), BLACK, BROWN);
	xyputstr(s1 + 1, s2 + 8, "Score: ", BLACK, BROWN);
	xyputstr(s1 + 8, s2 + 8, to_string(m->getScore()), BLACK, BROWN);

	xyputstr(s1 + 7, s2 + width - 9, "↑ : UP", BLUE, BROWN);
	xyputstr(s1 + 7, s2 + width - 8, "← : LEFT", BLUE, BROWN);
	xyputstr(s1 + 7, s2 + width - 7, "↓ : DOWN", BLUE, BROWN);
	xyputstr(s1 + 7, s2 + width - 6, "→ : RIGHT", BLUE, BROWN);
	xyputstr(s1+1, s2 + width - 5, "B,↑ : ↑ WallBreak", BLUE, BROWN);
	xyputstr(s1 + 1, s2 + width - 4, "B,← : ← WallBreak", BLUE, BROWN);
	xyputstr(s1 + 1, s2 + width - 3, "B,↓ : ↓ WallBreak", BLUE, BROWN);
	xyputstr(s1 + 1, s2 + width - 2, "B,→ : → WallBreak", BLUE, BROWN);
}

void MazeView::ClearMaze(MazeMove* m)
{

	fillbox(m->getStartX(), m->getStartY(), m->getEndX()+20, m->getEndY(), NULL);

}

void xyputc(int x, int y, char ch)
{
	gotoxy(x, y);
	cout << ch;
}

void fillbox(int x1, int y1, int x2, int y2, char color)
{
	textbackground(color);
	for (int i = x1; i < x2; i++)
	{
		for (int j = y1; j < y2; j++)
			xyputc(i, j, ' ');
	}
};

void xyputstr(int x, int y, string text, int textColor, int textBackGroundColor)
{
	gotoxy(x, y);
	textcolor(textColor);
	textbackground(textBackGroundColor);

	cout << text << endl;
}