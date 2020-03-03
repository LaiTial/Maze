#pragma once
#include<iostream>
#include <conio.h>
#include "ConsolGrapic.h"
#include "CharacterMove.h"

class Menu : public CharacterMove
{
private:
	int x;
	int y;
public:
	int MenuDraw();
};

