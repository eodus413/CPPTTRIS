#pragma once
#include "GameManager.h"
#include "Console.h"
#include "BlockManager.h"
#include "Block.h"
#include "Header.h"
class Viewer
{
private:
	Position m_pos;		//viewer�� ��ǥ��

	Square m_blockViewer[VIEWER_HEIGHT][VIEWER_WIDTH];
	
	Position m_blPos;		//block position
	Position m_lvPos;		//level position
	Position m_scPos;		//score position
	
	CBlock* m_next;			//���� ���� ���

public:
	void Init(CBlock* cblock);
	void Update();
	void Draw();
	

	Viewer();
	~Viewer();
};

