#include "mino.h"
#include "common.h"

mino::mino() :
	m_block(),
	m_posX(7),
	m_posY(0),
	m_count(0.0f),
	m_speed(0.0f)
{
	
}

mino::~mino()
{
}

void mino::init()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_block[y][x] = Mino::kBlocks[y][x];
		}
	}

	m_speed = 0.5f;
}

void mino::end()
{
}

void mino::update()
{
}

void mino::draw()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				DrawFormatString(100 + m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 160 + m_count + y * DRAW_BLOCK_WIDTH, Mino::kColor_Red, "¡");
			}
		}
	}
}

void mino::drawConfirm()
{
	DrawFormatString(0, 20, Mino::kColor_Black, "m_count = %d", m_count);
}

void mino::moveBlock()
{
	m_count += m_speed;
	m_posY = m_count / DRAW_BLOCK_WIDTH;
	if (m_count > DRAW_BLOCK_WIDTH * 19)
	{
		m_count = 0;
		m_posY = 0;
	}
}