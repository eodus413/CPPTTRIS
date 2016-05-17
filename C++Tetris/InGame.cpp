#include "InGame.h"
#include "SceneManager.h"
#include "Main.h"

CInGame::CInGame()
{
}


CInGame::~CInGame()
{
}

bool CInGame::Init()
{
	GM()->Init();
	GM()->set_Game_over(false);

	block = BM()->RandomBlock();
	next_block = BM()->RandomBlock();

	CreateNewBlock();


	board.Init();

	return true;
}
void CInGame::Release()
{

}
void CInGame::Input()
{
}
void CInGame::Update()
{
	board.Update();
	viewer.Update();
	block->Update(board);
	shadow.Update(board, block);

	if (block->state() == STACK)
	{
		CreateNewBlock();
	}

	if (!board.StackBlockCheckHeight())
	{
		GM()->set_Game_over(true);
	}
	if (GM()->Game_over() == true)
	{
		SceneManager()->ChangeScene(new CMain());
		Rect rt = { 0,0,20,20, };
		CNL()->Erase(rt);
	}
}

void CInGame::Draw()
{
	board.Draw();
	viewer.Draw();
	shadow.Draw();
	block->Draw();
}

void CInGame::CreateNewBlock()
{
	block = next_block;
	block->Init(BM()->CreatedPos());

	next_block = BM()->RandomBlock();
	if (next_block == block)
		while (next_block == block)
			next_block = BM()->RandomBlock();

	viewer.Init(next_block);

	shadow.Init(block);
}