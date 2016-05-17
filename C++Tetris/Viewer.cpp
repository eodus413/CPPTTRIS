#include "Viewer.h"



void Viewer::Init(CBlock* cblock)
{
	m_next = cblock;
	m_next->Init(m_blPos);
}

void Viewer::Update()
{
	if(GM()->Timer() % 1000 == 0)
		m_next->Rotate();
}

void Viewer::Draw()
{
	for (int y = 0; y < VIEWER_HEIGHT; y++)
	{
		for (int x = 0; x < VIEWER_WIDTH; x++)
		{
			CNL()->GotoXY(m_pos.x + x, m_pos.y + y);
			if (m_blockViewer[y][x] == NONE)
				std::cout << "  ";
			else if (m_blockViewer[y][x] == WALL)
				std::cout << "¡×";
			else if (m_blockViewer[y][x] == FLOOR)
				std::cout << "¡ë";
			else if (m_blockViewer[y][x] == CORNER)
				std::cout << "¢¿";
		}
	}
	CNL()->GotoXY(m_lvPos.x, m_lvPos.y);
	std::cout << "Level : " << GM()->Level();

	CNL()->GotoXY(m_scPos.x, m_scPos.y);
	std::cout << "Score : " << GM()->Score();



	m_next->Draw();
}

Viewer::Viewer() : m_pos(13,3),
m_lvPos(m_pos.x,m_pos.y + 7),
m_scPos(m_pos.x,m_pos.y + 9),
m_blPos(m_pos.x + 1,m_pos.y + 1)
{
	Square temp[VIEWER_HEIGHT][VIEWER_WIDTH] = {
		{ CORNER, FLOOR,  FLOOR,  FLOOR,  FLOOR,  CORNER },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ WALL  ,  NONE  ,  NONE  ,  NONE  ,  NONE  ,  WALL },
		{ CORNER, FLOOR,  FLOOR,  FLOOR,  FLOOR,  CORNER },
	};
	for (int y = 0; y < VIEWER_HEIGHT; y++)
	{
		for (int x = 0; x < VIEWER_WIDTH; x++)
		{
			m_blockViewer[y][x] = temp[y][x];
		}
	}
	CBlock* block = new CBlock();

	m_next = block;
}

Viewer::~Viewer()
{
}

