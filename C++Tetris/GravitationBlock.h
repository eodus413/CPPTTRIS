#pragma once
#include "Block.h"
class GravitationBlock : public CBlock
{
private:
	Color _color1;
	Color _color2;
	Color _color3;
public:
	virtual void Update(Board& board);
	virtual void Draw();
	void Grab(Board& board);
	GravitationBlock();
	~GravitationBlock();
};

