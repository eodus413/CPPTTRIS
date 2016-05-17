#pragma once
#include "Header.h"
#include "Singleton.h"
#include "LinkedList.h"
#include "BlockTypes.h"
#include "Viewer.h"

class CBlockManager : public Singleton<CBlockManager>
{
private:
	LinkedList<CBlock*> blocks;
	Position m_createdPos;
public:
	
	void AddBlockTypes();		// 블럭의 종류를 추가하는 함수
	
	CBlock* RandomBlock();

	Position CreatedPos() { return m_createdPos; }
	CBlockManager();
	~CBlockManager();
};

#define BM() Singleton<CBlockManager>::InstancePtr()