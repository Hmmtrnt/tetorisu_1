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
	// •`‰æˆ—
	void draw();
	// •Ï”Šm”F—p•`‰æˆ—
	void drawConfirm();
	// ƒ~ƒm‚Ì“®‚­ˆ—
	void moveBlock();


private:
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];
	
	int m_posX;
	int m_posY;

	float m_count;
	float m_speed;
};