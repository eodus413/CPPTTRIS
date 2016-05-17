#include "Button.h"
#include "SceneManager.h"

Button::Button() : pos(0, 0)
{
}
Button::Button(Position p_pos, string p_name, CScene* scene) : pos(p_pos)
{
	_scene = scene;
	name = p_name;
}

Button::~Button()
{
}

void Button::Init()
{
	Square temp[3][10] = {
		{ CORNER,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,CORNER },
		{ WALL,NONE,NONE, NONE, NONE, NONE, NONE, NONE, NONE, WALL },
		{ CORNER,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,FLOOR,CORNER },
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{ 
			box[i][j] = temp[i][j];
		}
	}
	select = false;
	color = yellow;
}
void Button::Update()
{
}
void Button::Input(int key)
{
	if (select == true)
	{
		const int enter = 13;
		if (key == enter)
		{
			SceneManager()->ChangeScene(_scene);
		}
	}
	else
	{

	}
}
void Button::Draw()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			CNL()->GotoXY(pos.x + x, pos.y + y);

			if (box[y][x] == NONE);
			else if (box[y][x] == WALL)
				std::cout << "¦¢";
			else if (box[y][x] == FLOOR)
			{
				if (select == true)
				{
					std::cout << "£ª";
				}
				else
				{
					std::cout << "¦¡";
				}
			}
			else if (box[y][x] == CORNER)
			{
				if (select == true)
					CNL()->SetColor(GM()->BGColor(), color);
				std::cout << "¡Ú";
			}
		}
	}
	CNL()->GotoXY(pos.x + 3, pos.y + 1);
	std::cout << name;

	CNL()->SetColor(GM()->BGColor(), white);
}
void Button::Copy(const Button& bt)
{
	pos = bt.pos;
	color = bt.color;

	int i = 0;

	name = bt.name;

	select = bt.select;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			box[i][j] = bt.box[i][j];
		}
	}
}


void Button::set_select(bool s)
{
	select = s;
}