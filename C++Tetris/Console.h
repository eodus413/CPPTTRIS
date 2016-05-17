#pragma once
#include <iostream>
#include "Header.h"
#include "Singleton.h"

class Console : public Singleton<Console>
{
private:
public:
	Console();
	~Console();

	void GotoXY(int p_x, int p_y);
	void CursorVisible(bool p_CursorVisible);
	COORD GetCursorPosition();
	void SetColor(int colorBack, int colorFore);

	void Erase(Rect p_rect);
	void Erase(int p_x, int p_y);
};

#define CNL() Singleton<Console>::InstancePtr()