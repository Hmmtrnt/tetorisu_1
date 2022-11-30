#include "mino.h"

namespace Mino
{
	// É~ÉmÇÃëÂÇ´Ç≥
	constexpr int kBlockHeight = 4;		// èc
	constexpr int kBlockWidth = 4;		// â°

	constexpr int kBlocks[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	};
}

mino::mino() :
	m_block()
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
