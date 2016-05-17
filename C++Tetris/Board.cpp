#include "Board.h"



Board::Board() :
m_rect()			//top 0 left 5 right 10 bottom 20
{
	m_rect.top = 0;
	m_rect.left = 0;
	m_rect.bottom = 20;
	m_rect.right = 10;

	m_rect.width = m_rect.right - m_rect.left;
	m_rect.height = m_rect.bottom - m_rect.top;

	drawEraseRect = { 0,1,HEIGHT - 1,WIDTH - 1 };
}

Board::~Board()
{
}

void Board::Init()
{
	m_endLine = 2;

	Square temp[HEIGHT][WIDTH] = {

		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ WALL , NONE , NONE , NONE , NONE , NONE , NONE , NONE , NONE , WALL },
		{ CORNER,FLOOR,FLOOR,FLOOR,FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, CORNER }

	};

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			m_board[y][x] = temp[y][x];
}
void Board::Update()
{
	StackLineClear();
}


void Board::StackLineClear()
{
	bool s = false;
	for (int y = 0; y < HEIGHT; y++)
	{
		int stackBlockCount = 0;
		for (int x = 0; x < WIDTH; x++)
		{

			if (m_board[y][x] == STACKBLOCK)
			{
				stackBlockCount++;
			}
		}

		if (stackBlockCount == WIDTH - 2)
		{
			for (int x = 1; x < WIDTH - 1; x++)
			{
				m_board[y][x] = NONE;
			}
			
			StackBlockDown(y);
			
			GM()->Score(GM()->Score(),100);	//이게 뭐하는 건지 하나도 모르겠다.
														//코드만 보면 ㅋㅋ 그러나 설명을 달아주지
														//score += 100 의 의미다.
			s = true;
		}
	}
	if (s == true)
	{
		Erase(drawEraseRect);
	}
}

void Board::StackBlockDown(int p_y)

{
	for (int x = 1; x < WIDTH-1; x++)
	{
		for (int y = p_y; y>0;y--)
		{
			m_board[y][x] = m_board[y-1][x];
		}
	}
}
void Board::SetStackBlock(Position pos)
{
	if ((pos.x < WIDTH && pos.x > 0) && (pos.y < HEIGHT && pos.y >0))
	{
		m_board[pos.y][pos.x] = STACKBLOCK;
	}
}

void Board::MoveBoard(Position pos,Direction dir)
{
	if((pos.x < WIDTH && pos.x > 0) && (pos.y < HEIGHT && pos.y >0))
	{
		Erase(pos);
		if (m_board[pos.y][pos.x] == STACKBLOCK)
		{
			if (dir == kup)
			{
				m_board[pos.y][pos.x] = NONE;
				m_board[pos.y - 1][pos.x] = STACKBLOCK;
				Erase(Position(pos.x,pos.y-1));
			}
			else if (dir == kdown)
			{
				m_board[pos.y][pos.x] = NONE;
				m_board[pos.y + 1][pos.x] = STACKBLOCK;
				Erase(Position(pos.x, pos.y + 1));
			}
			else if (dir == kleft)
			{
				m_board[pos.y][pos.x] = NONE;
				m_board[pos.y][pos.x - 1] = STACKBLOCK;
				Erase(Position(pos.x-1, pos.y));
			}
			else if (dir == kright)
			{
				m_board[pos.y][pos.x] = NONE;
				m_board[pos.y][pos.x + 1] = STACKBLOCK;
				Erase(Position(pos.x+1, pos.y ));
			}
		}
	}
}

void Board::Draw()
{
	for (int y = m_rect.top; y < m_rect.bottom; y++)
	{
		for (int x = m_rect.left; x < m_rect.right; x++)
		{
			CNL()->GotoXY(x, y);

			if (m_board[y][x] == NONE);
			else if (m_board[y][x] == LINE)
				std::cout << "〓";
			else if (m_board[y][x] == WALL)
				std::cout << "│";
			else if (m_board[y][x] == FLOOR)
				std::cout << "━";
			else if (m_board[y][x] == CORNER)
				std::cout << "◇";
			else if (m_board[y][x] == STACKBLOCK)
				std::cout << "▣";
		}
	}
}

void Board::Erase()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			CNL()->GotoXY(x, y);
			std::cout << "  ";
		}
	}
}

void Board::Erase(Position pos)
{
	CNL()->GotoXY(pos.x, pos.y);
	std::cout << "  ";
}

void Board::Erase(Rect p_rect)
{
	for (int y = p_rect.top; y < p_rect.bottom; y++)
	{
		for (int x = p_rect.left; x < p_rect.right; x++)
		{
			CNL()->GotoXY(x, y);
			std::cout << "  ";
		}
	}
}
bool Board::StackBlockCheckHeight()
{
	for (int x = 1; x < WIDTH - 1; x++)
	{
		if (m_board[m_endLine][x] == STACKBLOCK)
		{
			return false;
		}
	}
	return true;
}


Square Board::GetBoard(int p_x, int p_y)
{
	return m_board[p_y][p_x];
}