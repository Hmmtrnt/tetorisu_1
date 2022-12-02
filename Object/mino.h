// ミノ
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();

	void init();
	void end();
	void update();
	// 描画処理
	void draw();
	// 変数確認用描画処理
	void drawConfirm();
	// ミノの動く処理
	void moveBlock();
	// ミノを固定する処理
	void stopBlock();


	int m_getPosX()const { return m_posX; }
	int m_getPosY()const { return m_posY; }
	int m_getCount()const { return (int)m_countY; }
	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	int m_posX;
	int m_posY;

	float m_countY;
	float m_speed;

	bool HitFlag;

	Stage* m_Pstage;
};