#include "Mino.h"
#include "common.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	m_posX(4),
	m_posY(0),
	time(0),
	m_countY(0.0f),
	m_speed(0.0f),
	m_makeMinoFlag(false),
	m_hitMinoFlag(false),
	m_pStage(nullptr)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_block[y][x] = 0;
		}
	}
	m_pStage = new Stage;
}

Mino::~Mino()
{
	delete m_pStage;
}

void Mino::init()
{
	// ミノの初期位置
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_block[y][x] = kMino::kOMino[y][x];
		}
	}
	// ミノの位置情報
	m_posX = 4;
	m_posY = 0;

	time = 70;

	m_countY = 0.0f;
	// ミノの落ちる速さ
	m_speed = 0.5f;
	m_makeMinoFlag = true;
}

void Mino::initRevival()
{
	m_posX = 4;
	m_posY = 0;
	m_countY = 0;
	m_makeMinoFlag = true;
}

void Mino::end()
{
}

void Mino::update()
{
	/*if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		wallLeft();
		if (m_hitMinoFlag == false)
		{
			m_posX--;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		wallRight();
		if (m_hitMinoFlag == false)
		{
			m_posX++;
		}
	}*/
	/*if (m_countY > DRAW_BLOCK_WIDTH * 17 - 2)
	{
		return;
	}*/
	if (!HitFlagBottom())
	{
		return;
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		m_posX--;
		if (m_posX <= 0)
		{
			m_posX = 0;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		m_posX++;
		if (m_posX >= 8)
		{
			m_posX = 8;
		}
	}
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		m_countY += DRAW_BLOCK_WIDTH;
		if (m_posY >= DRAW_BLOCK_WIDTH * 17 - 2)
		{
			m_posY = DRAW_BLOCK_WIDTH * 17 - 2;
		}
	}
	saveMino();
	makeMino();
}

void Mino::draw()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				DrawFormatString(200 + m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 200 + (int)m_countY + y * DRAW_BLOCK_WIDTH, kMino::kColor_Red, "■");
			}
		}
	}
}

// 確認用描画
void Mino::drawConfirm()
{
	DrawFormatString(0, 20, kMino::kColor_Black, "m_count = %d", m_countY);
}

void Mino::moveBlock()
{
	/*m_countY += m_speed;
	m_posY = (int)m_countY / DRAW_BLOCK_WIDTH;*/
	time--;
	if (time <= 0)
	{
		time = 70;
		m_countY += DRAW_BLOCK_WIDTH;
	}
	
	//m_posY = (int)m_countY / DRAW_BLOCK_WIDTH;
	// 盤面の底についたら下へは動かない
	if (m_countY > DRAW_BLOCK_WIDTH * 17)
	{
		m_countY = DRAW_BLOCK_WIDTH * 17;
		m_posY = DRAW_BLOCK_WIDTH * 17;
	}
}

void Mino::stopBlock()
{
	
}

void Mino::saveMino()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_pStage->m_stage[m_posY + y][m_posX + x];
		}
	}
}

void Mino::makeMino()
{
	if (m_makeMinoFlag == true)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_block[y][x] = kMino::kOMino[y][x];
			}
		}
		m_makeMinoFlag = false;
	}
}

void Mino::wallLeft()
{
	m_hitMinoFlag = false;
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] != 0)
			{
				if (m_pStage->m_stage[m_posY + y][m_posX + (x - 1)] != 0)
				{
					m_hitMinoFlag = true;
				}
				else if ((int)(m_countY - (m_posY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stage[m_posY + (y + 1)][m_posX + (x - 1)] != 0)
					{
						m_hitMinoFlag = true;
					}
				}
			}
		}
	}
}

void Mino::wallRight()
{
	m_hitMinoFlag = false;
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] != 0)
			{
				if (m_pStage->m_stage[m_posY + y][m_posX + (x + 1)] != 0)
				{
					m_hitMinoFlag = true;
				}
				else if ((int)(m_countY - (m_posY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stage[m_posY + (y + 1)][m_posX + (x + 1)] != 0)
					{
						m_hitMinoFlag = true;
					}
				}
			}
		}
	}
}

// 左の壁判定
bool Mino::HitFlagLeft()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			// ミノの判定
			if (m_block[y][x] != 0)
			{
				// 左
				if (m_pStage->m_stage[m_posY + y][m_posX + (x - 1)] == 0)
				{
					return true;
				}
				// 左下
				else if ((int)(m_countY - (m_posY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stage[m_posY + (y + 1)][m_posX + (x - 1)] == 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

// 右の壁判定
bool Mino::HitFlagRight()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			// ミノの判定
			if (m_block[y][x] != 0)
			{
				// 右
				if (m_pStage->m_stage[m_posY + y][m_posX + (x + 1)] == 0)
				{
					return true;
				}
				// 右下
				else if ((int)(m_countY - (m_countY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stage[m_posY + (y + 1)][m_posX + (x + 1)] == 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

// 地面の判定
bool Mino::HitFlagBottom()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] != 0)
			{
				if (m_pStage->m_stage[m_posY + (y + 1)][m_posX + x] != 0)
				{
					return true;
				}
			}
		}
	}
	return false;
}