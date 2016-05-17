#include "InputManager.h"



CInputManager::CInputManager()
{
}


CInputManager::~CInputManager()
{
}

int CInputManager::KeyDown()
{
	int key = 0;
	if (_kbhit())
	{
		key = _getch();
		return key;
	}
	while (_kbhit()) _getch();
	return key;
}


