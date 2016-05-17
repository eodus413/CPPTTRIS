#include "PressureBlock.h"



PressureBlock::PressureBlock()
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
	_color1 = blue;
	_color2 = darkcyan;
	_color3 = cyan;
}


PressureBlock::~PressureBlock()
{
}

void PressureBlock::Update(Board& board)
{
	Erase();
	Move(board);
	Down(board);
	Press(board);
	Stack(board);
	Draw();
}

void PressureBlock::Draw()
{
	static int count = 0;
	for (int i = 0; i < 4; i++)
	{
		count++;
		if (count % 3 == 0)
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

void PressureBlock::Press(Board& board)
{
		int y = HEIGHT;

		for (int j = 1; j <= 2; j++)
		{
			if (Intersect(board, m_rotCount, m_pos.x, m_pos.y + j))
			{
				for (int i = 0; i < 4; i++)
				{
					Position pos =
					{ m_pos.x + m_block[m_rotCount][i][0],m_pos.y + m_block[m_rotCount][i][1]};

					if (board.GetBoard(pos.x, pos.y + j) == STACKBLOCK && board.GetBoard(pos.x, pos.y + j+1) == NONE)
					{
						board.MoveBoard(Position(pos.x, pos.y + j), kdown);
					}
				}
			}
	}
}
void PressureBlock::Move(Board board)
{
	int key = InputManager()->KeyDown();

	if (key == 'd' || key == 'D')
	{
		if (!Intersect(board, m_rotCount, m_pos.x + 1, m_pos.y))
		{
			m_pos.x++;
		}
	}
	else if (key == 'a' || key == 'A')
	{
		if (!Intersect(board, m_rotCount, m_pos.x - 1, m_pos.y))
		{
			m_pos.x--;
		}
	}
	if (key == 's' || key == 'S')
	{
		while (!Intersect(board, m_rotCount, m_pos.x, m_pos.y + 1))
		{
			m_pos.y++;
			Press(board);
		}
	}
	if (key == 'w' || key == 'W')
	{
		Rotate(board);
	}
	if (key == 32)
	{
		if (!Intersect(board, m_rotCount, m_pos.x, m_pos.y + 1))
		{
			m_pos.y++;
		}
	}
}