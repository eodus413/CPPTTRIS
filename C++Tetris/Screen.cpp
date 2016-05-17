#include "Screen.h"



Screen::Screen() : pos(0, 0)
{
	Square temp[11][20] =
	{
		{ CORNER ,FLOOR,FLOOR,FLOOR,FLOOR, FLOOR, FLOOR, FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,CORNER },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ CORNER ,FLOOR,FLOOR,FLOOR,FLOOR, FLOOR, FLOOR, FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,CORNER }
	};

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			title[i][j] = temp[i][j];
		}
	}
}


Screen::~Screen()
{
}

void Screen::Init()
{

}

void Screen::Update()
{

}

void Screen::Draw()
{
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			CNL()->GotoXY(pos.x+ x,pos.y+y);

			if (title[y][x] == NONE);
			else if (title[y][x] == WALL)
				std::cout << "¡ê";
			else if (title[y][x] == FLOOR)
				std::cout << "¢Â";
			else if (title[y][x] == CORNER)
				std::cout << "¡Þ";
		}
	}
}
