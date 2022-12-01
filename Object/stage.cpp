#include "stage.h"
#include "common.h"
#include "mino.h"

stage::stage() :
	m_stage(),
	m_backHandle(-1),
	m_hitFlag(0)
{
	m_mino = new mino;
}

stage::~stage()
{
	delete m_mino;
}

void stage::init()
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

void stage::end()
{
	DeleteGraph(m_backHandle);
}

void stage::update()
{
}

void stage::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_stage[y][x] == 1)
			{
				DrawFormatString(200 + x * DRAW_BLOCK_WIDTH,200 + y * DRAW_BLOCK_WIDTH, Stage::kColor_Red, "■");
			}
			else if (m_stage[y][x] == 9)
			{
				DrawFormatString(200 + x * DRAW_BLOCK_WIDTH, 200 + y * DRAW_BLOCK_WIDTH, Stage::kColor_Black, "■");
			}
		}
	}
}

void stage::wall()
{
	// 右の壁
	//for (int y = 0; y < BLOCK_HEIGHT; y++)
	//{
	//	for (int x = 0; x < BLOCK_WIDTH; x++)
	//	{
	//		if (m_mino->m_block[y][x] != 0)
	//		{
	//			if (m_stage[m_mino->m_getPosX() + y][m_mino->m_getPosY() + (x + 1)] != 0)
	//			{
	//				m_hitFlag = 1;
	//			}
				//else if ((int)(m_mino->m_count))
	//		}
	//	}
	//}
}