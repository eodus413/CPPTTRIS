#pragma once
#include "Header.h"
#include "Singleton.h"
class CGameManager : public Singleton<CGameManager>
{
private:
	const int MaxFrame;		//�ִ������� ��

	bool m_gameOn;			//������ ����������	
	bool game_over;

	int m_frame;					//�ʴ������Ӽ�
	int m_timer;					//�����÷��� �ð�

	int m_score;					//����

	int m_level;					//����

	int m_nextLevelScore[10];		//�������� ���ޱ����� ���ھ�

	Color m_bgColor;	//����

public:
	CGameManager();
	~CGameManager();

	void Init();
	void Update();

	bool Game_over();
	void set_Game_over(bool sgo);

	bool GameOn();
	void GameOn(bool p_on);

	int Frame();
	void Frame(int p_frame);

	int Timer();
	void Timer(int p_frame);

	int Score();
	void Score(int p_score);
	void Score(int p_socre, int p_add);

	int Level();
	void Level(int p_level);
	void Level(int p_level, int p_add);

	int NextLevelScore(int p_level);

	Color BGColor();
	void delay(clock_t n);
};

#define GM() Singleton<CGameManager>::InstancePtr()

//GM == GameManager
//Info , Game , GM ���߿� �ϳ��� �����~