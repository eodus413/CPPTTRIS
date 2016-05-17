#include "GameManager.h"





CGameManager::CGameManager() :
	MaxFrame(10) {

	GameOn(true);
	Frame(30);
	Timer(0);
	Score(0);
	Level(1);
	m_bgColor = black;
	for (int i = 0; i < 10; i++)
	{
		m_nextLevelScore[i] = i * 1000;
	}
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	GameOn(true);
	Score(0);
	Level(1);
	set_Game_over(false);
	m_bgColor = black;
}
void CGameManager::Update()
{
	int t = 1000 / GM()->Frame();
	GM()->delay(t);
	GM()->Timer(GM()->Timer() + t);

	if (GM()->Score() == GM()->NextLevelScore(GM()->Level() + 1))
	{
		GM()->Level(GM()->Level() + 1);
	}
}

bool CGameManager::GameOn()
{
	return m_gameOn;
}
void CGameManager::GameOn(bool p_isOn)
{
	m_gameOn = p_isOn;
}

bool CGameManager::Game_over()
{
	return game_over;
}
void CGameManager::set_Game_over(bool sgo)
{
	game_over = sgo;
}

int CGameManager::Frame()
{
	if (m_frame <= MaxFrame)
		return m_frame;
	else
	{
		m_frame = MaxFrame;
		return m_frame;
	}
}
void CGameManager::Frame(int p_frame)
{
	if (p_frame <= MaxFrame)
		m_frame = p_frame;
	else
		m_frame = MaxFrame;
}

int CGameManager::Timer()
{
	return m_timer;
}
void CGameManager::Timer(int p_timer)
{
	m_timer = p_timer;
}

int CGameManager::Score()
{
	if (m_score > 0)
		return m_score;
	else
		return 0;

}
void CGameManager::Score(int p_score)
{
	if (p_score > 0)
		m_score = p_score;
	else
		m_score = 0;
}
void CGameManager::Score(int p_score, int p_add)
{
	if (p_add >= 0 && p_add <= 100)
		m_score = p_score + p_add;
}

int CGameManager::Level()
{
	if (m_level > 0)
		return m_level;
	else
		return 1;
}
void CGameManager::Level(int p_level)
{
	if (p_level > m_level)
		m_level = p_level;
	else
		m_level = 1;
}
void CGameManager::Level(int p_level, int p_add)
{
	m_level = p_level + p_add;
}

int CGameManager::NextLevelScore(int p_level)
{
	return m_nextLevelScore[p_level];
}

Color CGameManager::BGColor()
{
	return m_bgColor;
}

void CGameManager::delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

