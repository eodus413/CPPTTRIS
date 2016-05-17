#include "Block.h"
#include "BlockManager.h"

CBlock::CBlock() : m_pos(1,1)
{
	m_rotCount = 0;
	m_state = NORMAL;
	m_image = "■";
	m_color = white;
}

CBlock::CBlock(Position pos) : m_pos(pos)
{
	m_rotCount = 0;
	m_state = NORMAL;
	m_image = "■";
	m_color = white;
}
CBlock::CBlock(const CBlock& cblock) : m_pos(cblock.m_pos), m_state(cblock.m_state)
{
	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = cblock.m_block[r][i][0];
			m_block[r][i][1] = cblock.m_block[r][i][1];
		}
	}
	m_image = cblock.m_image;
	m_rotCount = 0;
	m_color = cblock.m_color;
}

CBlock::~CBlock()
{
}

void CBlock::Copy(CBlock* cblock)
{
	m_pos = cblock->m_pos;
	m_state= cblock->m_state;
		for (int r = 0; r < 4; r++)
		{
			for (int i = 0; i < 4; i++)
			{
				m_block[r][i][0] = cblock->m_block[r][i][0];
				m_block[r][i][1] = cblock->m_block[r][i][1];
			}
		}
		m_image = cblock->m_image;
		m_rotCount = 0;
		m_color = cblock->m_color;
}

void CBlock::Init()
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_state = NORMAL;
}
void CBlock::Init(Position p_pos)
{
	m_pos = p_pos;
	m_state = NORMAL;
}

void CBlock::Update(Board& board)
{
	Erase();
	Move(board);
	Down(board);
	Stack(board);
	Draw();
}

void CBlock::Draw()
{
	CNL()->SetColor(GM()->BGColor(), m_color);

	for (int i = 0; i < 4; i++)
	{
		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
							m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << m_image;
	}


	CNL()->SetColor(GM()->BGColor(),white);
}

void CBlock::Erase()
{
	for (int i = 0; i < 4; i++)
	{
		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
			m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << "  ";
	}
}

void CBlock::Move(Board p_board)
{
	int key = InputManager()->KeyDown();

	if (key == 'd' || key == 'D')
	{
		if (!Intersect(p_board, m_rotCount, m_pos.x + 1, m_pos.y))
		{
			m_pos.x++;
		}
	}
	else if (key == 'a' || key == 'A')
	{
		if (!Intersect(p_board, m_rotCount, m_pos.x - 1, m_pos.y))
		{
			m_pos.x--;
		}
	}
	if (key == 's' || key == 'S')
	{
		while (!Intersect(p_board, m_rotCount, m_pos.x, m_pos.y + 1))
		{
			m_pos.y++;
		}
	}
	if (key == 'w' || key == 'W')
	{
		Rotate(p_board);
	}
	if (key == 32)
	{
		if (!Intersect(p_board, m_rotCount, m_pos.x , m_pos.y+1))
		{
			m_pos.y++;
		}
	}
}

void CBlock::Rotate()
{
	if (m_rotCount < 3)
	{
		m_rotCount++;
	}
	else if (m_rotCount == 3)
	{
		m_rotCount = 0;
	}
}
void CBlock::Rotate(Board p_board)
{
	if (m_rotCount < 3)
	{
		if (!Intersect(p_board, m_rotCount + 1, m_pos.x, m_pos.y))
		{
			m_rotCount++;
		}
	}
	else if (m_rotCount == 3)
	{
		if (!Intersect(p_board, m_rotCount - 3, m_pos.x, m_pos.y))
		{
			m_rotCount = 0;
		}
	}
}

void CBlock::Stack(Board& p_board)
{
	if (Intersect(p_board, m_rotCount, m_pos.x, m_pos.y + 1))	//아래체크
	{
		m_state = STACK;

		for (int i = 0; i < 4; i++)
		{
			Position now_block_pos = { m_pos.x + m_block[m_rotCount][i][0],m_pos.y + m_block[m_rotCount][i][1] };

			p_board.SetStackBlock(now_block_pos);
		}
	}
}

void CBlock::Down(Board p_board)
{
	if (GM()->Timer() % 1000 == 0)
	{
		if (!Intersect(p_board, m_rotCount, m_pos.x, m_pos.y + 1))
		{
			m_pos.y++;
		}
	}
}

bool CBlock::Intersect(Board p_board)
{
	for (int i = 0; i < 4; i++)
		if (p_board.GetBoard(m_pos.x + m_block[m_rotCount][i][0],
			m_pos.y + m_block[m_rotCount][i][1]) > LINE)
		{
			return true;
		}
	return false;
}

bool CBlock::Intersect(Board p_board, int p_rotCount, int p_x, int p_y)
{
	for (int i = 0; i < 4; i++)
		if (p_board.GetBoard(p_x + m_block[p_rotCount][i][0],
			p_y + m_block[p_rotCount][i][1]) > LINE)
		{
			return true;
		}
	return false;
}



