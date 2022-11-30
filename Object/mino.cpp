#include "mino.h"
#include "common.h"

namespace Mino
{
	// É~ÉmÇÃëÂÇ´Ç≥
	constexpr int kBlockHeight = 4;		// èc
	constexpr int kBlockWidth = 4;		// â°

	// êF
	const int const kColor_Red = GetColor(255, 0, 0);		// ê‘
	const int const kColor_Black = GetColor(0, 0, 0);		// çï

	// É~ÉmÇÃå`
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
