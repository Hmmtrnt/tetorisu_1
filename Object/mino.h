// ƒ~ƒm
#pragma once
#include "common.h"
#include "Player.h"

class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	virtual void end();
	virtual void update();
	// •`‰æˆ—
	virtual void draw();
	// •Ï”Šm”F—p•`‰æˆ—
	virtual void drawConfirm();
	// ƒ~ƒm‚Ì“®‚­ˆ—
	virtual void moveBlock();
	// ƒ~ƒm‚ğŒÅ’è‚·‚éˆ—
	virtual void stopBlock();


	int m_getPosX()const { return m_posX; }
	int m_getPosY()const { return m_posY; }
	int m_getCount()const { return (int)m_countY; }
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	int m_posX;
	int m_posY;

	float m_countY;
	float m_speed;

	Player* m_pPlayer;
};