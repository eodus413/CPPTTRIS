#pragma once
#include <Windows.h>
#include "InputManager.h"
#include "SceneManager.h"
#include "Singleton.h"

/*        Scene ������� ����       */
#include "Scene.h"
#include "Main.h"


class CGame :public Singleton<CGame>
{
private:

public:
	CGame();
	~CGame();

	bool Init();
	void Release();
	void Update();
	void Draw();
};

#define Game() Singleton<CGame>::InstancePtr()

