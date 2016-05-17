#include "BlockL.h"



BlockL::BlockL()
{
	Block temp[4][4][2] = {
		{ { 1,1 },{ 1,2 },{ 1,3 },{ 2,3 } },
		{ { 1,1 },{ 2,1 },{ 3,1 },{ 1,2 } },
		{ { 1,1 },{ 2,1 },{ 2,2 },{ 2,3 } },
		{ { 2,1 },{ 0,2 },{ 1,2 },{ 2,2 } }
	};

	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			m_block[r][i][0] = temp[r][i][0];
			m_block[r][i][1] = temp[r][i][1];
		}
	}
	m_color = darkred;
}


BlockL::~BlockL()
{
}
