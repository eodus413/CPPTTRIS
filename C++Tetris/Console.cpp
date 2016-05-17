#include "Console.h"



Console::Console()
{
}


Console::~Console()
{
}



void Console::GotoXY(int p_x, int p_y)
{
	COORD pos = { p_x * 2, p_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console::CursorVisible(bool p_CursorVisible)    // Console.CursorVisible = false;
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = p_CursorVisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

COORD Console::GetCursorPosition()
{
	COORD cursor;
	CONSOLE_SCREEN_BUFFER_INFO cursorInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursor.X = cursorInfo.dwCursorPosition.X;
	cursor.Y = cursorInfo.dwCursorPosition.Y;
	return cursor;
}


void Console::SetColor(int colorBack, int colorFore)
{
	int back = 0;
	if (colorBack & 1) back |= BACKGROUND_BLUE;
	if (colorBack & 2) back |= BACKGROUND_GREEN;
	if (colorBack & 4) back |= BACKGROUND_RED;
	if (colorBack & 8) back |= BACKGROUND_INTENSITY;

	int fore = 0;
	if (colorFore & 1) fore |= FOREGROUND_BLUE;
	if (colorFore & 2) fore |= FOREGROUND_GREEN;
	if (colorFore & 4) fore |= FOREGROUND_RED;
	if (colorFore & 8) fore |= FOREGROUND_INTENSITY;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back | fore);
}


void Console::Erase(Rect p_rect)
{
	for (int y = p_rect.top; y < p_rect.bottom; y++)
	{
		for (int x = p_rect.left; x < p_rect.right; x++)
		{
			GotoXY(x, y);
			std::cout << "  ";
		}
	}
}

void Console::Erase(int p_x, int p_y)
{
	GotoXY(p_x, p_y);
	std::cout << "  ";
}
