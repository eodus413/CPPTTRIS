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

	virtual void Init(CBlock* block);			// ���ο� ���������  �ٲ� ȣ��
	virtual void Update(Board p_board,CBlock* block);	//���� ��ǥ�� �����̰ų� ȸ������ �ٲ�� ȣ��
	virtual void Draw();
	virtual void Erase();
	virtual void Move(Board p_board);
};

