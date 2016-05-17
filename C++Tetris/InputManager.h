#pragma once
#include "Header.h"
#include "Singleton.h"

class CInputManager : public Singleton<CInputManager>
{
public:
	int KeyDown();
	CInputManager();
	~CInputManager();
};

#define InputManager() Singleton<CInputManager>::InstancePtr()
