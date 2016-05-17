#include "BlockD.h"

BlockD::BlockD()
{
	Block temp[4][4][2] = {
		{ { 3,0 },{ 0,1 },{ 0,2 },{ 3,3 } },
		{ { 1,0 },{ 2,0 },{ 0,3 },{ 3,3 } },
		{ { 0,0 },{ 3,1 },{ 3,2 },{ 0,3 } },
		{ { 0,0 },{ 3,0 },{ 1,3 },{ 2,3 } }
	};

	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = temp[r][i][0];
			m_block[r][i][1] = temp[r][i][1];
		}
	}
	m_color = darkcyan;
}


BlockD::~BlockD()
{
}
