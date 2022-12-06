// ミノ
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();

	virtual void init();
	// 二個目以降のノミの複製
	virtual void initRevival();
	// 終了処理
	virtual void end();
	// 更新処理
	virtual void update();
	// 描画処理
	virtual void draw();
	// 変数確認用描画処理
	virtual void drawConfirm();
	// ミノの動く処理
	virtual void moveBlock();
	// ミノを固定する処理
	virtual void stopBlock();
	// ミノの保存
	virtual void saveMino();
	// ミノの複製
	virtual void makeMino();

	// 壁判定たちその二
	void wallLeft();
	void wallRight();

	// 左の壁判定
	bool HitFlagLeft();
	// 右の壁判定
	bool HitFlagRight();
	// 地面の判定
	bool HitFlagBottom();

	// 座標などの情報取得
	int m_getPosX()const { return m_posX; }
	int m_getPosY()const { return m_posY; }

	int m_block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:

	int m_posX;
	int m_posY;

	int time;

	float m_countY;
	float m_speed;

	// true：存在する　false：存在しない
	bool m_makeMinoFlag;
	// true：あたった　false：あたってない
	bool m_hitMinoFlag;

	Stage* m_pStage;
};