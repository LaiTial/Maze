#include "StorySetting.h"
#include "ConsolGrapic.h"

void StorySetting::getName()
{
	xyputstr(1, 4, "당신의 이름은? ", WHITE, NULL);
	cin >> name;

	strNew = name;
	return;
}

void StorySetting::story_name_set(string filename, string newfilename)
{
	strTemp = "";
	height = 0;

	ifstream filein(filename);
	ofstream fileout(newfilename);
	if (!filein || !fileout)
	{
		cout << "Error opening files!" << endl;
		return;
	}
	while (filein >> strTemp)
	{
		if (strTemp == "__")
		{
			strTemp = "\n";
			fileout << strTemp;
		}

		if (strTemp == strReplace)
		{
			strTemp = strNew;
		}
		fileout << strTemp << " ";
		height++;
	}
}
void StorySetting::read_story(string filename)
{
	int initX = 4, initY = 4;
	int x = initX, y = initY;
	
	fillbox(x, y, x + 100, y + height / 2 + 5, LIGHTCYAN);
	fillbox(x+2, y+1, x + 98, y + height/2 + 4, WHITE);

	x += 2;
	y += 2;
	ifstream file_read(filename);

	if (file_read.is_open())
	{
		do {
			string in_line;
			getline(file_read, in_line);
			if (getchar() == 10) {
				xyputstr(x, y++, in_line, BLACK, WHITE);
			}
		} while (!file_read.eof());
	}
	fillbox(initX, initY, initX + 100, initY + height/2 + 4, NULL);
	system("cls");
	file_read.close();
}
