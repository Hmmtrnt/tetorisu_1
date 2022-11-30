// ƒ~ƒm
#pragma once
#include "common.h"

class mino
{
public:
	mino();
	virtual ~mino();

	void init();
	void end();
	void update();
	void draw();

private:
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];
	
	int m_blockX;
	int m_blockY;

	int m_count;
};