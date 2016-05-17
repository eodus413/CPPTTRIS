#pragma once
#include "Block.h"
class BlockO : public CBlock
{
private:
	Color _color2;
public:
	void Draw() override;
	BlockO();
	~BlockO();
};


