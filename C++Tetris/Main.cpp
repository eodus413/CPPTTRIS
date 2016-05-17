#include "Main.h"
#include "InGame.h"
#include "SceneManager.h"

CMain::CMain() :
	game_start(Button(Position(5,4),"게임 시작",new CInGame())),
	game_end(Button(Position(5, 7), "게임 종료",new CInGame()))
{
	select_button_number = 0;
}

bool CMain::Init()
{
	game_start.Init();
	game_end.Init();
	game_start.set_select(true);
	return true;
}
void CMain::Release()
{

}
void CMain::Input()
{
	int key = InputManager()->KeyDown();	//키 입력받음

	if (key == 'w' || key == 'W')
		select_button_number = 0;
	else if (key == 's' || key == 'S')
		select_button_number = 1;

	switch (select_button_number)
	{
	case 0:
		game_start.set_select(true);
		game_end.set_select(false);
		game_start.Input(key);
		break;
	case 1:
		game_start.set_select(false);
		game_end.set_select(true);
		game_end.Input(key);
		break;
	default:
		break;
	}
}
void CMain::Update()
{
}
void CMain::Draw()
{
	screen.Draw();
	game_end.Draw();
	game_start.Draw();
}
