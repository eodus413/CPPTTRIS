#include "Shadow.h"



Shadow::Shadow()
{
	m_image = "бр";
	m_color = gray;
	m_rotCount = 0;
}
Shadow::~Shadow()
{
}

void Shadow::Init(CBlock* block)
{
	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = block->m_block[r][i][0];
			m_block[r][i][1] = block->m_block[r][i][1];
		}
	}
	
	m_state = block->m_state;
	m_pos = block->m_pos;
	m_rotCount = block->m_rotCount;
}

void Shadow::Update(Board p_board,CBlock* block)
{
	Erase();
	Init(block);
	Move(p_board);
	Draw();
}

void Shadow::Draw()
{
	CNL()->SetColor(GM()->BGColor(), m_color);
	for (int i = 0; i < 4; i++)
	{
		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
			m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << m_image;
	}
	CNL()->SetColor(GM()->BGColor(), white);
}

void Shadow::Erase()
{
	for (int i = 0; i < 4; i++)
	{
		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
				m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << "  ";
	}
}

void Shadow::Move(Board p_board)
{
	while (! Intersect(p_board, m_rotCount, m_pos.x, m_pos.y + 1))
	{
		m_pos.y++;
	}
}
