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
	m_pStage(nullptr)
{
	m_pStage = new Stage;
}

Mino::~Mino()
{
	delete m_pStage;
}

void Mino::init()
{
	// �~�m�̏����ʒu
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_block[y][x] = kMino::kBlocks[y][x];
		}
	}
	// �~�m�̈ʒu���
	m_posX = 4;
	m_posY = 0;
	m_countY = 0.0f;
	// �~�m�̗����鑬��
	m_speed = 0.5f;
	m_pStage->init();
}

void Mino::end()
{
}

void Mino::update()
{
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		if (!m_pStage->HitFlagLeft())
		{
			m_posX--;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		if (!m_pStage->HitFlagRight())
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
								 200 + (int)m_countY + y * DRAW_BLOCK_WIDTH, kMino::kColor_Red, "��");
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
	// �Ֆʂ̒�ɂ����牺�ւ͓����Ȃ�
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
				m_pStage->m_stage[m_posY + y][m_posX + x] += m_block[y][x];
			}
		}
		init();
	}
}