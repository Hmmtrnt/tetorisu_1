#include "Stage.h"
#include "common.h"
#include "mino.h"

Stage::Stage() :
	m_stage(),
	m_backHandle(-1)
{
	m_mino = new Mino;
}

Stage::~Stage()
{
	delete m_mino;
}

void Stage::init()
{
	// ステージの形
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stage[y][0] = 9;
			m_stage[y][11] = 9;
			m_stage[20][x] = 9;
		}
	}
	m_backHandle = LoadGraph("data/back2.jpg");
}

void Stage::end()
{
	DeleteGraph(m_backHandle);
}

void Stage::update()
{
}

void Stage::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_stage[y][x] == 1)
			{
				DrawFormatString(200 + x * DRAW_BLOCK_WIDTH,200 + y * DRAW_BLOCK_WIDTH, kStage::kColor_Red, "■");
			}
			else if (m_stage[y][x] == 9)
			{
				DrawFormatString(200 + x * DRAW_BLOCK_WIDTH, 200 + y * DRAW_BLOCK_WIDTH, kStage::kColor_Black, "■");
			}
		}
	}
}