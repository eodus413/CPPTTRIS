#pragma once
#include "Scene.h"
#include "UserHeader.h"
#include "Block.h"
#include "BlockManager.h"
#include "BlockTypes.h"

class CInGame : public CScene
{
private:
	Board board;
	CBlock* block;
	Viewer viewer;
	Shadow shadow;

	CBlock* next_block;
public:
	CInGame();
	~CInGame();

	bool Init() override;
	void Release() override;
	void Input() override;
	void Update() override;
	void Draw() override;

	void CreateNewBlock();

};

