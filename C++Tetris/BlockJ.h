#pragma once
#include "Block.h"

class BlockJ : public CBlock
{
private:
	Color _color2;
public:
	virtual void Draw();
	BlockJ();
	~BlockJ();
};

