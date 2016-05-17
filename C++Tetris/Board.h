#pragma once
#include<iostream>	
#include "Console.h"
#include "GameManager.h"

class Board
{
private:
	Rect m_rect;			//������ rect������ ����ִ�.
	Rect drawEraseRect;

	Square m_board[HEIGHT][WIDTH];	//����� �簢���� ������ �ִ°���? �� �״ϱ� Square������ ���� ����?����

	int m_endLine;		//���� ������ ���̸� ������

	void StackLineClear();
	void StackBlockDown(int p_y);
public:

	Board();
	~Board();

	void Init();		//������ ���� �ʱ�ȭ  ���� �ٲ� ���� ȣ����
	void Update();

	void SetStackBlock(Position pos);		
	void MoveBoard(Position pos,Direction dir);

	void Draw();
	
	void Erase();
	void Erase(Position pos);
	void Erase(Rect p_rect);

	bool StackBlockCheckHeight();
	
	Square GetBoard(int p_x, int p_y);
};

