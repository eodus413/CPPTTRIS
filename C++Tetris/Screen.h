#pragma once
#include "Header.h"
#include "Console.h"
class Screen
{
private:
	Position pos;
	Square title[11][20];
public:
	void Init();
	void Update();
	void Draw();
	Screen();
	~Screen();
};

