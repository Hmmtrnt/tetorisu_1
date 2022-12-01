#include "mino.h"
#include "common.h"
#include "Pad.h"

mino::mino() :
	m_block(),
	m_posX(4),
	m_posY(0),
	m_countY(0.0f),
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
	if (m_countY = DRAW_BLOCK_WIDTH * 17 && m_posY = DRAW_BLOCK_WIDTH * 17)
	{

	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT))
	{
		m_posX += 1;
	}
	if (m_posX >= 8)
	{
		m_posX = 8;
	}
	if (Pad::isTrigger(PAD_INPUT_LEFT))
	{
		m_posX -= 1;
	}
	if (m_posX <= 0)
	{
		m_posX = 0;
	}
}

void mino::draw()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				DrawFormatString(200 + m_posX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 200 + (int)m_countY + y * DRAW_BLOCK_WIDTH, Mino::kColor_Red, "¡");
			}
		}
	}
}

void mino::drawConfirm()
{
	DrawFormatString(0, 20, Mino::kColor_Black, "m_count = %d", m_countY);
}

void mino::moveBlock()
{
	m_countY += m_speed;
	m_posY = (int)m_countY / DRAW_BLOCK_WIDTH;
	if (m_countY > DRAW_BLOCK_WIDTH * 17)
	{
		m_countY = DRAW_BLOCK_WIDTH * 17;
		m_posY = DRAW_BLOCK_WIDTH * 17;
	}
}