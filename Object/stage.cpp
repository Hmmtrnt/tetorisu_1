#include "Stage.h"
#include "common.h"
#include "Mino.h"

Stage::Stage() :
	m_stage(),
	m_backHandle(-1),
	m_pMino(nullptr)
{
	m_pMino = new Mino;
}

Stage::~Stage()
{
	delete m_pMino;
}

void Stage::init()
{
	// �Ֆʂ̊O�g
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
	m_pMino->init();
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
				DrawFormatString(200 + x * DRAW_BLOCK_WIDTH,200 + y * DRAW_BLOCK_WIDTH, kStage::kColor_Red, "��");
			}
			else if (m_stage[y][x] == 9)
			{
				DrawFormatString(200 + x * DRAW_BLOCK_WIDTH, 200 + y * DRAW_BLOCK_WIDTH, kStage::kColor_Black, "��");
			}
		}
	}
}

bool Stage::HitFlagLeft()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_block[y][x] != 0)
			{
				if (m_stage[m_pMino->m_getPosY() + y][m_pMino->m_getPosX() + (x - 1)] != 0)
				{
					return true;
				}
				else if ((m_pMino->m_getCount() - (m_pMino->m_getPosY() * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_stage[m_pMino->m_getPosY() + (y + 1)][m_pMino->m_getPosX() + (x - 1)] != 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Stage::HitFlagRight()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_block[y][x] != 0)
			{
				if (m_stage[m_pMino->m_getPosY() + y][m_pMino->m_getPosX() + (x + 1)] != 0)
				{
					return true;
				}
				else if ((m_pMino->m_getCount() - (m_pMino->m_getPosY() * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_stage[m_pMino->m_getPosY() + (y + 1)][m_pMino->m_getPosX() + (x + 1)] != 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}