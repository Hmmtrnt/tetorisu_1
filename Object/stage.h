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
	// �w�i�̃n���h��
	int m_backHandle;
	// ����ɐG�ꂽ���ǂ����̃t���O
	int m_hitFlag;

	mino* m_mino;
};