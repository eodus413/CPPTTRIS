#pragma once
#include "Header.h"
#include "Singleton.h"
class CGameManager : public Singleton<CGameManager>
{
private:
	const int MaxFrame;		//최대프레임 수

	bool m_gameOn;			//게임이 실행중인지	
	bool game_over;

	int m_frame;					//초당프레임수
	int m_timer;					//게임플레이 시간

	int m_score;					//점수

	int m_level;					//레벨

	int m_nextLevelScore[10];		//다음레벨 도달까지의 스코어

	Color m_bgColor;	//배경색

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
//Info , Game , GM 셋중에 하나로 골라써요~