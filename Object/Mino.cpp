#include "Mino.h"
#include "Stage.h"
#include "common.h"
#include "Pad.h"

Mino::Mino() :
	m_block(),
	m_posX(4),
	m_posY(0),
	m_countY(0.0f),
	m_speed(0.0f),
	m_Pstage(nullptr)
{
	m_Pstage = new Stage;
}

Mino::~Mino()
{
	delete m_Pstage;
}

void Mino::init()
{
	// ミノの初期位置
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_block[y][x] = kMino::kBlocks[y][x];
		}
	}
	// ミノの位置情報
	m_posX = 4;
	m_posY = 0;
	m_countY = 0.0f;
	// ミノの落ちる速さ
	m_speed = 0.5f;
}

void Mino::end()
{
}

void Mino::update()
{
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		if (!m_Pstage->HitFlagLeft())
		{
			m_posX--;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		if (!m_Pstage->HitFlagRight())
		{
			m_posX++;
		}
	}

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

void Mino::drawConfirm()
{
	DrawFormatString(0, 20, kMino::kColor_Black, "m_count = %d", m_countY);
}

void Mino::moveBlock()
{
	m_countY += m_speed;
	m_posY = (int)m_countY / DRAW_BLOCK_WIDTH;
	// 盤面の底についたら下へは動かない
	if (m_countY > DRAW_BLOCK_WIDTH * 17)
	{
		m_countY = DRAW_BLOCK_WIDTH * 17;
		m_posY = DRAW_BLOCK_WIDTH * 17;
	}
}

void Mino::stopBlock()
{
	if (m_countY > DRAW_BLOCK_WIDTH * 17)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_Pstage->m_stage[m_posY + y][m_posX + x] += m_block[y][x];
			}
		}
		init();
	}
}
