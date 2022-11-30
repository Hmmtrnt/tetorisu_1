#include "mino.h"
#include "common.h"

namespace Mino
{
	// �~�m�̑傫��
	constexpr int kBlockHeight = 4;		// �c
	constexpr int kBlockWidth = 4;		// ��

	// �F
	const int const kColor_Red = GetColor(255, 0, 0);		// ��
	const int const kColor_Black = GetColor(0, 0, 0);		// ��

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
	m_blockX(7),
	m_blockY(0),
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

void mino::draw()
{
}
