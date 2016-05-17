#include "BlockManager.h"


CBlockManager::CBlockManager() : m_createdPos(3,0)
{
	AddBlockTypes();
}

CBlockManager::~CBlockManager()
{
	blocks.DeleteAll();
}


void CBlockManager::AddBlockTypes()
{
	blocks.Add(new BlockD());
	blocks.Add(new BlockI());
	blocks.Add(new BlockJ());
	blocks.Add(new BlockL());
	blocks.Add(new BlockO());
	blocks.Add(new BlockS());
	blocks.Add(new BlockT());
	blocks.Add(new BlockZ());
	blocks.Add(new BlockT2());
	blocks.Add(new GravitationBlock());
	blocks.Add(new PressureBlock());
}


CBlock* CBlockManager::RandomBlock()
{
	CBlock* temp = new CBlock();
	return(blocks.GetData(rand() % blocks.GetSize()));	
}
