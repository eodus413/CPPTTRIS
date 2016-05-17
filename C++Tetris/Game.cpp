#include "Game.h"
#include "GameManager.h"
#include "InGame.h"

CGame::CGame() {}
CGame::~CGame() {}

bool CGame::Init()
{
	srand((unsigned)time(NULL));
	CNL()->CursorVisible(false);
	GM()->Frame(30);
	SceneManager()->ChangeScene(new CMain());
	return true;
}

void CGame::Release()
{
	InputManager()->DestroyInstance();
	SceneManager()->DestroyInstance();
}

void CGame::Update()
{
	do
	{
		GM()->Update();
		SceneManager()->Input();
		SceneManager()->Update();
		SceneManager()->Draw();

	} while (GM()->GameOn());
}

void CGame::Draw()// Double Buffer
{
	SceneManager()->Draw();
}