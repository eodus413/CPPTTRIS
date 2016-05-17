#pragma once
#include"Console.h"
#include"Board.h"
#include "InputManager.h"

class CBlock 
{
	friend class Shadow;
protected :
	Block m_block[4][4][2];	//블럭의 모양

	Image m_image;	//블럭의 이미지

	State m_state;		//블럭의 상태

	Position m_pos;		//블럭의 좌표
	
	int m_rotCount;	//블럭의 회전횟수
	
	Color m_color;	//블럭의 색
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
