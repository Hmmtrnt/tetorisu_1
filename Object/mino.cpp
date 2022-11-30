#include "mino.h"
#include "common.h"

namespace Mino
{
	// �~�m�̑傫��
	constexpr int kBlockHeight = 4;		// �c
	constexpr int kBlockWidth = 4;		// ��

	// �F
	const int kColor_Red = GetColor(255, 0, 0);		// ��
	const int kColor_Black = GetColor(0, 0, 0);		// ��

	// �~�m�̌`
	constexpr int kBlocks[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	};
}

mino::mino() :
	m_block(),
	m_blockPosX(7),
	m_blockPosY(0),
	m_count(0)
{
	
}

mino::~mino()
{
}

void mino::init()
{
}

void mino::end()
{
}

void mino::update()
{
}

void mino::make()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_block[y][x] = Mino::kBlocks[y][x];
		}
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
				DrawFormatString(m_blockPosX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								 m_count + y * DRAW_BLOCK_WIDTH, Mino::kColor_Red, "��");
			}
		}
	}
}
