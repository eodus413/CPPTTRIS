#pragma once
#include "Block.h"
class PressureBlock : public CBlock
{
private:
	Color _color1;
	Color _color2;
	Color _color3;
public:
	virtual void Update(Board& board);
	virtual void Draw();
	void Press(Board& board);
	virtual void Move(Board board);
	PressureBlock();
	~PressureBlock();
};

