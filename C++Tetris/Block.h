#pragma once
#include"Console.h"
#include"Board.h"
#include "InputManager.h"

class CBlock 
{
	friend class Shadow;
protected :
	Block m_block[4][4][2];	//���� ���

	Image m_image;	//���� �̹���

	State m_state;		//���� ����

	Position m_pos;		//���� ��ǥ
	
	int m_rotCount;	//���� ȸ��Ƚ��
	
	Color m_color;	//���� ��
public:
	CBlock();
	CBlock(Position pos);
	CBlock(const CBlock& cblock);
	void Copy(CBlock* cblock);
	~CBlock();

	virtual void Init();
	virtual void Init(Position p_pos);
	virtual void Update(Board& board);

	virtual void Draw();		
	virtual void Erase();

	virtual void Move(Board p_board);
	void Rotate();
	void Rotate(Board p_board);
	void Stack(Board& p_board);
	void Down(Board p_board);
	
	bool Intersect(Board p_board);
	bool Intersect(Board p_board, int p_rotCount, int p_x, int p_y);

	State state() { return m_state; }

	State GetState() { return m_state; }
};
