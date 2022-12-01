#pragma once
#include "common.h"

class mino;

class stage
{
public:
	stage();
	virtual ~stage();

	void init();
	void end();
	void update();
	void draw();
	void wall();

private:
	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];
	// ”wŒi‚Ìƒnƒ“ƒhƒ‹
	int m_backHandle;
	// ”»’è‚ÉG‚ê‚½‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
	int m_hitFlag;

	mino* m_mino;
};