#include "GravitationBlock.h"



GravitationBlock::GravitationBlock()
{
	Block temp[4][4][2] = {
		{ { 2,1 },{ 2,2 },{ 1,3 },{ 2,3 } },
		{ { 1,1 },{ 1,2 },{ 2,2 },{ 3,2 } },
		{ { 1,1 },{ 2,1 },{ 1,2 },{ 1,3 } },
		{ { 0,1 },{ 1,1 },{ 2,1 },{ 2,2 } }
	};

	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = temp[r][i][0];
			m_block[r][i][1] = temp[r][i][1];
		}
	}
	_color1 = red;
	_color2 = purple;
	_color3 = darkpurple;
}


GravitationBlock::~GravitationBlock()
{
}

void GravitationBlock::Update(Board& board)
{
	Erase();
	Grab(board);
	Move(board);
	Down(board);
	Stack(board);
	Draw();
}

void GravitationBlock::Draw()
{
	static int count = 0;
	for (int i = 0; i < 4; i++)
	{
		count++;
		if(count%3==0)
			CNL()->SetColor(GM()->BGColor(), _color1);
		else if (count % 3 == 1)
			CNL()->SetColor(GM()->BGColor(), _color2);
		else if (count % 3 == 2)
			CNL()->SetColor(GM()->BGColor(), _color3);

		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
			m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << m_image;
	}


	CNL()->SetColor(GM()->BGColor(), white);
}

void GravitationBlock::Grab(Board& board)
{
	int y = 0;
	if (GM()->Timer() % 1000 == 0)
	{
		while (!Intersect(board, m_rotCount, m_pos.x, m_pos.y + y))
		{
			++y;
		}
		for (int i = 0; i < 4; i++)
		{
			Position floor_pos = { m_pos.x + m_block[m_rotCount][i][0],m_pos.y + m_block[m_rotCount][i][1] + y };

			board.MoveBoard(floor_pos, kup);
		}
	}
}