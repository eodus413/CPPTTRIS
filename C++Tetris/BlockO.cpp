#include "BlockO.h"

void BlockO::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			CNL()->SetColor(GM()->BGColor(), m_color);
		else
			CNL()->SetColor(GM()->BGColor(), _color2);


		CNL()->GotoXY(m_pos.x + m_block[m_rotCount][i][0],
			m_pos.y + m_block[m_rotCount][i][1]);

		std::cout << m_image;
	}


	CNL()->SetColor(GM()->BGColor(), white);
}



BlockO::BlockO()
{
	Block temp[4][2] = {
		 { 1,1 },{ 2,1 },{ 1,2 },{ 2,2 }
	};

	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = temp[i][0];
			m_block[r][i][1] = temp[i][1];
		}
	}
	m_color = blue;

	_color2 = yellow;
}


BlockO::~BlockO()
{
}