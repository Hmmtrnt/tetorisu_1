#pragma once
#include "common.h"

class stage
{
public:
	stage();
	virtual ~stage();

	void init();
	void end();
	void update();
	void draw();

private:
	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];
	// �w�i�̃n���h��
	int m_backHandle;
};