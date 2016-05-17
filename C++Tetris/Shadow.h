#pragma once
#include "Header.h"
#include "Board.h"
#include "Block.h"
#include "Console.h"

class Shadow : public CBlock
{
public:
	Shadow();
	~Shadow();

	virtual void Init(CBlock* block);			// 새로운 블럭모양으로  바뀔때 호출
	virtual void Update(Board p_board,CBlock* block);	//블럭의 좌표가 움직이거나 회전값이 바뀌면 호출
	virtual void Draw();
	virtual void Erase();
	virtual void Move(Board p_board);
};

