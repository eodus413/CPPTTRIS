#include "BlockI.h"

void BlockI::Draw()
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

BlockI::BlockI()
{
	Block temp[2][4][2] = {
		{ { 1,0 },{ 1,1 },{ 1,2 },{ 1,3 } },
		{ { 0,2 },{ 1,2 },{ 2,2 },{ 3,2 } }
	};

	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = temp[r%2][i][0];
			m_block[r][i][1] = temp[r%2][i][1];
		}
	}
	m_color = darkblue;
}

BlockI::~BlockI()
{
}
