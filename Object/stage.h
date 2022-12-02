#pragma once
#include "common.h"

class Mino;

class Stage
{
public:
	Stage();
	virtual ~Stage();

	void init();
	void end();
	void update();
	void draw();

	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];

private:
	// �w�i�̃n���h��
	int m_backHandle;

	Mino* m_mino;
};