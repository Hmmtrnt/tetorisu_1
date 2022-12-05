// ステージ
#pragma once
#include "common.h"

class Mino;

class Stage
{
public:
	Stage();
	virtual ~Stage();

	virtual void init();
	virtual void end();
	virtual void update();
	virtual void draw();

	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];

private:
	// 背景のハンドル
	int m_backHandle;

};