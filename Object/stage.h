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
	// 背景のハンドル
	int m_backHandle;
	// 判定に触れたかどうかのフラグ
	int m_hitFlag;

	mino* m_mino;
};