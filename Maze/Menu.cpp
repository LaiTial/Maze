#include "Menu.h"

int Menu::MenuDraw()
{
	x = 53, y = 15;

	xyputstr(x - 2, y, "¢º GAME START", WHITE, NULL);
	xyputstr(x + 1, y + 1, "INFO", WHITE, NULL);
	xyputstr(x + 1, y + 2, "END", WHITE, NULL);

	while (1)
	{
		int num;
		num = getKey();
		switch (num)
		{
		case UPKEY:
			if (y > 15) {
				xyputstr(x - 2, y, " ", WHITE, NULL);
				xyputstr(x - 2, --y, "¢º", WHITE, NULL);
			}
			break;
		case DOWNKEY:
			if (y < 17) {
				xyputstr(x - 2, y, " ", WHITE, NULL);
				xyputstr(x - 2, ++y, "¢º", WHITE, NULL);
				break;
			}
		case RIGHTKEY:
			return y - 15;
		}
	}
}