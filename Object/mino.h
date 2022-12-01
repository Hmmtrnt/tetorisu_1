// ミノ
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
	// 描画処理
	void draw();
	// 変数確認用描画処理
	void drawConfirm();

private:
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];
	
	int m_posX;
	int m_posY;

	int m_count;
};