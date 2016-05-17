#include "BlockZ.h"



BlockZ::BlockZ()
{
	Block temp[4][4][2] = {
		{ { 0,1 },{ 1,1 },{ 1,2 },{ 2,2 } },
		{ { 2,1 },{ 1,2 },{ 2,2 },{ 1,3 } },
		{ { 0,1 },{ 1,1 },{ 1,2 },{ 2,2 } },
		{ { 2,1 },{ 1,2 },{ 2,2 },{ 1,3 } }
	};

	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = temp[r][i][0];
			m_block[r][i][1] = temp[r][i][1];
		}
	}
	m_color = purple;
}

BlockZ::~BlockZ()
{
}