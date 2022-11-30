// �~�m
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
	// �~�m��������
	void make();
	void draw();

private:
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];
	
	int m_blockPosX;
	int m_blockPosY;

	int m_count;
};