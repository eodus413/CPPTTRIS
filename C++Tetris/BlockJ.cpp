#include "BlockJ.h"



void BlockJ::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			CNL()->SetColor(GM()->BGColor(), m_color);
		else if (i == 2)
			CNL()->SetColor(GM()->BGColor(), m_color);
		else
			CNL()->SetColor(GM()->BGColor(), _color2);


		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
			m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << m_image;
	}

	CNL()->SetColor(GM()->BGColor(), white);
}

BlockJ::BlockJ()
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
	m_color = darkgreen;
	_color2 = red;
}


BlockJ::~BlockJ()
{
}
