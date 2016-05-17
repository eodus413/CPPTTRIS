#pragma once
#include<iostream>	
#include "Console.h"
#include "GameManager.h"

class Board
{
private:
	Rect m_rect;			//보드의 rect정보를 담고있다.
	Rect drawEraseRect;

	Square m_board[HEIGHT][WIDTH];	//보드는 사각형이 여러개 있는거죠? 네 그니까 Square형으로 선언 ㅇㅋ?ㅇㅇ

	int m_endLine;		//블럭이 어디까지 쌓이면 끝나나

	void StackLineClear();
	void StackBlockDown(int p_y);
public:

	Board();
	~Board();

	void Init();		//보드의 정보 초기화  씬이 바뀔때 마다 호출함
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

